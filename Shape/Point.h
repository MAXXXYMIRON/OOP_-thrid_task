#pragma once
class Point
{
protected:
	int x, y;

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

