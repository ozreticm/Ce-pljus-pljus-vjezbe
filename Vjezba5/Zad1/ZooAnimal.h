#pragma once
#ifndef ZOOANIMAL_H
#define ZOOANIMAL_H
#include <string>

struct Weight
{
	double weightByYear;
	int year;
};

class ZooAnimal
{
	std::string species, name;
	int yearOfBirth, cageNumber, mealNumber, lifeSpan, insertedWeights;
	Weight * weight;

public:
	ZooAnimal(std::string s, std::string n, int y, int c, int m, int l);
	ZooAnimal(const ZooAnimal& other);
	~ZooAnimal();

	void set(std::string s, std::string n, int y, int c, int m, int l);
	void get(std::string *s, std::string *n, int *y, int *c, int *m, int *l) const;
	void mealNumChange(bool yes);
	void addWeight(int year, double newWeight);
	void changeOfWeight();
	void print() const;
};
#endif

//težina!