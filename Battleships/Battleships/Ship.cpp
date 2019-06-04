#include "Ship.h"
#include <algorithm>
#include <iostream>
#include <string>

int hitHelp(int alive,int num)
{
	std::string ships[] = { "large", "medium","small" };
	alive--;
	if (alive == 0)
		std::cout << "The "<<ships[num]<< " ship is destroyed!";
	else
		std::cout << "The " << ships[num] << " ship is hit!";
	return alive;
}

bool LargeShip::set(int x1, int y1, int x2, int y2)
{
	if ((x1 == x2 && (y1 - y2 == 3 || y2 - y1 == 3)) || (y1 == y2 && (x1 - x2 == 3 || x2 - x1 == 3)))
	{
		if (x1 < 10 && x1 >= 0 && y1 < 10 && y1 >= 0 && x2 < 10 && x2 >= 0 && y2 <10 && y2 >= 0)
		{
			coorx1 = x1;
			coorx2 = x2;
			coory1 = y1;
			coory2 = y2;
			alive = 4;
			return true;
		}
	}
	return false;
}

bool LargeShip::hit(int x, int y)
{
	if (coorx1 == coorx2 && coory1<coory2)
	{
		if (x == coorx1 && (y == coory1 || y == coory1 + 1 || y == coory2 - 1 || y == coory2))
		{
			alive = hitHelp(alive, 0);
			return true;
		}
	}
	else if (coorx1 == coorx2 && coory1>coory2)
	{
		if (x == coorx1 && (y == coory1 || y == coory1 - 1 || y == coory2 + 1 || y == coory2))
		{
			alive = hitHelp(alive, 0);
			return true;
		}
	}
	else if (coory1 == coory2 && (coorx1 > coorx2))
	{
		if (y == coory1 && (x == coorx1 || x == coorx1 - 1 || x == coorx2 + 1 || x == coorx2))
		{
			alive = hitHelp(alive, 0);
			return true;
		}
	}
	else if (coory1 == coory2 && (coorx1 < coorx2))
	{
		if (y == coory1 && (x == coorx1 || x == coorx1 + 1 || x == coorx2 - 1 || x == coorx2))
		{
			alive = hitHelp(alive, 0);
			return true;
		}
	}
	return false;
}

void LargeShip::print() const
{
	std::cout << " Large ship: " << alive<<"   ";
}

bool MediumShip::set(int x1, int y1, int x2, int y2)
{
	if ((x1 == x2 && (y1 - y2 == 1 || y2 - y1 == 1)) || (y1 == y2 && (x1 - x2 == 1 || x2 - x1 == 1)))
	{
		if (x1 < 10 && x1 >= 0 && y1 < 10 && y1 >= 0 && x2 < 10 && x2 >= 0 && y2 < 10 && y2 >= 0)
		{
			coorx1 = x1;
			coorx2 = x2;
			coory1 = y1;
			coory2 = y2;
			alive = 2;
			return true;
		}
	}
	return false;
}

bool MediumShip::hit(int x, int y)
{
	if ((x == coorx1 && y == coory1) || (x == coorx2 && y == coory2))
	{
		alive = hitHelp(alive, 1);
		return true;
	}
	return false;
}

void MediumShip::print() const
{
	std::cout << " Medium ship: " << alive << "   ";
}

bool SmallShip::set(int x1, int y1)
{
		if (x1 < 10 && x1 >= 0 && y1 < 10 && y1 >= 0)
		{
			coorx1 = x1;
			coory1 = y1;
			alive = 1;
			return true;
		}
	return false;
}

bool SmallShip::hit(int x, int y)
{
	if (x == coorx1 && y == coory1)
	{
		alive = hitHelp(alive, 2);
		return true;
	}
	return false;
}

void SmallShip::print() const
{
	std::cout << " Small ship: " << alive << "   ";
}
