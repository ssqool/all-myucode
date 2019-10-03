NAME = endgame

INC = src/minilib.h
	

HDR = minilib.h

SRC = src/main.c \
	src/allerror.c \
	src/create_window.c \
	src/print_window.c \
	src/forever_loop.c \
	src/print_score.c \
	
		
SRCS = main.c \
	allerror.c \
	create_window.c \
	print_window.c \
	forever_loop.c \
	print_score.c \
	
	

SDLF =  -I ./res/SDL2.framework/Versions/A/Headers -F ./res -framework SDL2 -rpath ./res -I ./res/SDL2_image.framework/Versions/A/Headers -F ./res -framework SDL2_image -rpath ./res 

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

SDLM = -I ./res/SDL2_mixer.framework/Versions/A/Headers -F ./res -framework SDL2_mixer -rpath ./res

SDLT = -I ./res/SDL2_ttf.framework/Versions/A/Headers -F ./res -framework SDL2_ttf -rpath ./res

all: install clean
install:
	@cp $(SRC) .
	@cp $(INC) .
	@clang $(CFLAG) $(SDLM) $(SRCS) $(SDLF) $(SDLT) -o $(NAME) -I $(HDR) 
uninstall:
	@rm -rf $(SRCS)
	@rm -rf $(HDR)
	@rm -rf $(NAME)
clean:
	@rm -rf $(SRCS)
	@rm -rf $(HDR)
reinstall: uninstall all
