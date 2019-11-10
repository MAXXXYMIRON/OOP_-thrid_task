#include "Circle.h"


Circle::Circle()
{
	r = Point(0, 1);
	O = Point(0, 0);
}
Circle::~Circle()
{
}
Circle::Circle(Point _r, Point _O)
{
	if (_r == _O) throw NotDifferentCoordinate;
	r = _r;
	O = _O;
}


//�������� ��������� �������
void Circle::operator = (Circle C2)
{
	r = C2.r;
	O = C2.O;
}


//������
Point Circle::GetR()
{
	return r;
}
Point Circle::GetO()
{
	return O;
}

void Circle::SetR(Point _r)
{
	if (_r == O) throw NotDifferentCoordinate;
	r = _r;
}
void Circle::SetO(Point _O)
{
	if (_O == r) throw NotDifferentCoordinate;
	O = _O;
}


//�������
float Circle::Area()
{
	return 3.14 * pow(Length(r, O), 2);
}
//��������
float Circle::Perimeter()
{
	return 2 * 3.14 * Length(r, O);
}
//�����������
float Circle::HalfArea()
{
	return Area() / 2;
}
//������������
float Circle::HalfPerimeter()
{
	return Perimeter() / 2;
}


//������
float Circle::Rad()
{
	return Length(r, O);
}
//�������
float Circle::Diameter()
{
	return 2 * Length(r, O);
}



////����� ����� �� �����, ������� �� ������ r O
//float Circle::LenChord(Point dot)
//{
//
//}

////����� ����� �� ���� ������ �� ����������
//float Circle::LenChord(Point dot1, Point dot2)
//{
//
//}

////����� ����� �� ����
//float Circle::LenChord(float Angle)
//{
//
//}

////����� ���� �� �����
//float Circle::LenArc(float LenChord)
//{
//
//}

////������� �������� �� �����
//float Circle::AreaSeg(float LenChord)
//{
//
//}

////�������� �������� �� �����
//float Circle::PerimetrSeg(float LenChord)
//{
//
//}

////���� �������� �� �����
//float Circle::AngleSeg(float LenChord)
//{
//
//}

////������ �������� �� ����� 
//float Circle::HeightSeg(float LenChord)
//{
//
//}

////�������� �������������� ����� �����������
//bool Circle::Belong(Point dot)
//{
//
//}