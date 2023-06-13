#include "mat.h"

#include <float.h>
#include <stdlib.h>
#include <math.h>

#define FLT_EXP_RANGE (FLT_MAX_EXP - FLT_MIN_EXP)
#define DBL_EXP_RANGE (DBL_MAX_EXP - DBL_MIN_EXP)
#define LDBL_EXP_RANGE (LDBL_MAX_EXP - LDBL_MIN_EXP)

#define RandSign() ((rand() & 1 ? 1 : -1))

void generate4f(mat4f* m)
{
    for (int i = 0; i < 16; i++)
    {
        // mantissa is in range [-1, +1]
        float mant = (rand() / (float)RAND_MAX) * 2.f - 1.f;
        // only cover 1/2 the possible range of exponents
        int exp = RandSign() * (FLT_MIN_EXP + rand() % FLT_EXP_RANGE) / 2;
        m->content[i] = ldexpf(mant, exp);
    }
}

void generate4d(mat4d* m)
{
    for (int i = 0; i < 16; i++)
    {
        // mantissa is in range [-1, +1]
        double mant = (rand() / (double)RAND_MAX) * 2.0 - 1.0;
        // only cover 1/2 the possible range of exponents
        int exp = RandSign() * (DBL_MIN_EXP + rand() % DBL_EXP_RANGE) / 2;
        m->content[i] = ldexp(mant, exp);
    }
}

void generate4ld(mat4ld* m)
{
    for (int i = 0; i < 16; i++)
    {
        // mantissa is in range [-1, +1]
        long double mant = (rand() / (long double)RAND_MAX) * 2.0 - 1.0;
        // only cover 1/2 the possible range of exponents
        int exp = RandSign() * (LDBL_MIN_EXP + rand() % LDBL_EXP_RANGE) / 2;
        m->content[i] = ldexpl(mant, exp);
    }
}

#undef FLT_EXP_RANGE
#undef DBL_EXP_RANGE
#undef LDBL_EXP_RANGE

#undef RandSign

