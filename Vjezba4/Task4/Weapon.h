#include "Point.h"
#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
	Point position;
	int maxBullets;
	int currentBullets;
public:
	void set(Point x, int a);
	void get(Point *px,int *a, int *b) const;
	void move(Point x);
	bool shoot();
	void reload();
};



#endif
