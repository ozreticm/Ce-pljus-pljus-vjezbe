#include "pch.h"
#include "ZooAnimal.h"
#include <string>
#include <iostream>

ZooAnimal::ZooAnimal(std::string s, std::string n, int y, int c, int m, int l)
{
	species = s; name = n; cageNumber = c; mealNumber = m; yearOfBirth = y; lifeSpan = l;  
	weight = new Weight[2 * lifeSpan];
	//popunit nulama
}

ZooAnimal::ZooAnimal(const ZooAnimal & other)
{
	species = other.species; name = other.name; cageNumber = other.cageNumber; mealNumber = other.mealNumber; yearOfBirth = other.yearOfBirth; lifeSpan = other.lifeSpan;  
	weight = new Weight[2 * lifeSpan];/* std::copy(weight, other.weight);*/

	std::copy(other.weight, other.weight + (2 * lifeSpan), weight);

}



ZooAnimal::~ZooAnimal()
{
	species = ""; name = ""; yearOfBirth = 0; cageNumber = 0; mealNumber = 0; lifeSpan = 0; delete[] weight; weight = NULL;
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
	else if(mealNumber>1)
	{
		mealNumber--;
	}
	else
	{
		std::cout << "Morate hraniti zivotinje!\n";
	}
}

