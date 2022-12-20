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
	void operator+=(Point p);
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

inline Point Point::operator*(int n)
{
	return Point(x * n, y * n);
}

inline void Point::operator+=(Point p)
{
	*this = *this + p;
}


//Point operator+(Point p1, Point p2)
//{
//	return Point(p1.x + p2.x, p1.y + p2.y);
//}
