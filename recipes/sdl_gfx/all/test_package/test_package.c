#define SDL_MAIN_HANDLED

#include <SDL2_framerate.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL2_imageFilter.h>
#include <SDL2_rotozoom.h>
#include <SDL2_gfxPrimitives_font.h>

int main(int argc, char **argv) {

	SDL_Window* window;
	SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);

    characterRGBA(renderer, 10, 10, 'a', 0x40, 0x80, 0xC0, 0xff);
    return 0;
}
