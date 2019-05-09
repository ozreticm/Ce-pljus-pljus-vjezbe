#pragma once
#ifndef ZOOANIMAL_H
#define ZOOANIMAL_H

namespace OSS
{
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

	class Mammal : virtual public ZooAnimal
	{

	};

	class Bird : virtual public ZooAnimal
	{

	};

	class Reptile : virtual public ZooAnimal
	{

	};

	class Tiger : public Mammal
	{

	};

	class Monkey : public Mammal
	{

	};

	class Elephant : public Mammal
	{

	};

	class GriffonVulture : public Bird
	{

	};

	class Owl : public Bird
	{

	};

	class Crocodile : public Reptile
	{

	};

	class Turtle : public Reptile
	{

	};

}

#endif