#pragma once
#pragma once
#ifndef TASK1_H
#define TASK1_H

class Point {
	double length, width, height;
public:
	void set(double x = (0.0), double y = (0.0), double z = (0.0));
	void setRand();
	void get(double *px, double *py, double *pz) const;
	double distance2D(Point b);
	double distance3D(Point b);
};


#endif