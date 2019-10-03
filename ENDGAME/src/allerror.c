#include "minilib.h"

void mx_printerror(char *str) {
	write(2, "endgame: ", 9);                //приставка к еррору
	for (int i = 0; str[i] != '\0'; i++)
		write(2, &str[i], 1);                //сам еррор
	write(2, "\n", 1);
}

void allerror(void) {
	int err = errno;
	mx_printerror(strerror(err));
	exit(err);
}

void sdlerror(void) {
	mx_printerror((char*)SDL_GetError());
	exit(2);
}
