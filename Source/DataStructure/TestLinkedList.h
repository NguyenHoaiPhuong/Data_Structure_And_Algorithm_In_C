#pragma once
#include "LinkedList.h"

void Test_Linked_List()
{
	CLinkedList Akagi;
	Akagi.Insert(5);
	Akagi.Insert(10);
	Akagi.Insert(3);
	Akagi.Insert(1);
	Akagi.Insert(8);

	CLLNode* p = Akagi.Find(3);
	std::cout << p->GetKey() << std::endl;

	Akagi.Print();

	Akagi.Remove(5);
	Akagi.Print();

	Akagi.Remove(1);
	Akagi.Print();

	Akagi.RemoveAll();
	Akagi.Print();
}