#include <stdio.h>


typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

typedef struct {
    Point start;  
    Point end;    
    Color color;  
} Line;


void printLine(const Line *line) {
    printf("Line from (%d, %d) to (%d, %d) with color (R:%d, G:%d, B:%d)\n",
           line->start.x, line->start.y, line->end.x, line->end.y,
           line->color.r, line->color.g, line->color.b);
}


int main() {
   
    Line myLine = {{10, 10}, {20, 20}, {255, 0, 0}};  

    printLine(&myLine);

    return 0;
}
