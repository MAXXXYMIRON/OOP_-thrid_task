#pragma once
#include "Shape.h"
#include "Point.h"
#include "Triangle.h"

class Triangle;
class Quadrengle;

class Quadrangle : public Shape 
{
private:
	Point A, B, C, D;
public:
	Quadrangle();
	~Quadrangle();
	//���������������
	Quadrangle(Point _A, Point _B, Point _D, Point _C);
	//������������� ��� ������������
	Quadrangle(Point _A, Point _B, Point _D);
	//�������
	Quadrangle(Point _A, Point _B);

	//������
	Point GetA();
	Point GetB();
	Point GetC();
	Point GetD();
	void SetA(Point dot);
	void SetB(Point dot);
	void SetC(Point dot);
	void SetD(Point dot);

	//�������� ���� �������������� �������
	void operator = (Quadrangle Q2);

	//�������
	float Area() override;
	//��������
	float Perimeter() override;

	//��������� ��������� �� ������ �����
	float Diagonal(Point dot);
	//���� ��������� �� ������ �����
	float Angle(Point dot);
	//������ ������� 1, 2, 3 ��� 4
	float SideLen(char Num);
	//������� ����������� ���������������� ����������� �� ������ �����
	Triangle Trian(Point dot);
	//�������������� ����� ������
	bool Belong(Point dot);
};

