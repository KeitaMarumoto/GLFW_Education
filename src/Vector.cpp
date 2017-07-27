#include "Vector.h"

BS::Vector2& BS::Vector2::operator=(const Vector2& v)
{
	this->x = v.x;
	this->y = v.y;
	return *this;
}

BS::Vector2 & BS::Vector2::operator+()
{
	return *this;
}

BS::Vector2 & BS::Vector2::operator-()
{
	return Vector2(-x, -y);
}

BS::Vector2 & BS::Vector2::operator+=(const Vector2 & v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

BS::Vector2 & BS::Vector2::operator-=(const Vector2 & v)
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

BS::Vector2 & BS::Vector2::operator*=(float s)
{
	this->x *= s;
	this->y *= s;
	return *this;
}

BS::Vector2 & BS::Vector2::operator/=(float s)
{
	this->x /= s;
	this->y /= s;
	return *this;
}

BS::Vector2 BS::operator+(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}

BS::Vector2 BS::operator-(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

float BS::operator*(const Vector2 & v1, const Vector2 & v2)
{
	return v1.x*v2.x + v1.y*v2.y;
}

BS::Vector2 BS::operator*(const Vector2 & v, float s)
{
	return Vector2(v.x*s, v.y*s);
}

BS::Vector2 BS::operator*(float s, const Vector2 & v)
{
	return Vector2(v.x*s, v.y*s);
}

BS::Vector2 BS::operator/(const Vector2 & v, float s)
{
	return Vector2(v.x / s, v.y / s);
}

//*************************************************************************
// Vector3
//*************************************************************************

inline BS::Vector3 & BS::Vector3::cross(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}

BS::Vector3 & BS::Vector3::operator=(const Vector3 & v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;

	return *this;
}

BS::Vector3 BS::operator+(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

BS::Vector3 BS::operator-(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

float BS::operator*(const Vector3 & v1, const Vector3 & v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

BS::Vector3 BS::operator*(const Vector3 & v, float s)
{
	return Vector3(v.x*s, v.y*s, v.z*s);
}

BS::Vector3 BS::operator*(float s, const Vector3 & v)
{
	return Vector3(v.x*s, v.y*s, v.z*s);
}

BS::Vector3 BS::operator/(const Vector3 & v, float s)
{
	return Vector3(v.x / s, v.y / s, v.z / s);
}

BS::Vector3 & BS::Vector3::operator+()
{
	return *this;
}

BS::Vector3 & BS::Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

BS::Vector3 & BS::Vector3::operator+=(const Vector3 & v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

BS::Vector3 & BS::Vector3::operator-=(const Vector3 & v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

BS::Vector3 & BS::Vector3::operator*=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

BS::Vector3 & BS::Vector3::operator/=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}
