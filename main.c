#include <stdio.h>
#include <stdlib.h>
#include "bdot.h"
#include "math.h"

#include "test_functions.h"




int main() {

    int flag, sum = 0;/* calculate number of errors*/
    bool Q = 1;/* show details if '1', doesn't show if '0'*/
    flag = test_cross_product(Q); sum += flag; if (flag) flag = test_cross_product(1);
    flag = test_scaling(Q); sum += flag; if (flag) flag = test_scaling(1);
    flag = test_m_from_b_only(Q); sum += flag; if (flag) flag = test_m_from_b_only(1);
    flag = test_m_from_b_and_w(Q); sum += flag; if (flag) flag = test_m_from_b_and_w(1);
    flag = test_check_w_working(Q); sum += flag; if (flag) flag = test_check_w_working(1);
    flag = test_make_m_percent(Q); sum += flag; if (flag) flag = test_make_m_percent(1);
    flag = test_deg_to_rad(Q); sum += flag; if (flag) flag = test_deg_to_rad(1);
    flag = test_derivative(Q); sum += flag; if (flag) flag = test_derivative(1);
    flag = test_average(Q); sum += flag; if (flag) flag = test_average(1);
    flag = test_weighted_moving_average(Q); sum += flag; if (flag) flag = test_weighted_moving_average(1);
    flag = test_calculate_magnetic_moment(Q); sum += flag; if (flag) flag = test_calculate_magnetic_moment(1);

    if (sum == 0)
    {
        printf("\n \n==============================================="
               " ALL RIGHT ==============================================\n");
    }
    else
    {
        printf("\n \n=============================================="
               " %d PROBLEMS ========================================\n", sum);
    }

    return 0;
}

