#include "stdafx.h"
#include "ZooAnimal.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace OSS;



OSS::ZooAnimal::ZooAnimal(std::string n, int y, int c, int m, int l, int a)
{
	name = n; cageNumber = c; mealNumber = m; yearOfBirth = y; lifeSpan = l; amountOfFood = a;
	weight = new Weight[2 * lifeSpan];
	for (int i = 0; i < 2 * lifeSpan; i++)
	{
		weight[i].weightByYear = 0.0;
		weight[i].year = 0;
	}
	insertedWeights = 0;
	//popunit nulama
}

ZooAnimal::ZooAnimal(const ZooAnimal & other)
{
	name = other.name; cageNumber = other.cageNumber; mealNumber = other.mealNumber; yearOfBirth = other.yearOfBirth; lifeSpan = other.lifeSpan; amountOfFood = other.amountOfFood;
	weight = new Weight[2 * lifeSpan];
	std::copy(other.weight, other.weight + 2 * other.lifeSpan, weight);
	insertedWeights = other.insertedWeights;
}



ZooAnimal::~ZooAnimal()
{
	name = ""; yearOfBirth = 0; cageNumber = 0; mealNumber = 0; lifeSpan = 0; delete[] weight; weight = NULL; amountOfFood = 0;
}


void ZooAnimal::set(std::string n, int y, int c, int m, int l, int a)
{
	name = n;
	yearOfBirth = y;
	cageNumber = c;
	mealNumber = m;
	lifeSpan = l;
	amountOfFood = a;
}

void ZooAnimal::get(std::string * n, int * y, int * c, int * m, int * l, int *a) const
{
	*n = name;
	*y = yearOfBirth;
	*c = cageNumber;
	*m = mealNumber;
	*l = lifeSpan;
	*a = amountOfFood;
}

void ZooAnimal::mealNumChange(bool yes)
{
	if (yes)
	{
		mealNumber++;
		std::cout << "Povecali smo broj obroka na " << mealNumber << "\n";
	}
	else if (mealNumber>1)
	{
		mealNumber--;
		std::cout << "Smanjili smo broj obroka na " << mealNumber << "\n";
	}
	else
	{
		std::cout << "Morate hraniti zivotinje!\n";
	}
}

void ZooAnimal::addWeight(int year, double w)
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	for (int i = 0; i < insertedWeights; i++)
	{
		if (year == weight[i].year && year != (now->tm_year + 1900))
		{
			std::cout << "Vec je unesen podatak za zeljenu godinu!\n";
			return;
		}
	}
	weight[insertedWeights].year = year;
	weight[insertedWeights].weightByYear = w;
	insertedWeights += 1;
	std::cout << insertedWeights << "\n";
}

void ZooAnimal::changeOfWeight()
{
	int y = 2019, i;
	double thisYear = 0, lastYear = 0;
	std::cout << insertedWeights;
	for (i = 0; i < insertedWeights; i++)
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
		std::cout << "Nema dovoljno unesenih podataka!\n";
		return;
	}
	else if ((thisYear < lastYear) && ((lastYear / thisYear) * 100 > 10))
	{
		std::cout << "Smrsavila je!\n";
		this->mealNumChange(true);
		return;
	}
	else if ((thisYear > lastYear) && ((lastYear / thisYear) * 100 > 10))
	{
		std::cout << "Udebljala se!\n";
		this->mealNumChange(false);
		return;
	}
}

OSS::Tiger::Tiger(std::string n, int y, int c, int m, int l, int a) : Mammal(n, y, c, m, l, a)
{
	gestationPeriod = 105;
	averageBodyTemperature = 37.5;
}

void OSS::Tiger::print()
{
	std::cout << name << ": " << amountOfFood * mealNumber << " grama hrane dnevno\n";
}

OSS::Mammal::Mammal(std::string n, int y, int c, int m, int l, int a) : ZooAnimal(n, y, c, m, l, a)
{
}

