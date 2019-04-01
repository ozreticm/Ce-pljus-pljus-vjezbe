#include "stdafx.h"
#include "Target.h"
#include "Point.h"

void Target::set(Point a, double x, double y, bool h)
{
	corner = a;
	width = x;
	height = y;
	hit = h;
}

void Target::get(Point * pa, double * px, double * py, bool * h) const
{
	*pa = corner;
	*px = width;
	*py = height;
	*h = hit;

}

bool Target::aim(Point a)
{
	hit = false;
	double x1, x2, y1, y2, z1, z2, b, c, d;
	a.get(&b, &c, &d);
	corner.get(&x1, &y1, &z1);
	Point corner2;
	corner2.set(x1, y1 + width, z1 + height);
	corner2.get(&x2, &y2, &z2);
	if (x1 <= b && b <= x2)
	{
		if (y1 <= c && c <= y2)
		{
			if (z1 <= d && d <= z2)
			{
				hit = true;
			}
		}
	}
	return hit;
}
