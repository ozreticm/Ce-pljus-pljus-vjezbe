// Zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ZooAnimal.h"
#include <vector>

void menu()
{
	std::cout << "IZABERITE SLJEDECI KORAK:\n"
		"1. Unosenje nove zivotinje\n"
		"2. Dodavanje tezine postojecoj zivotinji\n"
		"3. Provjera jeli se zivotinja udebljala/smrsavila i promjena broja obroka\n"
		"0. Izlazak\n";
}
std::vector<ZooAnimal> input(std::vector<ZooAnimal> animals)
{
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
	return animals;
}


int main()
{
	std::vector<ZooAnimal> animals;
	int y;
	double w;
	int choice,numOfAnimals=0,n;
	std::cout << "Dobrodosli u nas zooloski vrt!\n"
		"Zasad nemamo podatke o nijednoj zivotinji :(, zato Vas molimo da unesete podatke o prvoj zivotinji!\n";
	animals=input(animals);
	numOfAnimals++;
	do {
		std::cout << "Za koju godinu zelite unjeti tezinu?\n";
		std::cin >> y;
		std::cout << "Kolika je bila tezina zivotinje?\n";
		std::cin >> w;
	} while (y > 2020 || w<0);
	animals.at(0).addWeight(y, w);
	menu();
	std::cin >> choice;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			animals = input(animals);
			numOfAnimals++;
			break;
		case 2:
			std::cout << "Upisite broj zivotinje kojoj zelite dodati tezinu:\n";
			std::cin >> n;
			if (n > numOfAnimals)
			{
				std::cout << "Niste unjeli toliko zivotinja";
				break;
			}
			else
			{
				
				do {
					std::cout << "Za koju godinu zelite unjeti tezinu?\n";
					std::cin >> y;
					std::cout << "Kolika je bila tezina zivotinje?\n";
					std::cin >> w;
				} while (y > 2020 || w<0);
				animals.at(n-1).addWeight(y, w);
			}
			break;
		case 3:
			std::cout << "Upisite broj zivotinje koju zelite provjeriti:\n";
			std::cin >> n;
			if (n > numOfAnimals)
			{
				std::cout << "Niste unjeli toliko zivotinja";
				break;
			}
			else
			{
				animals.at(n - 1).changeOfWeight();
				break;
			}
		default:
			std::cout << "Neispravno unesen broj!\n";
			break;
	}
		menu();
		std::cin >> choice;
	}
}
