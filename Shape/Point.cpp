#include "Point.h"


//������������
Point::Point()
{
	x = 0;
	y = 0;
}
Point::~Point()
{
}
Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}

//�������� ���������� ����� ����� ������ �����
void Point::operator = (Point dot)
{
	x = dot.x;
	y = dot.y;
}

//������� � ������� ��� ��������� �����
void Point::SetX(int _x)
{
	x = _x;
}
void Point::SetY(int _y)
{
	y = _y;
}
int Point::GetX()
{
	return x;
}
int Point::GetY()
{
	return y;
}

//�������������� ���������� �/� �������
unsigned Point::CathetHorizontal(Point dot1, Point dot2)
{
	return abs(dot2.x - dot1.x);
}
//������������ ��������� �/� �������
unsigned Point::CathetVertical(Point dot1, Point dot2)
{
	return abs(dot2.y - dot1.y);
}
//��������� �/� �������
float Point::Length(Point dot1, Point dot2)
{
	return sqrt(pow(CathetHorizontal(dot1, dot2), 2) + pow(CathetVertical(dot1, dot2), 2));
}
