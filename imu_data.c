//
// Created by iesm0 on 08.12.2021.
//

/* this file is my realization of imu_data.c */

//#include <stdio.h>
#include <stdlib.h>
#include "imu_data.h"
#include "bdot.h"

f32 rand_0_1(void)
{
    return rand() / ((double) RAND_MAX);
}

f32 random_range(f32 min, f32 max)
{
    return min + rand_0_1() * (max - min);
}

void imu_data_get(imu_data_s* imu)
{
    struct vec_ b_min, b_max; b_min.x = 0; b_min.y = -0.05; b_min.z = 1;
    b_max.x = 0; b_max.y = -0.05; b_max.z = 1;
    struct vec_ w_min, w_max; w_min.x = 1; w_min.y = 1.05; w_min.z = 0.045;
    w_max.x = 1; w_max.y = 1.05; w_max.z = 0.045;
    s16 i;
    struct  vec_ b[10], w[10];
    for (i = 0; i < 10; i++)
    {
        b[i].x = random_range(b_min.x, b_max.x);
        b[i].y = random_range(b_min.y, b_max.y);
        b[i].z = random_range(b_min.z, b_max.z);
        w[i].x = random_range(w_min.x, w_max.x);
        w[i].y = random_range(w_min.y, w_max.y);
        w[i].z = random_range(w_min.z, w_max.z);
    }
    for(i = 0; i < SIZE_OF_IMU_VECTOR; i++)
    {
        imu->magn[i].x = b[i].x; imu->magn[i].y = b[i].y; imu->magn[i].z = b[i].z;
        /*if (i >= 5)
        {
            imu->magn[i].x ++; imu->magn[i].y ++; imu->magn[i].z ++;
        }*/
        imu->gyro[i].x = w[i].x; imu->gyro[i].y = w[i].y; imu->gyro[i].z = w[i].z;
    }
    imu->time[0] = 100; imu->time[1] = 200;
    //imu->gyro[0].x = ERROR_OF_W;
}