#include "Quadrengle.h"



Quadrengle::Quadrengle()
{
	A = Point(0, 0);
	B = Point(0, 1);
	C = Point(1, 0);
	D = Point(1, 1);
}
Quadrengle::~Quadrengle()
{
}
//Четырехугольник
Quadrengle::Quadrengle(Point _A, Point _B, Point _C, Point _D)
{
	A = _A;
	B = _B;
	C = _C;
	D = _D;
}
//Прямоугольник или праллерограм
Quadrengle::Quadrengle(Point _A, Point _B, Point _C)
{
	A = _A;
	B = _B;
	C = _C;
	D.x = A.x + C.x - B.x;
	D.y = A.y + C.y - B.y;
}
//Квадрат
Quadrengle::Quadrengle(Point _A, Point _B)
{
	A = _A;
	B = _B;
	C.x = A.x + CathetHorizontal(A, B);
	C.y = A.y + CathetVertical(A, B);
	D.x = B.x + CathetHorizontal(A, B);
	D.y = B.y + CathetVertical(A, B);
}


//Присвоит один четырёхугольник другому
void Quadrengle::operator = (Quadrengle Q2)
{
	A = Q2.A;
	B = Q2.B;
	C = Q2.C;
	D = Q2.D;
}


////Площадь
//float Quadrengle::Area()
//{
//
//}
////Периметр
//float Quadrengle::Perimetr()
//{
//
//}
////Диагональ лежащая против данной точки
//float Quadrengle::Diagonal(Point dot)
//{
//
//}
////Угол исходящий из данной точки
//float Quadrengle::Angle(Point dot)
//{
//
//}
////Длинна стороны 1, 2, 3 или 4
//float Quadrengle::SideLen(char Num)
//{
//
//}
////Вернуть треугольник четырехугольника построенный из данной точки
//Triangle Quadrengle::Triangle(Point dot)
//{
//
//}
////Принадлежность точки фигуре
//bool Quadrengle::Belong(Point dot)
//{
//
//}
