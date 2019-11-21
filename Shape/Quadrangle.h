#pragma once
#include "Shape.h"
#include "Point.h"
#include "Triangle.h"

class Triangle;
class Quadrengle;

class Quadrangle : public Shape 
{
private:
	Point A, B, C, D;
public:
	Quadrangle();
	~Quadrangle();
	//Четырехугольник
	Quadrangle(Point _A, Point _B, Point _D, Point _C);
	//Прямоугольник или праллерограм
	Quadrangle(Point _A, Point _B, Point _D);
	//Квадрат
	Quadrangle(Point _A, Point _B);

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
	void operator = (Quadrangle Q2);

	//Площадь
	float Area() override;
	//Периметр
	float Perimeter() override;

	//Диагональ исходящая из данной точки
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

