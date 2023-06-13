#include "mat.h"

#include <stdio.h>

#define PRINT_FMT "%#+16.6"

#define print4(mat, fmt) \
    for (int i = 0; i < 16; i += 4) \
    { \
        for (int j = 0; j < 4; j++) \
        { \
            printf(PRINT_FMT fmt " ", mat[i + j]); \
        } \
        printf("\n"); \
    }

void print4f(mat4f* m)
{
    print4(m->content, "e");
}

void print4d(mat4d* m)
{
    print4(m->content, "e");
}

void print4ld(mat4ld* m)
{
    print4(m->content, "Le");
}

#undef PRINT_FNT
#undef print4

