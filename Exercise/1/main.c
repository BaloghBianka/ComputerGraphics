#include "brick.h"
#include <stdio.h>
#include <stdbool.h>

bool is_numeric(const char *str)
{
    char c;
    while ((c = *str++) != '\0')
    {
        if (c < '0' || c > '9')
        {
            return false;
        }
    }
    return true;
}

double get_valid_input(const char *prompt)
{
    double input;
    char input_buffer[100];

    while (1)
    {
        printf("%s", prompt);
        scanf("%s", input_buffer);

        if (is_numeric(input_buffer) && sscanf(input_buffer, "%lf", &input) == 1)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n')
                ;
        }
    }

    return input;
}

int main()
{
    Brick brick;
    double length, width, height;
    double volume, surface;
    int hasSquareFace;

    length = get_valid_input("Enter the length of the brick: ");
    width = get_valid_input("Enter the width of the brick: ");
    height = get_valid_input("Enter the height of the brick: ");

    set_size(&brick, length, width, height);
    volume = calc_volume(&brick);
    surface = calc_surface(&brick);
    hasSquareFace = has_square_face(&brick);

    printf("Brick volume: %lf\n", volume);
    printf("Brick surface: %lf\n", surface);

    if (hasSquareFace)
    {
        printf("Brick has a square face.\n");
    }
    else
    {
        printf("Brick does not have a square face.\n");
    }

    return 0;
}
