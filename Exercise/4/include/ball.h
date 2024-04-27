#ifndef BALL_H
#define BALL_H

/**
 * Ball position and speed
 */
typedef struct Ball
{
    float x;
    float y;
    float radius;
    float speed_x;
    float speed_y;
    float angle; 
    float angular_velocity; 
} Ball;

/**
 * Move the ball to the given position.
 */
void init_ball(Ball* ball, float x, float y);

/**
 * Update the ball.
 * @param time elapsed time in seconds.
 */
void update_ball(Ball* ball, double time);

/**
 * Render the ball.
 */
void render_ball(Ball* ball);

void set_ball_position(Ball* ball, float x, float y);

void increase_ball_size(Ball* ball, float amount);
void decrease_ball_size(Ball* ball, float amount);


#endif /* BALL_H */
