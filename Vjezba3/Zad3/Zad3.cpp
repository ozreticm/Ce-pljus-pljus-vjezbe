// Zad3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include <iterator>
//Space provjerava je li na određenoj poziciji u stringu razmak, te tu vrijednost pamti
//Interpunction[0] nalazili se na prethodnoj poziciji interpunkcijski znak, a interpunction[1] na trenutnoj
std::string fix(std::string str)
{
	bool space = false, interpunction[] = { false,false };
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it == ',' || *it == '.' || *it == '?' || *it == '!') interpunction[1] = true;
		else interpunction[1] = false;

		if (interpunction[1] && space)		str.erase (--it);

		if (*it == ' ') space = true;
		else space = false;

		if (interpunction[0] && !space)		str.insert(it,1, ' ');

		interpunction[0] = interpunction[1];
	}
	return str;
}


int main()
{
	std::string str;
	std::cout << "Unesite nepravilno napisanu recenicu:\n";
	std::getline(std::cin, str);
	str = fix(str);
	std::cout << str<<"\n";
    return 0;
}

