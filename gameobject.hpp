#ifndef __GAMEOBJECT_HPP
#define __GAMEOBJECT_HPP

class LoadParams;

/* Abstract class */
class GameObject
{
protected:
    GameObject (const LoadParams *pParams){}
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    //Necer ever make a destructor protected/private
    virtual ~GameObject()
    {

    }
};

#endif