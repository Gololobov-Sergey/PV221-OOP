#pragma once
#include<iostream>

using namespace std;


class Student
{
	const int id;
	int age;
	char* name;
	static int count;
	static int lastID;

public:

	Student() : id(++lastID), age(0)
	{
		setName("No name");
		cout << "Constructor" << endl;
		count++;
	}
	
	Student(const char* n, int a) : id(++lastID), age(0)/*, name(nullptr)*/
	{
		setAge(a);
		setName(n);
		count++;
	}

	static int getCount()
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

	void print() const
	{
		cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
	}

	void method(int a);


	void method(int a, char b);
};


int Student::count = 0;

int Student::lastID = 0;

void Student::method(int a)
{

}

inline void Student::method(int a, char b)
{

}