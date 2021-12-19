//
// Created by iesm0 on 07.12.2021.
//

#ifndef B_DOT_BDOT_H
#define B_DOT_BDOT_H

#include "globdefs.h"
#include "imu_data.h"

#define PI 3.14159265358979323846
#define ERROR_OF_W 1E+7

struct vec{
    f32 x, y, z;
};

struct config_values
{
    f32 tolerance, angle, speed;
    struct vec m_max;
    u64 work_time , work_time_b_dot;
}config;

struct magnMoment_tau
{
    struct vec m;
    u32 tau;
};

/* При вызове с параметром 'struct manMoment& mMt' записывает в неё время
в милисекундах и процент([-100, 100]) от максимума по осям катушек.*/
void calculate_magnetic_moment(struct magnMoment_tau* mMt, const s16 flag);


#endif //B_DOT_BDOT_H

