#pragma once
#include <iostream>
#include <vector>

template<typename T>
void Swap(T& a, T&b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void SortingBubble(const size_t& size, T* arr)
{
	for (size_t i = size - 1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	}
}

void TestBubbleSort()
{
	std::vector<int> a = { 7,1,6,9,4,5 };
	std::cout << "Before Bubble Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
	std::cout << "\n";

	SortingBubble<int>(a.size(), a.data());
	std::cout << "After Bubble Sorting:\n";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << "\t";
}