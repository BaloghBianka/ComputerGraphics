#include "brick.h"
#include <stdio.h>

int main()
{
    Brick brick;
    double volume, surface;
    int hasSquareFace;

    set_size(&brick, 3, 4, 5);
    volume = calc_volume(&brick);
    surface = calc_surface(&brick);
    hasSquareFace = has_square_face(&brick);

    printf("Brick volume: %lf\n", volume);
    printf("Brick surface: %lf\n", surface);
    
    if (hasSquareFace) {
        printf("Brick has a square face.\n");
    } else {
        printf("Brick does not have a square face.\n");
    }

    return 0;
}
