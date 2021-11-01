#ifndef __ENEMY_HPP
#define __ENEMY_HPP

#include "sdlgameobject.hpp"
#include "game.hpp"

class Enemy : public SDLGameObject
{
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    string m_textureID;
    int m_CurrentFrame;
    int m_RowNumber;
public:
    Enemy(LoadParams *pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    ~Enemy();
};

#endif