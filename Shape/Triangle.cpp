#include "Triangle.h"


Triangle::Triangle()
{
	A = Point(0, 0);
	B = Point(0, 2);
	C = Point(1, 2);
}
Triangle::~Triangle()
{
}

//Конструктор создаст заданный треугольник
Triangle::Triangle(Point _A, Point _B, Point _C)
{
	if (!DifferentCoordinate(_A, _B, _C)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(_A, _B, _C)) throw OnOneStraight;
	A = _A;
	B = _B;
	C = _C;
}

////Конструктор создаст прямоугольный, равнобедренный или равносторонний треугольник
//Triangle::Triangle(Point _A, Point _B, std::string TypeTriangle)
//{
//
//}

//Присвоит треугольник текущему
void Triangle::operator = (Triangle T2)
{
	A = T2.A;
	B = T2.B;
	C = T2.C;
}

//Доступ
Point Triangle::GetA()
{
	return A;
}
Point Triangle::GetB()
{
	return B;
}
Point Triangle::GetC()
{
	return C;
}

void Triangle::SetA(Point dot)
{
	if (!DifferentCoordinate(dot, B, C)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(dot, B, C)) throw OnOneStraight;
	A = dot;
}
void Triangle::SetB(Point dot)
{
	if (!DifferentCoordinate(A, dot, C)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, dot, C)) throw OnOneStraight;
	B = dot;
}
void Triangle::SetC(Point dot)
{
	if (!DifferentCoordinate(A, B, dot)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, B, dot)) throw OnOneStraight;
	C = dot;
}

//Площадь
float Triangle::Area()
{
	return
		(((A.x - C.x) * (B.y - C.y)) - ((B.x - C.x) * (A.y - C.y))) / 2;
}
//Периметр
float Triangle::Perimeter()
{
	return Length(A, B) + Length(B, C) + Length(C, A);
}


////Точка медианы к противополжной данной точке стороне
//Point Triangle::Median(Point dot)
//{
//	if (dot == A)
//	{
//
//	}
//	else if (dot == B)
//	{
//
//	}
//	else if (dot == C)
//	{
//
//	}
//
//	else throw NotCornerPointFigure;
//}

////Точка высоты к противополжной данной точке стороне
//Point Triangle::Height(Point dot)
//{
//	if (dot == A)
//	{
//
//	}
//	else if (dot == B)
//	{
//
//	}
//	else if (dot == C)
//	{
//
//	}
//
//	else throw NotCornerPointFigure;
//}

////Точка биссектрисы к противополжной данной точке стороне
//Point Triangle::Bisector(Point dot)
//{
//	if (dot == A)
//	{
//
//	}
//	else if (dot == B)
//	{
//
//	}
//	else if (dot == C)
//	{
//
//	}
//
//	else throw NotCornerPointFigure;
//}


////Угол в данной точке
//float Triangle::Angle(Point dot)
//{
//	if (dot != A && dot != B && dot != C) throw NotCornerPointFigure;
//}


//Длина стороны
float Triangle::SideLen(char Num)
{
	if (Num != 1 && Num != 2 && Num != 3) throw NotASide;
	switch (Num)
	{
	case 1:
		return Length(A, B);
		break;

	case 2:
		return Length(A, C);
		break;

	case 3:
		return Length(B, C);
		break;
	}
}


////Вернуть четырёхугольник, диагональ которого данная сторона
//Quadrengle Triangle::Quad(char Num)
//{
//	if (Num != 1 && Num != 2 && Num != 3) throw NotASide;
//	switch (Num)
//	{
//		case 1:
//		{
//
//		}
//		break;
//
//		case 2:
//		{
//
//		}
//		break;
//
//		case 3:
//		{
//
//		}
//		break;
//	}
//}


////Выяснить принадлежность точки треугольику
//bool Triangle::Belong(Point dot)
//{
//
//}
