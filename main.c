#include <stdio.h>
#include <stdlib.h>
#include "bdot.h"
#include "math.h"

#include "test_functions.h"




int main() {

    int sum = 0;/* calculate number of errors*/
    printf("\n");
    sum += test_cross_product();
    sum += test_scaling();
    sum += test_m_from_b_only();
    sum += test_m_from_b_and_w();
    sum += test_check_w_working();
    sum += test_make_m_percent();
    sum += test_deg_to_rad();
    sum += test_derivative();
    sum += test_average();
    sum += test_weighted_moving_average();
    sum += test_calculate_magnetic_moment();

    if (sum == 0)
    {
        printf("\nall test completed successfully \n");
    }
    else
    {
        printf("\n%d tests failed \n", sum);
    }

    return 0;
}

