#pragma once
#include "Shape.h"
#include "Point.h"

#include "Quadrengle.h"

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

	//Точка медианы к противополжной данной точке стороне
	float Median(Point dot);
	//Точка высоты к противополжной данной точке стороне
	float Height(Point dot);
	//Точка биссектрисы к противополжной данной точке стороне
	float Bisector(Point dot);
	//Угол в данной точке
	float Angle(Point dot);
	//Длина стороны
	float SideLen(char Num);
	//Вернуть четырёхугольник, диагональ которого данная сторона
	Quadrengle Quad(char Num);
	//Выяснить принадлежность точки треугольику
	bool Belong(Point dot);
};

