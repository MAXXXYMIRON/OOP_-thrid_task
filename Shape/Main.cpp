#include "Point.h"
#include "Quadrengle.h"
#include "Triangle.h"
#include "Circle.h"

using namespace std;

void main()
{
	setlocale(0, "");

	Quadrengle x(Point(1, 2), Point(1, 4));

	cout << x.Angle(x.GetA()) << endl;
	cout << x.Angle(x.GetB()) << endl;
	cout << x.Angle(x.GetC()) << endl;
	cout << x.Angle(x.GetD()) << endl << endl;

	system("pause");
}