#include "player.hpp"

Player::Player (LoadParams *pParams):SDLGameObject(pParams)
{
    m_X = pParams->getX();
    m_Y = pParams->getY();
    m_Width = pParams->getWidth();
    m_Height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_CurrentFrame = 0;
    m_RowNumber = 1;
}

void Player::draw()
{
    TheTextureManager::getInstance().drawFrame(m_textureID, \
        m_X, m_Y, m_Width, m_Height, \
        TheGame::getInstance().getRenderer(), \
        m_RowNumber, m_CurrentFrame);

    //cout << "Player::draw() called" << endl;
}

void Player::update()
{
    m_X +=1;
    m_CurrentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{

}

Player::~Player()
{

}