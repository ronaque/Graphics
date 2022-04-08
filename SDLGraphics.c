#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Surface *screenSurface;

    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Video Iniciado");
        window = SDL_CreateWindow("First window", 100, 50, 320, 480, SDL_WINDOW_SHOWN);
        screenSurface = SDL_GetWindowSurface(window);

        SDL_Delay(5000);

         SDL_FreeSurface(screenSurface);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    else
        SDL_Log("Erro ao carregar o video: %s", SDL_GetError());
    return 1;
}