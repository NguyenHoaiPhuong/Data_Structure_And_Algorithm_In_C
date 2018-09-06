#pragma once
#include "Animal_Operation.h"


void TestSunshine()
{
	Display(Cat());
	Display(Dog());
}

double add1(const double& a, const double& b)
{
	double c = a + b;
	std::cout << "Address of result in add1: " << &c << "\n";
	return c;
}

double& add2(const double& a, const double& b)
{
	double c = a + b;
	std::cout << "Address of result in add2: " << &c << "\n";
	return c;
}