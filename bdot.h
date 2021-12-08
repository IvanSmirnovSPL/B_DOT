//
// Created by iesm0 on 07.12.2021.
//

#ifndef B_DOT_BDOT_H
#define B_DOT_BDOT_H

#include "globdefs.h"
#include "config.h"


void calculate_magnetic_moment(struct vec* b, s16 n_b, struct vec* w, s16 n_w, u32 time, struct magnMoment_tau* mMt);


#endif //B_DOT_BDOT_H

