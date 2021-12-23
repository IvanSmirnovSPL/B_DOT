//
// Created by iesm0 on 08.12.2021.
//

#ifndef B_DOT_MY_SENSORS_H /* this file is my realization of imu_data.h */
#define B_DOT_MY_SENSORS_H

#include "globdefs.h"


#define SIZE_OF_IMU_VECTOR 10

struct vec_{
    f32 x, y, z;
};

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} gyro_data_s;

/* Данные компаса */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} magn_data_s;


/* Данные измерений с lsm imu */
typedef struct {
    unix_time_t  time[2];  /* Время начала измерений и время после последнего измерения. миллисекунды */
    gyro_data_s gyro[SIZE_OF_IMU_VECTOR];
    magn_data_s magn[SIZE_OF_IMU_VECTOR];
} imu_data_s;



void imu_data_get(imu_data_s* imu);


#endif //B_DOT_MY_SENSORS_H
