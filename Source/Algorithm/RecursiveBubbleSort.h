#pragma once
#include <iostream>
#include <vector>
#include "Utilities.h"

template <typename T>
void RecursiveBubbleSort(const size_t& size, T* arr)
{
	if (size <= 1)	return;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			Swap(arr[i], arr[i + 1]);
	}

	RecursiveBubbleSort(size - 1, arr);
}

void TestRecursiveBubbleSort()
{
	std::vector<int> a = { 7,1,6,9,4,5 };
	std::cout << "Before Recursive Bubble Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	RecursiveBubbleSort<int>(a.size(), a.data());
	std::cout << "After Recursive Bubble Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";
}