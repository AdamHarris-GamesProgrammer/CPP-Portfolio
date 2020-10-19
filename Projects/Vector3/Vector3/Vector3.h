#pragma once

class Vector3 {
public:
	//Constructors
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3& cpy);

	//Getters
	float X();
	float Y();
	float Z();

	//Arithmetic Operations
	Vector3 operator+(const Vector3& vec);
	Vector3 &operator+=(const Vector3& vec);
	Vector3 operator-(const Vector3& vec);
	Vector3 &operator-=(const Vector3& vec);
	Vector3 operator*(float value);
	Vector3 &operator*=(float value);
	Vector3 operator/(float value);
	Vector3 &operator/=(float value);
	Vector3 &operator=(const Vector3& vec);

	//Vector Operations
	float DotProduct(const Vector3& vec);
	Vector3 CrossProduct(const Vector3& vec);
	Vector3 Normalization();
	float Magnitude();

	//Scalar Operations
	float Square();
	float Distance(const Vector3& vec);

	//Display
	void Display();
private:
	float x, y, z;
};

