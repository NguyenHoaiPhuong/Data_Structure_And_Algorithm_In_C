#pragma once
#include <iostream>
#include <vector>
#include "Utilities.h"

template <typename T>
void SelectionSort(const size_t& totElems, T* a)
{
	for (size_t i = 0; i < totElems - 1; i++)
	{
		size_t idxMin = i;
		for (size_t j = i + 1; j < totElems; j++)
		{
			if (a[j] < a[idxMin])
				idxMin = j;
		}
		if (idxMin != i)
			Swap(a[i], a[idxMin]);
	}
}

void TestSelectionSort()
{
	std::vector<int> a = { 7,1,6,9,4,5 };
	std::cout << "Before Selection Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	SelectionSort<int>(a.size(), a.data());
	std::cout << "After Selection Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";
}