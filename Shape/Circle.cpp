#include "Circle.h"


Circle::Circle()
{
	R = 1;
	O = Point(0, 0);
}
Circle::~Circle()
{
}
Circle::Circle(float _R, Point _O)
{
	if (_R == 0) throw ZeroRadius;
	R = _R;
	O = _O;
}


//�������� ��������� �������
void Circle::operator = (Circle C2)
{
	R = C2.R;
	O = C2.O;
}


//������
float Circle::GetR()
{
	return R;
}
Point Circle::GetO()
{
	return O;
}

void Circle::SetR(float _R)
{
	if (_R == 0) throw ZeroRadius;
	R = _R;
}
void Circle::SetO(Point _O)
{
	O = _O;
}


//�������
float Circle::Area()
{
	return 3.14 * pow(R, 2);
}
//��������
float Circle::Perimeter()
{
	return 2 * 3.14 * R;
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


//�������
float Circle::Diameter()
{
	return 2 * R;
}



//����� ����� �� �����, ������� �� ������ r O
float Circle::LenChord(Point dot) 
{
	if (Belong(dot)) throw NotLieInCircle;
	return 2 * sqrt(pow(R, 2) * pow(Length(dot, O), 2));
}

//����� ����� �� ���� ������ �� ����������
float Circle::LenChord(Point dot1, Point dot2)
{
	if ((R != Length(dot1, O)) && (R != Length(dot2, O))) throw NotLieBoundaryCircle;
	return Length(dot1, dot2);
}

//����� ����� �� ����
float Circle::LenChord(float Angle)
{
	if (Angle > 180) throw IncorrectAngle;
	return 2 * R * sin((Angle / 2.0) * 3.14 / 180);
}

//����� ����� �� ������ ��������
float Circle::LenChord(float Height, char flag)
{
	if (Height > R) throw HeightSegLongerRadius;
	return 2 * sqrt(pow(R, 2) * pow(R - Height, 2));
}



//����� ���� �� �����
float Circle::LenArc(float LenChord)
{
	if (LenChord > Diameter()) throw ChordLongerDiametr;
	return R * AngleSeg(LenChord) * 3.14 / 180;
}

//������� �������� �� �����
float Circle::AreaSeg(float LenChord)
{
	if (LenChord > Diameter()) throw ChordLongerDiametr;
	return pow(R, 2) * ((AngleSeg(LenChord) * 3.14 / 180) - (sin(AngleSeg(LenChord) * 3.14 / 180))) / 2;
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
	return asin(LenChord / R) * 180 / 3.14;
}

//������ �������� �� ����� 
float Circle::HeightSeg(float LenChord)
{
	if (LenChord > Diameter()) throw ChordLongerDiametr;
	return R * (1 - cos(AngleSeg(LenChord) / 2  * 3.14 / 180));
}

//�������� �������������� ����� �����������
bool Circle::Belong(Point dot)
{
	return (Length(O, dot) <= R) ? true : false;
}