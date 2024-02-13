#ifndef BRICK_H
#define BRICK_H

typedef struct Brick
{
    double length;
    double width;
    double height;
} Brick;

void set_size(Brick* brick, double length, double width, double height);
double calc_volume(const Brick* cuboid);
double calc_surface(const Brick* cuboid);
int has_square_face(const Brick* cuboid);

#endif

