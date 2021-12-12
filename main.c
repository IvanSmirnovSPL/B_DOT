#include <stdio.h>
#include <stdlib.h>
#include "bdot.h"
#include "config.h"
#include "my_sensors.h"


int main() {
    struct magnMoment_tau mMt;
    calculate_magnetic_moment(&mMt);
    printf("[%f, %f, %f], %d\n", mMt.m.x, mMt.m.y, mMt.m.z, mMt.tau);
    return 0;
}

