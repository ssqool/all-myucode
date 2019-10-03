#include "minilib.h"

int main() {
	t_game *t = (t_game*)malloc(sizeof(t_game));


	print_window(t);
	forever_loop(t);
	return 0;
}
