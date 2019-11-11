#include "Quadrengle.h"



Quadrengle::Quadrengle()
{
	A = Point(0, 0);
	B = Point(0, 1);
	C = Point(1, 0);
	D = Point(1, 1);
}
Quadrengle::~Quadrengle()
{
}
//Четырехугольник
Quadrengle::Quadrengle(Point _A, Point _B, Point _D, Point _C)
{
	if (!DifferentCoordinate(_A, _B, _C, _D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(_A, _B, _C, _D)) throw OnOneStraight;

	A = _A;
	B = _B;
	D = _D;
	C = _C;
}
//Прямоугольник или праллерограм
Quadrengle::Quadrengle(Point _A, Point _B, Point _D)
{
	if (!DifferentCoordinate(_A, _B, _D)) throw NotDifferentCoordinate;

	A = _A;
	B = _B;
	D = _D;
	C.x = A.x + D.x - B.x;
	C.y = A.y + B.y - D.y;

	if (!NotOnOneStraight(A, B, C, D)) throw OnOneStraight;
}
//Квадрат
Quadrengle::Quadrengle(Point _A, Point _B)
{
	if (_A == _B) throw NotDifferentCoordinate;
	A = _A;
	B = _B;

	C.x = B.x + CathetVertical(A, B);
	D.x = A.x + CathetVertical(A, B);

	if (((A.x <= B.x) && (A.y >= B.y)) || ((A.x >= B.x) && (A.y <= B.y)))
	{
		C.y = B.y + CathetHorizontal(A, B);
		D.y = A.y + CathetHorizontal(A, B);
	}
	else
	{
		C.y = B.y - CathetHorizontal(A, B);
		D.y = A.y - CathetHorizontal(A, B);
	}
}


//Присвоит один четырёхугольник другому
void Quadrengle::operator = (Quadrengle Q2)
{
	A = Q2.A;
	B = Q2.B;
	C = Q2.C;
	D = Q2.D;
}


//Доступ
Point Quadrengle::GetA()
{
	return A;
}
Point Quadrengle::GetB()
{
	return B;
}
Point Quadrengle::GetC()
{
	return C;
}
Point Quadrengle::GetD()
{
	return D;
}

void Quadrengle::SetA(Point dot)
{
	if (!DifferentCoordinate(dot, B, C, D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(dot, B, C, D)) throw OnOneStraight;
	A = dot;
}
void Quadrengle::SetB(Point dot)
{
	if (!DifferentCoordinate(A, dot, C, D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, dot, C, D)) throw OnOneStraight;
	B = dot;
}
void Quadrengle::SetC(Point dot)
{
	if (!DifferentCoordinate(A, B, dot, D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, B, dot, D)) throw OnOneStraight;
	C = dot;
}
void Quadrengle::SetD(Point dot)
{
	if (!DifferentCoordinate(A, B, C, dot)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, B, C, dot)) throw OnOneStraight;
	D = dot;
}


//Площадь
float Quadrengle::Area()
{
	return abs(A.x * B.y + B.x * C.y + C.x * D.y + D.x * A.y 
			- B.x * A.y - C.x * B.y - D.x * C.y - A.x * D.y) / 2.0;
}
//Периметр
float Quadrengle::Perimeter()
{
	return Length(A, B) + Length(A, D) + Length(B, C) + Length(C, D);
}


//Диагональ лежащая против данной точки
float Quadrengle::Diagonal(Point dot)
{
	if (dot == A || dot == C)
		return Length(B, D);

	else if (dot == B || dot == D)
		return Length(A, C);

	else throw NotCornerPointFigure;
}


//Угол исходящий из данной точки
float Quadrengle::Angle(Point dot)
{
	if (dot != A && dot != B && dot != C && dot != D) throw NotCornerPointFigure;

	float Cos = 0;
	if (dot == A)
	{
		Cos = (pow(Length(A, B), 2) + pow(Length(A, D), 2) - pow(Length(D, B), 2)) 
			/ 2 * Length(A, B) * Length(A, D);
	}
	else if (dot == B)
	{
		Cos = (pow(Length(A, B), 2) + pow(Length(B, C), 2) - pow(Length(D, C), 2))
			/ 2 * Length(A, B) * Length(B, C);
	}
	else if (dot == C)
	{
		Cos = (pow(Length(C, B), 2) + pow(Length(C, D), 2) - pow(Length(D, B), 2))
			/ 2 * Length(C, B) * Length(C, D);
	}
	else if (dot == D)
	{
		Cos = (pow(Length(A, D), 2) + pow(Length(D, C), 2) - pow(Length(A, C), 2))
			/ 2 * Length(A, D) * Length(D, C);
	}
	return acos(Cos) * 180 / 3.14;
}


//Длинна стороны 1, 2, 3 или 4
float Quadrengle::SideLen(char Num)
{
	if (Num != 1 && Num != 2 && Num != 3 && Num != 4) throw NotASide;

	switch (Num)
	{
	case 1:
		return Length(A, B);
		break;

	case 2:
		return Length(A, D);
		break;

	case 3:
		return Length(B, C);
		break;

	case 4:
		return Length(C, D);
		break;
	}
}


//Вернуть треугольник четырехугольника построенный из данной точки
Triangle Quadrengle::Trian(Point dot)
{
	if (dot == A)
		return Triangle(B, A, D);

	else if (dot == B)
		return Triangle(A, B, C);

	else if (dot == C)
		return Triangle(B, C, D);

	else if (dot == D)
		return Triangle(A, D, C);

	else throw NotCornerPointFigure;
}


//Принадлежность точки фигуре
bool Quadrengle::Belong(Point dot)
{
	float result = 0;

	Triangle Temp(A, B, dot);
	result += Temp.Area();
	Temp = Triangle(A, D, dot);
	result += Temp.Area();
	Temp = Triangle(C, D, dot);
	result += Temp.Area();
	Temp = Triangle(C, B, dot);
	result += Temp.Area();

	return (result == Area()) ? true : false;
}
