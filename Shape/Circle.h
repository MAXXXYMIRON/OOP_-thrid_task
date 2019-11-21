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

	//Присвоиь окружость текущей
	void operator = (Circle C2);

	//Доступ
	float GetR();
	Point GetO();
	void SetR(float _R);
	void SetO(Point _O);

	//Площадь
	float Area() override;
	//Периметр
	float Perimeter() override;

	//Полуплощадь
	float HalfArea();
	//Полупериметр
	float HalfPerimeter();
	//Диаметр
	float Diameter();

	//Длина хорды проведённая перпендикулярно радиусу, через данную точку
	float LenChord(Point dot);
    //Длина хорды по двум точкам на окружности
	float LenChord(Point dot1, Point dot2);
	//Длина хорды по углу
	float LenChord(float Angle);
	//Длина хорды по высоте сермента
	float LenChord(float Height, char flag);

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

