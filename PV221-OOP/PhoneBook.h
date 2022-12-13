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

	Abonent(const char* _fio, const char* _phone)
	{
		fio = new char[strlen(_fio) + 1];
		strcpy_s(fio, strlen(_fio) + 1,_fio);
		phone = new char[strlen(_phone) + 1];
		strcpy_s(phone, strlen(_phone) + 1, _phone);
	}

	void print()
	{
		cout << setw(15) << left << fio << setw(15) << right << phone << endl;
	}

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

void PhoneBook::menu()
{
	do
	{
		system("cls");
		int c = Menu::select_vertical({ "Add", "Del", "Print567890-9876", "Exit" }, HorizontalAlignment::Left, 2);
		switch (c)
		{
		case 0: add(); break;
		case 1: del(); break;
		case 2: print(); break;
		case 3: exit(0);
		}
	} while (true);
}