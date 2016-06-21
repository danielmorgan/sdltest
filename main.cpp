#include <time.h>
#include <SDL2/SDL.h>

int main (int argc, char** argv)
{
    // Seed rand
    srand(time(NULL));

    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "Test", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        490,
        490,
        SDL_WINDOW_SHOWN
    );

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
            SDL_Rect r;
            r.x = 10 + (60 * x);
            r.y = 10 + (60 * y);
            r.w = 50;
            r.h = 50;

            // Set render color to blue ( rect will be rendered in this color )
            SDL_SetRenderDrawColor( renderer, rand()%256, rand()%256, rand()%256, 255 );

            // Render rect
            SDL_RenderFillRect( renderer, &r );
        }
    }

    // Render the rect to the screen
    SDL_RenderPresent(renderer);

    // Wait for 3 sec
    SDL_Delay( 3000 );

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
