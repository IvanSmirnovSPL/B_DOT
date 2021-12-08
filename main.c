#include <stdio.h>
#include <stdlib.h>
#include "bdot.h"
#include "config.h"
#include "my_sensors.h"


int main() {
    imu_data_s imu;
    imu_data_get(&imu);
    struct magnMoment_tau mMt;
    s16 i; struct vec b[SIZE_OF_IMU_VECTOR], w[SIZE_OF_IMU_VECTOR];
    for (i = 0; i < SIZE_OF_IMU_VECTOR; i++)
    {
        b[i].x = imu.magn[i].x; b[i].y = imu.magn[i].y; b[i].z = imu.magn[i].z;
        w[i].x = imu.gyro[i].x; w[i].y = imu.gyro[i].y; w[i].z = imu.gyro[i].z;
    }
    calculate_magnetic_moment(/*b*/ imu.magn, SIZE_OF_IMU_VECTOR, /*w*/ imu.gyro , SIZE_OF_IMU_VECTOR, imu.time[1] - imu.time[0], &mMt);
    printf("[%f, %f, %f], %d\n", mMt.m.x, mMt.m.y, mMt.m.z, mMt.tau);
    return 0;
}

