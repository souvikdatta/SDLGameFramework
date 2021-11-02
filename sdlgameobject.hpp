#ifndef __SDLGAMEOBJECT_HPP
#define __SDLGAMEOBJECT_HPP

#include "gameobject.hpp"
#include "loadparams.hpp"
#include "vector2D.hpp"


class SDLGameObject : public GameObject
{
private:
    SDLGameObject() = default;
protected:
    // int m_X;
    // int m_Y;
    vector2D m_position;
    int m_Width;
    int m_Height;
    std::string m_textureID;
    int m_CurrentFrame;
    int m_RowNumber;
public:

    SDLGameObject (LoadParams *pParams):GameObject(pParams)
    {
        m_position.setX(pParams->getX());
        m_position.setY(pParams->getY());
        m_Width = pParams->getWidth();
        m_Height = pParams->getHeight();
        m_textureID = pParams->getTextureID();
        m_CurrentFrame = 0;
        m_RowNumber = 1;
    }

    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
};

#endif