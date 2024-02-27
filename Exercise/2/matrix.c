#include "matrix.h"
#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i, j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
}

void multiply_matrix_scalar(const float matrix[3][3], float scalar, float result[3][3])
{
    int i, j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

void multiply_matrices(const float a[3][3], const float b[3][3], float result[3][3])
{
    int i, j, k;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            result[i][j] = 0.0;
            for (k = 0; k < 3; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transform_point(const float matrix[3][3], float point[3])
{
    float result[3] = {0.0, 0.0, 0.0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i] += matrix[i][j] * point[j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        point[i] = result[i];
    }
}

void scale(float matrix[3][3], float scaleX, float scaleY)
{
    matrix[0][0] *= scaleX;
    matrix[1][1] *= scaleY;
}

void shift(float matrix[3][3], float shiftX, float shiftY)
{
    matrix[0][2] += shiftX;
    matrix[1][2] += shiftY;
}

void rotate(float matrix[3][3], float angle)
{
    float cosTheta = cos(angle);
    float sinTheta = sin(angle);

    float temp[3][3];
    init_identity_matrix(temp);

    temp[0][0] = cosTheta;
    temp[0][1] = -sinTheta;
    temp[1][0] = sinTheta;
    temp[1][1] = cosTheta;

    multiply_matrices(temp, matrix, matrix);
}