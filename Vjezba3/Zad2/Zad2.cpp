// Zad2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Zad2.h"
#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> vectorInput(bool inputOrRandom = true, int numberOfElements = 5, int leftBorder = 0, int rightBorder = 100)
{
	std::vector<int> v;
	int element;
	if (inputOrRandom)
	{
		for (int i = 0; i < numberOfElements; i++)
		{
			std::cout << "Unesite " << i + 1 << ". element vektora";
			std::cin >> element;
			if (element <= rightBorder && element >= leftBorder)
				v.push_back(element);
			else
			{
				std::cout << "Uneseni broj nije unutar granica " << leftBorder << " i " << rightBorder << "\n";
				i--;
			}
		}
		return v;
	}
	srand((unsigned)time(0));
	for (int i = 0; i < numberOfElements; i++)
	{
		element = leftBorder + rand() % (rightBorder - leftBorder);
		v.push_back(element);
	}
	return v;
}

int main()
{
	std::cout << "Ukoliko zelite unijeti vlastite parametre za prvi vektor unesite 0, a ukoliko zelite raditi po zadanim parametrima unesite 1\n";
	bool inputOrRandom;
	std::cin >> inputOrRandom;
	std::vector<int> v1,v2;
	if (inputOrRandom)
		v1 = vectorInput();
	else
	{
		int leftBorder, rightBorder, numberOfElements;
		std::cout << "Unesite lijevu i desnu granicu\n";
		std::cin >> leftBorder;
		std::cin >> rightBorder;
		std::cout << "Unesite broj elemenata\n";
		std::cin >> numberOfElements;
		std::cout << "Ako zelite da se vektor automatski popuni unesite 0, a ako ga želite sami popunjavati unesite 1\n";
		std::cin >> inputOrRandom;
		v1 = vectorInput(inputOrRandom, numberOfElements, leftBorder, rightBorder);
	}
	std::cout << "Ukoliko zelite unijeti vlastite parametre za drugi vektor unesite 0, a ukoliko zelite raditi po zadanim parametrima unesite 1\n";
	std::cin >> inputOrRandom;
	if (inputOrRandom)
		v2 = vectorInput();
	else
	{
		int leftBorder, rightBorder, numberOfElements;
		std::cout << "Unesite lijevu i desnu granicu\n";
		std::cin >> leftBorder;
		std::cin >> rightBorder;
		std::cout << "Unesite broj elemenata\n";
		std::cin >> numberOfElements;
		std::cout << "Ako zelite da se vektor automatski popuni unesite 0, a ako ga želite sami popunjavati unesite 1\n";
		std::cin >> inputOrRandom;
		v2 = vectorInput(inputOrRandom, numberOfElements, leftBorder, rightBorder);
	}
	for (int i = 0; i < v1.size(); i++)
		std::cout << v1.at(i) << " ";
	std::cout<<"\n";
	for (int i = 0; i < v2.size(); i++)
		std::cout << v2.at(i) << " ";
	std::vector<int> v = filterVector(v1, v2);
	std::cout << "\n";
	for (int i = 0; i < v.size(); i++)
		std::cout << v.at(i) << " ";
	return 0;
}