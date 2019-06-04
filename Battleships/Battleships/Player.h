#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
class Player
{
	int life;
	bool who;	// false oznacava racunalo a true igraca
public:
	Player(bool a);
	bool hit(bool a);
	void print() const;
};


#endif
