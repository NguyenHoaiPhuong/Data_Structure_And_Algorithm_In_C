#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Utilities.h"

template <typename T>
void Merge3Arrays(const size_t& lo, const size_t& mid1, const size_t& mid2, const size_t& hi, T* a)
{
	std::unique_ptr<T[]> tmp = std::make_unique<T[]>(hi - lo + 1);

	size_t i = lo;
	size_t j = mid1;
	size_t k = mid2;
	size_t n = 0;

	while (i < mid1 && j < mid2 && k < hi)
	{
		if (a[i] < a[j])
		{
			if (a[i] < a[k])
			{
				tmp[n] = a[i];
				n++;
				i++;
			}
			else
			{
				tmp[n] = a[k];
				n++;
				k++;
			}
		}
		else
		{
			if (a[j] < a[k])
			{
				tmp[n] = a[j];
				n++;
				j++;
			}
			else
			{
				tmp[n] = a[k];
				n++;
				k++;
			}
		}
	}

	while (i < mid1 && j < mid2)
	{
		if (a[i] < a[j])
		{
			tmp[n] = a[i];
			n++;
			i++;
		}
		else
		{
			tmp[n] = a[j];
			n++;
			j++;
		}
	}

	while (i < mid1 && k < hi)
	{
		if (a[i] < a[k])
		{
			tmp[n] = a[i];
			n++;
			i++;
		}
		else
		{
			tmp[n] = a[k];
			n++;
			k++;
		}
	}

	while (j < mid2 && k < hi)
	{
		if (a[j] < a[k])
		{
			tmp[n] = a[j];
			n++;
			j++;
		}
		else
		{
			tmp[n] = a[k];
			n++;
			k++;
		}
	}

	while (i < mid1)
	{
		tmp[n] = a[i];
		n++;
		i++;
	}

	while (j < mid2)
	{
		tmp[n] = a[j];
		n++;
		j++;
	}

	while (k < hi)
	{
		tmp[n] = a[k];
		n++;
		k++;
	}

	std::memcpy(a, tmp.get(), sizeof(T) * (hi - lo));
}

template <typename T>
void MergeSort3Way(const size_t& size, T* a)
{
	if (size <= 1)
		return;

	size_t lo = 0;	
	size_t hi = size;
	size_t mid1 = (size_t)(size / 3);
	size_t mid2 = (size_t)(2 * size / 3);

	MergeSort3Way(mid1 - lo, a);
	MergeSort3Way(mid2 - mid1, a + mid1);
	MergeSort3Way(hi - mid2, a + mid2);
	Merge3Arrays(lo, mid1, mid2, hi, a);
}

void TestMergeSort3Way()
{
	std::vector<int> a = { 7,1,6,9,4,5 };
	std::cout << "Before 3 - Way Merge Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	MergeSort3Way<int>(a.size(), a.data());
	std::cout << "After 3 - Way Merge Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";
}