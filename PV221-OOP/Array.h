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
	T* arr;
	size_t size;

public:
	Array();

	explicit Array(size_t size);

	Array(const Array<T>& obj);

	~Array();

	Array<T>& operator=(const Array<T>& obj);

	void set(T iMin, T iMax) const;

	void set() const;

	void print() const;

	size_t count() const;

	T at(size_t index) const;

	void sort(bool(*method)(T, T)) const;

	//friend void printArrayInStarLine(Array arr);

	//friend class Visualisator;

	//friend void Visualisator::printArrayInStarLine(Array arr);

	T& operator[](int index);

	void push(const T& value);

	void remove(size_t index);

};

template<class T>
Array<T>::Array() : Array(0){ }

template<class T>
Array<T>::Array(size_t size) : size(size)
{
	arr = (size > 0)? new T[size] : nullptr;
	//cout << "Constructor" << endl;
}

template<class T>
Array<T>::Array(const Array<T>& obj)
{
	size = obj.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	//cout << "Constructor copy" << endl;
}

template<class T>
Array<T>::~Array()
{
	delete[] arr;
	//cout << "Destructor" << endl;
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	if (this == &obj)
		return *this;

	delete[] arr;
	size = obj.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}

	return *this;
}

template<class T>
void Array<T>::set(T iMin, T iMax) const
{
	cout << "Array : " << typeid(T).name() << endl;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (int)(iMax - iMin + 1) + iMin;
	}
}

template<>
void Array<double>::set(double iMin, double iMax) const
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = 10 * (rand() % (int)(iMax - iMin + 1) + iMin)/ 9.;
	}
}


template<>
void Array<Apple>::set() const
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = Apple("red", rand() % 15 + 1);
	}
}

template<class T>
void Array<T>::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
size_t Array<T>::count() const
{
	return size;
}

template<class T>
T Array<T>::at(size_t index) const
{
	assert(index < size);

	return arr[index];
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
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (method(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<class T>
T& Array<T>::operator[](int index)
{
	return arr[index];
}

template<class T>
void Array<T>::push(const T& value)
{
	T* newArr = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = value;
	size++;
	delete[] arr;
	arr = newArr;
}

template<class T>
void Array<T>::remove(size_t index)
{
	T* newArr = new T[size - 1];
	for (size_t i = 0; i < index; i++)
	{
		newArr[i] = arr[i];
	}
	for (size_t i = index+1; i < size; i++)
	{
		newArr[i-1] = arr[i];
	}
	delete[] arr;
	size--;
	arr = newArr;
}

//void printArrayInStarLine(Array arr)
//{
//	//*******************
//	for (size_t i = 0; i < arr.size; i++)
//	{
//		cout << arr.arr[i] << " ";
//	}
//	cout << endl;
//	//*******************
//}


//void Visualisator::printArrayInStarLine(Array arr)
//{
//	//*******************
//	for (size_t i = 0; i < arr.size; i++)
//	{
//		cout << arr.arr[i] << " ";
//	}
//	cout << endl;
//	//*******************
//}
//
//void Visualisator::method(Array a)
//{
//	cout << a.size() << endl;
//}