#include <SDL/SDL.h>
#include <imagemanager.h>
#include <window.h>
#include <timer.h>
#include <image.h>

int main(int argc, char * argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    {
        Surface * screen = Window::create(200, 200,
                Window::Resizable, 32);
        Timer timer;
        bool quit = false;
        while (!quit)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    quit = true;
                }
            }
            screen->update();
            timer.fps_delay();
        }
        Window::destroy();
    }
    SDL_Quit();

    return 0;
}
