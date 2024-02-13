#ifndef BRICK_H
#define BRICK_H

typedef struct Brick
{
	double a;
	double b;
	double c;
} Brick;

void set_brick_data(Brick* brick, double a, double b, double c);

double calc_brick_area(const Brick* brick);

#endif 



