#include "minilib.h"

int xTiles = MX_SCREEN_WIDTH;
int yTiles = MX_SCREEN_HEIGHT;


void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void drawBackground(SDL_Texture *background, SDL_Renderer *ren){
    for (int i = 0; i < xTiles * yTiles; ++i){
	    int x = i % xTiles;
	    int y = i / xTiles;
	    renderTexture(background, ren, x * MX_SCREEN_WIDTH, y * MX_SCREEN_HEIGHT, MX_SCREEN_WIDTH, MX_SCREEN_HEIGHT);
    }
}

void create_window(SDL_Renderer *ren, SDL_Texture *background){
	//SDL_Rect background_RECT = {0, 0, MX_SCREEN_WIDTH, MX_SCREEN_HEIGHT};
	// if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	// 	sdlerror();
	SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_Event e;
	bool quit = false;
	while (!quit){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			if(e.key.keysym.sym == SDLK_ESCAPE){
				quit = true;
			}
		}
		SDL_RenderCopy(ren,background,NULL,&background_RECT);
		SDL_RenderClear(ren);
		drawBackground(background, ren);
		//renderTexture(background, ren);
		SDL_RenderPresent(ren);
	}
}



int main(){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        write(2, "SDL_Init Error: ", strlen("SDL_Init Error: "));
        write(2, SDL_GetError(), strlen(SDL_GetError()));
        return 1;
    } 
    SDL_Window* win = SDL_CreateWindow("endgame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MX_SCREEN_WIDTH, MX_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(win == NULL){
        write(2, "SDL_CreateWindow Error: ", strlen("SDL_CreateWindow Error: "));
        write(2, SDL_GetError(), strlen(SDL_GetError()));
	      return 1;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        write(2, "SDL_CreateRenderer Error: ", strlen("SDL_CreateRenderer Error: "));
        write(2, SDL_GetError(), strlen(SDL_GetError()));
	      return 1;
    }
// // int InitImages(){
// //     for (int i = 0; i < 6; i++){ // У нас будет 6 цветов
// //         char path[20];
// //         for (int j = 0; j < 20; j++)
// //             path[j] = 0;
// //         sprintf(path, "Block%d.bmp", i);
// //         block[i] = SDL_LoadBMP(path); // Загружаем BMP по заданному пути в block[i]
// //         if (!block[i])
// //             return -1;
//     }
//      return 1;
// }
	// SDL_Texture *background = IMG_LoadTexture(ren,"background.bmp");
	 // create_window(SDL_Texture background);
    
    SDL_Texture *background = IMG_LoadTexture(ren,"background.bmp");
     SDL_DestroyTexture(background);
     SDL_DestroyRenderer(ren);
    return 0;
}
