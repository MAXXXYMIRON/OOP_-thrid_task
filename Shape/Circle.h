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

	//Присвоиь окружость текущей
	void operator = (Circle C2);

	//Доступ
	Point GetR();
	Point GetO();
	void SetR(Point _r);
	void SetO(Point _O);

	//Площадь
	float Area();
	//Периметр
	float Perimeter();
	//Полуплощадь
	float HalfArea();
	//Полупериметр
	float HalfPerimeter();
	//Радиус
	float Rad();
	//Диаметр
	float Diameter();

	//Длина хорды по точке, лежащей на прямой r O
	float LenChord(Point dot);
    //Длина хорды по двум точкам на окружности
	float LenChord(Point dot1, Point dot2);
	//Длина хорды по углу
	float LenChord(float Angle);
	//Длина дуги по хорде
	float LenArc(float LenChord);
	//Площадь сегмента по хорде
	float AreaSeg(float LenChord);
	//Периметр сегмента по хорде
	float PerimetrSeg(float LenChord);
	//Угол сегмента по хорде
	float AngleSeg(float LenChord);
	//Высота сегмента по хорде 
	float HeightSeg(float LenChord);

	//Выяснить принадлежность точки треугольику
	bool Belong(Point dot);
};

