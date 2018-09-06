#pragma once
#include "BST.h"

void Test_BST()
{
	CBST Akagi;
	Akagi.Insert(4);
	Akagi.Insert(1);
	Akagi.Insert(8);
	Akagi.Insert(5);
	Akagi.Insert(6);
	Akagi.Insert(2);
	Akagi.Insert(3);
	Akagi.Insert(7);

	Akagi.Remove(4);
	Akagi.Remove(8);
	Akagi.Remove(6);

	std::vector<long> arKey = Akagi.Traverse();
	Akagi.Print();

	std::cout << "Tree Height: " << Akagi.GetHeight() << std::endl;
}