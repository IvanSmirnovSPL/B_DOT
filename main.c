#include <stdio.h>
#include <stdlib.h>
#include "bdot.h"
#include "math.h"

#define ACCURACY 0.02

int test_cross_product()
{
    printf("\n====================== Test of 'cross_product' ======================\n \n");
    struct vec a = {1.51 , 3.2, 10.645}, b = {7.89, 0.12, 54.9}, c,
            tv = {174.4026, 1.09005, -25.0668}, delta, rel_err;
    printf("Input: a = (%f, %f, %f), b = (%f, %f, %f)\n", a.x, a.y, a.z, b.x, b.y, b.z);
    cross_product(a, b,  &c);
    printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 0;
    }
    else
    {
        printf("CORRECTLY\n");
        return 1;
    }
}

int test_scaling()
{
    printf("\n====================== Test of 'scaling' ======================\n \n");
    struct vec c = {100.51 , 30.2, 1.645},
            tv = {10.124500, 3.042084, 0.165703}, delta, rel_err,
            m_max = {10.1245, 20.4668, 5.6324};
    printf("Input: a = (%f, %f, %f)\n", c.x, c.y, c.z);
    scaling(&c, m_max);
    printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 0;
    }
    else
    {
        printf("CORRECTLY\n");
        return 1;
    }
}

int test_make_m_percent()
{
    printf("\n====================== Test of 'make_m_percent' ======================\n \n");
    struct magnMoment_tau mMt = {{10.124500, 3.042084, 0.165703} , 200};
    struct vec c = {100.51 , 30.2, 1.645}, m_max = {10.1245, 20.4668, 5.6324},
            tv = {100,	14.863505,	2.941960}, delta, rel_err;
    printf("Input: a = (%f, %f, %f)\n", c.x, c.y, c.z);
    make_m_percent(&mMt, m_max);
    printf("Output: rez = (%f, %f, %f)\n", mMt.m.x, mMt.m.y, mMt.m.z);
    printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(mMt.m.x - tv.x); delta.y = fabs(mMt.m.y - tv.y); delta.z = fabs(mMt.m.z -tv.z);
    printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 0;
    }
    else
    {
        printf("CORRECTLY\n");
        return 1;
    }
}

int test_deg_to_rad()
{
    printf("\n====================== Test of 'deg_to_rad' ======================\n \n");
    struct vec c[1] = {{100.23, 2.5, 1000.456}},
            tv = {1.749343, 0.043633, 17.461251}, delta, rel_err;
    deg_to_rad(c, 1);
    printf("Output: rez = (%f, %f, %f)\n", c[0].x, c[0].y, c[0].z);
    printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c[0].x - tv.x); delta.y = fabs(c[0].y - tv.y); delta.z = fabs(c[0].z -tv.z);
    printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 0;
    }
    else
    {
        printf("CORRECTLY\n");
        return 1;
    }
}

int test_derivative()
{
    printf("\n====================== Test of 'derivative' ======================\n \n");
    struct vec a = {1.2345,	50.001,	-100.24389}, b = {2.3456,	-10.1,	20.3467}, c,
            tv = {-0.0044444,	0.240404,	-0.48236236}, delta, rel_err;
    printf("Input: a = (%f, %f, %f), b = (%f, %f, %f)\n", a.x, a.y, a.z, b.x, b.y, b.z);
    derivative (a, b, 250,&c);
    printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 0;
    }
    else
    {
        printf("CORRECTLY\n");
        return 1;
    }
}

int test_average()
{
    printf("\n====================== Test of 'average' ======================\n \n");
    struct vec array[5] = {{-10.126329 , -5.051127, 101.122772}, {-12.971122 , -5.557734, 156.881348},
            {-11.097907 , -5.224148, 120.165901}, {-14.211337 , -5.778594, 181.18985},
            {-13.079504 , -5.577035, 159.005646}}, c,
            tv = {-12.2972398, -5.4377276, 143.6731034}, delta, rel_err;
    average(array, 5,  &c);
    printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 0;
    }
    else
    {
        printf("CORRECTLY\n");
        return 1;
    }
}

int test_weighted_moving_average()
{
    printf("\n====================== Test of 'weighted_moving_average' ======================\n \n");
    struct vec array[5] = {{-10.126329 , -5.051127, 101.122772}, {-12.971122 , -5.557734, 156.881348},
                           {-11.097907 , -5.224148, 120.165901}, {-14.211337 , -5.778594, 181.18985},
                           {-13.079504 , -5.577035, 159.005646}}, c,
            tv = {-12.773677, -5.522572, 153.011386}, delta, rel_err;
    weighted_moving_average(array, 5,  &c);
    printf("Output: rez = (%f, %f, %f)\n", c.x, c.y, c.z);
    printf("True value: (%f, %f, %f)\n", tv.x, tv.y, tv.z);
    delta.x = fabs(c.x - tv.x); delta.y = fabs(c.y - tv.y); delta.z = fabs(c.z -tv.z);
    printf("ABS residual: (%f, %f, %f)\n", delta.x, delta.y, delta.z);
    rel_err.x =  delta.x / fabs(tv.x); rel_err.y =  delta.y / fabs(tv.y); rel_err.z =  delta.z / fabs(tv.z);
    printf("Relative error: (%f, %f, %f)\n", rel_err.x, rel_err.y, rel_err.z);
    if (rel_err.x > ACCURACY || rel_err.y > ACCURACY|| rel_err.z > ACCURACY)
    {
        printf("SMTH IS WRONG\n");
        return 0;
    }
    else
    {
        printf("CORRECTLY\n");
        return 1;
    }
}

int main() {


   int flag = test_make_m_percent();


    return 0;
}

