#pragma once
#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <iostream>
template<typename T1, typename T2>
class Pair
{
	T1 first;
	T2 second;
public:
	Pair() = default;
	Pair(T1& t1=nullptr, T2& t2=nullptr) : first(t1), second(t2) {}
	Pair(const Pair<T1, T2>& other) : first(other.first), second(other.second) {}
	bool operator== (const Pair<T1, T2>& other) const
	{
		return first == other.first && second == other.second;
	}
	bool operator>(const Pair<T1, T2>& other) const
	{
		return first > other.first && second > other.second;
	}
	bool operator>=(const Pair<T1, T2>& other) const
	{
		return first >= other.first && second >= other.second;
	}
	bool operator<(const Pair<T1, T2>& other) const
	{
		return first < other.first && second < other.second;
	}
	bool operator<=(const Pair<T1, T2>& other) const
	{
		return first <= other.first && second <= other.second;
	}
	bool operator!=(const Pair<T1, T2>& other) const
	{
		return first != other.first && second != other.second;
	}
	Pair & operator=(const Pair<T1, T2>& other)
	{
		first = other.first;
		second = other.second;
		return *this;
	}
	friend std::istream& operator>> (std::istream& is, Pair & p)
	{
		std::cout << "Unesite par\n";
		is >> p.first >> p.second;
		return is;
	}
	friend std::ostream& operator<< (std::ostream& os, Pair & p)
	{
		os << "pair=" << p.first << ", " << p.second;
		return os;
	}
	friend void swap(Pair<T1, T2>& other)
	{
		T1 temp1;
		T2 temp2;
		temp1 = first;
		first = other.first;
		other.first = temp1;
		temp2 = second;
		second = other.second;
		other.second = temp2;
	}
};
template<>
class Pair<char*, char*>
{
	char first, second;
public:
	Pair(const char t1,const char t2)
	{
		first = t1;
		second = t2;
	}
	Pair(const Pair<char*, char*>& other) : first(other.first), second(other.second) {}
	bool operator== (const Pair<char*, char*>& other) const
	{
		return first == other.first && second == other.second;
	}
	bool operator>(const Pair<char*, char*>& other) const
	{
		return first > other.first && second > other.second;
	}
	bool operator>=(const Pair<char*, char*>& other) const
	{
		return first >= other.first && second >= other.second;
	}
	bool operator<(const Pair<char*, char*>& other) const
	{
		return first < other.first && second < other.second;
	}
	bool operator<=(const Pair<char*, char*>& other) const
	{
		return first <= other.first && second <= other.second;
	}
	bool operator!=(const Pair<char*, char*>& other) const
	{
		return first != other.first && second != other.second;
	}
	Pair & operator=(const Pair<char*, char*>& other)
	{
		first = other.first;
		second = other.second;
		return *this;
	}
	friend std::istream& operator>> (std::istream& is, Pair & p)
	{
		std::cout << "Unesite par\n";
		is >> p.first >> p.second;
		return is;
	}
	friend std::ostream& operator<< (std::ostream& os, Pair & p)
	{
		os << "pair=" << p.first << ", " << p.second;
		return os;
	}
	friend void swap(Pair<char*, char*>& other, Pair<char*, char*>& a)
	{
		char temp1;
		char temp2;
		temp1 = a.first;
		a.first = other.first;
		other.first = temp1;
		temp2 = a.second;
		a.second = other.second;
		other.second = temp2;
	}
};
#endif



