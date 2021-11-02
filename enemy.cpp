#include "enemy.hpp"

void Enemy::draw() 
{
    TheTextureManager::getInstance().drawFrame(m_textureID, \
        m_position.getX(), m_position.getY(), m_Width, m_Height, \
        TheGame::getInstance().getRenderer(), \
        m_RowNumber, m_CurrentFrame);
}

void Enemy::update()
{
    m_CurrentFrame = int(((SDL_GetTicks() / 100) % 6));
    //Update acceleration 
    m_acceleration.setX(0.75);
    SDLGameObject::update();
}

void Enemy::clean()
{

}

Enemy::Enemy (LoadParams *pParams):SDLGameObject(pParams)
{
#if 0    
    m_X = pParams->getX();
    m_Y = pParams->getY();
    m_Width = pParams->getWidth();
    m_Height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_CurrentFrame = 0;
    m_RowNumber = 1;
#endif
}

Enemy::~Enemy(){}