//
// Created by iesm0 on 07.12.2021.
//

#include "stdio.h"
#include "bdot.h"
#include "math.h"




struct data_from_sensor
{
    struct vec w[SIZE_OF_IMU_VECTOR], b[SIZE_OF_IMU_VECTOR];
    u32 time;
};


void make_conf(struct config_values* conf)
{
    f32 value; u32 tmp; s8 name[50];
    FILE* file; file = fopen("configuration.txt", "r");
    while (fscanf(file, "%u%f%s", &tmp, &value, name) != EOF) {
        switch (tmp)
        {
            case 1: conf->tolerance = value; break;
            case 2: conf->angle = value; break;
            case 3: conf->speed = value; break;
            case 4:  conf->work_time = value; break;
            case 5: conf->work_time_b_dot = value; break;
            case 6: conf->m_max.x = value; break;
            case 7: conf->m_max.y = value; break;
            case 8: conf->m_max.z = value; break;
        }
    }
}



void weighted_moving_average(const struct vec* array, s16 n_a, struct vec* rez)
{
    f32 total_weight = 1. * n_a * (n_a + 1) / 2;
    s64 i;
    rez->x = 0.; rez->y = 0.; rez->z = 0.;
    for (i = 0; i < n_a; i++)
    {
        rez->x += (i + 1) * array[i].x;
        rez->y += (i + 1) * array[i].y;
        rez->z += (i + 1) * array[i].z;
    }
    rez->x /= total_weight; rez->y /= total_weight; rez->z /= total_weight;
}

void average(const struct vec* array, s16 n_a, struct vec* rez)
{
    s64 i;
    rez->x = 0.; rez->y = 0.; rez->z = 0.;
    for (i = 0; i < n_a; i++)
    {
        rez->x += array[i].x;
        rez->y += array[i].y;
        rez->z += array[i].z;
    }
    rez->x /= n_a; rez->y /= n_a; rez->z /= n_a;
}

void cross_product(struct vec a, struct vec b,  struct vec* rez)
{
    rez->x = a.y * b.z - a.z * b.y;
    rez->y = a.z * b.x - a.x * b.z;
    rez->z = a.x * b.y - a.y * b.x;
}

void derivative (const struct vec* a, const struct vec* b, u32 step, struct vec* rez)
{
    step = step > 0 ? step : 10;
    rez->x = (a->x - b->x) / step;
    rez->y = (a->y - b->y) / step;
    rez->z = (a->z - b->z) / step;
}

void deg_to_rad(struct vec* w, s16 n_w)
{
    s64 i;
    for (i = 0; i < n_w; i++)
    {
        w[i].x *= (PI / 180.0);
        w[i].y *= (PI / 180.0);
        w[i].z *= (PI / 180.0);
    }
}

void scaling(struct vec* rez, struct vec m_max)
{
    struct vec k; k.x = 0., k.y = 0.; k.z = 0.;
    f32 K, tmp;
    if (rez->x != 0){k.x = ABS(m_max.x / rez->x) ;}
    if (rez->y != 0){k.y = ABS(m_max.y / rez->y) ;}
    if (rez->z != 0){k.z = ABS(m_max.z / rez->z) ;}
    if (k.x > k.y) { tmp = k.x; k.x = k.y; k.y = tmp; }
    if (k.x > k.z) { tmp = k.x; k.x = k.z; k.z = tmp; }
    if (k.y > k.z) { tmp = k.y; k.y = k.z; k.z = tmp; }
    K = k.x > 0 ? k.x : (k.y > 0 ? k.y : k.z); K = K > 0 ? K : 1;
    rez->x *= K; rez->y *= K; rez->z *= K;
}

void m_from_b_and_w (const struct vec* b, s16 n_b, const struct vec* w, s16 n_w, struct magnMoment_tau* rez)
{
    struct vec b_avg, w_avg;
    weighted_moving_average(b, n_b, &b_avg);
    //printf("b_avg: [%f, %f, %f]\n", b_avg.x, b_avg.y, b_avg.z);
    weighted_moving_average(w, n_w, &w_avg);
    //printf("w_avg: [%f, %f, %f]\n", w_avg.x, w_avg.y, w_avg.z);
    f32 tmp = w_avg.x * w_avg.x + w_avg.y * w_avg.y + w_avg.z * w_avg.z;
    cross_product(w_avg, b_avg, &(rez->m));
    scaling(&(rez->m), config.m_max);
    rez->tau = sqrt(tmp) < config.speed ? config.work_time : config.angle * 1000 / sqrt(tmp);
}

void m_from_b_only (const struct vec* b, s16 n_b, u32 step, struct magnMoment_tau* rez)
{
    s16 n_1 = n_b / 2, n_2 = n_b - n_1;
    struct vec b_avg_1, b_avg_2;
    weighted_moving_average(b, n_1, &b_avg_1);
    weighted_moving_average(b + n_1, n_2, &b_avg_2);
    //printf("b_avg_1: [%f, %f, %f]\n", b_avg_1.x, b_avg_1.y, b_avg_1.z);
    //printf("b_avg_2: [%f, %f, %f]\n", b_avg_2.x, b_avg_2.y, b_avg_2.z);
    derivative(&b_avg_2, &b_avg_1, step, &(rez->m));
    scaling(&(rez->m), config.m_max);
    rez->tau = config.work_time_b_dot;
}

s16 check_w_working(struct vec* w)
{
    if (w[0].x == ERROR_OF_W)
    {

        return 0;
    }
    return 1;
}

void get_data_from_sensors(struct data_from_sensor* dFS)
{
    imu_data_s imu;
    imu_data_get(&imu);
    s16 i;
    for (i = 0; i < SIZE_OF_IMU_VECTOR; i++)
    {
        dFS->b[i].x = imu.magn[i].x; dFS->b[i].y = imu.magn[i].y; dFS->b[i].z = imu.magn[i].z;
        dFS->w[i].x = imu.gyro[i].x; dFS->w[i].y = imu.gyro[i].y; dFS->w[i].z = imu.gyro[i].z;
    }
    dFS->time = imu.time[1] - imu.time[0];
}

void make_m_percent(struct magnMoment_tau* mMt)
{
    mMt->m.x = mMt->m.x * 100 / config.m_max.x;
    mMt->m.y = mMt->m.y * 100 / config.m_max.y;
    mMt->m.z = mMt->m.z * 100 / config.m_max.z;
}

void calculate_magnetic_moment(struct magnMoment_tau* mMt, const s16 flag)
{
    struct data_from_sensor dataFromSensor;
    get_data_from_sensors(&dataFromSensor);
    if (flag == 1) make_conf(&config);
    if (check_w_working(dataFromSensor.w) == 1)
    {
        //printf("from b and w\n");
        deg_to_rad(dataFromSensor.w, SIZE_OF_IMU_VECTOR);
        m_from_b_and_w(dataFromSensor.b, SIZE_OF_IMU_VECTOR, dataFromSensor.w, SIZE_OF_IMU_VECTOR, mMt);
    }
    else
    {
        //printf("from b\n");
        m_from_b_only (dataFromSensor.b, SIZE_OF_IMU_VECTOR, dataFromSensor.time, mMt);
    }
    make_m_percent(mMt);
}

