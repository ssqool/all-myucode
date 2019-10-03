#include "minilib.h"

void print_window(t_game *t) {

	SDL_BlitSurface(t->wlpp ,NULL, t->win_srfc, NULL);// распечатай Морфиуса
	SDL_BlitSurface(t->kr.srf, NULL, t->win_srfc, &t->kr.rec); // print Kianu Rivz
	print_heart_score(t);
	if (t->hp > 0) {
		SDL_BlitSurface(t->rd.srf, NULL, t->win_srfc, &t->rd.rec); // что куда где red pill
		SDL_BlitSurface(t->bl.srf, NULL, t->win_srfc, &t->bl.rec); // что куда где	blue pill
		SDL_BlitSurface(t->rd.srf, NULL, t->win_srfc, &t->rd.rc2); // что куда где 2red pill
		SDL_BlitSurface(t->bl.srf, NULL, t->win_srfc, &t->bl.rc2); // что куда где	2blue pill
		SDL_BlitSurface(t->rd.srf, NULL, t->win_srfc, &t->rd.rc3); // что куда где 3red pill
		SDL_BlitSurface(t->bl.srf, NULL, t->win_srfc, &t->bl.rc3); // что куда где	3blue pill
	}
	SDL_UpdateWindowSurface(t->window); // фото в рамку
}
