#include <stdio.h>
#include "bdot.h"



int main() {
    struct magnMoment_tau mMt;
    calculate_magnetic_moment(&mMt);
    printf("[%f, %f, %f], %d\n", mMt.m.x, mMt.m.y, mMt.m.z, mMt.tau);
    return 0;
}

