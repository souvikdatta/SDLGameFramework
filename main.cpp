#include "game.hpp"

using namespace std;

static constexpr int FPS = 60;
static constexpr int DELAY_IN_MS = 1000.0f / FPS; //Time taken in ms to display 1 Frame @ 60 FPS

int main()
{
    Uint32 frameStart, frameTime;
    
    //Init the game
    if(TheGame::getInstance().init("Chap 1", 100, 100, 1920, 1080, false) == false)
        return 1;
    
    while(TheGame::getInstance().running())
    {
        frameStart = SDL_GetTicks();
        TheGame::getInstance().handleEvents();
        TheGame::getInstance().update();
        TheGame::getInstance().render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameTime < DELAY_IN_MS)
            SDL_Delay ((int) (DELAY_IN_MS - frameTime));
    }

    TheGame::getInstance().clean();

    return 0;
}
