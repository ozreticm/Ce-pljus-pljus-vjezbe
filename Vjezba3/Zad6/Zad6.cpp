// Zad6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

std::string numbers(std::string str)
{
	int n=0;
	bool num[] = { false,false };
	std::string newString;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (isdigit(*it))	num[1] = true;
		else num[1] = false;
		if (num[0] && num[1]);
		else if (!num[0] && num[1]) n = std::atoi(&*it);
		else if (num[0] && !num[1])
			for (int i = 0; i < n; i++)
				newString.push_back(*it);
		else
		{
			n = 0;
			newString.push_back(*it);
		}
		num[0] = num[1];
	}
	str = newString;
	return str;
}

std::string numbersAndLetters(std::string str)
{
	int n = 0;
	char ch[] = { *str.begin(),' ' };
	std::string newString;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		ch[1] = *it;
		if (ch[0] != ch[1])
		{
			if(n!=1)
			newString +=std::to_string(n);
			newString +=ch[0];
			n=1;
		}
		else n++;
		ch[0] = ch[1];
	}
	if(n!=1)
	newString += std::to_string(n);
	newString += ch[0];
	return newString;
}

bool check(std::vector<std::string>::iterator p)
{
	bool digit = false,alpha=false;
	if ((*p).size() > 20)
	{
		std::cout << "String ima vise od 20 znakova! Molimo unesite novi string:\n";
		return false;
	}
	for (std::string::iterator it = (*p).begin(); it != (*p).end(); ++it)
	{
		if (!isalnum(*it))
		{
			std::cout << "Nije dozvoljeno unositi znakove koji nisu velika slova ili brojevi! Molimo unesite novi string:\n";
			return false;
		}
		if (isalpha(*it) && islower(*it))
		{
			std::cout << "Nije dozvoljeno unositi mala slova! Molimo unesite novi string:\n";
			return false;
		}
		if (isdigit(*it))
			digit = true;
		if (isalpha(*it))
			alpha = true;
	}
	if (!alpha)
	{
		std::cout << "Ne mozete upisati samo brojeve! Molimo unesite novi string:\n";
		return false;
	}
	if (isdigit(*((*p).end()-1)))
	{
		std::cout << "Posljedni znak u stringu mora biti veliko slovo! Molimo unesite novi string:\n";
		return false;
	}
	if (digit)
		*p=numbers(*p);
	else *p=numbersAndLetters(*p);
	return true;
}

int main()
{
	int n,br=1;
	std::cout << "Koliko stringova zelite unijeti?\n";
	std::cin >> n;
	std::vector<std::string> v(n);
	for (std::vector<std::string>::iterator p=v.begin(); p!=v.end(); p++)
	{
		std::cout << "Unesite "<<br++<<". string (Dozvoljeno je unijeti do 20 znakova, te samo velika slova ili brojeve!):\n";
		std::cin >> (*p);
		while (!check(p))
		{
			std::cin >> (*p);
		}
	}
	for (std::vector<std::string>::iterator p = v.begin(); p != v.end(); p++)
	{
		std::cout << *p<<"\n";
	}
    return 0;
}

