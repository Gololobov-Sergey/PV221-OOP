#pragma once
#include<iostream>
#include<iomanip>
#include"Function.h"
#include"Menu.h"

using namespace std;

class Abonent
{
	char* fio;
	char* phone;

public:
	Abonent()
	{
		
	}

	Abonent(const char* fio, const char* phone)
	{
		this->fio = new char[strlen(fio) + 1];
		strcpy_s(this->fio, strlen(fio) + 1,fio);
		this->phone = new char[strlen(phone) + 1];
		strcpy_s(this->phone, strlen(phone) + 1, phone);
	}

	void print()
	{
		cout << setw(15) << left << fio << setw(15) << right << phone << endl;
	}

	//Abonent
};

class PhoneBook
{
	Abonent** abonents;
	size_t size;

	void  add();
	void del();
	void print();


public:
	PhoneBook() : abonents(nullptr), size(0) { }
	~PhoneBook();
	void menu();
};

inline void PhoneBook::add()
{
	system("cls");
	cout << "Add Abonent" << endl;
	cout << "================" << endl;
	char fio[80], phone[80];
	cout << "Enter FIO: ";
	cin.getline(fio, 80);
	cout << "Enter Phone: ";
	cin.getline(phone, 80);
	Abonent* a = new Abonent(fio, phone);
	pushArray(abonents, size, a);
	cout << "Abonent Added" << endl;
	system("pause");
}

inline void PhoneBook::del()
{


}

inline void PhoneBook::print()
{
	system("cls");
	cout << "All Abonents" << endl;
	cout << "================" << endl;
	for (size_t i = 0; i < size; i++)
	{
		abonents[i]->print();
	}
	system("pause");
}

inline PhoneBook::~PhoneBook()
{
	for (size_t i = 0; i < size; i++)
	{
		delete abonents[i];
	}
	delete[] abonents;
}

void PhoneBook::menu()
{
	
	do
	{
		system("cls");
		int c = Menu::select_vertical({ "Add", "Del", "Print", "Exit" }, HorizontalAlignment::Left, 2);
		switch (c)
		{
		case 0: add(); break;
		case 1: del(); break;
		case 2: print(); break;
		case 3: exit(0);
		}
	} while (true);
}