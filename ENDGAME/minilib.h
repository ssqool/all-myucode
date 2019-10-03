#ifndef MINILIB_H
#define MINILIB_H

#include <unistd.h>
#include <errno.h>
//#include <time.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

void allerror(void);
void sdlerror(void);
int random_int(int low, int high);

typedef struct s_img {
	SDL_Surface *srf;
	SDL_Rect	rec;
	SDL_Rect	rc2;
	SDL_Rect	rc3;
}t_img;

typedef struct s_game {
	SDL_Window *window;
	SDL_Surface *win_srfc; //головний сурфейс
	SDL_Surface *wlpp; //картинка заставка МОРФИУС
	SDL_Surface *txt;  // для подсчета чисел
	SDL_Surface *game_over;  // для game over
	TTF_Font * font;
	Mix_Music *music;

	int		w;
	int 	h;
	int 	hp;
	int 	score;
	int 	step;
	t_img rd;
	t_img bl;
	t_img kr;
	t_img heart;

}t_game;

void create_window(t_game *t);
void print_heart_score(t_game *t);
void print_window(t_game *t) ;
void forever_loop (t_game *t);

void moovement(t_game *t, int x);


#endif
