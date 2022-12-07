#include<iostream>
#include"Student.h"
#include"Area.h"

using namespace std;

int main()
{

	Student st("Vasya", 20);
	st.print();
	st.setName("Petya");
	st.print();

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