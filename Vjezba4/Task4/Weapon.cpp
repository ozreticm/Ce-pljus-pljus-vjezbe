#include "stdafx.h"
#include "Weapon.h"
#include "Point.h"
#include <iostream>

void Weapon::set(Point x, int a)
{
	position = x;
	maxBullets = a;
	currentBullets = a;
}

void Weapon::get(Point * px, int * a, int * b) const
{
	*px = position;
	*a = maxBullets;
	*b = currentBullets;
}

void Weapon::move(Point x)
{
	position = x;
}

bool Weapon::shoot()
{
	if (currentBullets == 0)
	{
		std::cout << "Ne mozete pucati! Nemate metaka!\n";
		return false;
	}
	if (currentBullets == 1)
	{
		std::cout << "Ovo vam je posljednji metak!\n";
	}
	currentBullets--;
	return true;
}

void Weapon::reload()
{
	currentBullets = maxBullets;
}
