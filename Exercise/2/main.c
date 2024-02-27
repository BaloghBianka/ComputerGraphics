#include "matrix.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
    float b[3][3];
    float c[3][3];

    float scaled_a[3][3];
    float scalar = 2.0f;

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    printf("Matrix A:\n");
    print_matrix(a);

    printf("\nMatrix B:\n");
    print_matrix(b);

    add_matrices(a, b, c);

    printf("\nMatrix A + B:\n");
    print_matrix(c);

    multiply_matrix_scalar(a, scalar, scaled_a);

    printf("\nMatrix A multiplied by scalar %f:\n", scalar);
    print_matrix(scaled_a);

    float result[3][3];

    multiply_matrices(a, b, result);

    printf("\nMatrix A * B:\n");
    print_matrix(result);

    float identity_matrix[3][3];

    init_identity_matrix(identity_matrix);

    printf("\nIdentity Matrix:\n");
    print_matrix(identity_matrix);

    // Transforming a 2D point with homogeneous coordinates
    float point[3] = {1.0f, 2.0f, 1.0f}; // Homogeneous coordinates: (1, 2, 1)
    transform_point(result, point);

    printf("\nTransformed Point with Matrix A * B:\n");
    printf("(%.2f, %.2f, %.2f)\n", point[0], point[1], point[2]);

    return 0;
}
