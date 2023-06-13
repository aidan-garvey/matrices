#include "mat_struct.h"

#ifndef MATRICES_MAIN_HEADER_H
#define MATRICES_MAIN_HEADER_H 1

void mult4f(mat4f* src1, mat4f* src2, mat4f* dest);
void mult4d(mat4d* src1, mat4d* src2, mat4d* dest);
void mult4ld(mat4ld* src1, mat4ld* src2, mat4ld* dest);

void generate4f(mat4f*);
void generate4d(mat4d*);
void generate4ld(mat4ld*);

void print4f(mat4f*);
void print4d(mat4d*);
void print4ld(mat4ld*);

#endif

