#include "mat.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define NUM_OPS 1000000

void test_flt(int ops);
void test_dbl(int ops);
void test_ldbl(int ops);

int main()
{
    srand(0);

    struct timeval start_tv, end_tv;
    long double diff;

    printf("Testing floats (%zu-bit)\n", sizeof(float) * 8);
    gettimeofday(&start_tv, NULL);
    test_flt(NUM_OPS);
    gettimeofday(&end_tv, NULL);
    diff = (end_tv.tv_sec - start_tv.tv_sec) + 
            (end_tv.tv_usec - start_tv.tv_usec) / 1000000.0;
    printf("Took %Lf seconds\n", diff);

    printf("Testing doubles (%zu-bit)\n", sizeof(double) * 8);
    gettimeofday(&start_tv, NULL);
    test_dbl(NUM_OPS);
    gettimeofday(&end_tv, NULL);
    diff = (end_tv.tv_sec - start_tv.tv_sec) + 
            (end_tv.tv_usec - start_tv.tv_usec) / 1000000.0;
    printf("Took %Lf seconds\n", diff);

    printf("Testing long doubles (%zu-bit)\n", sizeof(long double) * 8);
    gettimeofday(&start_tv, NULL);
    test_ldbl(NUM_OPS);
    gettimeofday(&end_tv, NULL);
    diff = (end_tv.tv_sec - start_tv.tv_sec) + 
            (end_tv.tv_usec - start_tv.tv_usec) / 1000000.0;
    printf("Took %Lf seconds\n", diff);

    return 0;
}

void test_flt(int ops)
{
    mat4f src1, src2, dest;
    for (int i = 0; i < ops; i++)
    {
        generate4f(&src1);
        generate4f(&src2);
        mult4f(&src1, &src2, &dest);
    }
}

void test_dbl(int ops)
{
    mat4d src1, src2, dest;
    for (int i = 0; i < ops; i++)
    {
        generate4d(&src1);
        generate4d(&src2);
        mult4d(&src1, &src2, &dest);
    }
}

void test_ldbl(int ops)
{
    mat4ld src1, src2, dest;
    for (int i = 0; i < ops; i++)
    {
        generate4ld(&src1);
        generate4ld(&src2);
        mult4ld(&src1, &src2, &dest);
    }
}