OSS::Bird::Bird(std::string n, int y, int c, int m, int l, int a) : ZooAnimal(n, y, c, m, l, a)
{
}

OSS::Reptile::Reptile(std::string n, int y, int c, int m, int l, int a) : ZooAnimal(n, y, c, m, l, a)
{
}

OSS::Monkey::Monkey(std::string n, int y, int c, int m, int l, int a) : Mammal(n, y, c, m, l, a)
{
	gestationPeriod = 164;
	averageBodyTemperature = 37.3;
}

void OSS::Monkey::print()
{
	int k = amountOfFood * mealNumber;
	std::cout << name << ": " << k << " grama hrane dnevno\n";
}


OSS::Elephant::Elephant(std::string n, int y, int c, int m, int l, int a) : Mammal(n, y, c, m, l, a)
{
	gestationPeriod = 660;
	averageBodyTemperature = 36.5;
}

void OSS::Elephant::print()
{
	int k = amountOfFood * mealNumber;
	std::cout << name << ": " << k << " grama hrane dnevno\n";
}

OSS::GriffonVulture::GriffonVulture(std::string n, int y, int c, int m, int l, int a) : Bird(n, y, c, m, l, a)
{
	incubationPeriod = 57;
	averageBodyTemperature = 38.9;
}

void OSS::GriffonVulture::print()
{
	int k = amountOfFood * mealNumber;
	std::cout << name << ": " << k << " grama hrane dnevno\n";
}

OSS::Owl::Owl(std::string n, int y, int c, int m, int l, int a) : Bird(n, y, c, m, l, a)
{
	incubationPeriod = 32;
	averageBodyTemperature = 41;
}

void OSS::Owl::print()
{
	int k = amountOfFood * mealNumber;
	std::cout << name << ": " << k << " grama hrane dnevno\n";
}

OSS::Crocodile::Crocodile(std::string n, int y, int c, int m, int l, int a) : Reptile(n, y, c, m, l, a)
{
	incubationPeriod = 75;
	averageOutdoorTemperature = 30;
}

void OSS::Crocodile::print()
{
	int k = amountOfFood * mealNumber;
	std::cout << name << ": " << k << " grama hrane dnevno\n";
}

OSS::Turtle::Turtle(std::string n, int y, int c, int m, int l, int a) : Reptile(n, y, c, m, l, a)
{
	incubationPeriod = 60;
	averageOutdoorTemperature = 27;
}

void OSS::Turtle::print()
{
	int k = this->amountOfFood * this->mealNumber;
	std::cout << this->name << ": " << k << " grama hrane dnevno\n";
}

std::istream & OSS::operator>>(std::istream & input, Tiger & t)
{
	std::cout << "Unesite ime, godinu rodenja, broj kaveza, broj obroka, ocekivani zivotni vijek i kolicinu hrane u gramima u jednom obroku za tigra:\n";
	input >> t.name >> t.yearOfBirth >> t.cageNumber >> t.mealNumber >> t.lifeSpan >> t.amountOfFood;
	return input;
}

std::ostream & OSS::operator<<(std::ostream & os, const Tiger & t)
{
	os << t.name << " tigar, rada se i gestacijski period mu je " << t.gestationPeriod << " dana, a prosjecna temperature tijela " << t.averageBodyTemperature << ".\n";
	return os;
}

std::istream & OSS::operator>>(std::istream & input, Monkey & t)
{
	std::cout << "Unesite ime, godinu rodenja, broj kaveza, broj obroka, ocekivani zivotni vijek i kolicinu hrane u gramima u jednom obroku za majmuna:\n";
	input >> t.name >> t.yearOfBirth >> t.cageNumber >> t.mealNumber >> t.lifeSpan >> t.amountOfFood;
	return input;
}

