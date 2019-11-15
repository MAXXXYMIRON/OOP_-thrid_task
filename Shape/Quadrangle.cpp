#include "Quadrangle.h"



Quadrangle::Quadrangle()
{
	A = Point(0, 0);
	B = Point(0, 1);
	C = Point(1, 0);
	D = Point(1, 1);
}
Quadrangle::~Quadrangle()
{
}
//���������������
Quadrangle::Quadrangle(Point _A, Point _B, Point _D, Point _C)
{
	if (!DifferentCoordinate(_A, _B, _C, _D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(_A, _B, _C, _D)) throw OnOneStraight;

	A = _A;
	B = _B;
	D = _D;
	C = _C;
}
//������������� ��� ������������
Quadrangle::Quadrangle(Point _A, Point _B, Point _D)
{
	if (!DifferentCoordinate(_A, _B, _D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, B, C)) throw OnOneStraight;

	A = _A;
	B = _B;
	D = _D;
	C.x = A.x + D.x - B.x;
	C.y = A.y + B.y - D.y;
}
//�������
Quadrangle::Quadrangle(Point _A, Point _B)
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


//�������� ���� �������������� �������
void Quadrangle::operator = (Quadrangle Q2)
{
	A = Q2.A;
	B = Q2.B;
	C = Q2.C;
	D = Q2.D;
}


//������
Point Quadrangle::GetA()
{
	return A;
}
Point Quadrangle::GetB()
{
	return B;
}
Point Quadrangle::GetC()
{
	return C;
}
Point Quadrangle::GetD()
{
	return D;
}

void Quadrangle::SetA(Point dot)
{
	if (!DifferentCoordinate(dot, B, C, D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(dot, B, C, D)) throw OnOneStraight;
	A = dot;
}
void Quadrangle::SetB(Point dot)
{
	if (!DifferentCoordinate(A, dot, C, D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, dot, C, D)) throw OnOneStraight;
	B = dot;
}
void Quadrangle::SetC(Point dot)
{
	if (!DifferentCoordinate(A, B, dot, D)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, B, dot, D)) throw OnOneStraight;
	C = dot;
}
void Quadrangle::SetD(Point dot)
{
	if (!DifferentCoordinate(A, B, C, dot)) throw NotDifferentCoordinate;
	if (!NotOnOneStraight(A, B, C, dot)) throw OnOneStraight;
	D = dot;
}


//�������
float Quadrangle::Area()
{
	return abs(A.x * B.y + B.x * C.y + C.x * D.y + D.x * A.y 
			- B.x * A.y - C.x * B.y - D.x * C.y - A.x * D.y) / 2.0;
}
//��������
float Quadrangle::Perimeter()
{
	return Length(A, B) + Length(A, D) + Length(B, C) + Length(C, D);
}


//��������� ��������� �� ������ �����
float Quadrangle::Diagonal(Point dot)
{
	if (dot == A || dot == C)
		return Length(A, C);

	else if (dot == B || dot == D)
		return Length(B, D);

	else throw NotCornerPointFigure;
}


//���� ��������� �� ������ �����
float Quadrangle::Angle(Point dot)
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


//������ ������� 1, 2, 3 ��� 4
float Quadrangle::SideLen(char Num)
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


//������� ����������� ���������������� ����������� �� ������ �����
Triangle Quadrangle::Trian(Point dot)
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


//�������������� ����� ������
bool Quadrangle::Belong(Point dot)
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
