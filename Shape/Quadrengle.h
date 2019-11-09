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
	Quadrengle(Point _A, Point _B, Point _C, Point _D);
	//Прямоугольник или праллерограм
	Quadrengle(Point _A, Point _B, Point _C);
	//Квадрат
	Quadrengle(Point _A, Point _B);

	//Присвоит один четырёхугольник другому
	void operator = (Quadrengle Q2);

	//Площадь
	float Area();
	//Периметр
	float Perimetr();
	//Диагональ лежащая против данной точки
	float Diagonal(Point dot);
	//Угол исходящий из данной точки
	float Angle(Point dot);
	//Длинна стороны 1, 2, 3 или 4
	float SideLen(char Num);
	//Вернуть треугольник четырехугольника построенный из данной точки
	Triangle Triangle(Point dot);
	//Принадлежность точки фигуре
	bool Belong(Point dot);
};

