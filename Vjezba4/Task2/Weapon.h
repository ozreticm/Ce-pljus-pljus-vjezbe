#pragma once
#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
	double length;
	double width;
	double height;
	int maxBullets;
	int currentBullets;
public:
	void set(double x, double y, double z, int a);
	void get(double *px, double *py, double *pz , int *a, int *b) const;
	void move(double x, double y, double c);
	void shoot();
	void reload();
};



#endif
