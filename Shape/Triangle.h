#pragma once
#include "Point.h"
#include "Quadrengle.h"

class Triangle : Point
{
private:
	Point A, B, C;
public:
	const std::string RECT = "Rectengular";
	const std::string ISO = "Isosceles";
	const std::string EQU = "Equilateral";

	Triangle();
	~Triangle();
	//����������� ������� �������� �����������
	Triangle(Point _A, Point _B, Point _C);
	//����������� ������� �������������, �������������� ��� �������������� �����������
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
	float Area();
	//��������
	float Perimeter();
	//����� ������� � �������������� ������ ����� �������
	Point Median(Point dot);
	//����� ������ � �������������� ������ ����� �������
	Point Height(Point dot);
	//����� ����������� � �������������� ������ ����� �������
	Point Bisector(Point dot);
	//���� � ������ �����
	float Angle(Point dot);
	//����� �������
	float SideLen(char Num);
	//������� ��������������, ��������� �������� ������ �������
	Quadrengle Quad(char Num);
	//�������� �������������� ����� �����������
	bool Belong(Point dot);
};

