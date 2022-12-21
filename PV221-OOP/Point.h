#pragma once
#include<iostream>

using namespace std;

class Point
{
	int x;
	int y;

public:
	Point();
	Point(int x, int y);
	void print();

	//friend Point operator+(Point p1, Point p2);

	Point operator+();
	Point operator-();
	Point operator++();    //prefix
	Point operator++(int); //postfix

	Point operator+(Point p);

	Point operator*(int n);

	friend Point operator*(int n, Point p);
	
	void operator+=(Point p);

	bool operator!();

	bool operator==(Point p);

	bool operator!=(Point p);

	/*bool operator>(Point p);
	bool operator<(Point p);*/

	auto operator<=>(Point p);

	operator bool();
	operator float();

	friend ostream& operator<<(ostream& out, const Point& p);
	friend istream& operator>>(istream& in, Point& p);


	void operator()(int x, int y);

	float operator[](const char* key);
};

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : x(x), y(y)
{

}

void Point::print()
{
	cout << "X = " << x << ", Y = " << y << endl;
}

inline Point Point::operator-()
{
	return Point(-x, -y);
}

inline Point Point::operator++()     //prefix
{
	x++;
	y++;
	return *this;
}

inline Point Point::operator++(int)  //postfix
{
	Point p(*this);
	x++;
	y++;
	return p;
}

Point Point::operator+(Point p)
{
	return Point(x + p.x, y + p.y);
}

Point Point::operator*(int n)
{
	return Point(x * n, y * n);
}

void Point::operator+=(Point p)
{
	*this = *this + p;
}

bool Point::operator!()
{
	return x == 0 && y == 0;
}

bool Point::operator==(Point p)
{
	return x == p.x && y == p.y;
}

bool Point::operator!=(Point p)
{
	return x =! p.x || y != p.y;
}

Point::operator bool()
{
	return x != 0 || y != 0;
}

Point::operator float()
{
	return sqrt(x * x + y * y);
}

void Point::operator()(int x, int y)
{
	this->x = x;
	this->y = y;
}

float Point::operator[](const char* key)
{
	if (strcmp(key, "x") == 0)
		return x;
	if (strcmp(key, "y") == 0)
		return y;
	if (strcmp(key, "length") == 0)
		return (float)*this;
}

auto Point::operator<=>(Point p)
{
	return y <=> p.y;
}

//bool Point::operator>(Point p)
//{
//	return y > p.y;
//}
//
//bool Point::operator<(Point p)
//{
//	return y < p.y;
//}

Point operator*(int n, Point p)
{
	return p * n;
}

ostream& operator<<(ostream& out, const Point& p)
{
	out << "X = " << p.x << ", Y = " << p.y;
	return out;
}

inline istream& operator>>(istream& in, Point& p)
{
	in >> p.x >> p.y;
	return in;
}

//Point operator+(Point p1, Point p2)
//{
//	return Point(p1.x + p2.x, p1.y + p2.y);
//}
