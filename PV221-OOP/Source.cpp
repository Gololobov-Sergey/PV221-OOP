#include<iostream>
#include"Student.h"

using namespace std;

int main()
{

	Student st("Vasya", 20);
	//st.age = 10000000;
	//st.setAge(20);
	//st.setAge(1000000);
	//st.setName("Vasya");
	st.print();

	cout << sizeof(Student) << endl;

	Student* st1 = new Student;
	st1->setAge(20);

	Student st2[2];

	Student* st3 = new Student[2];
	st3[0].getAge();
	


}