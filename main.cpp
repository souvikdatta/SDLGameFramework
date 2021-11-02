#include "game.hpp"
//#include <memory>


using namespace std;

int main()
{
    //Init the game
    if(TheGame::getInstance().init("Chap 1", 100, 100, 1920, 1080, false) == false)
        return 1;
    
    while(TheGame::getInstance().running())
    {
        TheGame::getInstance().handleEvents();
        TheGame::getInstance().update();
        TheGame::getInstance().render();

        SDL_Delay (10);
    }

    TheGame::getInstance().clean();

    return 0;
}
