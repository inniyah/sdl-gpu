#include "SDL.h"
#include "SDL_gpu.h"
#include "SDL_FontCache.h"

void main_loop(GPU_Target* screen, FC_Font *font)
{
    Uint8 done;
    SDL_Event event;

    done = 0;
    while (!done) {
	while (SDL_PollEvent(&event)) {
	    if (event.type == SDL_QUIT)
		done = 1;
	    else if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_ESCAPE)
		    done = 1;
	    }
	}

	// Update logic here

	GPU_Clear(screen);

	// Draw stuff here

	FC_Draw(font, screen, 0, 0, "Hello World");

	GPU_Flip(screen);
    }
}

int main(int argc, char* argv[])
{
    GPU_Target* screen;
    FC_Font *font;

    if (TTF_Init() == -1)
	return -1;

    screen = GPU_Init(800, 600, GPU_DEFAULT_INIT_FLAGS);
    if (screen == NULL)
	return -1;

    font = FC_CreateFont();
    if (font == NULL)
	return -1;

    SDL_Color white = { 255, 255, 255, 255 };
    if (FC_LoadFont(font, "data/ProggyClean.ttf", 48, white, 0) == 0)
	return -1;

    FC_SetFilterMode(font, FC_FILTER_NEAREST);

    main_loop(screen, font);

    FC_FreeFont(font);

    GPU_Quit();

    TTF_Quit();

    return 0;
}
