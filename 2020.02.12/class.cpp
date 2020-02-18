//#include <iostream>
//
//using namespace std;
//
//void enterPoint(Point&);
//
//int main()
//{//(*ppoint).x <=> ppoint->x обращение к свойствам структуры через указатель
//	Point point;//создание переменной с вызовом конструктора по умолчанию
//	//point.x = 3;
//	//point.y = 0.3; // "." опреация, через которую обращаются к свойству структуры(полю)
//	point.move(0.1, 2.5);
//	Point point1(12, 24);//создание переменной с вызовом конструктора 
//}
//
//struct Point
//{
//private://модификатор доступа(по умолчанию public)
//	double x;//поле
//	double y;//поле
//
//public:
//	Point()//конструктор по умолчанию(т. к. вызывается по умолчанию)
//	{
//		x = 0;
//		y = 0;
//	}
//
//	Point(double a, double b)//конструктор
//	{
//		x = a;
//		y = b;
//	}
//
//	void move(double deltaX, double deltaY)//метод типа
//	{
//		x += deltaX;
//		y += deltaY;
//	}
//};

// ArrayOfStructs.cpp : Defines the entry point for the console application.

//массив координат + размер; массив размеров

#include"PointLibrary.h"
#include <iostream>

using namespace std;

void EnterPoint(Point&);
void DisplayPoint(const Point&);
void EnterPoint(Point*);
void DisplayPoint(const Point*);
Point* InitArray(int);
void DisplayPoints(Point*, int);
void SortVectors(Point*, int);
void SortVectors(Point*, int, double*);
//void Swap(Point*, int, int);


int main()
{
	srand(time(0));

	int n = 10;

	Point* points = InitArray(n);

	double* length = new double[n];
	for (int i = 0; i < n; i++)
		length[i] = points[i].length();

	DisplayPoints(points, n);

	/*for (int i = 0; i < n; i++)
		cout << length[i] << endl;*/

	SortVectors(points, n, length);

	DisplayPoints(points, n);

	return 0;
}


void SortVectors(Point* point, int n, double* length)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (length[j] < length[min])
				min = j;
		if (min != i)
		{
			swap(point[i], point[min]);
			swap(length[i], length[min]);
		}
	}
}


void SortVectors(Point* point, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (point[j].length() < point[min].length())
				min = j;
		if (min != i)
			swap(point[i], point[min]);
	}
}


void EnterPoint(Point& point)
{
	std::cout << "Enter x - coordinate:";
	std::cin >> point.x;
	std::cout << "Enter y - coordinate:";
	std::cin >> point.y;
}

void DisplayPoint(const Point& point)
{
	cout << "( " << point.x << " ; " << point.y << " )" << " ";
}

void EnterPoint(Point* p)
{
	std::cout << "Enter x - coordinate:";
	std::cin >> (*p).x;
	std::cout << "Enter y - coordinate:";
	std::cin >> p->y;
}

void DisplayPoint(const Point* p)
{
	std::cout << "( " << p->x << " ; " << p->y << " )" << std::endl;
}

Point* InitArray(int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Count of elements can not be less or equal than zero!");
	}

	Point* points = new Point[n];

	return points;
}

void DisplayPoints(Point* points, int n)
{
	for (int i = 0; i < n; i++)
	{
		//DisplayPoint(points[i]);
		points[i].display();
	}
}

