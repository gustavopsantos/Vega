#include "Vector2.h"
#include <cmath>

Vector2::Vector2() : x(0.0f), y(0.0f)
{
}

Vector2::Vector2(float xVal, float yVal) : x(xVal), y(yVal)
{
}

float Vector2::Magnitude() const
{
    return std::sqrt(x * x + y * y);
}

float Vector2::SqrMagnitude() const
{
    return x * x + y * y;
}

Vector2 Vector2::Normalized() const
{
    float magnitude = Magnitude();
    return Vector2(x / magnitude, y / magnitude);
}

Vector2 Vector2::ClampMagnitude(float maxLength) const
{
    float magnitude = Magnitude();

    if (magnitude <= maxLength)
    {
        return Vector2(x, y);
    }

    return Vector2((x / magnitude) * maxLength, (y / magnitude) * maxLength);
}

Vector2 Vector2::MoveTowards(const Vector2& from, const Vector2& to, float maxDelta)
{
    Vector2 direction = to - from;
    float distance = direction.Magnitude();

    if (distance <= maxDelta)
    {
        return to;
    }

    return from + direction.Normalized() * maxDelta;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const
{
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const
{
    return Vector2(x / scalar, y / scalar);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}