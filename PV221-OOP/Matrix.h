#pragma once
#include<iostream>

using namespace std;

template<class T>
class Matrix
{
	T** matrix;
	size_t rows;
	size_t columns;

public:
	Matrix(size_t r, size_t c);
	~Matrix();

	//[]

};

