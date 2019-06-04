#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Ship.h"
class Board
{
	char matrix[10][10];
	bool hit[10][10];
	bool ships[10][10];
public:
	Board();
	void set(LargeShip a,MediumShip b,SmallShip c1, SmallShip c2);
	void setHidden(LargeShip a, MediumShip b, SmallShip c1, SmallShip c2);
	bool aim1(int x, int y);
	void aim2(int x, int y, bool h); // h će se proslijeđivat iz funkcije broda, ako je pogođen bit će true ako nije bit će false
	void print(const Board &other) const;
};


#endif
