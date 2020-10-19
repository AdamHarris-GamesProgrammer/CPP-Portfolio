#include "Vector3.h"
#include <cassert>
#include <corecrt_math.h>
#include <iostream>
#include <string>

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
	: x(x),y(y),z(z)
{}

Vector3::Vector3(const Vector3& cpy)
{
	x = cpy.x;
	y = cpy.y;
	z = cpy.z;
}

float Vector3::X()
{
	return x;
}

float Vector3::Y()
{
	return y;
}

float Vector3::Z()
{
	return z;
}

Vector3 Vector3::operator+(const Vector3& vec)
{
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

Vector3& Vector3::operator+=(const Vector3& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

Vector3 Vector3::operator-(const Vector3& vec)
{
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3& Vector3::operator-=(const Vector3& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

Vector3 Vector3::operator*(float value)
{
	return Vector3(x * value, y * value, z * value);
}

Vector3& Vector3::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector3 Vector3::operator/(float value)
{
	assert(value != 0);
	return Vector3(x / value, y / value, z / value);
}

Vector3& Vector3::operator/=(float value)
{
	assert(value != 0);
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

float Vector3::DotProduct(const Vector3& vec)
{
	return (x * vec.x + y * vec.y + z * vec.z);
}

Vector3 Vector3::CrossProduct(const Vector3& vec)
{
	return Vector3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}

Vector3 Vector3::Normalization()
{
	return *this / Magnitude();
}

float Vector3::Magnitude()
{
	return sqrtf(Square());
}

float Vector3::Square()
{
	return x * x + y * y + z * z;
}

float Vector3::Distance(const Vector3& vec)
{
	return sqrtf(((x - vec.x) * (x - vec.x)) + ((y - vec.y) * (y - vec.y)) + ((z - vec.z) * (z - vec.z)));
}

void Vector3::Display()
{
	std::cout << "X: " << x << " Y: " << y << " Z: " << z << std::endl;
}

Vector3& Vector3::operator=(const Vector3& vec)
{
	return *this;
}
