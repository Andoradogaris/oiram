#pragma once

enum Plan {
    Horizontal,
    Vertical
};

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
        return *this - Vector2(other);
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
        return *this * Vector2(other);
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
        return *this / Vector2(other);
    }
    
    void operator+=(const Vector2& other)
    {
        x = x + other.x;
        y = y + other.y;
    }

    void operator-=(const Vector2& other)
    {
        x = x - other.x;
        y = y - other.y;
    }
    
    void operator*=(const Vector2& other)
    {
        x = x * other.x;
        y = y * other.y;
    }

    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const
    {
        return !(*this == other);
    }

    float Length() const
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

    float Dot(const Vector2& other) const
    {
        return x * other.x + y * other.y;
    }

    static float Dot(const Vector2& A, const Vector2& B)
    {
        return A.Dot(B);
    }

    float GetAngle(Vector2& other)
    {
        Normalize();
        other.Normalize();
        float cosinus = Dot(*this, other);
        float angle = std::acos(cosinus) * 180.f / 3.1415f;
        
        return (angle);
    }

    static float GetAngle(const Vector2& A, const Vector2& B)
    {
        return A.GetAngle(B);
    }

    bool isColinear(const Vector2& other)
    {
        float cosAngle = Dot(other) / (Length() * other.Length());
        return fabs(cosAngle - 1.0f) < 0.0001f;
    }
    
    static bool isColinear(const Vector2& A, const Vector2& B)
    {
        return A.isColinear(B);
    }

    bool isOrtho(const Vector2& other)
    {
        if(this->Dot(other) == 0.f)
        {
            return true;
        }
        return false;
    }

    static bool isOrtho(const Vector2& A, const Vector2& B)
    {
        return A.isOrtho(B);
    }

    void Negate()
    {
        *this *= Vector2(-1.f);
    }

    void ReflectVector(Plan plan)
    {
        if(plan == Horizontal)
        {
            y *= -1; 
        }
        else
        {
            x *= -1;
        }
    }

    public :
        T x;
        T y;
};