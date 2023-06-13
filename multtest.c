#include "mat.h"

#include <stdio.h>
#include <stdlib.h>

#define DoTest(ptype, mtype, stype) \
    mtype* src1 = malloc(sizeof(mtype)); \
    mtype* src2 = malloc(sizeof(mtype)); \
    mtype* dest = malloc(sizeof(mtype)); \
    generate4 ## stype(src1); \
    generate4 ## stype(src2); \
    print4 ## stype(src1); \
    printf("\n    TIMES\n\n"); \
    print4 ## stype(src2); \
    printf("\n    EQUALS\n\n"); \
    mult4 ## stype(src1, src2, dest); \
    print4 ## stype(dest); \
    printf("\n"); \
    free(src1); \
    free(src2); \
    free(dest);

void testf()
{
    printf ("----------------\n"
            "FLOATS   %3zu-bit\n"
            "----------------\n", sizeof(float) * 8);
    DoTest(float, mat4f, f);
}

void testd()
{
    printf ("-----------------\n"
            "DOUBLES   %3zu-bit\n"
            "-----------------\n", sizeof(double) * 8);
    DoTest(double, mat4d, d);
}

void testld()
{
    printf ("----------------------\n"
            "LONG DOUBLES   %3zu-bit\n"
            "----------------------\n", sizeof(long double) * 8);
    DoTest(long double, mat4ld, ld);
}

int main()
{
    srand(0);

    testf();
    testd();
    testld();

    return 0;
}

