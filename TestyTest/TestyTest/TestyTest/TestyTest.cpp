// TestyTest.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "Vec3.h"
using namespace OOP;
int main()
{
	Vec3 a1 = Vec3();
	std::cout<< "a1 " << a1;
	Vec3 a2 = Vec3(1, 2, 3);
	std::cout << " a2 " << a2;
	Vec3 a3;
	std::cin >> a3;
	std::cout << "a3" << a3;
	Vec3 a4 = Vec3(4, 5, 6);
	std::cout << "a4 " << a4;
	std::cout << "a1+a2 " << a1 + a2;
	std::cout << "a1-a2 " << a1 - a2;
	a3 = a2;
	std::cout <<"a3 = a2 "<< a3;
	a1 += a2;
	std::cout <<"a1 + a2 "<< a1;
	a4 -= a3;
	std::cout << "a4 - a3 " << a4;
	std::cout << "a2 " << a2;
	a4 = a2 * 3;
	std::cout << "a4 = a2 * 3 " << a4;
	a4 = a4 / 2;
	std::cout << "a4 / 2 " << a4;
	a4 *= 2;
	std::cout << "a4 * 2 " << a4;
	a4 /= 3;
	std::cout << "a4 / 3 " << a4;
	double a = a3 * a2;
	std::cout << "a3 * a2 " << a;
	if (a3 == a2)
	{
		std::cout << "a3 i a2 su jednaki.\n";
	}
	else
	{
		std::cout << "a3 i a2 nisu jednaki.\n";
	}
	if(a1!=a2)
	{
		std::cout << "a3 i a2 nisu jednaki.\n";
	}
	else
	{
		std::cout << "a3 i a2 su jednaki.\n";
	}
	a3.clan();
	std::cout << "Normaliziran vektor a3 je " << a3;
	std::cout << "i vektora a3 je " << a3['i'];
	a1.count();
    return 0;
}

