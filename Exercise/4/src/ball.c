#include "ball.h"

#include <OpenGL/gl.h>

#include <math.h>

void init_ball(Ball* ball, float x, float y)
{
    ball->x = x;
    ball->y = y;
    ball->radius = 50;
    ball->speed_x = 500;
    ball->speed_y = 500;
    ball->angle = 0.0;  
    ball->angular_velocity = 0.1;  
}

void update_ball(Ball* ball, double time)
{
    ball->x += ball->speed_x * time;
    ball->y += ball->speed_y * time;
    ball->angle += ball->angular_velocity * time; 
}

void render_ball(Ball* ball)
{
    double angle;
    double x;
    double y;

    glPushMatrix();
    glTranslatef(ball->x, ball->y, 0.0);
    glRotatef(ball->angle, 0.0, 0.0, 1.0); 
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.9, 0.8);
    glVertex2f(0, 0);
    angle = 0;
    while (angle < 2.0 * M_PI + 1) {
        x = cos(angle) * ball->radius;
        y = sin(angle) * ball->radius;
        glVertex2f(x, y);
        angle += 0.8;
    }
    glEnd();
    glPopMatrix();
}

void set_ball_position(Ball* ball, float x, float y) {
    ball->x = x;
    ball->y = y;
}

void increase_ball_size(Ball* ball, float amount)
{
    ball->radius += amount;
    if (ball->radius > 100) ball->radius = 100;  
}

void decrease_ball_size(Ball* ball, float amount)
{
    ball->radius -= amount;
    if (ball->radius < 10) ball->radius = 10;  
}

