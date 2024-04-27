CC = gcc
CFLAGS = $(shell sdl2-config --cflags) -DGL_SILENCE_DEPRECATION -Iinclude/ -Wall -Wextra -Wpedantic
LDFLAGS = $(shell sdl2-config --libs) -framework OpenGL -lm

all: pong

pong: src/ball.c src/game.c src/main.c src/pad.c src/pong.c
	$(CC) $(CFLAGS) src/ball.c src/game.c src/main.c src/pad.c src/pong.c $(LDFLAGS) -o pong

clean:
	rm -f pong
