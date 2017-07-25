#include "Vector.h"

BlueSignal::Vector2& BlueSignal::Vector2::operator=(const Vector2& v)
{
	this->x = v.x;
	this->y = v.y;
	return *this;
}

BlueSignal::Vector2 & BlueSignal::Vector2::operator+()
{
	return *this;
}

BlueSignal::Vector2 & BlueSignal::Vector2::operator-()
{
	return Vector2(-x, -y);
}

BlueSignal::Vector2 & BlueSignal::Vector2::operator+=(const Vector2 & v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

BlueSignal::Vector2 & BlueSignal::Vector2::operator-=(const Vector2 & v)
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

BlueSignal::Vector2 & BlueSignal::Vector2::operator*=(float s)
{
	this->x *= s;
	this->y *= s;
	return *this;
}

BlueSignal::Vector2 & BlueSignal::Vector2::operator/=(float s)
{
	this->x /= s;
	this->y /= s;
	return *this;
}

BlueSignal::Vector2 BlueSignal::operator+(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}

BlueSignal::Vector2 BlueSignal::operator-(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

float BlueSignal::operator*(const Vector2 & v1, const Vector2 & v2)
{
	return v1.x*v2.x + v1.y*v2.y;
}

BlueSignal::Vector2 BlueSignal::operator*(const Vector2 & v, float s)
{
	return Vector2(v.x*s, v.y*s);
}

BlueSignal::Vector2 BlueSignal::operator*(float s, const Vector2 & v)
{
	return Vector2(v.x*s, v.y*s);
}

BlueSignal::Vector2 BlueSignal::operator/(const Vector2 & v, float s)
{
	return Vector2(v.x / s, v.y / s);
}
