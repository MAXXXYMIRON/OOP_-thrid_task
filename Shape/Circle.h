#pragma once
#include "Shape.h"
#include "Point.h"


class Circle : public Shape
{
private:
	float R;
	Point O;
public:
	Circle();
	~Circle();
	Circle(float _R, Point _O);

	//�������� ��������� �������
	void operator = (Circle C2);

	//������
	float GetR();
	Point GetO();
	void SetR(float _R);
	void SetO(Point _O);

	//�������
	float Area() override;
	//��������
	float Perimeter() override;

	//�����������
	float HalfArea();
	//������������
	float HalfPerimeter();
	//�������
	float Diameter();

	//����� ����� ���������� ��������������� �������, ����� ������ �����
	float LenChord(Point dot);
    //����� ����� �� ���� ������ �� ����������
	float LenChord(Point dot1, Point dot2);
	//����� ����� �� ����
	float LenChord(float Angle);
	//����� ����� �� ������ ��������
	float LenChord(float Height, char flag);

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

