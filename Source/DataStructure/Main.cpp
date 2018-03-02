#include <iostream>
#include "LinkedList.h"

int main(int argc, char* argv[])
{
	CLinkedList Akagi;
	Akagi.Insert(5);
	Akagi.Insert(10);
	Akagi.Insert(3);
	Akagi.Insert(1);
	Akagi.Insert(8);

	Akagi.Print();
	getchar();
	return 0;
}