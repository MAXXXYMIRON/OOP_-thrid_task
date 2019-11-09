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
//���������������
Quadrengle::Quadrengle(Point _A, Point _B, Point _C, Point _D)
{
	A = _A;
	B = _B;
	C = _C;
	D = _D;
}
//������������� ��� ������������
Quadrengle::Quadrengle(Point _A, Point _B, Point _C)
{
	A = _A;
	B = _B;
	C = _C;
	D.x = A.x + C.x - B.x;
	D.y = A.y + C.y - B.y;
}
//�������
Quadrengle::Quadrengle(Point _A, Point _B)
{
	A = _A;
	B = _B;
	C.x = A.x + CathetHorizontal(A, B);
	C.y = A.y + CathetVertical(A, B);
	D.x = B.x + CathetHorizontal(A, B);
	D.y = B.y + CathetVertical(A, B);
}


//�������� ���� �������������� �������
void Quadrengle::operator = (Quadrengle Q2)
{
	A = Q2.A;
	B = Q2.B;
	C = Q2.C;
	D = Q2.D;
}


////�������
//float Quadrengle::Area()
//{
//
//}
////��������
//float Quadrengle::Perimetr()
//{
//
//}
////��������� ������� ������ ������ �����
//float Quadrengle::Diagonal(Point dot)
//{
//
//}
////���� ��������� �� ������ �����
//float Quadrengle::Angle(Point dot)
//{
//
//}
////������ ������� 1, 2, 3 ��� 4
//float Quadrengle::SideLen(char Num)
//{
//
//}
////������� ����������� ���������������� ����������� �� ������ �����
//Triangle Quadrengle::Triangle(Point dot)
//{
//
//}
////�������������� ����� ������
//bool Quadrengle::Belong(Point dot)
//{
//
//}
