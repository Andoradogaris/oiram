#pragma once

#include "../Engine.h"

template<typename T>
struct Vector2
{
    Vector2(){};
    Vector2(T XY) : x(XY), y(XY){};
    Vector2(T _X, T _Y) : x(_X), y(_Y){};

    Vector2 operator+(const Vector2& other) const
    {
        Vector2 res = Vector2();
        res.x = x + other.x;
        res.y = y + other.y;
        return res;
    }

    Vector2 operator+(const T& other) const
    {
        return *this + Vector2(other);
    }

    Vector2 operator-(const Vector2& other) const
    {
        Vector2 res = Vector2();
        res.x = x - other.x;
        res.y = y - other.y;
        return res;
    }

    Vector2 operator-(const T& other) const
    {
        return *this + Vector2(other);
    }

    Vector2 operator*(const Vector2& other) const
    {
        Vector2 res = Vector2();
        res.x = x * other.x;
        res.y = y * other.y;
        return res;
    }

    Vector2 operator*(const T& other) const
    {
        return *this + Vector2(other);
    }

    Vector2 operator/(const Vector2& other) const
    {
        Vector2 res = Vector2();
        res.x = x / other.x;
        res.y = y / other.y;
        return res;
    }
    
    Vector2 operator/(const T& other) const
    {
        return *this + Vector2(other);
    }

    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const
    {
        return !(*this == other);
    }

    float Length()
    {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }

    void Normalize()
    {
        float length = Length();
        
        if(length > 0)
        {
            *this = *this / length;
        }
    }

    float Dot(const Vector2& other)
    {
        return x * other.x + y * other.y;
    }

    static float Dot(const Vector2& A, const Vector2& B)
    {
        return A.Dot(B);
    }

    float GetAngle(const Vector2& other)
    {
        float num = *this.Dot(other);
        float den = *this->Normalize() * other.Normalize();

        return std::acos(num / den);
    }

    static float GetAngle(const Vector2& A, const Vector2& B)
    {

        return A.GetAngle(B);
    }

    bool isColinear(const Vector2& other)
    {
        return *this->Dot(other) == *this->Normalize() * other.Normalize() || *this->Dot(other) == - *this->Normalize() * other.Normalize();
    }

    static bool isColinear(const Vector2& A, const Vector2& B)
    {
        return A.isColinear(B);
    }

    bool isOrtho(const Vector2& other)
    {
        if(*this->Dot(other) == 0)
        {
            return true;
        }
        return false;
    }

    static bool isOrtho(const Vector2& A, const Vector2& B)
    {
        return A.isOrtho(B);
    }

public :
    T x;
    T y;
};
