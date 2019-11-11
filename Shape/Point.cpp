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


//��������� �����
bool Point::operator == (Point dot)
{
	return (x == dot.x && y == dot.y) ? true : false;
}
bool Point::operator != (Point dot)
{
	return (x != dot.x || y != dot.y) ? true : false;
}


Point Point::operator + (Point dot)
{
	Point Res;
	Res.x = x + dot.x;
	Res.y = y + dot.y;
	return Res;
}
Point Point::operator - (Point dot)
{
	Point Res;
	Res.x = x - dot.x;
	Res.y = y - dot.y;
	return Res;
}
Point Point::operator * (Point dot)
{
	Point Res;
	Res.x = x * dot.x;
	Res.y = y * dot.y;
	return Res;
}


void Point::operator += (int Val)
{
	x += Val;
	y += Val;
}
void Point::operator -= (int Val)
{
	x -= Val;
	y -= Val;
}
void Point::operator *= (int Val)
{
	x *= Val;
	y *= Val;
}
void Point::operator ++ ()
{
	x++;
	y++;
}
void Point::operator -- ()
{
	x--;
	y--;
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


//�������� �� �������� ��������� �����
bool Point::DifferentCoordinate(Point dot1, Point dot2, Point dot3, Point dot4)
{
	return ((dot1 != dot2) && (dot1 != dot3) && (dot1 != dot4)
		&& (dot2 != dot3) && (dot2 != dot4) && (dot3 != dot4))
		? true 
		: false;
}
bool Point::DifferentCoordinate(Point dot1, Point dot2, Point dot3)
{
	return ((dot1 != dot2) && (dot1 != dot3) && (dot2 != dot3)) ? true : false;
}

//����� ����� �� ����� ������
bool Point::NotOnOneStraight(Point dot1, Point dot2, Point dot3, Point dot4)
{
	if (!NotOnOneStraight(dot1, dot2, dot3)) return false;
	if (!NotOnOneStraight(dot1, dot2, dot4)) return false;
	if (!NotOnOneStraight(dot1, dot3, dot4)) return false;
	if (!NotOnOneStraight(dot2, dot3, dot4)) return false;
	return true;
}

//������� ��� ��������� �������������� ����� ������
bool Point::NotOnOneStraight(Point dot1, Point dot2, Point dot3)
{
	return (((dot2.x - dot3.x) * (dot1.y - dot3.y)) == ((dot1.x - dot3.x) * (dot2.y - dot3.y))) 
		? false
		: true;
}