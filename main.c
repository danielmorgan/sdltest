#include <time.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int loops = 0;

void draw(SDL_Renderer *renderer)
{
    // Hack to slow down draws, probably dependent on CPU clock speed
    if (loops < 100000) {
        ++loops;
        return;
    }

    loops = 0;

    // Set render color to white (background will be rendered in this color)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Clear window
    SDL_RenderClear(renderer);

    // Draw 8x8 colored squares
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            // Creat rect
            SDL_Rect r;
            r.x = 10 + (60 * x);
            r.y = 10 + (60 * y);
            r.w = 50;
            r.h = 50;

            // Set random color
            SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 255);

            // Render rect
            SDL_RenderFillRect(renderer, &r);
        }
    }

    // Render the rect to the screen
    SDL_RenderPresent(renderer);
}

int main (int argc, char *argv[])
{
    // Seed rand
    srand(time(NULL));

    // Setup window
    SDL_Window *window = NULL;
    window = SDL_CreateWindow(
        "Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        490,
        490,
        SDL_WINDOW_SHOWN
    );

    // Setup events
    SDL_Event events;

    // Setup renderer
    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Game loop
    bool running = true;
    while (running) {
        // Listen to events
        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) {
                running = false;
            }
        }

        // Draw the scene
        draw(renderer);
    }

    // Exit
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
