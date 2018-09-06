#pragma once
#include "MaxBinaryHeap.h"

void Test_Max_Heap()
{
	CMaxBinaryHeap Akagi(20);

	Akagi.Insert(7);
	Akagi.Insert(5);
	Akagi.Insert(3);
	Akagi.Insert(9);
	Akagi.Insert(10);
	Akagi.Insert(17);
	Akagi.Insert(14);
	Akagi.Insert(16);

	Akagi.Print(PrintType::TREE);

	std::cout << std::endl;
	std::cout << "---------------- Remove 9 ----------------\n";
	Akagi.Remove(9);
	Akagi.Print(PrintType::TREE);

	std::cout << std::endl;
	std::cout << "---------------- Remove 3 ----------------\n";
	Akagi.Remove(3);
	Akagi.Print(PrintType::TREE);

	std::cout << std::endl;
	std::cout << "---------------- Change Key 7 to 20 ----------------\n";
	Akagi.ChangeKey(4, 20);
	Akagi.Print(PrintType::TREE);

	std::cout << std::endl;
	std::cout << "---------------- Change Key 14 to 3 ----------------\n";
	Akagi.ChangeKey(2, 3);
	Akagi.Print(PrintType::TREE);
}