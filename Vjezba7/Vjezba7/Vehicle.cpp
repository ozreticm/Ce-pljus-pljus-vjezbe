#include "stdafx.h"
#include "Vehicle.h"

oss::Land_vehicle::Land_vehicle()
{
	typeOfVehicle = "land";
}

std::string oss::Land_vehicle::type()
{
	return typeOfVehicle;
}

oss::Watercraft::Watercraft()
{
	typeOfVehicle = "water";
}

std::string oss::Watercraft::type()
{
	return typeOfVehicle;
}

oss::Aircraft::Aircraft()
{
	typeOfVehicle = "air";
}

std::string oss::Aircraft::type()
{
	return typeOfVehicle;
}

oss::Seaplane::Seaplane(unsigned x)
{
	numOfPassengers = x;
	typeOfVehicle = "water-air";
}

unsigned oss::Seaplane::passengers()
{
	return numOfPassengers;
}

std::string oss::Seaplane::type()
{
	return typeOfVehicle;
}

unsigned oss::Bike::passengers()
{
	return 1;
}

unsigned oss::Car::passengers()
{
	return 5;
}

oss::Ferry::Ferry(unsigned x, unsigned y, unsigned z)
{
	numOfPassengers = x + y + 5 * z;
}

unsigned oss::Ferry::passengers()
{
	return numOfPassengers;
}

oss::Catamaran::Catamaran(unsigned x)
{
	numOfPassengers = x;
}

unsigned oss::Catamaran::passengers()
{
	return numOfPassengers;
}

oss::Counter::Counter()
{
	totalPassengers = 0;
}

void oss::Counter::add(Vehicle * v)
{
	totalPassengers += v->passengers();
	std::cout << v->type() << ", putnika: " << v->passengers()<<"\n";
}

unsigned oss::Counter::total()
{
	return totalPassengers;
}

