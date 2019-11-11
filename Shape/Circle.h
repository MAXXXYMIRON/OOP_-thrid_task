#pragma once
#include "Point.h"

class Circle : Point
{
private:
	Point r, O;
public:
	Circle();
	~Circle();
	Circle(Point _r, Point _O);

	//�������� ��������� �������
	void operator = (Circle C2);

	//������
	Point GetR();
	Point GetO();
	void SetR(Point _r);
	void SetO(Point _O);

	//�������
	float Area();
	//��������
	float Perimeter();
	//�����������
	float HalfArea();
	//������������
	float HalfPerimeter();
	//������
	float Rad();
	//�������
	float Diameter();

	//����� ����� �� �����, ������� �� ������ r O
	float LenChord(Point dot);
    //����� ����� �� ���� ������ �� ����������
	float LenChord(Point dot1, Point dot2);
	//����� ����� �� ����
	float LenChord(float Angle);
	//����� ���� �� �����
	float LenArc(float LenChord);
	//������� �������� �� �����
	float AreaSeg(float LenChord);
	//�������� �������� �� �����
	float PerimetrSeg(float LenChord);
	//���� �������� �� �����
	float AngleSeg(float LenChord);
	//������ �������� �� ����� 
	float HeightSeg(float LenChord);

	//�������� �������������� ����� �����������
	bool Belong(Point dot);
};

