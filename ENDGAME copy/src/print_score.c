#include "minilib.h"

void print_heart_score(t_game *t) {
	t->heart.rec = t->heart.srf->clip_rect;
	for (int i = 0; i < t->hp; i++) {
		SDL_BlitSurface(t->heart.srf, NULL, t->win_srfc, &t->heart.rec); // print heart
		t->heart.rec.x += 45;
	}
	char str[30];
 SDL_Color color = { 55, 255, 55, 0 };
 t->txt = TTF_RenderText_Solid(t->font, SDL_itoa(t->score, str, 10), color);
 SDL_Rect nbr = t->txt->clip_rect;
 nbr.x = 660;
 SDL_BlitSurface(t->txt ,NULL, t->win_srfc, &nbr);
 if (t->hp <= 0) {
  t->game_over = TTF_RenderText_Solid(t->font, "Maybe I was wrong about you, Neo.", color);
  nbr.x = 500;
  nbr.y = 450;
  SDL_BlitSurface(t->wlpp ,NULL, t->win_srfc, NULL);
  SDL_BlitSurface(t->game_over ,NULL, t->win_srfc, &nbr);
  
 }
}
