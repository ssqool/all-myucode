all:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o race02 src/*.c
install:
	install race02 ../
uninstall:
	rm ../race02
reinstall:
	make uninstall
	make clean
	make all.
	make install
clean:
	rm race02