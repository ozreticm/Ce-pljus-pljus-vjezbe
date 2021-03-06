// Task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Point.h"
#include "Weapon.h"
#include "Target.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


int main()
{
	int numOfTargets,br=0,numOfBullets;
	double x, y, z, h, w,x1,y1,z1;
	Point poz,poz2;
	bool hit;
	Weapon gun;
	std::cout << "Za pocetak, koliko meta zelite unjeti?\n";
	std::cin >> numOfTargets;
	while (numOfTargets < 1)
	{
		std::cout << "Ne moze, opet!\n";
		std::cin >> numOfTargets;
	}
	//std::cout << "Sada cemo lijepo unositi podatke o metama :)\n";
	Target *mete;
	mete = new Target[numOfTargets];

	srand(time(0));
	for (int i = 0; i < numOfTargets; i++)
	{
		/*std::cout << "Unesite koordinate " << i + 1 << ". mete:\n";
		std::cin >> x >> y >> z;
		std::cout << "Unesite sirinu i visinu<< i + 1 << mete:\n";
		std::cin >> w >> h;
		poz.set(x, y, z);*/
		w = std::rand() % 10+2;
		h = std::rand() % 10+2;
		poz.setRand();
		mete[i].set(poz, w, h);
	}
	/*std::cout << "Unesite poziciju oruzja:\n";
	std::cin >> x >> y >> z;
	poz.set(x, y, z);
	std::cout << "Bit cu dobra i u pistolj stavit jednak broj metaka kao sto je meta. Nema na cemu!\n";*/
	std::cout << "Unesite broj metaka:\n";
	std::cin >> numOfBullets;
	poz.setRand();
	poz.get(&x1, &y1, &z1);
	std::cout << "Koordinate oruzja su " << x1 << " " << y1 << " " << z1 << "!\n";
	gun.set(poz, numOfBullets);
	for (int i = 0; i < numOfTargets; i++)
	{
		mete[i].get(&poz2, &w, &h, &hit);
		if (gun.shoot())
		{
			hit = mete[i].aim(poz);
			if (hit)
			{
				poz2.get(&x, &y, &z);
				std::cout << "Pogodena je meta sa koordinatama: " << x << " " << y << " " << z << "!\n";
				br++;
			}
		}
	}
	double rez = (double)br/numOfTargets;
	std::cout << "Pogodeno je " << rez*100 << "% meta s jednim punjenjem!";

	delete[] mete;
	mete = nullptr;
    return 0;
}

