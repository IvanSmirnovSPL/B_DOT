#ifndef _IMU_DATA_H
#define _IMU_DATA_H

#include <globdefs.h>
#include <main.h>

#define		SIZE_OF_IMU_VECTOR		10


/* Данные гироскопа */
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
  u32  time[2];  /* Время начала измерений и время после последнего измерения. миллисекунды */
  gyro_data_s gyro[SIZE_OF_IMU_VECTOR];
  magn_data_s magn[SIZE_OF_IMU_VECTOR];
} imu_data_s;



void imu_data_get(imu_data_s* imu);

#endif  /* imu_data.h */
