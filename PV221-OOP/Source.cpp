#include<iostream>
#include"Student.h"
#include"Area.h"
#include"Array.h"
#include"PhoneBook.h"
#include"Menu.h"
#include"Fraction.h"
#include"House.h"

using namespace std;


void test(Array a)
{
	a.print();
}

void test(Student a)
{
	a.print();
}

void test(Fraction a)
{
	a.print();
}

void hello()
{
	cout << "Hello" << endl;
}

void goodbye()
{
	cout << "Goodbye" << endl;
}

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	House house("м. Миколаїв, вул. Садова, 15", 2, 3, 18);
	house.menu();

	

	//{
	//	Array a(20);
	//	a.set(0, 20);
	//	a.print();
	//	//test("Vasya", 20);

	//	////1
	//	//test(a);
	//	//a.print();

	//	//2
	//	/*Array b(a);
	//	b.print();
	//	a.print();*/
	//}




	//Fraction f1;
	//Fraction f2(5);
	//Fraction f3(8, 4);

	//Fraction f4 = f3.sum(f2); //sum(f1, f2);
	//Fraction f5 = f4.normal();
	//f4.print();
	//f5.print();
	//test(10);


	//int c = Menu::select_vertical({ "Add", "Edit", "Del", "Exit" }, HorizontalAlignment::Center);

	/*int a = 3;     int b = 3;
	int* pa = &a;  int& rb = b;
	*pa = 5;       rb = 5;

	int* const d = &a;    const int& rd = a;
	d = &b;
	pa = &b;       rb = a;*/


	//PhoneBook ph;
	//ph.menu(); //menu(ph)

	/*Array a(20);
	a.set(0, 20);
	a.print();
	a.sort();
	a.print();*/

	// type (*namePointer)(param);

	/*void(*method)();
	method = hello;
	method();
	method = goodbye;
	method();*/

	/*{
		Student st("Vasya", 20);
		st.setMark(10);
		st.setMark(11);
		st.setMark(12);
		st.setMark(11);
		st.print();
		test(st);
		st.print();
	}*/

	/*size_t t = -1;
	cout << t << endl;*/

	//Area a;
	//cout << Area::SquareRectangle(12, 34) << endl;

	/*cout << "Count: " << Student::getCount() << endl;

	Student st("Vasya", 2000000000);
	st.print();
	cout << "Count: " << st.getCount() << endl;

	Student st1("Petya", 20);
	st1.print();
	cout << "Count: " << st.getCount() << endl;*/

	//st.age = 10000000;
	//st.setAge(20);
	//st.setAge(1000000);
	//st.setName("Vasya");

	//st.getName()[3] = 'M';


	//st.print();

	/*cout << sizeof(Student) << endl;

	Student* st1 = new Student(1);
	st1->setAge(20);

	Student st2[2];

	Student* st3 = new Student[2];
	st3[0].getAge();*/

	/*int a = 9.2;
	int b(9.2);
	int c{ (int)9.2 };*/


	//const int a{ 9 };


}