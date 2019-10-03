#include "minilib.h"

void create_window(t_game *t) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		sdlerror();
	t->w = 1440;
	t->h = 900;
	t->window = SDL_CreateWindow("***_endgame_***", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, t->w, t->h, SDL_WINDOW_ALLOW_HIGHDPI);
	if (t->window == NULL) 
	    sdlerror();
	if ((t->win_srfc = SDL_GetWindowSurface(t->window)) == NULL)// головний сурфейс
		sdlerror();
	if ((t->wlpp = IMG_Load("./res/img/asd.jpg")) == NULL)//заставка (Morpheus)
		sdlerror();
	if ((t->kr.srf = IMG_Load("./res/img/neo_1.png")) == NULL)
		sdlerror();
	if ((t->rd.srf = IMG_Load("./res/img/red_54.png")) == NULL)
		sdlerror();
	if ((t->bl.srf = IMG_Load("./res/img/blue_54.png")) == NULL)
		sdlerror();
	if ((t->heart.srf = IMG_Load("./res/img/heart_40.png")) == NULL)
		sdlerror();
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		sdlerror();
	if ((t->music = Mix_LoadMUS("./res/music/Spybreak.mp3")) == NULL)
	 	sdlerror();
	 t->kr.rec.y = 730;						// опустили Киану Ривза по у
	if(TTF_Init() == -1)
		sdlerror();
	if((t->font = TTF_OpenFont("./res/ttf/Oswald-Bold.ttf", 30)) == NULL)
		sdlerror();
}
