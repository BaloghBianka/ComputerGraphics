#include "brick.h"

void set_size(Brick* brick , double length, double width, double height)
{
    brick->length = (length > 0.0) ? length : 0.0;
    brick->width = (width > 0.0) ? width : 0.0;
    brick->height = (height > 0.0) ? height : 0.0;
}

double calc_volume(const Brick* brick)
{
    return brick->length * brick->width * brick->height;
}

double calc_surface(const Brick* brick)
{
    return 2 * (brick->length * brick->width + brick->length * brick->height + brick->width * brick->height);
}

int has_square_face(const Brick* brick)
{
    return brick->length == brick->width || brick->length == brick->height || brick->width == brick->height;
}
