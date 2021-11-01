#include "game.hpp"

Game::Game()
{

}

Game& Game::getInstance()
{
    static Game o;
    return o;
}

Game::~Game()
{

}

SDL_Renderer* Game::getRenderer() const
{
    return m_pRenderer;
}

bool Game::init(const string nameOfWindow, const int xPos, \
    const int yPos, const int wWidth, const int hHeight, \
    const bool isFullScreen)
{
    bool retStatus = true;

    m_bRunning = true;

    if(! SDL_Init(SDL_INIT_EVERYTHING))
    {
        cout << "SDL Init successful" << endl;
        //create window
        m_pWindow = SDL_CreateWindow (nameOfWindow.c_str(), xPos, yPos, wWidth, hHeight, 0);
        if(m_pWindow != nullptr)
        {
            //create renderer
            m_pRenderer = SDL_CreateRenderer (m_pWindow, -1, SDL_RENDERER_ACCELERATED);
            if(nullptr == m_pRenderer)
            {
                retStatus =  false;
                cout << "Failed to create Renderer" << endl;
            }
            else
            {
                //Set render color
                SDL_SetRenderDrawColor (m_pRenderer, 255, 0, 0, 255);


                if (TheTextureManager::getInstance().load ("assets/animate-alpha.png", \
                    "animate", m_pRenderer) == false)
                {
                    retStatus =  false;
                }

                m_GameObjects.push_back(new Player(new LoadParams(100, 100, 128, 82, "animate")));
                m_GameObjects.push_back(new Player(new LoadParams(200, 200, 128, 82, "animate")));
            }
        }
        else 
        {
            retStatus =  false;
            cout << "Failed to create SDL window" << endl;
        }
    }
    else 
    {
        retStatus =  false;
        cout << "Failed to do SDL Init" << endl;
    }

    return retStatus;
}

void Game::render()
{
    SDL_RenderClear (m_pRenderer);

    for(auto &i: m_GameObjects)
        i->draw();

    SDL_RenderPresent (m_pRenderer);
}

void Game::update()
{
    for(auto &i: m_GameObjects)
        i->update();
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                // cout << "Default case" << event.type << "\n";
            break;
        }
    }
}

void Game::clean()
{
    cout << "SDL environment cleaned" << endl;
    SDL_DestroyWindow (m_pWindow);
    SDL_DestroyRenderer (m_pRenderer);
    SDL_Quit ();
}

bool Game::running()
{
    return m_bRunning;
}