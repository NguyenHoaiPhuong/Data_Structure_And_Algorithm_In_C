#pragma once
#include "DoubleLinkedList.h"

void Test_Double_Linked_List()
{
	CDoubleLinkedList Akagi;
	Akagi.Insert(10);
	Akagi.Insert(5);
	Akagi.Insert(8);
	Akagi.Insert(1);
	Akagi.Insert(3);

	Akagi.Remove(10);
	Akagi.Remove(8);
	Akagi.Remove(3);

	CDLLNode* p = Akagi.Find(1);
	CDLLNode* q = Akagi.RFind(1);

	Akagi.Print();
}