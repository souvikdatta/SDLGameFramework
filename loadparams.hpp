#ifndef __LOADPARAMS_H
#define __LOADPARAMS_H
#include <string>
using namespace std;

class LoadParams
{
private:
    int m_X;
    int m_Y;
    int m_Width;
    int m_Height;
    std::string m_textureID;
    //Making the default constructor private
    LoadParams() = default;
public:
    LoadParams(int x, int y, int width, int height, \
        string textureID):m_X{x},m_Y{y},m_Width{width},\
        m_Height{height},m_textureID{textureID}
    {
    }

    int getX() const {return m_X;}
    int getY() const {return m_Y;}
    int getWidth() const {return m_Width;}
    int getHeight() const {return m_Height;}
    string& getTextureID() {return m_textureID;}
};
#endif