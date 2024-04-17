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

/**
 * Scale the transformation matrix based on scaling factors.
 * Assumes scaling is centered at the origin.
 */
void scale(float matrix[3][3], float scaleX, float scaleY);

/**
 * Shift the transformation matrix based on translation factors.
 */
void shift(float matrix[3][3], float shiftX, float shiftY);

/**
 * Rotate the transformation matrix based on an angle in radians.
 * Assumes rotation is centered at the origin.
 */
void rotate(float matrix[3][3], float angle);


#endif // MATRIX_H

