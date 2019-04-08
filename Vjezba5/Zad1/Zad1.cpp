// Zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ZooAnimal.h"
#include <vector>

int main()
{
	std::vector<ZooAnimal> animals;
	std::cout << "Dobrodosli u nas zooloski vrt!\n"
		"Zasad nemamo podatke o nijednoj zivotinji :(, zato Vas molimo da unesete podatke o prvoj zivotinji!\n";
	std::string species, name;
	int yearOfBirth, cageNumber, mealNumber, lifeSpan;
	std::cout << "Koje je zivotinja vrste i kako se zove?\n";
	std::cin >> species >> name;
	std::cout << "Unesite godinu rodenja i ocekivani zivotni vijek:\n";
	std::cin >> yearOfBirth >> lifeSpan;
	std::cout << "Unesite broj kaveza i broj obroka:\n";
	std::cin >> cageNumber >> mealNumber;
	ZooAnimal a(species, name, yearOfBirth, cageNumber, mealNumber, lifeSpan);
	animals.push_back(a);
}
