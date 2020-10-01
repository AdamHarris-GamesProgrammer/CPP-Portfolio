#include <iostream>



struct Vector2 {
	float x, y;
	static constexpr double PI = 3.14159265358979323846;

	Vector2(float x, float y) : x(x), y(y) {}

	bool operator==(const Vector2& a) {
		if (this->x == a.x && this->y == a.y) return true;

		return false;
	}
	Vector2 operator+(const Vector2& a) {
		return {this->x + a.x, this->y + a.y};
	}

	Vector2 operator*(float val) {
		return { this->x * val, this->y * val };
	}
	Vector2 operator-(const Vector2& a) {
		return { this->x - a.x, this->y - a.y };
	}

	float Magnitude() {
		//Magnitude is the hypotenuse of the triangle that a vector's horizontal and vertical side would form
		//Therefore we can rearrange Pythagoras theorem to C^2 = A^2 + B^2, however we need the square root of C so I use the sqrtf function to get it.

		float val = sqrtf((x * x) + (y * y));
		return val;
	}
	float Magnitude(const Vector2& a) {
		//Magnitude is the hypotenuse of the triangle that a vector's horizontal and vertical side would form
		//Therefore we can rearrange Pythagoras theorem to C^2 = A^2 + B^2, however we need the square root of C so I use the sqrtf function to get it.

		float val = sqrtf((a.x * a.x) + (a.y * a.y));
		return val;
	}

	float DotProduct(const Vector2& a, const Vector2& b) {
		return a.x * b.x + a.y * b.y;
	}

	float DotProduct(const Vector2& a) {
		return (x * a.x) + (y * a.y);
	}

	float AngleBetween(const Vector2& a, const Vector2& b) {
		float dot = DotProduct(a, b);
		float aMag = Magnitude(a);
		float bMag = Magnitude(b);

		float cosTheta = dot / (aMag * bMag);
		float angle = acos(cosTheta);

		return angle * 180 / PI;
	}

	void Normalize() {
		float magnitude = Magnitude();
		x /= magnitude;
		y /= magnitude;
	}

};

std::ostream& operator<<(std::ostream& out, const Vector2& a) {
	return out << "X: " << a.x << '\t' << "Y: " << a.y;
}

int main() {
	Vector2 testVector = { 3.0f,5.0f };
	Vector2 otherVector = { 3.0f, 5.0f };
	Vector2 thirdVector = { 1.0f, 2.0f };

	if (testVector == otherVector) {
		std::cout << "They are the same" << std::endl;
	}
	testVector == thirdVector ? std::cout << "They are the same" : std::cout << "They are not the same";

	std::cout << std::endl;

	Vector2 addTest = testVector + thirdVector;
	Vector2 multiplyTest = addTest * 5.0f;
	Vector2 subtractTest = addTest - Vector2(3.0f, 2.0f);

	std::cout << addTest << std::endl;
	std::cout << multiplyTest << std::endl;
	std::cout << subtractTest << std::endl;

	Vector2 magnitudeTest = { 3.0f,-5.0f };
	std::cout << magnitudeTest.Magnitude() << std::endl;

	Vector2 angleTestA = { 2.0f,3.0f };
	Vector2 angleTestB = { 3.0f,4.0f };
	float angle = angleTestA.AngleBetween(angleTestA, angleTestB);

	std::cout << angle << std::endl;
}