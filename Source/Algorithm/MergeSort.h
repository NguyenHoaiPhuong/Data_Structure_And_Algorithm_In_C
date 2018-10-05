#pragma once
#include <iostream>
#include "Utilities.h"

template <typename T>
void Merge(const size_t& totElem, const size_t& half, T* a)
{
	T* tmp = (T*)malloc(totElem * sizeof(T));
	std::fill_n(tmp, totElem, 0.0);

	size_t i = 0;
	size_t j = half;
	size_t k = 0;
	while (i < half && j < totElem)
	{
		if (a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	while (i < half)
	{
		tmp[k++] = a[i++];
	}
	while (j < totElem)
	{
		tmp[k++] = a[j++];
	}

	std::memcpy(a, tmp, totElem * sizeof(T));
	delete tmp;
}

template <typename T>
void MergeSort(const size_t& aNum, T* a)
{
	if (aNum == 1)
		return;

	int half = (int) (aNum / 2);
	MergeSort(half, a);
	MergeSort(aNum - half, a + half);
	Merge<T>(aNum, half, a);
}

void TestMergeSort()
{
	const size_t totElem = 8;
	double a[] = { 14, 7, 4, 1, 17, 9, 3, 27 };

	std::cout << "Before Merge Sort:\n";
	for (size_t i = 0; i < totElem; i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	MergeSort<double>(totElem, a);

	std::cout << "After Merge Sort:\n";
	for (size_t i = 0; i < totElem; i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";
}