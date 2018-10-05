#pragma once
#include <iostream>
#include <vector>
#include "Utilities.h"

template<typename T>
void RecursiveInsertionSort(const size_t& size, T* arr)
{
	if (size <= 1)	return;

	RecursiveInsertionSort(size - 1, arr);
	for (size_t i = size - 2; i >= 0; i--)
	{
		if (arr[i + 1] < arr[i])
			Swap(arr[i], arr[i + 1]);
		else
			break;
	}
}

void TestRecursiveInsertionSort()
{
	std::vector<int> a = { 7,1,6,9,4,5 };
	std::cout << "Before Recursive Insertion Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	RecursiveInsertionSort<int>(a.size(), a.data());
	std::cout << "After Recursive Insertion Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";
}