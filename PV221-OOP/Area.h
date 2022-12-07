#pragma once
#include<iostream>

using namespace std;


class Area
{
	static int count;

    Area()
    {

    }

public:

    /// <summary>
    /// Розрахунок площі прямокутника
    /// </summary>
    /// <param name="width"> - довжина</param>
    /// <param name="heigth"> - висота</param>
    /// <returns>площа прямокутника</returns>
    static float SquareRectangle(float width, float heigth)
    {
        count++;
        return width * heigth;
    }
};

int Area::count = 0;