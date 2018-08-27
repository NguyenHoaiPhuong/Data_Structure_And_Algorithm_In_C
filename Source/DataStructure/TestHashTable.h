#pragma once
#include "HashTable.h"

void TestHashTable()
{
	const int TB_SIZE = 5;
	const long num[] = {  1,  3,  5,  7,  9,
						 11, 13, 15, 17, 19,
						 21, 23, 25, 27, 29 };
	HashTable<long> tbl(TB_SIZE);
	for (int i = 0; i < TB_SIZE * 3; i++)
	{
		tbl.Insert(num[i]);
	}
}