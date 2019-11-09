#pragma once
#include <iostream>
#include "math.h"

class Point
{
protected:
	//Горизонтальное расстояние м/у точками
	unsigned CathetHorizontal(Point dot1, Point dot2);
	//Вертикальное растояние м/у точками
	unsigned CathetVertical(Point dot1, Point dot2);
	//Растояние м/у точками
	float Length(Point dot1, Point dot2);

	//Проверка на неравенство координат точек
	bool DifferentCoordinate(Point dot1, Point dot2, Point dot3, Point dot4);
	bool DifferentCoordinate(Point dot1, Point dot2, Point dot3);
public:
	int x, y;

	Point();
	~Point();
	Point(int _x, int _y);

	//Присвоит координаты одной точки другой точке
	void operator = (Point dot);

	//Сравнение точек
	bool operator == (Point dot);
	bool operator != (Point dot);

	//+, -, *
	Point operator + (Point dot);
	Point operator - (Point dot);
	Point operator * (Point dot);

	void operator += (int Val);
	void operator -= (int Val);
	void operator *= (int Val);
	void operator ++ ();
	void operator -- ();
};

