#pragma once
#include "Shape.h"
#include "Point.h"
#include "Quadrangle.h"


class Quadrangle;

class Triangle : Shape
{
private:
	Point A, B, C;
public:
	const std::string RECT = "Rectengular";
	const std::string ISO = "Isosceles";

	Triangle();
	~Triangle();
	//Конструктор создаст заданный треугольник
	Triangle(Point _A, Point _B, Point _C);
	//Конструктор создаст прямоугольный или равнобедренный
	Triangle(Point _A, Point _B, std::string TypeTriangle);

	//Присвоит треугольник текущему
	void operator = (Triangle T2);

	//Доступ
	Point GetA();
	Point GetB();
	Point GetC();
	void SetA(Point dot);
	void SetB(Point dot);
	void SetC(Point dot);

	//Площадь
	float Area() override;
	//Периметр
	float Perimeter() override;

	//Длина медианы проведенной из данной точки
	float Median(Point dot);
	//Длина высоты проведенной из данной точки
	float Height(Point dot);
	//Длина биссектрисы проведенной из данной точки
	float Bisector(Point dot);
	//Угол в данной точке
	float Angle(Point dot);
	//Длина стороны
	float SideLen(char Num);
	//Вернуть четырёхугольник, диагональ которого данная сторона
	Quadrangle Quad(char Num);
	//Выяснить принадлежность точки треугольику
	bool Belong(Point dot);
};

