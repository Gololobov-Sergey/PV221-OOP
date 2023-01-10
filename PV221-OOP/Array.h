#pragma once
#include<iostream>
#include<cassert>
#include"Apple.h"

using namespace std;

//class Array;

//class Visualisator
//{
//public:
//	void printArrayInStarLine(Array arr);
//
//	void method(Array a);
//};

template<class T>
class Array
{
	T* m_aArr;
	size_t m_nSize;

public:
	Array();

	explicit Array(size_t size);

	Array(const Array<T>& obj);

	~Array();

	void set(T iMin, T iMax) const;
	void set() const;

	void print() const;

	size_t size() const;

	T at(size_t index) const;

	void sort(bool(*method)(T, T)) const;

	//friend void printArrayInStarLine(Array arr);

	//friend class Visualisator;

	//friend void Visualisator::printArrayInStarLine(Array arr);

	T& operator[](int index);
};

template<class T>
Array<T>::Array() : Array(0){ }

template<class T>
Array<T>::Array(size_t size) : m_nSize(size)
{
	m_aArr = (m_nSize > 0)? new T[m_nSize] : nullptr;
	//cout << "Constructor" << endl;
}

template<class T>
Array<T>::Array(const Array<T>& obj)
{
	m_nSize = obj.m_nSize;
	m_aArr = new T[m_nSize];
	for (size_t i = 0; i < m_nSize; i++)
	{
		m_aArr[i] = obj.m_aArr[i];
	}
	//cout << "Constructor copy" << endl;
}

template<class T>
Array<T>::~Array()
{
	delete[] m_aArr;
	//cout << "Destructor" << endl;
}

template<class T>
void Array<T>::set(T iMin, T iMax) const
{
	cout << "Array : " << typeid(T).name() << endl;
	for (size_t i = 0; i < m_nSize; i++)
	{
		m_aArr[i] = rand() % (int)(iMax - iMin + 1) + iMin;
	}
}

template<>
void Array<double>::set(double iMin, double iMax) const
{
	for (size_t i = 0; i < m_nSize; i++)
	{
		m_aArr[i] = 10 * (rand() % (int)(iMax - iMin + 1) + iMin)/ 9.;
	}
}


template<>
void Array<Apple>::set() const
{
	for (size_t i = 0; i < m_nSize; i++)
	{
		m_aArr[i] = Apple("red", rand() % 15 + 1);
	}
}

template<class T>
void Array<T>::print() const
{
	for (size_t i = 0; i < m_nSize; i++)
	{
		cout << m_aArr[i] << " ";
	}
	cout << endl;
}

template<class T>
size_t Array<T>::size() const
{
	return m_nSize;
}

template<class T>
T Array<T>::at(size_t index) const
{
	assert(index < m_nSize);

	return m_aArr[index];
}

template<class T>
bool ascending(T a, T b)
{
	return a > b;
}

template<class T>
bool descending(T a, T b)
{
	return a < b;
}

template<class T>
bool evenFirst(T a, T b)
{
	if (a % 2 == 0 && b % 2 == 1)
		return false;
	if (a % 2 == 1 && b % 2 == 0)
		return true;
	return ascending(a, b);
}

template<class T>
void Array<T>::sort(bool(*method)(T, T)) const
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

template<class T>
T& Array<T>::operator[](int index)
{
	return m_aArr[index];
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


//void Visualisator::printArrayInStarLine(Array arr)
//{
//	//*******************
//	for (size_t i = 0; i < arr.m_nSize; i++)
//	{
//		cout << arr.m_aArr[i] << " ";
//	}
//	cout << endl;
//	//*******************
//}
//
//void Visualisator::method(Array a)
//{
//	cout << a.size() << endl;
//}