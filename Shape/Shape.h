#pragma once
#include "Color.h"

class Shape
{
public:
	ColorShape *Coloring;
	Shape();
	~Shape();

	virtual float Area() = 0;
	virtual float Perimeter() = 0;
};

enum ERRORS
{
	NotLieBoundaryCircle, //Точка не лежит на границе окружности
	NotLieInCircle,  //Точка не лежит в окружности
	IncorrectAngle, //Угол больше 180 градусов
	IncorrectRadius, //Нулевой радиус
	ChordLongerDiametr, //Хорда длиньше диаметра
	HeightSegLongerRadius, //Высота сегмента длиньше радиуса

	NotDifferentCoordinate, //Не разные координаты 
	OnOneStraight, //Точки лежат на одной прямой

	NotASide, //Указанный номер стороны не является стороной
	IncorrectTypeTriangle, //Не существующий тип треугольника
	PointPerpendicularOneAxes, //Точки перпендикулярны одной из осей
	NotCornerPointFigure //Не является угловой точкой фигуры
};


