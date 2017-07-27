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


	class Vector3 
	{
	public:
		Vector3()
			:x(0), y(0), z(0)
		{}

		Vector3(float _x, float _y, float _z)
			:x(_x), y(_y), z(_z)
		{}

		Vector3& Vector3::operator=(const Vector3& v);
		Vector3& operator+();
		Vector3& operator-();
		Vector3& operator+=(const Vector3& v);
		Vector3& operator-=(const Vector3& v);
		Vector3& operator*=(float s);
		Vector3& operator/=(float s);

		float x;
		float y;
		float z;
	};

	Vector3 operator+(const Vector3& v1, const Vector3& v2);
	Vector3 operator-(const Vector3& v1, const Vector3& v2);
	float operator*(const Vector3& v1, const Vector3& v2);

	Vector3 operator*(const Vector3& v, float s);
	Vector3 operator*(float s, const Vector3& v);
	Vector3 operator/(const Vector3& v, float s);
}