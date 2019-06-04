#pragma once
#ifndef SHIP_H
#define SHIP_H

class Ship
{
protected:
	int length;
	int coorx1, coory1,coorx2,coory2, alive;
public:
	virtual bool set() { return false; };
	virtual bool hit() { return false; };
};

class SmallShip : Ship
{
protected:
	int length = 1;
	int coorx1, coory1, alive;
public:
	bool set(int x1, int y1);
	bool hit(int x, int y);
	friend class Board;
	void print() const;
};

class MediumShip : Ship
{
protected:
	int length = 2;
	int coorx1, coory1, coorx2, coory2, alive;
public:
	bool set(int x1, int y1, int x2, int y2);
	bool hit(int x, int y);
	friend class Board;
	void print() const;
};

class LargeShip : Ship
{
protected:
	int length = 4;
	int coorx1, coory1, coorx2, coory2,alive;
public:
	bool set(int x1, int y1, int x2, int y2);
	bool hit(int x, int y);
	friend class Board;
	void print() const;
};
#endif