#include "stdafx.h"
#include "ZooAnimal.h"
#include <string>
#include <iostream>

ZooAnimal::ZooAnimal(std::string s, std::string n, int y, int c, int m, int l)
{
	species = s; name = n; cageNumber = c; mealNumber = m; yearOfBirth = y; lifeSpan = l;
	weight = new Weight[2 * lifeSpan];
	for (int i = 0; i < 2 * lifeSpan; i++)
	{
		weight[i].weightByYear = 0.0;
	}
	std::cout << "Izvrsen je konstruktor\n";
	//popunit nulama
}

ZooAnimal::ZooAnimal(const ZooAnimal & other)
{
	species = other.species; name = other.name; cageNumber = other.cageNumber; mealNumber = other.mealNumber; yearOfBirth = other.yearOfBirth; lifeSpan = other.lifeSpan;
	weight = new Weight[2 * lifeSpan];
	std::copy(other.weight, other.weight + 2 * lifeSpan, weight);
	std::cout << "Izvrsen je copy konstruktor\n";
}



ZooAnimal::~ZooAnimal()
{
	species = ""; name = ""; yearOfBirth = 0; cageNumber = 0; mealNumber = 0; lifeSpan = 0; delete[] weight; weight = NULL;
	std::cout << "Izvrsen je destruktor\n";
}

void ZooAnimal::set(std::string s, std::string n, int y, int c, int m, int l)
{
	species = s;
	name = n;
	yearOfBirth = y;
	cageNumber = c;
	mealNumber = m;
	lifeSpan = l;
}

void ZooAnimal::get(std::string * s, std::string * n, int * y, int * c, int * m, int * l) const
{
	*s = species;
	*n = name;
	*y = yearOfBirth;
	*c = cageNumber;
	*m = mealNumber;
	*l = lifeSpan;
}

void ZooAnimal::mealNumChange(bool yes)
{
	if (yes)
	{
		mealNumber++;
	}
	else if (mealNumber>1)
	{
		mealNumber--;
	}
	else
	{
		std::cout << "Morate hraniti zivotinje!\n";
	}
}

void ZooAnimal::addWeight(int year, double weight)
{
	for (int i = 0; i < 2 * lifeSpan; i++)
	{
		if (year = this->weight[i].year && year != 2019)
		{
			std::cout << "Vec je unesen podatak za zeljenu godinu!\n";
			return;
		}
	}
	this->weight[insertedWeights].year = year;
	this->weight[insertedWeights].weightByYear = weight;
	++insertedWeights;
}

void ZooAnimal::changeOfWeight()
{
	int y = 2019;
	double thisYear=0, lastYear=0;
	for (int i = 0; i < insertedWeights; i++)
	{
		if (weight[i].year == y)
		{
			thisYear = weight[i].weightByYear;
		}
		else if (weight[i].year == y - 1)
		{
			lastYear = weight[i].weightByYear;
		}
	}
	if (thisYear == 0 || lastYear == 0)
	{
		std::cout << "Nema dovoljno unesenih podataka!";
		return;
	}
	if ((lastYear / thisYear) * 100 > 10)
	{
		this->mealNumChange(true);
	}
	if ((thisYear / lastYear) * 100 > 10)
	{
		this->mealNumChange(false);
	}
}

void ZooAnimal::print() const
{
	std::cout << "Životinja koja Vas zanima je " << species << " i zove se " << name << ".\n"
		"Rodena je " << yearOfBirth << " godine, a ocekivani zivotni vijek joj je " << lifeSpan << " godina.\n"
		"Nalazi se u kavezu broj " << cageNumber << " i dnevno dobiva " << mealNumber << " obroka.\n";
	for (int i = 0; i < insertedWeights; i++)
	{
		std::cout << "Godine " << weight[i].year << " je tezila " << weight[i].weightByYear << ".\n";
	}
}

