#include <iostream>
#include "Board.h"
#include "Ship.h"
#include "Player.h"
#include <time.h>

void fill(std::vector<int> *x, std::vector<int> *y, int a1, int b1, int a2, int b2)
{
	if (a1 == a2 && b1<b2)
	{
		x->push_back(a1);
		x->push_back(a1);
		x->push_back(a1);
		x->push_back(a1);
		y->push_back(b1);
		y->push_back(b1+1);
		y->push_back(b2-1);
		y->push_back(b2);
	}
	else if (a1 == a2 && b1 > b2)
	{
		x->push_back(a1);
		x->push_back(a1);
		x->push_back(a1);
		x->push_back(a1);
		y->push_back(b1);
		y->push_back(b1 + 1);
		y->push_back(b2 - 1);
		y->push_back(b2);
	}
	else if (a1 > a2 && b1 == b2)
	{
		x->push_back(a1);
		x->push_back(a1-1);
		x->push_back(a2+1);
		x->push_back(a2);
		y->push_back(b1);
		y->push_back(b1);
		y->push_back(b1);
		y->push_back(b1);
	}
	else if (a1 > a2 && b1 == b2)
	{
		x->push_back(a1);
		x->push_back(a1 + 1);
		x->push_back(a2 - 1);
		x->push_back(a2);
		y->push_back(b1);
		y->push_back(b1);
		y->push_back(b1);
		y->push_back(b1);
	}
}
void menu(int a)
{
	switch (a)
	{
	case 0:
		std::cout << "Welcome to the game of BATTLESHIPS!\n"
			"Rules are simple, you against computer. You both have 4 ships, one large (length 4),\n one medium (length 2) and two small (length 1) ships."
			"Now you will be placing your ships to the board!\n";
		break;
	case 1:
		std::cout << "As you can see, our battlefield has 10 spaces in width and 10 spaces in height.\n"
			"You need to put one ship at a time, starting with the large one.\n";
		break;
	}
}

void setShipPlayer(LargeShip* l, MediumShip* m, SmallShip* s1, SmallShip* s2)
{
	int x1, x2, y1, y2;
	std::vector<int> x;
	std::vector<int> y;
	bool ok = false;
	do
	{
		std::cout << "Put in coordinates of two ends of the large ship(0 - 9, first rows than columns)\n";
		std::cin >> x1 >> y1 >> x2 >> y2;
		ok= l->set(x1,y1,x2,y2);
	} while (!ok);
	fill(&x, &y, x1, y1, x2, y2);
	do
	{
		std::cout << "Put in coordinates of two ends of the medium ship(0 - 9, first rows than columns)\n";
		std::cin >> x1 >> y1 >> x2 >> y2;
		ok = m->set(x1, y1, x2, y2);
		std::vector<int>::iterator iy = y.begin();
		for (std::vector<int>::iterator it = x.begin(); it < x.end(); it++)
		{
			if ((*it == x1 && *iy == y1) || (*it == x2 && *iy == y2))
			{
				ok = false;
				std::cout << "you have already placed a ship there!\n";
				break;
			}
			iy++;
		}
	} while (!ok);
	x.push_back(x1);
	x.push_back(x2);
	y.push_back(y1);
	y.push_back(y2);
	do
	{
		std::cout << "Put in coordinates of first small ship(0 - 9, first rows than columns)\n";
		std::cin >> x1 >> y1;
		ok = s1->set(x1, y1);
		std::vector<int>::iterator iy = y.begin();
		for (std::vector<int>::iterator it = x.begin(); it < x.end(); it++)
		{
			if ((*it == x1 && *iy == y1))
			{
				ok = false;
				std::cout << "you have already placed a ship there!\n";
				break;
			}
			iy++;
		}
	} while (!ok);
	x.push_back(x1);
	y.push_back(y1);
	do
	{
		std::cout << "Put in coordinates of second small ship(0 - 9, first rows than columns)\n";
		std::cin >> x1 >> y1;
		ok = s2->set(x1, y1);
		std::vector<int>::iterator iy = y.begin();
		for (std::vector<int>::iterator it = x.begin(); it < x.end(); it++)
		{
			if ((*it == x1 && *iy == y1))
			{
				ok = false;
				std::cout << "you have already placed a ship there!\n";
				break;
			}
			iy++;
		}
	} while (!ok);
}

