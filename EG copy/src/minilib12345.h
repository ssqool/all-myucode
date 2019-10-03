#ifndef MINILIB_H
#define MINILIB_H

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PLAYER_WIDTH 80
#define SECURITY_WIDTH 30
#define PLAYER_STEP 4
#define SECURITY_STEP 4

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"
#include "math.h"
#include "ctype.h"
#include "unistd.h"
#include "SDL_mixer.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <time.h>




#include "main.c"

// typedef struct Application
// {
// 	SDL_Renderer *renderer;
// 	SDL_Window *window;
// 	int up;
// 	int down;
// 	int left;
// 	int right;
//     int quit;
// } App;

// typedef struct s_entity
// {
// 	int x;
// 	int y;
// 	SDL_Rect *rect;
// 	SDL_Texture *texture;
// } t_entity;

// void initSDL(App *app);
// void presentScene(SDL_Renderer *renderer);
// void prepareScene(SDL_Renderer *renderer);
// void cleanup(App *app);
// void doInput(App *app);
// t_entity *createPlayer(SDL_Renderer *renderer, char *texture);
// void playerMoveUp(t_entity *player);
// void playerMoveDown(t_entity *player);
// void playerMoveLeft(t_entity *player);
// void playerMoveRight(t_entity *player);
// t_entity *createSecurity(SDL_Renderer *renderer, char *texture);
// void securityMove(t_entity *security, int *level, int *score);
// void renderEntity(SDL_Renderer *renderer, t_entity *player);
// void doKeyDown(SDL_KeyboardEvent *event, App *app);
// void doKeyUp(SDL_KeyboardEvent *event, App *app);
// char *itoa(int num, char b[]);
// void blit(App *app, SDL_Texture *texture, int x, int y);

#endif
