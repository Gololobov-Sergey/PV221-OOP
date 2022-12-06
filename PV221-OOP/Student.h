#pragma once
#include<iostream>

using namespace std;



class Student
{
	int age;
	char* name;

public:

	Student()
	{
		age = 0;
		setName("No name");
		cout << "Constructor" << endl;
	}
	
	Student(const char* n, int a)
	{
		setAge(a);
		setName(n);
	}

	void setAge(int a)
	{
		if (a > 120)
			return;
		age = a;
	}

	int getAge()
	{
		return age;
	}

	void setName(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}

	void print()
	{
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};
