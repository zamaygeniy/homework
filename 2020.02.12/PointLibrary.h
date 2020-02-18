#pragma once
#include "ctime"
#include <iostream>

using namespace std;

struct Point
{
	double x, y;

	Point()
	{
		x = rand() % 100;
		y = rand() % 100;
	}

	Point(double a, double b)
	{
		x = a;
		y = b;
	}

	void move(double deltaX, double deltaY)
	{
		x += deltaX;
		y += deltaY;
	}

	void display()
	{
		cout << "( " << x << " ; " << y << " )" << endl;
	}

	void enter()
	{
		cout << "Enter x - coordinate:";
		cin >> x;
		cout << "Enter y - coordinate:";
		cin >> y;
	}

	double length()
	{
		return sqrt(x * x + y * y);
	}
};

//class Point2D
//{
//public:
//	Point2D()
//	{
//		x = 0;
//		y = 0;
//	}
//	Point2D(double a, double b)
//	{
//		x = a;
//		y = b;
//	}
//private:
//	double x;
//	double y;
//};