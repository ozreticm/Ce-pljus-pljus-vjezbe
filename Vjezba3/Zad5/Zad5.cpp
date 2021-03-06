// Zad5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct Producent
{
	std::string name, movie;
	int year;
};

void menu()
{
	std::cout << "IZBORNIK\n\n"
		"Upisite broj akcije koju zelite izvrsiti\n"
		"1 Unesite novog producenta\n"
		"2 Ispisi najzastupljenijeg/najzastupljenije producente\n"
		"3 Izlaz\n";
}
Producent input()
{
	//std::cin.clear();
	//std::cin.sync();
	Producent newProducent;
	std::string str;
	std::cout << "Unesite ime producenta:\n";
	std::cin.ignore();
	std::getline(std::cin, newProducent.name);
	std::cout << "Unesite naziv filma:\n";
	//std::cin.ignore();
	getline (std::cin,str);
	newProducent.movie = str;
	std::cout << "Unesite godinu objavljivanja filma:\n";
	std::cin >> newProducent.year;
	while (newProducent.year < 1895 || newProducent.year>2019)
	{
		if (newProducent.year < 1895)
			std::cout << "Koga vi tu zafrkajete? Prvi film je objavljen 1895. godine... Unesite ponovo:\n";
		else
			std::cout << "Jel to neki film iz buducnosti? Molim unesite ponovo:\n";
		std::cin >> newProducent.year;
	}
	return newProducent;
}

void mostMovies(std::vector<Producent> v)
{
	int max = 0;
	std::unordered_map<std::string, int> producentFreq;
	for (std::vector<Producent>::iterator it = v.begin(); it != v.end(); it++)
	{
		producentFreq[(*it).name]++;
		if (producentFreq[(*it).name] > max)
			max = producentFreq[(*it).name];
	}
	std::unordered_map<std::string, int>::iterator p;
	for (p = producentFreq.begin(); p != producentFreq.end(); p++)
	{
		if(p->second==max)
		std::cout << "(" << p->first << ", " << p->second << ")\n";
	}
}

int main()
{
	std::vector<Producent> v;
	menu();
	int choice,br=0;
	std::cin >> choice;
	while (choice != 3)
	{
		switch (choice)
		{
		case 1:
			v.push_back(input());
			break;
		case 2:
			mostMovies(v);
			break;
		case 3:
			break;
		default:
			std::cout << "Rekli smo 1,2 ili 3, brojkom, ne slovima, i ne neke gluposti!\n";
			break;
		}
		menu();
		std::cin >> choice;
	}
    return 0;
}

