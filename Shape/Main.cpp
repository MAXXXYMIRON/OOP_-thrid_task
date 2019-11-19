#include <iostream>
#include "Shape.h"
#include "Color.h"
#include "Point.h"
#include "Quadrangle.h"
#include "Triangle.h"
#include "Circle.h"

using namespace std;

void main()
{
	setlocale(0, "");

	try
	{
		cout << "ЧЕТЫРЕХУГОЛЬИК" << endl;
		Quadrangle Square = Quadrangle(Point(1, 3), Point(3, 1));
		cout << "Площадь = " << Square.Area() << endl;
		cout << "Периметр = " << Square.Perimeter() << endl;
		cout << "Диагональ AC = " << Square.Diagonal(Square.GetA()) << endl;
		cout << "Угол ABC = " << Square.Angle(Square.GetB()) << endl;
		cout << "Длина стороны АВ = " << Square.SideLen(1) << endl;
		if (Square.Belong(Point(3, 10))) cout << "Точка принадлежит\n";
		else  cout << "Точка не принадлежит\n";

		cout << "ТРЕУГОЛЬНИК" << endl;
		Triangle RectengularTriangle = Square.Trian(Square.GetC());
		cout << "Площадь = " << RectengularTriangle.Area() << endl;
		cout << "Периметр = " << RectengularTriangle.Perimeter() << endl;
		cout << "Длина медианы проведенная из точки В = " << RectengularTriangle.Median(RectengularTriangle.GetB()) << endl;
		cout << "Длина высоты проведенная из точки В = " << RectengularTriangle.Height(RectengularTriangle.GetB()) << endl;
		cout << "Длина биссектрисы проведенная из точки В = " << RectengularTriangle.Bisector(RectengularTriangle.GetB()) << endl;
		cout << "Угол АВС = " << RectengularTriangle.Angle(RectengularTriangle.GetB()) << endl;
		cout << "Длина стороны АС = " << RectengularTriangle.SideLen(3) << endl;
		if (RectengularTriangle.Belong(Point(4, 3))) cout << "Точка принадлежит\n";
		else  cout << "Точка не принадлежит\n";
		Quadrangle QuadAtTriangle = RectengularTriangle.Quad(1);

		cout << "ОКРУЖНОСТЬ" << endl;
		Circle Range = Circle(10, Point(0, 0));
		cout << "Площадь = " << Range.Area() << endl;
		cout << "Периметр = " << Range.Perimeter() << endl;
		cout << "Полуплощадь = " << Range.HalfArea() << endl;
		cout << "Полупериметр = " << Range.HalfPerimeter() << endl;
		cout << "Диаметр  = " << Range.Diameter() << endl;

		cout << "Длина хорды по точкам, лежащим на окр. = " << Range.LenChord(Point(0, 10), Point(10, 0)) << endl;
		cout << "Длина дуги по длине хорды = " << Range.LenArc(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;
		cout << "Площадь сегмента по длине хорды = " << Range.AreaSeg(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;
		cout << "Периметр сегмента по длине хорды = " << Range.PerimetrSeg(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;
		cout << "Угол сегмента по длине хорды = " << Range.AngleSeg(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;
		cout << "Высота сегмента по длине хорды = " << Range.HeightSeg(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;


		cout << "Длина хорды проведённая через данную точку перпендикулярно радиусу = " << Range.LenChord(Point(2, 2)) << endl;
	}
	catch(ERRORS e)
	{
		switch (e)
		{
		case NotLieBoundaryCircle:
			cout << "Точка не лежит на границе окружности" << endl;
			break;
		case NotLieInCircle:
			cout << "Точка не лежит в окружности" << endl;
			break;
		case IncorrectAngle:
			cout << "Угол сегмента больше 180 градусов" << endl;
			break;
		case IncorrectRadius:
			cout << "Указанный радиус равен нулю" << endl;
			break;
		case ChordLongerDiametr:
			cout << "Указанная хорда длиньше диаметра" << endl;
			break;
		case HeightSegLongerRadius:
			cout << "Указанная высота сегмента длинше радиуса" << endl;
			break;
		case NotDifferentCoordinate:
			cout << "Указанные координаты не являются разными" << endl;
			break;
		case OnOneStraight:
			cout << "Указанные точки лежат на одной прямой" << endl;
			break;
		case NotASide:
			cout << "Указанный номер стороны не существует" << endl;
			break;
		case IncorrectTypeTriangle:
			cout << "Указанный тип треугольника не существует" << endl;
			break;
		case PointPerpendicularOneAxes:
			cout << "Прямая проведенная через две указанные точки, перпендикулярна одной из координатных осей" << endl;
			break;
		case NotCornerPointFigure:
			cout << "Указанная точка не является угловой точкой данной фигуры" << endl;
			break;
		default:
			break;
		}
	}

	system("pause");
}