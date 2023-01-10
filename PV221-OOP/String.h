#pragma once
#include<iostream>

using namespace std;

class String
{
	char* str;
	size_t size;

public:
	String();
	String(const char* str);
	~String();
	String(const String& obj);
	String& operator=(const String& obj);
	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, String& str);
	size_t length() const;
	String operator+(const String& str);
	void operator+=(const String& str);
	char& operator[](size_t index);
	String& append(const String& str);
	String& append(const String& str, size_t count);
	String& append(const char symbol, size_t count);
	void clear();
	void reverse();
	size_t find(const String& str) const;
	size_t find(const char symbol) const;
	bool empty() const;
	void insert(size_t pos, const String& str);
	void insert(size_t pos, size_t count, const char symbol);
	String& erase(size_t pos, size_t count);
	auto operator<=>(const String& str);
	int compare(const String& str) const;
};


String::String()
{
	
}

ostream& operator<<(ostream& out, const String& str)
{
	out << str.str;
	return out;
}