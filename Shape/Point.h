#pragma once
#include <iostream>
#include<stdlib.h>
#include "math.h"
#include <string>

class Point
{
public:
	float x, y;

	Point();
	~Point();
	Point(float _x, float _y);

	//��������� �����
	bool operator == (Point dot);
	bool operator != (Point dot);

	//+, -, *
	Point operator + (Point dot);
	Point operator - (Point dot);
	Point operator * (Point dot);

	void operator += (float Val);
	void operator -= (float Val);
	void operator *= (float Val);
	void operator ++ ();
	void operator -- ();
};


//�������������� ���������� �/� �������
float CathetHorizontal(Point dot1, Point dot2);
//������������ ��������� �/� �������
float CathetVertical(Point dot1, Point dot2);
//��������� �/� �������
float Length(Point dot1, Point dot2);

//�������� �� ����������� ��������� �����
bool DifferentCoordinate(Point dot1, Point dot2, Point dot3, Point dot4);
bool DifferentCoordinate(Point dot1, Point dot2, Point dot3);
//����� ����� �� ����� ������
bool NotOnOneStraight(Point dot1, Point dot2, Point dot3, Point dot4);
//������� ��� ��������� �������������� ����� ������
bool NotOnOneStraight(Point dot1, Point dot2, Point dot3);

