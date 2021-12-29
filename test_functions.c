//
// Created by iesm0 on 29.12.2021.
//

#include "test_functions.h"



int test_cross_product(bool q)
{
    printf("\n====================== Test of 'cross_product' ======================\n \n");
    struct vec a = {1.51 , 3.2, 10.645}, b = {7.89, 0.12, 54.9}, c,
            tv = {174.4026, 1.09005, -25.0668}, delta, rel_err;
    if(q) printf("Input: a = (%f, %f, %f), b = (%f, %f, %f)\n", a.x, a.y, a.z, b.x, b.y, b.z);
    cross_product(a, b,  &c);
    if(q) printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_scaling(bool q)
{
    printf("\n====================== Test of 'scaling' ======================\n \n");
    struct vec c = {100.51 , 30.2, 1.645},
            tv = {10.124500, 3.042084, 0.165703}, delta, rel_err,
            m_max = {10.1245, 20.4668, 5.6324};
    if(q) printf("Input: a = (%f, %f, %f)\n", c.x, c.y, c.z);
    scaling(&c, m_max);
    if(q) printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_m_from_b_only(bool q)
{
    printf("\n====================== Test of 'm_from_b_only' ======================\n \n");
    struct magnMoment_tau mMt;
    b_field_last.x = 23.3474; b_field_last.y = 45.4567; b_field_last.z = 98.0764;
    config.m_max.x = 10.1245; config.m_max.y = 20.4668; config.m_max.z = 5.6324;
    config.work_time_b_dot = 200;
    struct vec delta, rel_err,
            b[1] = {{14.5473, 22.2422, 93.2352}}, tv = {-7.758509 ,-20.466801, -4.268191};
    m_from_b_only (b, 1, 1, &mMt);
    if(q) printf("Output: rez = (%f, %f, %f)\n", mMt.m.x, mMt.m.y, mMt.m.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_m_from_b_and_w(bool q)
{
    printf("\n====================== Test of 'm_from_b_and_w' ======================\n \n");
    struct magnMoment_tau mMt;
    b_field_last.x = 23.3474; b_field_last.y = 45.4567; b_field_last.z = 98.0764;
    config.m_max.x = 10.1245; config.m_max.y = 20.2490; config.m_max.z = 10.1245;
    config.speed = 50; config.work_time = 500; config.angle = 0.5;
    struct vec delta, rel_err,
            b[1] = {{1., 2.0, 3.0}}, w[1] = {{4., 5., 6.}},
            tv = {10.1245 , -20.2490, 10.1245};
    m_from_b_and_w (b, 1, w, 1, &mMt);
    if(q) printf("Output: rez = (%f, %f, %f)\n", mMt.m.x, mMt.m.y, mMt.m.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_check_w_working(bool q)
{
    printf("\n====================== Test of 'check_w_working' ======================\n \n");
    struct vec w_1[1] = {{ERROR_OF_W , 1, 0}}, w_2[1] = {{45 , 1, 0}};
    int f_1 = check_w_working(w_1); int f_2 = check_w_working(w_2);
    if (f_1 != 0 || f_2 != 1)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_make_m_percent(bool q)
{
    printf("\n====================== Test of 'make_m_percent' ======================\n \n");
    struct magnMoment_tau mMt = {{10.124500, 3.042084, 0.165703} , 200};
    struct vec c = {100.51 , 30.2, 1.645}, m_max = {10.1245, 20.4668, 5.6324},
            tv = {100,	14.863505,	2.941960}, delta, rel_err;
    if(q) printf("Input: a = (%f, %f, %f)\n", c.x, c.y, c.z);
    make_m_percent(&mMt, m_max);
    if(q) printf("Output: rez = (%f, %f, %f)\n", mMt.m.x, mMt.m.y, mMt.m.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_deg_to_rad(bool q)
{
    printf("\n====================== Test of 'deg_to_rad' ======================\n \n");
    struct vec c[1] = {{100.23, 2.5, 1000.456}},
            tv = {1.749343, 0.043633, 17.461251}, delta, rel_err;
    deg_to_rad(c, 1);
    if(q) printf("Output: rez = (%f, %f, %f)\n", c[0].x, c[0].y, c[0].z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c[0].x - tv.x); delta.y = fabs(c[0].y - tv.y); delta.z = fabs(c[0].z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_derivative(bool q)
{
    printf("\n====================== Test of 'derivative' ======================\n \n");
    struct vec a = {1.2345,	50.001,	-100.24389}, b = {2.3456,	-10.1,	20.3467}, c,
            tv = {-0.0044444,	0.240404,	-0.48236236}, delta, rel_err;
    if(q) printf("Input: a = (%f, %f, %f), b = (%f, %f, %f)\n", a.x, a.y, a.z, b.x, b.y, b.z);
    derivative (a, b, 250,&c);
    if(q) printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_average(bool q)
{
    printf("\n====================== Test of 'average' ======================\n \n");
    struct vec array[5] = {{-10.126329 , -5.051127, 101.122772}, {-12.971122 , -5.557734, 156.881348},
                           {-11.097907 , -5.224148, 120.165901}, {-14.211337 , -5.778594, 181.18985},
                           {-13.079504 , -5.577035, 159.005646}}, c,
            tv = {-12.2972398, -5.4377276, 143.6731034}, delta, rel_err;
    average(array, 5,  &c);
    if(q) printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_calculate_magnetic_moment(bool q)
{
    printf("\n====================== Test of 'calculate_magnetic_moment' ======================\n \n");
    struct magnMoment_tau mMt;
    b_field_last.x = 23.3474; b_field_last.y = 45.4567; b_field_last.z = 98.0764;
    config.m_max.x = 0.25; config.m_max.y = 0.25; config.m_max.z = 0.17;
    config.speed = 50; config.work_time = 500; config.angle = 0.5;
    struct vec delta, rel_err,
            b[1] = {{1., 2.0, 3.0}}, w[1] = {{4., 5., 6.}},
            tv = {100 , -95.008102, -6.987828};
    calculate_magnetic_moment(&mMt, 0);
    if(q) printf("Output: rez = (%f, %f, %f)\n", mMt.m.x, mMt.m.y, mMt.m.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}

int test_weighted_moving_average(bool q)
{
    printf("\n====================== Test of 'weighted_moving_average' ======================\n \n");
    struct vec array[5] = {{-10.126329 , -5.051127, 101.122772}, {-12.971122 , -5.557734, 156.881348},
                           {-11.097907 , -5.224148, 120.165901}, {-14.211337 , -5.778594, 181.18985},
                           {-13.079504 , -5.577035, 159.005646}}, c,
            tv = {-12.773677, -5.522572, 153.011386}, delta, rel_err;
    weighted_moving_average(array, 5,  &c);
    if(q)printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    if(q) printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    if(q) printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    if(q) printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 1;
    }
    else
    {
        printf("CORRECTLY\n");
        return 0;
    }
}