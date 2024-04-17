/*Készítsünk egy szakasz rajzoló programot, 
amellyel egérkattintással lehet megadni a szakaszok végpontjait! 
(Feltételezzük, hogy legfeljebb MAX_LINE_COUNT számú szakasz tárolható és jeleníthető meg egyszerre.)*/

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_LINE_COUNT 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Point start;
    Point end;
    Color color;
} Line;

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    Line lines[MAX_LINE_COUNT];
    int line_count = 0;
    bool selecting = false;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Line Drawer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    while (true) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                case SDL_MOUSEBUTTONDOWN:
                    if (line_count < MAX_LINE_COUNT) {
                        if (!selecting) {
                            // Start a new line
                            lines[line_count].start.x = event.button.x;
                            lines[line_count].start.y = event.button.y;
                            lines[line_count].color = (Color){255, 0, 0};  // Red color
                            selecting = true;
                        } else {
                            // Finish the current line
                            lines[line_count].end.x = event.button.x;
                            lines[line_count].end.y = event.button.y;
                            line_count++;
                            selecting = false;
                        }
                    }
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
        SDL_RenderClear(renderer);

        // Draw all lines
        for (int i = 0; i < line_count; i++) {
            SDL_SetRenderDrawColor(renderer, lines[i].color.r, lines[i].color.g, lines[i].color.b, 255);
            SDL_RenderDrawLine(renderer, lines[i].start.x, lines[i].start.y, lines[i].end.x, lines[i].end.y);
        }

        SDL_RenderPresent(renderer);
    }

    return 0;
}
