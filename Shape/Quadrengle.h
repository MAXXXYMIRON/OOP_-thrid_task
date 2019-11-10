#pragma once
#include "Point.h"
#include "Triangle.h"


class Quadrengle : Point
{
private:
	Point A, B, C, D;
public:
	Quadrengle();
	~Quadrengle();
	//Четырехугольник
	Quadrengle(Point _A, Point _B, Point _D, Point _C);
	//Прямоугольник или праллерограм
	Quadrengle(Point _A, Point _B, Point _D);
	//Квадрат
	Quadrengle(Point _A, Point _B);

	//Доступ
	Point GetA();
	Point GetB();
	Point GetC();
	Point GetD();
	void SetA(Point dot);
	void SetB(Point dot);
	void SetC(Point dot);
	void SetD(Point dot);

	//Присвоит один четырёхугольник другому
	void operator = (Quadrengle Q2);

	//Площадь
	float Area();
	//Периметр
	float Perimeter();
	//Диагональ лежащая против данной точки
	float Diagonal(Point dot);
	//Угол исходящий из данной точки
	float Angle(Point dot);
	//Длинна стороны 1, 2, 3 или 4
	float SideLen(char Num);
	//Вернуть треугольник четырехугольника построенный из данной точки
	Triangle Trian(Point dot);
	//Принадлежность точки фигуре
	bool Belong(Point dot);

};

