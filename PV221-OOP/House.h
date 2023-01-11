#pragma once
#include<iostream>
#include<iomanip>

#include"Menu.h"
#include"Function.h"
#include"Array.h"

using namespace std;

class Human
{
	char* fullName;
	bool responsible;

public:
	Human();
	Human(const char* fullName, bool responsible);
	~Human();
	Human(const Human& h);
	Human& operator=(const Human& h);
	void setName(const char* fullName);
	void setResponsible(bool res);
	const char* getFullName() const;
	bool getResponsible() const;
	void print();
	friend ostream& operator<<(ostream& out, const Human& h);
	friend istream& operator>>(istream& in, Human& h);
};


Human::Human() : Human("", false) {}

Human::Human(const char* fullName, bool responsible = false) : responsible(responsible)
{
	setName(fullName);
}

Human::~Human()
{
	delete fullName;
}

Human::Human(const Human& h)
{
	setName(h.getFullName());
	setResponsible(h.getResponsible());
}


Human& Human::operator=(const Human& h)
{
	if (this == &h)
		return *this;

	delete fullName;

	setName(h.getFullName());
	setResponsible(h.getResponsible());

	return *this;
}

bool Human::getResponsible() const
{
	return responsible;
}

void Human::setResponsible(bool res)
{
	responsible = res;
}

void Human::setName(const char* fullName)
{
	this->fullName = new char[strlen(fullName) + 1];
	strcpy_s(this->fullName, strlen(fullName) + 1, fullName);
}

const char* Human::getFullName() const
{
	return fullName;
}

istream& operator>>(istream& in, Human& h)
{
	char buff[80];
	cout << "Ім'я : ";
	in.getline(buff, 80);
	h.setName(buff);
	cout << "Відповідальний? y/n :";
	char r;
	in >> r;
	h.setResponsible((r == 'y') ? true : false);
	return in;
}



class Room
{
	Array<Human> residents;
	//Human* residents;
	//size_t sizeResidents;
	size_t number;
	size_t area;

public:
	Room();
	Room(size_t number, size_t area);
	~Room();
	Room& operator=(const Room& obj);
	void addResidents();
	void addResidents(const Human& h);
	void delResidents();
	void print();
	void printResponsible();
	void menu();
};

Room::Room() : Room(0, 0) {}

Room::Room(size_t number, size_t area) : number(number), area(area)
{

}

Room::~Room()
{

}


Room& Room::operator=(const Room& obj)
{
	if (this == &obj)
		return *this;

	//delete[] residents;

	//sizeResidents = obj.sizeResidents;
	//residents = (sizeResidents)? new Human[sizeResidents] : nullptr;
	/*for (size_t i = 0; i < sizeResidents; i++)
	{
		residents[i] = obj.residents[i];
	}*/
	residents = obj.residents;
	area = obj.area;
	number = obj.number;

	return *this;
}

void Room::addResidents()
{
	cout << "Додавання мешканця: " << endl;
	Human h;
	cin >> h;
	addResidents(h);
}


void Room::addResidents(const Human& h)
{
	residents.push(h);
}

void Room::printResponsible()
{
	cout << setw(4) << number << setw(20) << left << ((residents.count())? residents[0].getFullName() : " ") << " " << setw(6) << right << area << endl;
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
		case 0: addResidents();     break;
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
	rooms[index - 1].menu();
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