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



//����� ����� �� �����, ������� �� ������ r O
float Circle::LenChord(Point dot)
{
	if (NotOnOneStraight(r, O, dot)) throw NoOnOneStraight;
	return 2 * sqrt(pow(Rad(), 2) * pow(Rad() - Length(dot, r), 2));
}

//����� ����� �� ���� ������ �� ����������
float Circle::LenChord(Point dot1, Point dot2)
{
	if ((Rad() != Length(dot1, O)) && (Rad() != Length(dot2, O))) throw NotLieBoundaryCircle;
	return Length(dot1, dot2);
}

//����� ����� �� ����
float Circle::LenChord(float Angle)
{
	if (Angle > 180) throw IncorrectAngle;
	return 2 * Rad() * sin((Angle / 2.0) * 3.14 / 180);
}

//����� ���� �� �����
float Circle::LenArc(float LenChord)
{
	if (LenChord > Diameter()) throw ChordLongerDiametr;
	return Rad() * AngleSeg(LenChord) * 3.14 / 180;
}

//������� �������� �� �����
float Circle::AreaSeg(float LenChord)
{
	if (LenChord > Diameter()) throw ChordLongerDiametr;
	return pow(Rad(), 2) * ((AngleSeg(LenChord) * 3.14 / 180) - (sin(AngleSeg(LenChord) * 3.14 / 180))) / 2;
}

//�������� �������� �� �����
float Circle::PerimetrSeg(float LenChord)
{
	if (LenChord > Diameter()) throw ChordLongerDiametr;
	return LenChord + LenArc(LenChord);
}

//���� �������� �� �����
float Circle::AngleSeg(float LenChord)
{
	if (LenChord > Diameter()) throw ChordLongerDiametr;
	return asin(LenChord / Rad()) * 180 / 3.14;
}

//������ �������� �� ����� 
float Circle::HeightSeg(float LenChord)
{
	if (LenChord > Diameter()) throw ChordLongerDiametr;
	return Rad() * (1 - cos(AngleSeg(LenChord) / 2  * 3.14 / 180));
}

//�������� �������������� ����� �����������
bool Circle::Belong(Point dot)
{
	return (Length(O, dot) <= Rad()) ? true : false;
}