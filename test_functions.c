//
// Created by iesm0 on 29.12.2021.
//

#include "test_functions.h"



int test_cross_product()
{
    char name[40] = "cross_product";
    struct vec a = {1.51 , 3.2, 10.645}, b = {7.89, 0.12, 54.9}, c,
            tv = {174.4026, 1.09005, -25.0668}, delta, rel_err;
    cross_product(a, b,  &c);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_scaling()
{
    char name[40] = "scaling";
    struct vec c = {100.51 , 30.2, 1.645},
            tv = {10.124500, 3.042084, 0.165703}, delta, rel_err,
            m_max = {10.1245, 20.4668, 5.6324};
    scaling(&c, m_max);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_m_from_b_only(bool q)
{
    char name[40] = "m_from_b_only";
    struct magnMoment_tau mMt;
    b_field_last.x = 23.3474; b_field_last.y = 45.4567; b_field_last.z = 98.0764;
    config.m_max.x = 10.1245; config.m_max.y = 20.4668; config.m_max.z = 5.6324;
    config.work_time_b_dot = 200;
    struct vec delta, rel_err,
            b[1] = {{14.5473, 22.2422, 93.2352}}, tv = {-7.758509 ,-20.466801, -4.268191};
    m_from_b_only (b, 1, 1, &mMt);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_m_from_b_and_w()
{
    char name[40] = "m_from_b_and_w";
    struct magnMoment_tau mMt;
    b_field_last.x = 23.3474; b_field_last.y = 45.4567; b_field_last.z = 98.0764;
    config.m_max.x = 10.1245; config.m_max.y = 20.2490; config.m_max.z = 10.1245;
    config.speed = 50; config.work_time = 500; config.angle = 0.5;
    struct vec delta, rel_err,
            b[1] = {{1., 2.0, 3.0}}, w[1] = {{4., 5., 6.}},
            tv = {10.1245 , -20.2490, 10.1245};
    m_from_b_and_w (b, 1, w, 1, &mMt);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_check_w_working()
{
    char name[40] = "check_w_working";
    struct vec w_1[1] = {{ERROR_OF_W , 1, 0}}, w_2[1] = {{45 , 1, 0}};
    int f_1 = check_w_working(w_1); int f_2 = check_w_working(w_2);
    if (f_1 != 0 || f_2 != 1)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_make_m_percent()
{
    char name[40] = "make_m_percent";
    struct magnMoment_tau mMt = {{10.124500, 3.042084, 0.165703} , 200};
    struct vec c = {100.51 , 30.2, 1.645}, m_max = {10.1245, 20.4668, 5.6324},
            tv = {100,	14.863505,	2.941960}, delta, rel_err;
    make_m_percent(&mMt, m_max);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_deg_to_rad()
{
    char name[40] = "deg_to_rad";
    struct vec c[1] = {{100.23, 2.5, 1000.456}},
            tv = {1.749343, 0.043633, 17.461251}, delta, rel_err;
    deg_to_rad(c, 1);
    delta.x = fabs(c[0].x - tv.x); delta.y = fabs(c[0].y - tv.y); delta.z = fabs(c[0].z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_derivative()
{
    char name[40] = "derivative";
    struct vec a = {1.2345,	50.001,	-100.24389}, b = {2.3456,	-10.1,	20.3467}, c,
            tv = {-0.0044444,	0.240404,	-0.48236236}, delta, rel_err;
    derivative (a, b, 250,&c);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_average()
{
    char name[40] = "average";
    struct vec array[5] = {{-10.126329 , -5.051127, 101.122772}, {-12.971122 , -5.557734, 156.881348},
                           {-11.097907 , -5.224148, 120.165901}, {-14.211337 , -5.778594, 181.18985},
                           {-13.079504 , -5.577035, 159.005646}}, c,
            tv = {-12.2972398, -5.4377276, 143.6731034}, delta, rel_err;
    average(array, 5,  &c);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_calculate_magnetic_moment()
{
    char name[40] = "calculate_magnetic_moment";
    struct magnMoment_tau mMt;
    b_field_last.x = 23.3474; b_field_last.y = 45.4567; b_field_last.z = 98.0764;
    config.m_max.x = 0.25; config.m_max.y = 0.25; config.m_max.z = 0.17;
    config.speed = 50; config.work_time = 500; config.angle = 0.5;
    struct vec delta, rel_err,
            b[1] = {{1., 2.0, 3.0}}, w[1] = {{4., 5., 6.}},
            tv = {100 , -95.008102, -6.987828};
    calculate_magnetic_moment(&mMt, 0);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}

int test_weighted_moving_average()
{
    char name[40] = "weighted_moving_average";
    struct vec array[5] = {{-10.126329 , -5.051127, 101.122772}, {-12.971122 , -5.557734, 156.881348},
                           {-11.097907 , -5.224148, 120.165901}, {-14.211337 , -5.778594, 181.18985},
                           {-13.079504 , -5.577035, 159.005646}}, c,
            tv = {-12.773677, -5.522572, 153.011386}, delta, rel_err;
    weighted_moving_average(array, 5,  &c);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("test '%s' failed\n", name);
        return 1;
    }
    else
    {
        printf("test '%s' completed successfully\n", name);
        return 0;
    }
}