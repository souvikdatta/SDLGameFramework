#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "sdlgameobject.hpp"
#include "game.hpp"
//#include "gameobject.hpp"

class Player: public SDLGameObject
{
private:
#if 0
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    string m_textureID;
    int m_CurrentFrame;
    int m_RowNumber;
#endif
public:
    Player (LoadParams *pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual ~Player();
};

#endif
