#include <stdio.h>
#include <stdlib.h>
#include "bdot.h"



int main() {
    s16 flag, j;
    for (j = 0; j > -1 ; j++) {
        printf("Enter flag: \n");
        scanf("%d", &flag);
        printf("Ok, result: \n");
        struct magnMoment_tau mMt;
        calculate_magnetic_moment(&mMt, flag);
        printf("[%f, %f, %f], %d\n", mMt.m.x, mMt.m.y, mMt.m.z, mMt.tau);
    }
    return 0;
}

