#include "stdafx.h"
#include "Point.h"
#include <cstdlib> 
#include <ctime>

void Point::set(double x, double y, double z)
{
	length = x;
	width = y;
	height = z;
}

void Point::setRand()
{
	srand((unsigned)time(0));
	length = (rand() % 10);
	width = (rand() % 10);
	height = (rand() % 10);
}

void Point::get(double *px, double *py, double *pz) const
{
	*px = length;
	*py = width;
	*pz = height;
}

double Point::distance2D(Point b)
{
	double dx = this->length - b.length;
	double dy = this->width - b.width;
	double distance = sqrt(dx*dx + dy*dy);
	return distance;
}

double Point::distance3D(Point b)
{
	double dx = this->length - b.length;
	double dy = this->width - b.width;
	double dz = this->height - b.height;
	double distance = sqrt(dx*dx + dy*dy + dz*dz);
	return distance;
}
