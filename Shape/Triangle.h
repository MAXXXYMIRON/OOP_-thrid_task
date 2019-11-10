#pragma once
#include "Point.h"
#include "Quadrengle.h"

class Triangle : Point
{
private:
	Point A, B, C;
public:
	const std::string RECT = "Rectengular";
	const std::string ISO = "Isosceles";
	const std::string EQU = "Equilateral";

	Triangle();
	~Triangle();
	//Конструктор создаст заданный треугольник
	Triangle(Point _A, Point _B, Point _C);
	//Конструктор создаст прямоугольный, равнобедренный или равносторонний треугольник
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
	float Area();
	//Периметр
	float Perimeter();
	//Точка медианы к противополжной данной точке стороне
	Point Median(Point dot);
	//Точка высоты к противополжной данной точке стороне
	Point Height(Point dot);
	//Точка биссектрисы к противополжной данной точке стороне
	Point Bisector(Point dot);
	//Угол в данной точке
	float Angle(Point dot);
	//Длина стороны
	float SideLen(char Num);
	//Вернуть четырёхугольник, диагональ которого данная сторона
	Quadrengle Quad(char Num);
	//Выяснить принадлежность точки треугольику
	bool Belong(Point dot);
};

