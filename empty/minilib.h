#ifndef MINILIB_H
#define MINILIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#define MX_SCREEN_WIDTH 800 // width
#define MX_SCREEN_HEIGHT 600 // height

//#include "mx_strlen.c"
//#include "allerror.c"
void drawBackground(SDL_Texture *background, SDL_Renderer *ren);
void create_window();

#endif
