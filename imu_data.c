#include "imu_data.h"
#include <imu.h>

static f32 mag[3];
static f32 acc[3];
static f32 gyro[3];


#define		TAG		"IMU"


/**
 * Собираем 2 вектора данных компас-гироскоп
 */
void imu_data_get(imu_data_s * imu)
{
    f32 x, y, z;


     /* Метка времени, мс */
    imu->time[0] = HAL_GetTicks();

    /* У нас 40 Гц обновление, стираем массив и читаем данные компаса */
    for (int i = 0; i < SIZE_OF_IMU_VECTOR; i++) {


	/* Магнимтное поле  */
	if (imu_read_mag(&x, &y, &z) == 0) {
		imu->magn[i].x = x;
	    imu->magn[i].y = y;
	    imu->magn[i].z = z;
	}

	x = y = z = 0;
	if (imu_read_gyro(&x, &y, &z) == 0) {
		imu->gyro[i].x = x;
		imu->gyro[i].y = y;
		imu->gyro[i].z = z;
	}
	vTaskDelay(5);
    }
    mag[0] = mag[0] / SIZE_OF_IMU_VECTOR;
    mag[1] = mag[1] / SIZE_OF_IMU_VECTOR;
    mag[2] = mag[2] / SIZE_OF_IMU_VECTOR;

    gyro[0] = gyro[0] / SIZE_OF_IMU_VECTOR;
    gyro[1] = gyro[1] / SIZE_OF_IMU_VECTOR;
    gyro[2] = gyro[2] / SIZE_OF_IMU_VECTOR;


    log_printf(TAG, "Gyro: ");
//      log_float_array(mag, 3);
    log_float_array(gyro, 3);
}