void setShipComputer(LargeShip* l, MediumShip* m, SmallShip* s1, SmallShip* s2)
{
	int x1, x2, y1, y2;
	srand(time(NULL));
	std::vector<int> x;
	std::vector<int> y;
	bool ok = false;
	do
	{
		x1 = rand() % 10;
		y1 = rand() % 10;
		x2 = rand() % 10;
		y2 = rand() % 10;
		ok = l->set(x1, y1, x2, y2);
	} while (!ok);
	fill(&x, &y, x1, y1, x2, y2);
	do
	{
		x1 = rand() % 10;
		y1 = rand() % 10;
		x2 = rand() % 10;
		y2 = rand() % 10;
		ok = m->set(x1, y1, x2, y2);
		std::vector<int>::iterator iy = y.begin();
		for (std::vector<int>::iterator it = x.begin(); it < x.end(); it++)
		{
			if ((*it == x1 && *iy == y1) || (*it == x2 && *iy == y2))
			{
				ok = false;
				break;
			}
			iy++;
		}
	} while (!ok);
	x.push_back(x1);
	x.push_back(x2);
	y.push_back(y1);
	y.push_back(y2);
	do
	{
		x1 = rand() % 10;
		y1 = rand() % 10;
		ok = s1->set(x1, y1);
		std::vector<int>::iterator iy = y.begin();
		for (std::vector<int>::iterator it = x.begin(); it < x.end(); it++)
		{
			if ((*it == x1 && *iy == y1))
			{
				ok = false;
				break;
			}
			iy++;
		}
	} while (!ok);
	x.push_back(x1);
	y.push_back(y1);
	do
	{
		x1 = rand() % 10;
		y1 = rand() % 10;
		ok = s2->set(x1, y1);
		std::vector<int>::iterator iy = y.begin();
		for (std::vector<int>::iterator it = x.begin(); it < x.end(); it++)
		{
			if ((*it == x1 && *iy == y1))
			{
				ok = false;
				break;
			}
			iy++;
		}
	} while (!ok);
}

int main()
{
	bool test,l,m,s1,s2;
	int c1, c2;
	bool aliveP=true, aliveC=true;
	Board playerBoard, computerBoard;
	Player you(true), computer(false);
	LargeShip pL, cL;
	MediumShip pM, cM;
	SmallShip pS1, pS2, cS1, cS2;
	menu(0);
	playerBoard.print(computerBoard);
	menu(1);
	setShipPlayer(&pL, &pM, &pS1, &pS2);
	playerBoard.set(pL, pM, pS1, pS2);
	setShipComputer(&cL, &cM, &cS1, &cS2);
	//computerBoard.setHidden(cL, cM, cS1, cS2);
	computerBoard.set(cL, cM, cS1, cS2);
	do
	{
		system("cls");
		playerBoard.print(computerBoard);
		you.print();	pL.print();	std::cout << "				";
		computer.print();	cL.print();	 std::cout << "\n";
		pM.print(); pS1.print();	pS2.print(); std::cout << "		";
		cM.print();	cS1.print();	cS2.print(); std::cout << "\n\n";
		do
		{
			std::cout << "Where do yo want to aim?\n";
			std::cin >> c1 >> c2;
			test = computerBoard.aim1(c1, c2);
		} while (test);
		if (cL.hit(c1, c2) || cM.hit(c1, c2) || cS1.hit(c1, c2) || cS2.hit(c1, c2))
		{
			computerBoard.aim2(c1, c2, true);
			aliveC=computer.hit(true);
			if (aliveC == false)
				break;
		}
		else
		{
			computerBoard.aim2(c1, c2, false);
			aliveC=computer.hit(false);
		}
		do
		{
			std::cout << "It is computers turn!\n";
			c1 = rand() % 10;
			c2 = rand() % 10;
			test = playerBoard.aim1(c1, c2);
		} while (test);
		if (pL.hit(c1, c2) || pM.hit(c1, c2) || pS1.hit(c1, c2) || pS2.hit(c1, c2))
		{
			playerBoard.aim2(c1, c2, true);
			aliveP = you.hit(true);
			if (aliveP == false)
				break;
		}
		else
		{
			playerBoard.aim2(c1, c2, false);
			aliveP = you.hit(false);
		}
			} while (aliveP && aliveC);
	system("pause");
	return 0;
}