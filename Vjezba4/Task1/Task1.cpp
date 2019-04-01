// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Point.h"
#include <cstdlib> 
#include <ctime> 

int main()
{
	double x1, x2, y1, y2, z1, z2;
	std::cout << "Unesite duljinu, sirinu i visinu prve tocke:\n";
	std::cin >> x1 >> y1 >> z1;
	std::cout << "Unesite duljinu, sirinu i visinu druge tocke:\n";
	std::cin >> x2 >> y2 >> z2;
	Point a, b;
	a.set(x1, y1, z1);
	b.set(x2, y2, z2);
	double dist2D = a.distance2D(b);
	double dist3D = a.distance3D(b);
	std::cout << "2D udaljenost izmedu tocaka a i b je " << dist2D << "\n";
	std::cout << "3D udaljenost izmedu tocaka a i b je " << dist3D << "\n";
	return 0;
}
