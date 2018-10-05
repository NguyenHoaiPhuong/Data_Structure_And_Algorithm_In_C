#pragma once
#include <iostream>
#include <vector>
#include "Utilities.h"

template<typename T>
void SortingInsertion(const size_t& size, T* arr)
{
	for (size_t i = 1; i < size; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
				Swap(arr[j - 1], arr[j]);
			else
				break;
		}
	}
}

void TestInsertionSort()
{
	std::vector<int> a = { 7,1,6,9,4,5 };
	std::cout << "Before Insertion Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	SortingInsertion<int>(a.size(), a.data());
	std::cout << "After Insertion Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";
}