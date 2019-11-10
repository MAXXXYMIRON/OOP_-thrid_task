#pragma once
#include <iostream>
#include "math.h"
#include <string>

class Point
{
public:
	int x, y;

	Point();
	~Point();
	Point(int _x, int _y);

	enum ERRORS
	{
		NotDifferentCoordinate, //Не разные координаты 
		OnOneStraight, //Точки лежат на одной прямой
		NotASide, //Указанный номер стороны не является стороной
		NotCornerPointFigure //Не является угловой точкой фигуры
	};

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
	//Точки лежат на одной прямой
	bool NotOnOneStraight(Point dot1, Point dot2, Point dot3, Point dot4);
	//Формула для выяснения принадлежности точки прямой
	bool NotOnOneStraight(Point dot1, Point dot2, Point dot3);
};

