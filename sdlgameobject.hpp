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
    vector2D m_position;
    vector2D m_velocity;
    vector2D m_acceleration;
    int m_Width;
    int m_Height;
    std::string m_textureID;
    int m_CurrentFrame;
    int m_RowNumber;
public:

    SDLGameObject (LoadParams *pParams):GameObject(pParams)
    {
        m_velocity.setX(0);
        m_velocity.setY(0);
        m_acceleration.setX(0);
        m_acceleration.setY(0);        
        m_position.setX(pParams->getX());
        m_position.setY(pParams->getY());
        m_Width = pParams->getWidth();
        m_Height = pParams->getHeight();
        m_textureID = pParams->getTextureID();
        m_CurrentFrame = 0;
        m_RowNumber = 1;
    }

    virtual void draw()
    {

    }

    virtual void update()
    {       
        //Change position according to velocity
        //The amount of actual change in position would be controlled in the subclass
        m_position += m_velocity;
    
        //Change velocity according to acceleration
        //The amount of actual change in velocity would be controlled in the subclass
        m_velocity += m_acceleration;
    }

    virtual void clean()
    {

    }
};

#endif