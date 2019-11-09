#pragma once
#include "Point.h"
#include "Triangle.h"


class Quadrengle : Point
{
private:
	Point A, B, C, D;
public:
	Quadrengle();
	~Quadrengle();
	//���������������
	Quadrengle(Point _A, Point _B, Point _C, Point _D);
	//������������� ��� ������������
	Quadrengle(Point _A, Point _B, Point _C);
	//�������
	Quadrengle(Point _A, Point _B);

	//�������� ���� �������������� �������
	void operator = (Quadrengle Q2);

	//�������
	float Area();
	//��������
	float Perimetr();
	//��������� ������� ������ ������ �����
	float Diagonal(Point dot);
	//���� ��������� �� ������ �����
	float Angle(Point dot);
	//������ ������� 1, 2, 3 ��� 4
	float SideLen(char Num);
	//������� ����������� ���������������� ����������� �� ������ �����
	Triangle Triangle(Point dot);
	//�������������� ����� ������
	bool Belong(Point dot);
};

