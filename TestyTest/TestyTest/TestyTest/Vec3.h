#pragma once
#ifndef VEC3_H
#define VEC3_H
#include <iostream>
namespace OOP
{
	class Vec3
	{
		double i, j, k;
		static int counter;
	public:
		Vec3();
		Vec3(double x, double y, double z);
		~Vec3();
		friend std::istream& operator>>(std::istream &input, Vec3& v);
		friend std::ostream& operator<<(std::ostream &os, const Vec3& v);
		Vec3& operator=(const Vec3& other);
		Vec3 operator+(const Vec3& other);
		Vec3 operator-(const Vec3& other);
		Vec3& operator+=(const Vec3& other);
		Vec3& operator-=(const Vec3& other);
		Vec3& operator*(const double a);
		Vec3& operator/(const double a);
		Vec3& operator*=(const double a);
		Vec3& operator/=(const double a);
		double operator*(const Vec3& other);
		bool operator==(const Vec3& other);
		bool operator!=(const Vec3& other);
		Vec3& clan();
		double operator[](char a);
		void count();
	};
}

#endif // !VEC3_H

