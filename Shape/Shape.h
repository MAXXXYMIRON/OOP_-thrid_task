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
	ZeroRadius, //������� ������
	ChordLongerDiametr, //����� ������� ��������
	HeightSegLongerRadius, //������ �������� ������� �������

	NotDifferentCoordinate, //�� ������ ���������� 
	OnOneStraight, //����� ����� �� ����� ������
	NoOnOneStraight, //����� �� ����� �� ����� ������

	NotASide, //��������� ����� ������� �� �������� ��������
	IncorrectTypeTriangle, //�� ������������ ��� ������������
	PointPerpendicularOneAxes, //����� ��������������� ����� �� ����
	NotCornerPointFigure //�� �������� ������� ������ ������
};


