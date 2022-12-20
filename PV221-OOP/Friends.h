#pragma once
#include<iostream>


using namespace std;

class Humidity;

class Temperature
{
	int temp;

public:
	Temperature(int temp) : temp(temp)
	{
			
	}
	friend void WeatherInformer(Temperature temp, Humidity humidity);
};


class Humidity
{
	int humidity;

public:
	Humidity(int humidity) : humidity(humidity)
	{

	}

	friend void WeatherInformer(Temperature temp, Humidity humidity);
};


void WeatherInformer(Temperature temp, Humidity humidity)
{
	cout << "Temperature : " << temp.temp << " " << (char)248 << "C" << endl;
	cout << "Humidity    : " << humidity.humidity << " %" << endl;
}