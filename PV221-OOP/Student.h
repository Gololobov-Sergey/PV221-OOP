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

	Student() : Student("No name", 0)
	{
		cout << "Constructor" << endl;
	}
	
	Student(const char* n, int age) : id(++lastID), age(0), name(nullptr)
	{
		this->age = age;
		cout << "Constructor 2 param" << endl;
		this->setAge(age);
		this->setName(n);
		count++;
	}

	~Student()
	{
		delete name;
		cout << "Destructor" << endl;
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

};


int Student::count = 0;

int Student::lastID = 0;
