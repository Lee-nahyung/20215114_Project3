#include <iostream>
#include <vector>

using namespace std;

class Vector
{
private:
	float x, y, z;

public:
	Vector(){}
	Vector(float x, float y, float z): x{ x }, y{ y }, z{ z } {}

	Vector operator+(const Vector& v)const {
		return Vector{ x + v.x, y + v.y, z + v.z }; 
	}

	Vector operator-() const{
		return Vector(-x, -y, -z);
	}

	float operator*(const Vector& v) const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}

	Vector operator*(float n) const {
		return Vector(x * n, y * n, z * n);
	}

	Vector& operator++() { //그 자체를 증가시켜야 해서 const No.
		++x;
		++y;
		++z;
		return *this;
	}

	Vector& operator++(int) {
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;
	}


	Vector operator+() const{
		return Vector{ +x, +y, +z };
	}

	Vector operator-(const Vector&v) const{
		return Vector{ x - v.x, y - v.y, z - v.z };
	}

	Vector operator/(float n) {
		return Vector{ x / n, y / n, z / n };
	}

	void print() {
		cout << x << " " << y << " " << z << endl;
	}
};


int main() {

	Vector v0{ 0, 1, 2 };
	Vector v1{ 1, 2, 3 };

	Vector v2 = v0 + v1; //이항연산자 +, v0.operator+(v1)
	//Vector v2 = v0.operator+(v1); 위와 동일
	v2.print();//1 3 5

	Vector v3 = -v1;//단항연산자 -, v1.operator-()
	v3.print();
	 
	//이항연산자*
	//벡터연산, 내적계산 ->(v0.x * v1.x)+ (v0.y * v1.y) = float
	//벡터*실수값 -> 벡터

	float v4 = v0 * v1; //v0.operator*(v1)
	cout << v4 << endl; //0 +2 + 6 =8 

	Vector v5 = v1 * 3.0f;//v1.operator*(3.0f)
	v5.print();

	//++v1
	//v1++

	Vector v6 = ++v1; //v1.operator++()
	v6.print();
	Vector v7 = v1++;
	v7.print();
	v1.print(); //후위연산자 확인

	Vector v8 = +v1;
	v8.print();

	Vector v9 = v0 - v1;
	v9.print();

	Vector v10 = v1 / 3.0f;
	v10.print();
}