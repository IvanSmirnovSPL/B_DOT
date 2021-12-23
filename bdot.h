//
// Created by iesm0 on 07.12.2021.
//

#ifndef B_DOT_BDOT_H
#define B_DOT_BDOT_H

#include "globdefs.h"
#include "imu_data.h"

/* TEST shows the place where we get configuration
if it is '1' - hardcode below, '0' - from outside*/
#define TEST 1

/* PI value*/
#define PI 3.14159265358979323846
/* value informing that gyroscope doesn't work*/
#define ERROR_OF_W 1E+7
/* instead of zero */
#define EPSILON 1E-6

#if TEST

#define TOLERANCE 100.0
#define ANGLE 3.14159265358979323846 / 6
#define SPEED 5.0
#define WORK_TIME 500
#define WORK_TIME_B_DOT 250
#define M_MAX_X 0.1253914864729585 * 2
#define M_MAX_Y 0.1253914864729585 * 2
#define M_MAX_Z 0.08568002662482765 * 2

#endif

/* 3D vector */
struct vec{
    f32 x, y, z;
};

/* structure of configuration values, may be rewritten during running*/
struct config_values
{
    f32 tolerance, angle, speed;
    struct vec m_max;
    u64 work_time , work_time_b_dot;
}config;

/*service structure for saving B-field from previous iteration*/
struct vec b_field_last;

/*service structure for transferring sensors' data inside the module*/
struct data_from_sensor
{
    struct vec w[SIZE_OF_IMU_VECTOR], b[SIZE_OF_IMU_VECTOR];
    u32 time;
};

/* result structure, contains magnetic moment in percent from maximum(m) [-100, 100]
 * and duration of control action(tau) [ms]*/
struct magnMoment_tau
{
    struct vec m;
    unix_time_t tau;
};


void calculate_magnetic_moment(struct magnMoment_tau* mMt, s16 flag);
/*update magnetorquers control action depends on working sensors
 * Inputs:
 * - flag -- necessity to rewrite configuration ('1' - need, '0' - not need)
 * Outputs:
 * - mMt -- magnetic moment(m) in percents[-100, 100] from maximum
 * and its duration(tau) [ms]*/

void m_from_b_only (const struct vec* b, s16 n_b, unix_time_t step, struct magnMoment_tau* rez);
/* calculate magnetic moment if gyroscope is not working
 * Inputs:- b -- [mT] array of B-field vectors
 * - n_b -- length of B-field array
 * - step -- [ms] duration of B-field measuring
 * Outputs:
 * - rez -- magnetic moment and its duration*/

void m_from_b_and_w (const struct vec* b, s16 n_b, const struct vec* w, s16 n_w, struct magnMoment_tau* rez);
/* calculate magnetic moment if gyroscope is working
 * Inputs:
 * - b -- [mT] array of B-field vectors
 * - n_b -- length of B-field array
 * - w -- [deg/s]array of angular velocity vectors
 * - n_w -- length of angular velocity array
 * Outputs:
 * - rez -- magnetic moment and its duration*/


void make_m_percent(struct magnMoment_tau* mMt);
/* determine percent of supplied magnetic moment from maximum
 * Output:
 * - mMt -- structure consisting of magnetic moment array (m) [%]
 * and duration of working (tau) [ms]
 * */


void get_data_from_sensors(struct data_from_sensor* dFS);
/* reading data from magnetometers and gyroscopes
 * Output:
 * -dFS -- data_from_sensors structure: array of B-field vectors(b),
 * array of angular velocity vectors(w), duration of measuring(time) */


s16 check_w_working(struct vec* w);
/* determining status of gyroscope sensor
 * Inputs:
 * - w -- [deg/sec] array of angular velocity vectors*/

void scaling(struct vec* rez, struct vec m_max);
/* normalization of magnetic moment vector depending on maximums
 * Inputs:
 * - m_max -- [A*m^2] array of magnetic moment maximums
 * Outputs:
 * -rez -- [A*m^2] array of normalized magnetic moments*/

void deg_to_rad(struct vec* w, s16 n_w);
/* translate angular velocity from [deg/sec] to [rad/sec]
 * Inputs:
 * - n_w -- length of angular velocity vectors array(w)
 * Outputs:
 * -w -- array of angular velocity vectors*/

void derivative (const struct vec a, const struct vec b, u32 step, struct vec* rez);
/* calculate derivative from scheme (a - b)/step
 * Inputs:
 * - a -- first vector(current)
 * - b -- second vector(last)
 * - step -- time difference
 * Outputs:
 * - rez -- vector of derivative*/

void cross_product(struct vec a, struct vec b,  struct vec* rez);
/* calculate cross product rez = a x b
 * Inputs:
 * - a -- first vector
 * - b -- second vector
 * Outputs:
 * - rez -- result vector*/

void average(const struct vec* array, s16 n_a, struct vec* rez);
/* calculate average value of vectors' array
 * -Input:
 * - array -- array of vectors
 * - n_a -- length of array
 * Outputs:
 * - rez -- average vector*/

void weighted_moving_average(const struct vec* array, s16 n_a, struct vec* rez);
/* calculate weighted average value of vectors' array
 * -Input:
 * - array -- array of vectors
 * - n_a -- length of array
 * Outputs:
 * - rez -- average vector*/

void make_conf(struct config_values* conf);
/* fill configuration structure if it is necessary
 * Outputs:
 * - conf -- config_values structure */

#endif //B_DOT_BDOT_H

