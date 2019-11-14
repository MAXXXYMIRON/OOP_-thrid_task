#pragma once
#include "Color.h"

class Shape
{
public:
	ColorShape *Coloring;
	Shape();
	~Shape();

	virtual float Area() = 0;
	virtual float Perimeter() = 0;
};

enum ERRORS
{
	NotLieBoundaryCircle, //����� �� ����� �� ������� ����������
	NotLieInCircle,  //����� �� ����� � ����������
	IncorrectAngle, //���� ������ 180 ��������
	IncorrectRadius, //������� ������
	ChordLongerDiametr, //����� ������� ��������
	HeightSegLongerRadius, //������ �������� ������� �������

	NotDifferentCoordinate, //�� ������ ���������� 
	OnOneStraight, //����� ����� �� ����� ������

	NotASide, //��������� ����� ������� �� �������� ��������
	IncorrectTypeTriangle, //�� ������������ ��� ������������
	PointPerpendicularOneAxes, //����� ��������������� ����� �� ����
	NotCornerPointFigure //�� �������� ������� ������ ������
};


