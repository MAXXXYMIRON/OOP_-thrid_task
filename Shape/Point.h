#pragma once
#include <iostream>
#include "math.h"

class Point
{
protected:
	int x, y;

	unsigned CathetHorizontal(Point dot1, Point dot2);
	unsigned CathetVertical(Point dot1, Point dot2);
	float Length(Point dot1, Point dot2);

public:
	Point();
	~Point();
	Point(int _x, int _y);

	void operator = (Point dot);

	void SetX(int _x);
	void SetY(int _y);
	int GetX();
	int GetY();
};

