// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Weapon.h"

void menu()
{
	std::cout << "1 Pomakni se!\n"
		"2 Pucaj!\n"
		"3 Napuni!\n"
		"4 Where the f* am I?\n"
		"5 Dosta mi je vise...\n";
}

int main()
{
	double a, b, c;
	int n;
	int k;
	std::cout << "Unesite polozaj oruzja i maksimalan broj metaka:\n";
	std::cin >> a >> b >> c >> n;
	Weapon gun;
	gun.set(a, b, c, n);
	menu();
	std::cin >> k;
	while (k != 5)
	{
		switch (k)
		{
		case 1:
			std::cout << "Brzo! Unesite nove koordinate!\n";
			std::cin >> a >> b >> c;
			gun.move(a, b, c);
			break;
		case 2:
			gun.shoot();
			break;
		case 3:
			gun.reload();
			break;
		case 4:
			std::cout << "Na koordinatama ste " << a << " " << b << " " << c << "\n";
		default:
			std::cout << "To nije ponudeno!";
			break;
		}
		menu();
		std::cin >> k;
	}
    return 0;
}

