#pragma once

namespace BS
{

	class Vector2
	{
	public:
		Vector2() 
			:x(0), y(0) 
		{}

		Vector2(float _x, float _y)
			:x(_x), y(_y)
		{}

		Vector2& Vector2::operator=(const Vector2& v);
		Vector2& operator+();
		Vector2& operator-();
		Vector2& operator+=(const Vector2& v);
		Vector2& operator-=(const Vector2& v);
		Vector2& operator*=(float s);
		Vector2& operator/=(float s);

		float x;
		float y;
	};

	Vector2 operator+(const Vector2& v1, const Vector2& v2);
	Vector2 operator-(const Vector2& v1, const Vector2& v2);
	float operator*(const Vector2& v1, const Vector2& v2);

	Vector2 operator*(const Vector2& v, float s);
	Vector2 operator*(float s, const Vector2& v);
	Vector2 operator/(const Vector2& v, float s);
}