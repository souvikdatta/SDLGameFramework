#include "enemy.hpp"

void Enemy::draw() 
{
    TheTextureManager::getInstance().drawFrame(m_textureID, \
        m_X, m_Y, m_Width, m_Height, \
        TheGame::getInstance().getRenderer(), \
        m_RowNumber, m_CurrentFrame);
}

void Enemy::update()
{
    m_X +=1;
    m_CurrentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{

}

Enemy::Enemy (LoadParams *pParams):SDLGameObject(pParams)
{
    m_X = pParams->getX();
    m_Y = pParams->getY();
    m_Width = pParams->getWidth();
    m_Height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_CurrentFrame = 0;
    m_RowNumber = 1;
}

Enemy::~Enemy(){}