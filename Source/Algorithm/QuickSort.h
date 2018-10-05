#pragma once
#include <iostream>
#include <vector>
#include "Utilities.h"

template<typename T>
size_t QuickPartition(const size_t& totElems, T* a)
{
	int l = -1;
	int r = totElems - 1;
	T pivot = a[r];
	while (true)
	{
		while (a[++l] < pivot && l < totElems)
		{
		}
		while (a[--r] > pivot && r > -1)
		{
		}
		if (l >= r)
			break;
		else
			Swap(a[l], a[r]);
	}
	Swap(a[l], a[totElems - 1]);
	return l;
}

template<typename T>
void QuickSort(const size_t& totElems, T* a)
{
	size_t idx = QuickPartition(totElems, a);
	if (idx == 0 || idx >= totElems - 1)
		return;
	QuickSort(idx, a);
	QuickSort(totElems - idx - 1, a + idx + 1);
}

void TestQuickSort()
{
	std::vector<int> a = { 7,1,6,9,4,5 };
	std::cout << "Before Quick Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	QuickSort<int>(a.size(), a.data());
	std::cout << "After Quick Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";
}
