#pragma once
#include<iostream>

using namespace std;


enum class TYPE
{
	NOTYPE = -1, INT, DOUBLE, STRING
};


class var
{
	void* value = nullptr;
	TYPE type;

public:
	var() : type(TYPE::NOTYPE) {}
	var(int a) : type(TYPE::INT) { delete value; value = new int(a); }
	var(double a) : type(TYPE::DOUBLE) { delete value; value = new double(a); }
	var(const char* a) : type(TYPE::STRING) 
	{ 
		delete value;
		value = new char[strlen(a) + 1]; 
		strcpy_s((char*)value, strlen(a) + 1, a);
	}

	friend ostream& operator<<(ostream& out, const var& var);

	var operator+(const var& v);
};

ostream& operator<<(ostream& out, const var& var)
{
	switch (var.type)
	{
	case TYPE::INT:    out << *(int*)var.value; break;
	case TYPE::DOUBLE: out << *(double*)var.value; break;
	case TYPE::STRING: out << (char*)var.value; break;
	}
	return out;
}

var var::operator+(const var& v)
{
	switch (this->type)
	{

	case TYPE::INT:
		switch (v.type)
		{
		case TYPE::INT: return var(*(int*)value + *(int*)v.value);
		case TYPE::DOUBLE: return var((int)(*(int*)value + *(double*)v.value));
		case TYPE::STRING: return var(*(int*)value + atoi((char*)v.value));
		}
		break;
	case TYPE::DOUBLE:
		switch (v.type)
		{
		case TYPE::INT: return var(*(double*)value + *(int*)v.value);
		case TYPE::DOUBLE: return var(*(double*)value + *(double*)v.value);
		case TYPE::STRING: return var(*(double*)value + atof((char*)v.value));
		}
		break;
	case TYPE::STRING:
		switch (v.type)
		{

		case TYPE::INT:
			break; // 
		case TYPE::DOUBLE:
			break;
		case TYPE::STRING:
			break;
		}
		break;
	default:
		break;
	}

}