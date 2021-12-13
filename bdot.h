//
// Created by iesm0 on 07.12.2021.
//

#ifndef B_DOT_BDOT_H
#define B_DOT_BDOT_H

#include "globdefs.h"
#include "config.h"
//#include "imu_data.h"
#include "my_sensors.h"

struct vec{
    f32 x, y, z;
};

struct magnMoment_tau
{
    struct vec m;
    u32 tau;
};

/* При вызове с параметром 'struct manMoment& mMt' записывает в неё время
в милисекундах и процент([-100, 100]) от максимума по осям катушек.*/
void calculate_magnetic_moment(struct magnMoment_tau* mMt);


#endif //B_DOT_BDOT_H

