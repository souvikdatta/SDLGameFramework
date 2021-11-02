#ifndef __VECTOR_HPP
#define __VECTOR_HPP

#include <math.h>

class vector2D
{
private:
    float m_X;
    float m_Y;

public:
    vector2D() = default;
    vector2D(float x, float y):m_X{x},m_Y{y}
    {

    }

    //Copy Constructor
    vector2D (const vector2D& o)
    {
        this->m_X = o.m_X;
        this->m_Y = o.m_Y;
    }

    //Assignment op
    vector2D& operator=(const vector2D& o)
    {
        this->m_X = o.m_X;
        this->m_Y = o.m_Y;

        return *this;
    }
    
    float getX() const {return m_X;}
    
    float getY() const {return m_Y;}

    void setX(const float x) {m_X = x;}
    
    void setY(const float y) {m_Y = y;}

    float length() {return (sqrt( (m_X* m_X) + (m_Y* m_Y) ));}

    //Operator +
    vector2D operator+(const vector2D& o) 
    {
        return vector2D (this->m_X + o.m_X, this->m_Y + o.m_Y);
    }

    //Operator +=
    vector2D& operator+=(const vector2D& o)
    {
        m_X += o.m_X;
        m_Y += o.m_Y;

        return *this;
    }

    //Operator -
    //Here I have to create a new vector object
    vector2D operator-(const vector2D& o) 
    {
        return vector2D (this->m_X - o.m_X, this->m_Y - o.m_Y);
    }

    //Operator -=
    vector2D& operator-=(const vector2D& o)
    {
        m_X -= o.m_X;
        m_Y -= o.m_Y;

        return *this;
    }

    //Operator * Scale
     //Here I have to create a new vector object
    vector2D operator*(float scaler)
    {
        return vector2D (scaler * m_X, scaler * m_Y);
    }

    vector2D operator*=(float scaler)
    {
        m_X *= scaler;
        m_Y *= scaler;;

        return *this;
    }

    //Operator / Scale
     //Here I have to create a new vector object
    vector2D operator/(float scaler)
    {
        return vector2D (m_X/scaler, m_Y/scaler);
    }

    vector2D operator/=(float scaler)
    {
        m_X /= scaler;
        m_Y /= scaler;;

        return *this;
    }

    void normalize()
    {
        float l = length();
        if(l > 0)
            (*this) *= 1/l;
    }


    virtual ~vector2D(){}

};

#endif