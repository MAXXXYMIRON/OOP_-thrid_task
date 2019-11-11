#pragma once
#include <iostream>
#include<stdlib.h>
#include "math.h"
#include <string>

class Point
{
public:
	int x, y;

	Point();
	~Point();
	Point(int _x, int _y);

	enum ERRORS
	{
		NotDifferentCoordinate, //�� ������ ���������� 
		OnOneStraight, //����� ����� �� ����� ������
		NoOnOneStraight, //����� �� ����� �� ����� ������
		NotASide, //��������� ����� ������� �� �������� ��������
		NotLieBoundaryCircle, //����� �� ����� �� ������� ����������
		IncorrectAngle, //���� ������ 180 ��������
		IncorrectTypeTriangle, //�� ������������ ��� ������������
		PointPerpendicularOneAxes, //����� ��������������� ����� �� ����
		ChordLongerDiametr, //����� ������� ��������
		NotCornerPointFigure //�� �������� ������� ������ ������
	};

	//�������� ���������� ����� ����� ������ �����
	void operator = (Point dot);

	//��������� �����
	bool operator == (Point dot);
	bool operator != (Point dot);

	//+, -, *
	Point operator + (Point dot);
	Point operator - (Point dot);
	Point operator * (Point dot);

	void operator += (int Val);
	void operator -= (int Val);
	void operator *= (int Val);
	void operator ++ ();
	void operator -- ();

protected:
	//�������������� ���������� �/� �������
	unsigned CathetHorizontal(Point dot1, Point dot2);
	//������������ ��������� �/� �������
	unsigned CathetVertical(Point dot1, Point dot2);
	//��������� �/� �������
	float Length(Point dot1, Point dot2);

	//�������� �� ����������� ��������� �����
	bool DifferentCoordinate(Point dot1, Point dot2, Point dot3, Point dot4);
	bool DifferentCoordinate(Point dot1, Point dot2, Point dot3);
	//����� ����� �� ����� ������
	bool NotOnOneStraight(Point dot1, Point dot2, Point dot3, Point dot4);
	//������� ��� ��������� �������������� ����� ������
	bool NotOnOneStraight(Point dot1, Point dot2, Point dot3);
};

