#pragma once

struct Vector2
{
public:
    float x = 0;
    float y = 0;

    Vector2();
    Vector2(float xVal, float yVal);

    float Magnitude() const;
    float SqrMagnitude() const;

    Vector2 Normalized() const;
    Vector2 ClampMagnitude(float maxLength) const;
    static Vector2 MoveTowards(const Vector2& from, const Vector2& to, float maxDelta);

    // Operators
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
};