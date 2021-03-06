// Zad4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

int computerMove(int a)
{
	int move;
	srand((unsigned)time(0));
	if(a>3) move =rand() % 3+1;
	else move = rand() % 2+1;
	std::cout << "Racunalo je izvuklo " << move << " sibicu.\n";
	return (a - move);
}

int humanMove(int a)
{
	std::cout << "Koliko sibica zelite izvuci?\n";
	int move;
	std::cin >> move;
	if (a < 3)
	{
		while (move > 2 || move < 1)
		{
			std::cout << "Ne mozete izvuci vise od dvije sibice ili nijednu sibicu, ponovo unesite broj sibica!\n";
			std::cin >> move;
		}
	}
	else
	{
		while (move > 3 || move < 1)
		{
			std::cout << "Ne mozete izvuci vise od tri sibice ili nijednu sibicu, ponovo unesite broj sibica!\n";
			std::cin >> move;
		}
	}
	std::cout << "Izvukli ste " << move << " sibica.\n";
	return a - move;
}

int main()
{
	std::vector<int> v(21);
	v[0] = 21;
	int i=0;
	while (v.at(i) != 0)
	{
		v.at(++i) = computerMove(v.at(i-1));
		if (v.at(i) == 1)
		{
			std::cout << "Ostala je jedna sibica, izgubili ste!";
			break;
		}
		if (v.at(i) == 0)
		{
			std::cout << "Ostalo je nula sibica, pobijedili ste!";
			break;
		}
		std::cout << "Preostalo je " << v.at(i) << " sibica!\n";
		v.at(++i) = humanMove(v.at(i - 1));
		if (v.at(i) == 1)
		{
			std::cout << "Ostala je jedna sibica, pobijedili ste!";
			break;
		}
		if (v.at(i) == 0)
		{
			std::cout << "Ostalo je nula sibica, izgubili ste!";
			break;
		}
		std::cout << "Preostalo je " << v.at(i) << " sibica!\n";
	}
    return 0;
}

