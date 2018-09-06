#pragma once
#include "HashTable.h"

void TestHashTable()
{
	const int TB_SIZE = 5;
	const long num[] = {  1,  3,  5,  7,  9,
						 11, 13, 15, 17, 19,
						 21, 23, 25, 27, 29,
						 31, 33, 35, 37, 39,
						 41, 43, 45, 47, 49 };
	HashTable<long> tbl(TB_SIZE);
	//for (int i = 0; i < TB_SIZE * 3; i++)
	for (int i = TB_SIZE * 3 - 1; i >= 0; i--)
	{
		tbl.Insert(num[i]);
	}

	std::cout << "Before sort:\n";
	for (int i = 0; i < TB_SIZE; i++)
	{
		std::cout << "Cell #" << i << "\n";
		tbl.Print(i);
	}

	std::cout << "After sort:\n";	
	for (int i = 0; i < TB_SIZE; i++)
	{
		tbl.Sort(i);
		std::cout << "Cell #" << i << "\n";
		tbl.Print(i);
	}
}
