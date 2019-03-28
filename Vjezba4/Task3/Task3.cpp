// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Point.h"
#include "Target.h"

void menu()
{
	std::cout << "Zelite li pucati u metu?\n"
		"1 Naravno!\n"
		"2 Ma kakvi, idemo radit nesto drugo\n";
}

int main()
{
	Target meta;
	Point position;
	double x, y, z,width,height;
	int choice;
	std::cout << "Unesite poziciju mete!\n";
	std::cin >> x >> y >> z;
	position.set(x,y,z);
	std::cout << "Koliko je meta siroka i visoka?\n";
	std::cin >> width >> height;
	meta.set(position, width, height);
	menu();
	std::cin >> choice;
	while (choice == 2)
	{
		std::cout << "U koje koordinate pucamo (samo sirina i visina)?\n";
		std::cin >> y >> z;
		position.set(x, y, z);
		if (meta.aim(position))
		{
			std::cout << "Bravo, pogodili ste metu!\n";
		}
		else
		{
			std::cout << "Ufff, koji promasaj...\n";
		}
		menu();
		std::cin >> choice;
		
	}
	if (choice != 1 && choice != 2)
	{
		std::cout << "Rekli smo 1 ili 2! Sad za kaznu nema vise pucanja!";
	}
    return 0;
}

