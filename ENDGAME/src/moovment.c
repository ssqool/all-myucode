// #include "minilib.h"

// int random_int(int low, int high) {
// 	int range = high - low;
// 	return (int)((rand() / (float)(RAND_MAX)) * range) + low;
// }

// SDL_Rect set_coordinate(SDL_Rect rct, int speed) {
// 	rct.y = (rct.y > 850) ? 0 : rct.y + speed; // если больше 820у то начни с начала, двигайся со скоростю 1 - блу
// 	if (rct.y == 0)
// 		rct.x = random_int(0, 1375);
// 	return (rct);
// }

// _Bool compare(SDL_Rect a, SDL_Rect b) {
// 	_Bool x = 0;
// 	_Bool y = 0;
// 	if (a.x <= b.x && a.x + a.w >= b.x)
// 		x = 1;
// 	if (a.x >= b.x && a.x + a.w <= b.x + b.w)
// 		x = 1;
// 	if (a.x <= b.x + b.w && a.x + a.w >= b.x + b.w)
// 		x = 1;
// 	if (a.y <= b.y && a.y + a.h >= b.y)
// 		y = 1;
// 	if (a.y >= b.y && a.y + a.h <= b.y + b.h)
// 		y = 1;
// 	if (a.y <= b.y + b.h && a.y + a.h >= b.y + b.h)
// 		y = 1;
// 	if (x == 1 && y == 1)
// 		return (1);
// 	return (0);
// }

// void is_ketch_pill(t_game *t) {
// 	if ((compare(t->kr.rec, t->bl.rec)) == 1) {
// 		if (t->hp > 0 && (t->bl.rec.y = 851))
// 			t->hp--;
// 	}
// 	if ((compare(t->kr.rec, t->bl.rc2)) == 1) {
// 		if (t->hp > 0 && (t->bl.rc2.y = 851))
// 			t->hp--;
// 	}
// 	if ((compare(t->kr.rec, t->bl.rc3)) == 1)  {
// 		if (t->hp > 0 && (t->bl.rc3.y = 851))
// 			t->hp--;
// 	}

// 	if ((compare(t->kr.rec, t->rd.rec)) == 1) {
// 		if ((t->rd.rec.y = 851))
// 			t->score += 63;
// 	}
// 	if ((compare(t->kr.rec, t->rd.rc2)) == 1) {
// 		if ((t->rd.rc2.y = 851))
// 			t->score += 63;
// 	}
// 	if ((compare(t->kr.rec, t->rd.rc3)) == 1)  {
// 		if ((t->rd.rc3.y = 851))
// 			t->score += 63;
// 	}

// }

// void moovement(t_game *t, int x) {
// 	if (x > (t->w - 64))
// 		x = t->w - 64;
// 	if (x < 64)
// 		x = 64;
// 	t->kr.rec.x = x - 64; // центрирование картинки с мышкой

// 	if (t->step == 1) {
// 		is_ketch_pill(t);

// 		t->rd.rec = set_coordinate(t->rd.rec, 1);
// 		t->bl.rec = set_coordinate(t->bl.rec, 2);

// 		t->rd.rc2 = set_coordinate(t->rd.rc2, 3);
// 		t->bl.rc2 = set_coordinate(t->bl.rc2, 4);

// 		t->rd.rc3 = set_coordinate(t->rd.rc3, 5);
// 		t->bl.rc3 = set_coordinate(t->bl.rc3, 6);
// 	}

// }
