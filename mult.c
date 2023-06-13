#include "mat.h"

#define dot4(src1, row1, src2, col2) \
        src1[row1] * src2[col2] + \
        src1[row1 + 1] * src2[4 + col2] + \
        src1[row1 + 2] * src2[8 + col2] + \
        src1[row1 + 3] * src2[12 + col2]

#define mult4(src1, src2, dest)                     \
    for (int i = 0; i < 16; i += 4)                 \
    {                                               \
        for (int j = 0; j < 4; j++)                 \
        {                                           \
            dest[i + j] = dot4(src1, i, src2, j);   \
        }                                           \
    }

void mult4f(mat4f* src1, mat4f* src2, mat4f* dest)
{
    mult4(src1->content, src2->content, dest->content);
}

void mult4d(mat4d* src1, mat4d* src2, mat4d* dest)
{
    mult4(src1->content, src2->content, dest->content);
}

void mult4ld(mat4ld* src1, mat4ld* src2, mat4ld* dest)
{
    mult4(src1->content, src2->content, dest->content);
}

#undef dot4
#undef mult4

