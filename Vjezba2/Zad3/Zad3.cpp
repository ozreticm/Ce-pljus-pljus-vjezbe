// Zad3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct vectorTest {
	int* arr;
	int logSize, phisSize;

	void vectorNew()
	{
		this->phisSize = 10;
		this->logSize = 0;
		this->arr = new int[this->phisSize];
	}
	void vectorDelete()
	{
		delete[] this->arr;
		this->arr = 0;
		this->logSize = 0;
		this->phisSize = 0;
	}
	void vectorPushBack(int a)
	{
		if (this->logSize == this->phisSize)
		{
			this->phisSize *= 2;
			int* newArr = new int[this->phisSize];
			for (int i = 0; i < this->logSize; i++)
				newArr[i] = this->arr[i];
			delete this->arr;
			this->arr = 0;
			this->arr = newArr;
		}
		this->arr[this->logSize] = a;
		this->logSize ++;
	}
	void vectorPopBack()
	{
		this->arr[--this->logSize] = 0;
	}
	int vectorFront()
	{
		return this->arr[0];
	}
	int vectorBack()
	{
		return this->arr[this->logSize-1];
	}
	int vectorSize()
	{
		return this->logSize;
	}
};

void menu()
{
	std::cout << "MENU\n"
		"Upisite broj akcije koju zelite izvrsiti:\n"
		"1 Kreirajte novi vektor\n"
		"2 Izbrisite vektor\n"
		"3 Dodajte element na kraj vektora\n"
		"4 Izbrisite element sa kraja vektora\n"
		"5 Prvi element vektora\n"
		"6 Posljednji element vektora\n"
		"7 Duljina vektora\n"
		"8 izadite iz programa\n";
}

void printVector(vectorTest vector)
{
	for (int i = 0; i < vector.logSize; i++)
		std::cout << vector.arr[i] << " ";
	std::cout << "\n";
}

int main()
{
	vectorTest ourOwnVector;
	menu();
	int select;
	std::cin >> select;
	while (select != 8)
	{
		switch (select)
		{
		case 1:
			ourOwnVector.vectorNew();
			break;
		case 2:
			ourOwnVector.vectorDelete();
			break;
		case 3:
			int el;
			std::cout << "Unesite zeljeni element";
			std::cin >> el;
			ourOwnVector.vectorPushBack(el);
			break;
		case 4:
			ourOwnVector.vectorPopBack();
			break;
		case 5:
			std::cout << "Prvi element je " << ourOwnVector.vectorFront() << "\n";
			break;
		case 6:
			std::cout << "Posljednji element je " << ourOwnVector.vectorBack() << "\n";
			break;
		case 7:
			std::cout << "Velicina vektora je " << ourOwnVector.vectorSize() << "\n";
			break;
		case 8:
			break;
		default:
			std::cout << "Nevaljan unos!";
			break;
		}
		std::cout << "Trenutno stanje vektora je ";
		printVector(ourOwnVector);
		menu();
		std::cin >> select;
	}
    return 0;
}

