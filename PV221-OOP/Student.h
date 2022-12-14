#pragma once
#include<iostream>
#include"Function.h"

using namespace std;


class Student
{
	const int id;
	int age;
	char* name;
	static size_t count;
	static int lastID;
	int* mark;
	size_t sizeMark;

public:

	Student() : Student("No name", 0)
	{
		cout << "Constructor" << endl;
	}
	
	Student(const char* n, int age) : id(++lastID), age(0), name(nullptr), mark(nullptr), sizeMark(0)
	{
		this->age = age;
		cout << "Constructor 2 param" << endl;
		this->setAge(age);
		this->setName(n);
		count++;
	}

	Student(const Student& obj) : id(obj.id), name(nullptr)
	{
		age = obj.age;
		setName(obj.name);
		sizeMark = obj.sizeMark;
		mark = new int[sizeMark];
		for (size_t i = 0; i < sizeMark; i++)
		{
			mark[i] = obj.mark[i];
		}
		count++;
	}

	~Student()
	{
		delete name;
		delete[] mark;
		cout << "Destructor" << endl;
	}


	static size_t getCount()
	{
		return count;
	}

	void setAge(int a)
	{
		if (a > 120)
			return;
		age = a;
	}

	int getAge() const
	{
		return age;
	}

	void setName(const char* n)
	{
		delete name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}

	const char* getName() const
	{
		return name;
	}

	void setMark(int mark)
	{
		pushArray(this->mark, sizeMark, mark);
	}

	void print() const
	{
		cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
		cout << "Mark: ";
		for (size_t i = 0; i < sizeMark; i++)
		{
			cout << mark[i] << " ";
		}
		cout << endl;
	}

};


size_t Student::count = 0;

int Student::lastID = 0;
