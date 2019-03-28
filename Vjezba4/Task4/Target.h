#pragma once
#ifndef TARGET_H
#define TARGET_H
#include "Point.h"

class Target {
	Point corner;
	double width, height;
	bool hit;
public:
	void set(Point a, double x, double y, bool h = false);
	void get(Point *pa, double *px, double *py, bool *h) const;
	bool aim(Point a);

};



#endif
