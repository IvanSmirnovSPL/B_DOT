//
// Created by iesm0 on 07.12.2021.
//

#ifndef BDOT_CONFIG_H
#define BDOT_CONFIG_H

#include "globdefs.h"

#define PI 3.14159265358979323846
#define TOLERANCE 100.0
#define ANGLE PI / 6
#define SPEED 5.0
#define WORK_TIME 500
#define WORK_TIME_B_DOT 250
#define M_MAX_X 0.1253914864729585 * 2
#define M_MAX_Y 0.1253914864729585 * 2
#define M_MAX_Z 0.08568002662482765 * 2
#define ERROR_OF_W 1E+7
/*
struct vec{
    f32 x, y, z;
};

struct config_values
{
    f32 tolerance, angle, speed;
    struct vec m_max;
    u64 work_time , work_time_b_dot;
};

struct magnMoment_tau
{
    struct vec m;
    u32 tau;
};
*/

#endif //BDOT_CONFIG_H



