#ifndef MATRICES_STRUCTS_H
#define MATRICES_STRUCTS_H 1

typedef struct
{
    float content[16];
}
mat4x4f, mat4f;

typedef struct
{
    double content[16];
}
mat4x4d, mat4d;

typedef struct
{
    long double content[16];
}
mat4x4ld, mat4ld;

#endif

