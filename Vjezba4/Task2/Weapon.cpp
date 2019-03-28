#include "stdafx.h"
#include "Weapon.h"
#include <iostream>

void Weapon::set(double x, double y, double z, int a)
{
	length = x;
	width = y;
	height = z;
	maxBullets = a;
	currentBullets = a;
}

void Weapon::get(double * px, double * py, double * pz, int * a, int * b) const
{
	*px = length;
	*py = width;
	*pz = height;
	*a = maxBullets;
	*b = currentBullets;
}

void Weapon::move(double x, double y, double z)
{
	length = x;
	width = y;
	height = z;
}

void Weapon::shoot()
{
	if (currentBullets == 0)
	{
		std::cout << "Ne mozete pucati! Nemate metaka!";
		return;
	}
	if (currentBullets == 1)
	{
		std::cout << "Ovo vam je posljednji metak!";
	}
	currentBullets--;
}

void Weapon::reload()
{
	currentBullets = maxBullets;
}
