#include "stdafx.h"
#include "Vec3.h"
#include <iostream>
using namespace OOP;

Vec3::Vec3()
{
	i = 0;
	j = 0;
	k = 0;
	counter++;
}

Vec3::Vec3(double x, double y, double z)
{
	i = x;
	j = y;
	k = z;
	counter++;
}

Vec3::~Vec3()
{
	i = 0;
	j = 0;
	k = 0;
}

Vec3 & Vec3::operator=(const Vec3 & other)
{
	i = other.i;
	j = other.j;
	k = other.k;
	return *this;
}

Vec3 Vec3::operator+(const Vec3 & other)
{
	return Vec3(i + other.i, j + other.j, k + other.k);
}

Vec3 Vec3::operator-(const Vec3 & other)
{
	return Vec3(i - other.i, j - other.j, k - other.k);
}

Vec3 & Vec3::operator+=(const Vec3 & other)
{
	i += other.i;
	j += other.j;
	k += other.k;
	return *this;
}

Vec3 & Vec3::operator-=(const Vec3 & other)
{
	i = i - other.i;
	j = j - other.j;
	k = k - other.k;
	return *this;
}

Vec3 & Vec3::operator*(const double a)
{
	i = i * a;
	j = j * a;
	k = k * a;
	return *this;
}

Vec3 & Vec3::operator/(const double a)
{
	i = i / a;
	j = j / a;
	k = k / a;
	return *this;
}

Vec3 & Vec3::operator*=(const double a)
{
	i *= a;
	j *= a;
	k *= a;
	return *this;
}

Vec3 & Vec3::operator/=(const double a)
{
	i /= a;
	j /= a;
	k /= a;
	return *this;
}

double Vec3::operator*(const Vec3 & other)
{
	return i * other.i + j * other.j + k * other.k;
}

bool Vec3::operator==(const Vec3 & other)
{
	if (i == other.i && j == other.j && k == other.k)
	{
		return true;
	}
	else return false;
}

bool Vec3::operator!=(const Vec3 & other)
{
	if (i == other.i && j == other.j && k == other.k)
	{
		return false;
	}
	else return true;
}

Vec3 & Vec3::clan()
{
	double length = sqrt(i*i + j*j + k*k);
	i /= length;
	j /= length;
	k /= length;
	return *this;
}

double Vec3::operator[](char a)
{
	if (a == 'i')
		return i;
	else if (a == 'j')
		return j;
	else if (a == 'k')
		return k;
	else
		std::cout << "Neispravan unos!\n";
	return 0.0;
}

void OOP::Vec3::count()
{
	std::cout <<"Sveukupno je "<< counter<<" vektora.";
}



int Vec3::counter = 0;

std::istream & OOP::operator>>(std::istream & input, Vec3 & v)
{
	std::cout << "Unesite i, j i k\n";
	input >> v.i >> v.j >> v.k;
	return input;
}

std::ostream & OOP::operator<<(std::ostream & os, const Vec3 & v)
{
	os << "v=" << v.i << "x+" << v.j << "y+" << v.k << "z\n";
	return os;
}
