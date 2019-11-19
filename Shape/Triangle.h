#pragma once
#include "Shape.h"
#include "Point.h"
#include "Quadrangle.h"


class Quadrangle;

class Triangle : Shape
{
private:
	Point A, B, C;
public:
	const std::string RECT = "Rectengular";
	const std::string ISO = "Isosceles";

	Triangle();
	~Triangle();
	//����������� ������� �������� �����������
	Triangle(Point _A, Point _B, Point _C);
	//����������� ������� ������������� ��� ��������������
	Triangle(Point _A, Point _B, std::string TypeTriangle);

	//�������� ����������� ��������
	void operator = (Triangle T2);

	//������
	Point GetA();
	Point GetB();
	Point GetC();
	void SetA(Point dot);
	void SetB(Point dot);
	void SetC(Point dot);

	//�������
	float Area() override;
	//��������
	float Perimeter() override;

	//����� ������� ����������� �� ������ �����
	float Median(Point dot);
	//����� ������ ����������� �� ������ �����
	float Height(Point dot);
	//����� ����������� ����������� �� ������ �����
	float Bisector(Point dot);
	//���� � ������ �����
	float Angle(Point dot);
	//����� �������
	float SideLen(char Num);
	//������� ��������������, ��������� �������� ������ �������
	Quadrangle Quad(char Num);
	//�������� �������������� ����� �����������
	bool Belong(Point dot);
};

