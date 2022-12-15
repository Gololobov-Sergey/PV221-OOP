#pragma once
#include<iostream>
#include<iomanip>

#include"Menu.h"
#include"Function.h"

using namespace std;

class Human
{
	char* fullName;
	bool responsible;

public:
	Human();
	Human(const char* fullName, bool responsible);
	~Human();
	const char* getFullName() const;
	void print();
};


Human::Human() : Human("", false) {}

Human::Human(const char* fullName, bool responsible = false) : responsible(responsible)
{
	this->fullName = new char[strlen(fullName) + 1];
	strcpy_s(this->fullName, strlen(fullName) + 1, fullName);
}

Human::~Human()
{
	delete fullName;
}


const char* Human::getFullName() const
{
	return fullName;
}





class Room
{
	Human* residents;
	size_t sizeResidents;
	size_t number;
	size_t area;

public:
	Room();
	Room(size_t number, size_t area);
	~Room();
	Room& operator=(const Room& obj);
	void addResidents();
	void addResidents(Human h);
	void delResidents();
	void print();
	void printResponsible();
	void menu();
};

Room::Room() : Room(0, 0) {}

Room::Room(size_t number, size_t area) : 
	number(number), area(area), residents(nullptr), sizeResidents(0)
{

}

Room::~Room()
{

}


Room& Room::operator=(const Room& obj)
{
	if (this == &obj)
		return *this;

	delete[] residents;

	sizeResidents = obj.sizeResidents;
	residents = (sizeResidents)? new Human[sizeResidents] : nullptr;
	for (size_t i = 0; i < sizeResidents; i++)
	{
		residents[i] = obj.residents[i];
	}
	area = obj.area;
	number = obj.number;

	return *this;
}

void Room::printResponsible()
{
	cout << setw(4) << number << setw(20) << left << ((residents)? residents[0].getFullName() : " ") << " " << setw(6) << right << area << endl;
}

void Room::menu()
{
	do
	{
		system("cls");
		int choice = Menu::select_vertical(
			{ "Додати мешканця",
			"Інформація про квартиру",
			"Видалити мешканця",
			"Вихід" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0:                 break;
		case 1: /*print();*/        break;
		case 2: /*workWithRoom()*/; break;
		case 3: return;
		}
	} while (true);
}



class House
{
	char* adress;
	const size_t countRooms;
	Room* rooms;
	const size_t floor;
	const size_t entrance;

public:

	House(const char* adress, size_t entrance, size_t floor, size_t countRooms);
	~House();
	void print();
	void workWithRoom();
	void menu();
};


House::House(const char* adress, size_t entrance, size_t floor, size_t countRooms) :
	entrance(entrance), floor(floor), countRooms(countRooms)
{
	this->adress = new char[strlen(adress) + 1];
	strcpy_s(this->adress, strlen(adress) + 1, adress);
	rooms = new Room[countRooms];
	for (size_t i = 0; i < countRooms; i++)
	{
		Room room(i + 1, rand() % 31 + 50);
		rooms[i] = room;
	}
}


House::~House()
{

}


void House::print()
{
	system("cls");
	cout << endl;
	cout << "Адреса: " << adress << endl;
	cout << "---------------------------------------------" << endl << endl;
	cout << setw(4) << "№" << setw(20) << left << "ПІБ" << " " << setw(6) << right << "Площа" << endl;
	cout << "--------------------------------------------------" << endl;
	for (size_t i = 0; i < countRooms; i++)
	{
		rooms[i].printResponsible();
	}
	cout << endl;
	system("pause");
}

void House::workWithRoom()
{
	system("cls");
	cout << "Робота з квартирою" << endl;
	cout << "------------------------" << endl;
	cout << "Виберить номер квартири [1-" << countRooms << "] :";
	size_t index;
	cin >> index;
	cin.ignore();
	rooms[index].menu();
}

void House::menu()
{
	do
	{
		system("cls");
		int choice = Menu::select_vertical(
			{ "Змінити адресу",
			"Інформація про будинок",
			"Робота з каватирою",
			"Вихід" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0:                 break;
		case 1: print();        break;
		case 2: workWithRoom(); break;
		case 3: exit(0);
		}
	} while (true);
}