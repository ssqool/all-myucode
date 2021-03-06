#include "header.h"

#define SPEED (150)

void create_hero(SDL_Renderer *ren, SDL_Texture *player, SDL_Texture *skelet, SDL_Texture *background){
    const int FPS = 60;
    
    int frameTime = 0;
    int frameW = 0;
    int frameH = 0;
    int textW = 0;
    int textH = 0;
    
    int frameTimes = 0;
    int frameWs = 0;
    int frameHs = 0;
    int textWs = 0;
    int textHs = 0;

    
    SDL_QueryTexture(player, NULL, NULL, &textW, &textH);
    frameW = (textW - 65) / 8;
    frameH = textH / 4;
    SDL_QueryTexture(skelet, NULL, NULL, &textWs, &textHs);
    frameWs = (textWs - 63) / 8;
    frameHs = textHs / 4;
    float x_pos = 0;
    float y_pos = 0;
    float x_vel = 0;
    float y_vel = 0;
    
    SDL_Rect player_Pos = {0, 0, frameW, frameH};
    SDL_Rect background_RECT = {0, 0, MX_SCREEN_WIDTH, MX_SCREEN_HEIGHT};
    SDL_Rect player_RECT = {(MX_SCREEN_WIDTH - frameW)/2, (MX_SCREEN_HEIGHT - frameH)/2, frameW, frameH};
    SDL_Rect skelet_Pos = {0, 0, frameWs, frameHs};
    SDL_Rect skelet_RECT = {0, 0, frameWs, frameHs};

    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Event event;
    bool quit = false;
    while(!quit){
	    while(SDL_PollEvent(&event))
	    {
		    SDL_PumpEvents(); // обработчик событий.

            switch(event.type){
                case SDL_QUIT: quit = true; break;
                case SDL_KEYDOWN: 
                    switch(event.key.keysym.sym){
                        case SDLK_ESCAPE: quit = true;break;
                        case SDLK_LEFT: player_RECT.x -= 20;frameTime++;
                                        player_Pos.y = frameH;skelet_Pos.y = frameHs;
                                        break;
                        case SDLK_RIGHT: player_RECT.x += 20;frameTime++;
                                        player_Pos.y = 3*frameH;skelet_Pos.y = 3*frameHs;
                                        break;
                        case SDLK_UP: player_RECT.y -= 20;frameTime++;
                                        player_Pos.y = 0;skelet_Pos.y = 0;
                                        break;
                        case SDLK_DOWN: player_RECT.y += 20;frameTime++;
                                        player_Pos.y = 2 * frameH;skelet_Pos.y = 2 * frameHs;
                                        break;

                    }
            }
            if (frameTime == 1){
                frameTime = 0;
                player_Pos.x += frameW;
                if (player_Pos.x > textW - 65) player_Pos.x = 0;
            }
        }
        // determine velocity toward hero
        float delta_x = player_RECT.x - player_RECT.w/4 - x_pos;
        float delta_y = player_RECT.y - player_RECT.h/4 - y_pos;
        float distance = sqrt(delta_x * delta_x + delta_y * delta_y);
        
        // prevent jitter
        if (distance < 5){
            x_vel = y_vel = 0;
        }
        else{
            x_vel = delta_x * SPEED / distance;
            y_vel = delta_y * SPEED / distance;
        }
        // update positions
        x_pos += x_vel / 60;
        y_pos += y_vel / 60;
         // collision detection with bounds
        if (x_pos <= 0) x_pos = 0;
        if (y_pos <= 0) y_pos = 0;
        if (x_pos >= MX_SCREEN_WIDTH - skelet_RECT.w) x_pos = MX_SCREEN_WIDTH - skelet_RECT.w;
        if (y_pos >= MX_SCREEN_HEIGHT - skelet_RECT.h) y_pos = MX_SCREEN_HEIGHT - skelet_RECT.h;
        // set the positions in the struct
        skelet_RECT.y = (int) y_pos;
        skelet_RECT.x = (int) x_pos;

        frameTimes +=2;
        if (FPS / frameTimes == 4){
            frameTimes = 0;
            skelet_Pos.x += frameW;
            if (skelet_Pos.x > textWs - 63) skelet_Pos.x = 0;
        }

        
        if(player_RECT.x <= 0) player_RECT.x = 0;
        if(player_RECT.y >= MX_SCREEN_HEIGHT - frameH) player_RECT.y = MX_SCREEN_HEIGHT - frameH;
        if (player_RECT.y <= 0) player_RECT.y = 0;
        if(player_RECT.x >= MX_SCREEN_WIDTH - frameW) player_RECT.x = MX_SCREEN_WIDTH - frameW;
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren,background,NULL,&background_RECT);
        SDL_RenderCopy(ren, player, &player_Pos, &player_RECT);
        SDL_RenderCopy(ren, skelet, &skelet_Pos, &skelet_RECT);
        SDL_RenderPresent(ren);
        SDL_Delay(1000/60);
    }
}

int main(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        write(2, "SDL_Init Error: ", mx_strlen("SDL_Init Error: "));
        write(2, SDL_GetError(), mx_strlen(SDL_GetError()));
        return 1;
    } 
    SDL_Window* win = SDL_CreateWindow("endgame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MX_SCREEN_WIDTH, MX_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(win == NULL){
        write(2, "SDL_CreateWindow Error: ", mx_strlen("SDL_CreateWindow Error: "));
        write(2, SDL_GetError(), mx_strlen(SDL_GetError()));
	      return 1;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        write(2, "SDL_CreateRenderer Error: ", mx_strlen("SDL_CreateRenderer Error: "));
        write(2, SDL_GetError(), mx_strlen(SDL_GetError()));
	      return 1;
    }

    SDL_Texture *player =  IMG_LoadTexture(ren,"hero.png");
    SDL_Texture *skelet =  IMG_LoadTexture(ren,"skelet.png");
    SDL_Texture *background = IMG_LoadTexture(ren,"background.bmp");
    create_hero(ren, player, skelet, background);
    
    SDL_DestroyTexture(player);
    SDL_DestroyTexture(skelet);
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();	
    return 1;
}

