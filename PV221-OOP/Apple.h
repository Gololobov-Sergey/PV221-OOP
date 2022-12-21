#pragma once
#include<iostream>
#include"Function.h"

using namespace std;

class Kompot;

class Apple
{
	char* color;
	int radius;

public:
	Apple();
	Apple(const char* color, int radius);

	~Apple();

	Kompot operator+(const Apple & apple); 
	friend ostream& operator<<(ostream& out, const Apple& apple);
};


Apple::Apple() : color(nullptr), radius(0) {}

Apple::Apple(const char* color, int radius) : radius(radius)
{
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

Apple::~Apple()
{
	delete color;
}





class Kompot
{
	Apple* apples;
	size_t size;

public:
	Kompot();
	void operator+=(const Apple& apple);
	friend ostream& operator<<(ostream& out, const Kompot& k);
};

Kompot::Kompot() : apples(nullptr) {}

void Kompot::operator+=(const Apple& apple)
{
	pushArray(apples, size , apple);
}

ostream& operator<<(ostream& out, const Apple& apple)
{
	out << "Apple : " << apple.color << ", R - " << apple.radius;
	return out;
}

ostream& operator<<(ostream& out, const Kompot& k)
{
	for (size_t i = 0; i < k.size; i++)
	{
		cout << k.apples[i] << endl;
	}
	return out;
}


Kompot Apple::operator+(const Apple& apple)
{
	Kompot k;
	k += *this;
	k += apple;
	return k;
}