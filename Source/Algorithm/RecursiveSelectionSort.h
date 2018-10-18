#pragma once
#include <iostream>
#include <vector>
#include "Utilities.h"

template <typename T>
void RecursiveSelectionSort(const size_t& size, T* a)
{
	if (size <= 1)
		return;

	size_t minIdx = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (a[minIdx] > a[i])
			minIdx = i;
	}
	if (minIdx != 0)
		Swap(a[0], a[minIdx]);

	RecursiveSelectionSort(size - 1, a + 1);
}


void TestRecursiveSelectionSort()
{
	std::vector<int> a = { 7,1,6,9,4,5 };
	std::cout << "Before Recursive Selection Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	RecursiveSelectionSort<int>(a.size(), a.data());
	std::cout << "After Recursive Selection Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";
}