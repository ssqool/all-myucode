#include "minilib.h"

void forever_loop (t_game *t) {
	SDL_Event event;
	_Bool on = 1;
	int x;
	if (Mix_PlayMusic(t->music, 1) < 0)
		sdlerror();
	while (on == 1) {
		while (SDL_PollEvent(&event)) {
			x = event.motion.x;						//позиция мышки по х
			int key = event.key.keysym.sym;
			if (event.type == SDL_QUIT)				//условия выхода с программы
				on = 0;
			if (event.type == SDL_KEYDOWN && key == SDLK_ESCAPE) //условия выхода с программы
				on = 0;
		}
		if (t->hp > 0)
  		moovement(t, x);
	// 	t->step = (t->step == 4) ? 1 : t->step + 1; // ЗАМЕДЛИТЬ ПАДАНИЕ ПИЛЮЛЬ t->step == 3 || == 4 || == 2
		print_window(t);
	}
	SDL_FreeSurface(t->win_srfc);
	SDL_DestroyWindow(t->window);
	TTF_CloseFont(t->font);
	TTF_Quit();
	SDL_Quit();
}
