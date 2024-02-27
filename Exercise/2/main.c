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

    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    print_matrix(c);

    multiply_matrix_scalar(a, scalar, scaled_a);

    printf("Original matrix:\n");
    print_matrix(a);

    printf("\nMatrix multiplied by scalar %f:\n", scalar);
    print_matrix(scaled_a);

    return 0;
}
