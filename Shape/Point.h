#pragma once
#include <iostream>
#include<stdlib.h>
#include "math.h"
#include <string>

class Point
{
public:
	float x, y;

	Point();
	~Point();
	Point(float _x, float _y);

	//Сравнение точек
	bool operator == (Point dot);
	bool operator != (Point dot);

	//+, -, *
	Point operator + (Point dot);
	Point operator - (Point dot);
	Point operator * (Point dot);

	void operator += (float Val);
	void operator -= (float Val);
	void operator *= (float Val);
	void operator ++ ();
	void operator -- ();
};


//Горизонтальное расстояние м/у точками
float CathetHorizontal(Point dot1, Point dot2);
//Вертикальное растояние м/у точками
float CathetVertical(Point dot1, Point dot2);
//Растояние м/у точками
float Length(Point dot1, Point dot2);

//Проверка на неравенство координат точек
bool DifferentCoordinate(Point dot1, Point dot2, Point dot3, Point dot4);
bool DifferentCoordinate(Point dot1, Point dot2, Point dot3);
//Точки лежат на одной прямой
bool NotOnOneStraight(Point dot1, Point dot2, Point dot3, Point dot4);
//Формула для выяснения принадлежности точки прямой
bool NotOnOneStraight(Point dot1, Point dot2, Point dot3);

