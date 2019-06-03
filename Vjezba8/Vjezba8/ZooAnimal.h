#pragma once
#ifndef ZOOANIMAL_H
#define ZOOANIMAL_H
#include <string>
#include <iostream>
namespace OSS
{
	struct Weight
	{
		double weightByYear;
		int year;
	};

	class ZooAnimal
	{
	protected:
		std::string name;
		int yearOfBirth, cageNumber, mealNumber, lifeSpan, insertedWeights,amountOfFood;
		Weight * weight;

	public:
		ZooAnimal() = default;
		ZooAnimal(std::string n, int y, int c, int m, int l, int a);
		ZooAnimal(const ZooAnimal& other);
		~ZooAnimal();

		void set(std::string n, int y, int c, int m, int l, int a);
		void get(std::string *n, int *y, int *c, int *m, int *l, int *a) const;
		void mealNumChange(bool yes);
		void addWeight(int year, double newWeight);
		void changeOfWeight();
	};

	class Mammal : public ZooAnimal
	{
	protected:
		double gestationPeriod,averageBodyTemperature;
		Mammal(std::string n, int y, int c, int m, int l, int a);
	};

	class Bird : public ZooAnimal
	{
	protected:
		double incubationPeriod, averageBodyTemperature;
		Bird(std::string n, int y, int c, int m, int l, int a);
	};

	class Reptile : public ZooAnimal
	{
	protected:
		double incubationPeriod, averageOutdoorTemperature;
		Reptile(std::string n, int y, int c, int m, int l, int a);
	};

	class Tiger : public Mammal
	{
	public:
		Tiger(std::string n, int y, int c, int m, int l, int a);
		friend std::istream& operator>>(std::istream &input, Tiger& t);
		friend std::ostream& operator<<(std::ostream &os, const Tiger& t);
		void print();
	};

	class Monkey : public Mammal
	{
	public:
		Monkey(std::string n, int y, int c, int m, int l, int a);
		friend std::istream& operator>>(std::istream &input, Monkey& t);
		friend std::ostream& operator<<(std::ostream &os, const Monkey& t);
		void print();
	};

	class Elephant : public Mammal
	{
	public:
		Elephant(std::string n, int y, int c, int m, int l, int a);
		friend std::istream& operator>>(std::istream &input, Elephant& t);
		friend std::ostream& operator<<(std::ostream &os, const Elephant& t);
		void print();
	};

	class GriffonVulture : public Bird
	{
	public:
		GriffonVulture(std::string n, int y, int c, int m, int l, int a);
		friend std::istream& operator>>(std::istream &input, GriffonVulture& t);
		friend std::ostream& operator<<(std::ostream &os, const GriffonVulture& t);
		void print();
	};

	class Owl : public Bird
	{
	public:
		Owl(std::string n, int y, int c, int m, int l, int a);
		friend std::istream& operator>>(std::istream &input, Owl& t);
		friend std::ostream& operator<<(std::ostream &os, const Owl& t);
		void print();
	};

	class Crocodile : public Reptile
	{
	public:
		Crocodile(std::string n, int y, int c, int m, int l, int a);
		friend std::istream& operator>>(std::istream &input, Crocodile& t);
		friend std::ostream& operator<<(std::ostream &os, const Crocodile& t);
		void print();
	};

	class Turtle : public Reptile
	{
	public:
		Turtle(std::string n, int y, int c, int m, int l, int a);
		friend std::istream& operator>>(std::istream &input, Turtle& t);
		friend std::ostream& operator<<(std::ostream &os, const Turtle& t);
		void print();
	};

}

#endif