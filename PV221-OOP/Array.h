#pragma once
#include<iostream>

using namespace std;

class Array
{
	int* m_aArr;
	size_t m_nSize;

public:
	Array();

	Array(size_t size);

	void set(int min = 0, int max = 9);

	void print();
};


Array::Array() : m_nSize(0), m_aArr(nullptr) { }

Array::Array(size_t size) : m_nSize(size)
{
	m_aArr = new int[m_nSize];
}


void Array::set(int min, int max)
{
	for (size_t i = 0; i < m_nSize; i++)
	{
		m_aArr[i] = rand() % (max - min + 1) + min;
	}
}


void Array::print()
{
	for (size_t i = 0; i < m_nSize; i++)
	{
		cout << m_aArr[i] << " ";
	}
	cout << endl;
}
