#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>
namespace oss
{
	class Vehicle
	{
		public:
			virtual std::string type()=0;
			virtual unsigned passengers()=0;
	};

	class Land_vehicle : virtual public Vehicle
	{
		protected:
			std::string typeOfVehicle;
		public:
			Land_vehicle();
			std::string type();
	};

	class Watercraft : virtual public Vehicle
	{
		protected:
			std::string typeOfVehicle;
		public:
			Watercraft();
			std::string type();
	};

	class Aircraft : virtual public Vehicle
	{
		protected:
			std::string typeOfVehicle;
		public:
			Aircraft();
			std::string type();
	};

	class Bike : public Land_vehicle
	{
		public:
			unsigned passengers();
	};

	class Car : public Land_vehicle
	{
		public:
			unsigned passengers();
	};

	class Ferry : public Watercraft
	{
			unsigned numOfPassengers;
		public:
			Ferry(unsigned x, unsigned y, unsigned z);
			unsigned passengers();
	};

	class Catamaran : public Watercraft
	{
			unsigned numOfPassengers;
		public:
			Catamaran(unsigned x);
			unsigned passengers();
	};

	class Seaplane : public Watercraft, public Aircraft
	{
			unsigned numOfPassengers;
			std::string typeOfVehicle;
		public:
			Seaplane(unsigned x);
			unsigned passengers();
			std::string type();
	};

	class Counter
	{
			unsigned totalPassengers;
		public:
			Counter();
			void add(Vehicle * v);
			unsigned total();
	};
}
#endif