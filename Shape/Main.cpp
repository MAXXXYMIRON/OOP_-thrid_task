#include <iostream>
#include "Shape.h"
#include "Color.h"
#include "Point.h"
#include "Quadrangle.h"
#include "Triangle.h"
#include "Circle.h"

using namespace std;

void main()
{
	setlocale(0, "");

	try
	{
		cout << "��������������" << endl;
		Quadrangle Square = Quadrangle(Point(1, 3), Point(3, 1));
		cout << "������� = " << Square.Area() << endl;
		cout << "�������� = " << Square.Perimeter() << endl;
		cout << "��������� AC = " << Square.Diagonal(Square.GetA()) << endl;
		cout << "���� ABC = " << Square.Angle(Square.GetB()) << endl;
		cout << "����� ������� �� = " << Square.SideLen(1) << endl;
		if (Square.Belong(Point(3, 10))) cout << "����� �����������\n";
		else  cout << "����� �� �����������\n";

		cout << "�����������" << endl;
		Triangle RectengularTriangle = Square.Trian(Square.GetC());
		cout << "������� = " << RectengularTriangle.Area() << endl;
		cout << "�������� = " << RectengularTriangle.Perimeter() << endl;
		cout << "����� ������� ����������� �� ����� � = " << RectengularTriangle.Median(RectengularTriangle.GetB()) << endl;
		cout << "����� ������ ����������� �� ����� � = " << RectengularTriangle.Height(RectengularTriangle.GetB()) << endl;
		cout << "����� ����������� ����������� �� ����� � = " << RectengularTriangle.Bisector(RectengularTriangle.GetB()) << endl;
		cout << "���� ��� = " << RectengularTriangle.Angle(RectengularTriangle.GetB()) << endl;
		cout << "����� ������� �� = " << RectengularTriangle.SideLen(3) << endl;
		if (RectengularTriangle.Belong(Point(4, 3))) cout << "����� �����������\n";
		else  cout << "����� �� �����������\n";
		Quadrangle QuadAtTriangle = RectengularTriangle.Quad(1);

		cout << "����������" << endl;
		Circle Range = Circle(10, Point(0, 0));
		cout << "������� = " << Range.Area() << endl;
		cout << "�������� = " << Range.Perimeter() << endl;
		cout << "����������� = " << Range.HalfArea() << endl;
		cout << "������������ = " << Range.HalfPerimeter() << endl;
		cout << "�������  = " << Range.Diameter() << endl;

		cout << "����� ����� �� ������, ������� �� ���. = " << Range.LenChord(Point(0, 10), Point(10, 0)) << endl;
		cout << "����� ���� �� ����� ����� = " << Range.LenArc(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;
		cout << "������� �������� �� ����� ����� = " << Range.AreaSeg(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;
		cout << "�������� �������� �� ����� ����� = " << Range.PerimetrSeg(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;
		cout << "���� �������� �� ����� ����� = " << Range.AngleSeg(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;
		cout << "������ �������� �� ����� ����� = " << Range.HeightSeg(Range.LenChord(Point(0, 10), Point(10, 0))) << endl;


		cout << "����� ����� ���������� ����� ������ ����� ��������������� ������� = " << Range.LenChord(Point(2, 2)) << endl;
	}
	catch(ERRORS e)
	{
		switch (e)
		{
		case NotLieBoundaryCircle:
			cout << "����� �� ����� �� ������� ����������" << endl;
			break;
		case NotLieInCircle:
			cout << "����� �� ����� � ����������" << endl;
			break;
		case IncorrectAngle:
			cout << "���� �������� ������ 180 ��������" << endl;
			break;
		case IncorrectRadius:
			cout << "��������� ������ ����� ����" << endl;
			break;
		case ChordLongerDiametr:
			cout << "��������� ����� ������� ��������" << endl;
			break;
		case HeightSegLongerRadius:
			cout << "��������� ������ �������� ������ �������" << endl;
			break;
		case NotDifferentCoordinate:
			cout << "��������� ���������� �� �������� �������" << endl;
			break;
		case OnOneStraight:
			cout << "��������� ����� ����� �� ����� ������" << endl;
			break;
		case NotASide:
			cout << "��������� ����� ������� �� ����������" << endl;
			break;
		case IncorrectTypeTriangle:
			cout << "��������� ��� ������������ �� ����������" << endl;
			break;
		case PointPerpendicularOneAxes:
			cout << "������ ����������� ����� ��� ��������� �����, ��������������� ����� �� ������������ ����" << endl;
			break;
		case NotCornerPointFigure:
			cout << "��������� ����� �� �������� ������� ������ ������ ������" << endl;
			break;
		default:
			break;
		}
	}

	system("pause");
}