std::ostream & OSS::operator<<(std::ostream & os, const Monkey & t)
{
	os << t.name << " majmun, rada se i gestacijski period mu je " << t.gestationPeriod << " dana, a prosjecna temperature tijela " << t.averageBodyTemperature << ".\n";
	return os;
}

std::istream & OSS::operator>>(std::istream & input, Elephant & t)
{
	std::cout << "Unesite ime, godinu rodenja, broj kaveza, broj obroka, ocekivani zivotni vijek i kolicinu hrane u gramima u jednom obroku za slona:\n";
	input >> t.name >> t.yearOfBirth >> t.cageNumber >> t.mealNumber >> t.lifeSpan >> t.amountOfFood;
	return input;
}

std::ostream & OSS::operator<<(std::ostream & os, const Elephant & t)
{
	os << t.name << " slon, rada se i gestacijski period mu je " << t.gestationPeriod << " dana, a prosjecna temperature tijela " << t.averageBodyTemperature << ".\n";
	return os;
}

std::istream & OSS::operator>>(std::istream & input, GriffonVulture & t)
{
	std::cout << "Unesite ime, godinu rodenja, broj kaveza, broj obroka, ocekivani zivotni vijek i kolicinu hrane u gramima u jednom obroku za bjeloglavog supa:\n";
	input >> t.name >> t.yearOfBirth >> t.cageNumber >> t.mealNumber >> t.lifeSpan >> t.amountOfFood;
	return input;
}

std::ostream & OSS::operator<<(std::ostream & os, const GriffonVulture & t)
{
	os << t.name << " bjeloglavi sup, lijeze se i inkubacijski period mu je " << t.incubationPeriod << " dana, a prosjecna temperature tijela " << t.averageBodyTemperature << ".\n";
	return os;
}

std::istream & OSS::operator>>(std::istream & input, Owl & t)
{
	std::cout << "Unesite ime, godinu rodenja, broj kaveza, broj obroka, ocekivani zivotni vijek i kolicinu hrane u gramima u jednom obroku za sovu:\n";
	input >> t.name >> t.yearOfBirth >> t.cageNumber >> t.mealNumber >> t.lifeSpan >> t.amountOfFood;
	return input;
}

std::ostream & OSS::operator<<(std::ostream & os, const Owl & t)
{
	os << t.name << " sova, lijeze se i inkubacijski period joj je " << t.incubationPeriod << " dana, a prosjecna temperature tijela " << t.averageBodyTemperature << ".\n";
	return os;
}

std::istream & OSS::operator>>(std::istream & input, Crocodile & t)
{
	std::cout << "Unesite ime, godinu rodenja, broj kaveza, broj obroka, ocekivani zivotni vijek i kolicinu hrane u gramima u jednom obroku za krokodila:\n";
	input >> t.name >> t.yearOfBirth >> t.cageNumber >> t.mealNumber >> t.lifeSpan >> t.amountOfFood;
	return input;
}

std::ostream & OSS::operator<<(std::ostream & os, const Crocodile & t)
{
	os << t.name << " krokodil, lijeze se i inkubacijski period mu je " << t.incubationPeriod << " dana, a prosjecna temperature okoline " << t.averageOutdoorTemperature << ".\n";
	return os;
}

std::istream & OSS::operator>>(std::istream & input, Turtle & t)
{
	std::cout << "Unesite ime, godinu rodenja, broj kaveza, broj obroka, ocekivani zivotni vijek i kolicinu hrane u gramima u jednom obroku za kornjaču	:\n";
	input >> t.name >> t.yearOfBirth >> t.cageNumber >> t.mealNumber >> t.lifeSpan >> t.amountOfFood;
	return input;
}

std::ostream & OSS::operator<<(std::ostream & os, const Turtle & t)
{
	os << t.name << " kornjaca, lijeze se i inkubacijski period mu je " << t.incubationPeriod << " dana, a prosjecna temperature okoline " << t.averageOutdoorTemperature << ".\n";
	return os;
}
