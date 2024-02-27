#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Initializes the matrix as an identity matrix.
 */
void init_identity_matrix(float matrix[3][3]);


/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
 * Multiply the matrix by a scalar.
 */
void multiply_matrix_scalar(const float matrix[3][3], float scalar, float result[3][3]);

/**
 * Multiply matrices.
 */
void multiply_matrices(const float a[3][3], const float b[3][3], float result[3][3]);


/**
 * Transform a 2D point with homogeneous coordinates using a matrix.
 */
void transform_point(const float matrix[3][3], float point[3]);

#endif // MATRIX_H

