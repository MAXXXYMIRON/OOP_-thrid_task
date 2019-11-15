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

//Конструктор создаст прямоугольный или равнобедренный
Triangle::Triangle(Point _A, Point _B, std::string TypeTriangle)
{
	if (_A == _B) throw NotDifferentCoordinate;
	if ((_A.x == _B.x) || (_A.y == _B.y)) throw PointPerpendicularOneAxes;

	A = _A;
	B = _B;

	if (TypeTriangle == RECT)
	{
		C.x = (A.y > B.y) ? A.x : B.x;
		C.y = (A.y < B.y) ? A.y : B.y;
	}

	else if (TypeTriangle == ISO)
	{
		C.x = (A.y > B.y) 
			? (A.x > B.x) ? A.x + CathetHorizontal(A, B) : A.x - CathetHorizontal(A, B)
			: (B.x > A.x) ? B.x + CathetHorizontal(A, B) : B.x - CathetHorizontal(A, B);

		C.y = (A.y < B.y) ? A.y : B.y;
	}

	else
		throw IncorrectTypeTriangle;
}

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


//Точка медианы к противополжной данной точке стороне
float Triangle::Median(Point dot)
{
	if (dot == A)
	{
		return sqrt(2 * pow(Length(A, B), 2) + 2 * pow(Length(A, C), 2) - Length(B, C)) / 2.0;
	}
	else if (dot == B)
	{
		return sqrt(2 * pow(Length(B, C), 2) + 2 * pow(Length(B, A), 2) - Length(A, C)) / 2.0;
	}
	else if (dot == C)
	{
		return sqrt(2 * pow(Length(C, A), 2) + 2 * pow(Length(C, B), 2) - Length(A, B)) / 2.0;
	}

	else throw NotCornerPointFigure;
}

//Точка высоты к противополжной данной точке стороне
float Triangle::Height(Point dot)
{
	float p = Perimeter() / 2;

	if (dot == A)
	{
		return (2 * sqrt(p * (p - Length(A, B)) * (p - Length(C, B)) * (p - Length(A, C)))) / Length(B, C);
	}
	else if (dot == B)
	{
		return (2 * sqrt(p * (p - Length(A, B)) * (p - Length(C, B)) * (p - Length(A, C)))) / Length(A, C);
	}
	else if (dot == C)
	{
		return (2 * sqrt(p * (p - Length(A, B)) * (p - Length(C, B)) * (p - Length(A, C)))) / Length(A, B);
	}

	else throw NotCornerPointFigure;
}

//Точка биссектрисы к противополжной данной точке стороне
float Triangle::Bisector(Point dot)
{
	float p = Perimeter() / 2;

	if (dot == A)
	{
		return (2 * sqrt(Length(A, B) * Length(A, C) * p * (p - Length(C, B)))) / (Length(A, B) + Length(A, C));
	}
	else if (dot == B)
	{
		return (2 * sqrt(Length(B, C) * Length(B, A) * p * (p - Length(A, C)))) / (Length(B, C) + Length(B, A));
	}
	else if (dot == C)
	{
		return (2 * sqrt(Length(C, A) * Length(C, B) * p * (p - Length(A, B)))) / (Length(C, A) + Length(C, B));
	}

	else throw NotCornerPointFigure;
}


//Угол в данной точке
float Triangle::Angle(Point dot)
{
	if (dot != A && dot != B && dot != C) throw NotCornerPointFigure;

	float Cos = 0;
	if (dot == A)
	{
		Cos = (pow(Length(A, B), 2) + pow(Length(A, C), 2) - pow(Length(C, B), 2))
			/ 2 * Length(A, B) * Length(A, C);
	}
	else if (dot == B)
	{
		Cos = (pow(Length(A, B), 2) + pow(Length(B, C), 2) - pow(Length(A, C), 2))
			/ 2 * Length(A, B) * Length(B, C);
	}
	else if (dot == C)
	{
		Cos = (pow(Length(C, B), 2) + pow(Length(C, A), 2) - pow(Length(A, B), 2))
			/ 2 * Length(C, B) * Length(C, A);
	}
	return acos(Cos) * 180 / 3.14;
}


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


//Вернуть четырёхугольник, диагональ которого данная сторона
Quadrangle Triangle::Quad(char Num)
{
	if (Num != 1 && Num != 2 && Num != 3) throw NotASide;
	switch (Num)
	{
		case 1:
		{
			return Quadrangle(C, A, B);
		}
		break;

		case 2:
		{
			return Quadrangle(A, B, C);
		}
		break;

		case 3:
		{
			return Quadrangle(B, A, C);
		}
		break;
	}
}


//Выяснить принадлежность точки треугольику
bool Triangle::Belong(Point dot)
{
	float result = 0;

	Triangle Temp(A, B, dot);
	result += Temp.Area();
	Temp = Triangle(A, C, dot);
	result += Temp.Area();
	Temp = Triangle(C, B, dot);
	result += Temp.Area();

	return (result == Area()) ? true : false;
}
