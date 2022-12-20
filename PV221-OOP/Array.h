#pragma once
#include<iostream>
#include<cassert>

using namespace std;

class Array;

class Visualisator
{
public:
	void printArrayInStarLine(Array arr);

	void method(Array a);
};


class Array
{
	int* m_aArr;
	size_t m_nSize;

public:
	Array();

	explicit Array(size_t size);

	Array(const Array& obj);

	~Array();

	void set(int iMin, int iMax) const;

	void print() const;

	size_t size() const;

	int at(size_t index) const;

	void sort(bool(*method)(int, int)) const;

	//friend void printArrayInStarLine(Array arr);

	friend class Visualisator;

	//friend void Visualisator::printArrayInStarLine(Array arr);
};


Array::Array() : Array(0){ }


Array::Array(size_t size) : m_nSize(size)
{
	m_aArr = (m_nSize > 0)? new int[m_nSize] {0} : nullptr;
	cout << "Constructor" << endl;
}

Array::Array(const Array& obj)
{
	m_nSize = obj.m_nSize;
	m_aArr = new int[m_nSize];
	for (size_t i = 0; i < m_nSize; i++)
	{
		m_aArr[i] = obj.m_aArr[i];
	}
	cout << "Constructor copy" << endl;
}


Array::~Array()
{
	delete[] m_aArr;
	cout << "Destructor" << endl;
}


void Array::set(int iMin = 0, int iMax = 9) const
{
	for (size_t i = 0; i < m_nSize; i++)
	{
		m_aArr[i] = rand() % (iMax - iMin + 1) + iMin;
	}
}


void Array::print() const
{
	for (size_t i = 0; i < m_nSize; i++)
	{
		cout << m_aArr[i] << " ";
	}
	cout << endl;
}


size_t Array::size() const
{
	return m_nSize;
}


int Array::at(size_t index) const
{
	assert(index < m_nSize);

	return m_aArr[index];
}


bool ascending(int a, int b)
{
	return a > b;
}

bool descending(int a, int b)
{
	return a < b;
}

bool evenFirst(int a, int b)
{
	if (a % 2 == 0 && b % 2 == 1)
		return false;
	if (a % 2 == 1 && b % 2 == 0)
		return true;
	return ascending(a, b);
}

void Array::sort(bool(*method)(int, int) = ascending) const
{
	for (size_t i = 0; i < m_nSize - 1; i++)
	{
		for (size_t j = 0; j < m_nSize - i - 1; j++)
		{
			if (method(m_aArr[j], m_aArr[j + 1]))
			{
				swap(m_aArr[j], m_aArr[j + 1]);
			}
		}
	}
}

//void printArrayInStarLine(Array arr)
//{
//	//*******************
//	for (size_t i = 0; i < arr.m_nSize; i++)
//	{
//		cout << arr.m_aArr[i] << " ";
//	}
//	cout << endl;
//	//*******************
//}


void Visualisator::printArrayInStarLine(Array arr)
{
	//*******************
	for (size_t i = 0; i < arr.m_nSize; i++)
	{
		cout << arr.m_aArr[i] << " ";
	}
	cout << endl;
	//*******************
}

void Visualisator::method(Array a)
{
	cout << a.size() << endl;
}