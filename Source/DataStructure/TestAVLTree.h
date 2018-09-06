#pragma once
#include "AVLTree.h"

void Test_AVL_Tree()
{
	CAVLTree Akagi;

	Akagi.Insert(20);
	std::cout << "--------------------------------Insert(20)--------------------------------------\n";
	Akagi.Print();

	Akagi.Insert(25);
	std::cout << "--------------------------------Insert(25)--------------------------------------\n";
	Akagi.Print();

	Akagi.Insert(30);
	std::cout << "--------------------------------Insert(30)--------------------------------------\n";
	Akagi.Print();

	Akagi.Insert(7);
	std::cout << "--------------------------------Insert(7)---------------------------------------\n";
	Akagi.Print();

	Akagi.Insert(25);
	std::cout << "--------------------------------Insert(25)--------------------------------------\n";
	Akagi.Print();

	Akagi.Insert(22);
	std::cout << "--------------------------------Insert(22)--------------------------------------\n";
	Akagi.Print();

	Akagi.Insert(24);
	std::cout << "--------------------------------Insert(24)--------------------------------------\n";
	Akagi.Print();

	std::cout << "-------------------------------------------------------------------------------\n";

	std::shared_ptr<CAVLNode> q = Akagi.Find(16);
	if (q)
		std::cout << "Node ID " << q->GetKey() << ", H = " << q->GetHeight() << ", Balance = " << q->GetBalance() << std::endl;

	std::cout << "----------------------------------------------------------------------\n";

	std::shared_ptr<CAVLNode> m = Akagi.FindMax();
	if (m)
		std::cout << "Node with Max ID " << m->GetKey() << ", H = " << m->GetHeight() << ", Balance = " << m->GetBalance() << std::endl;

	std::cout << "----------------------------------------------------------------------\n";

	std::shared_ptr<CAVLNode> n = Akagi.FindMin();
	if (n)
		std::cout << "Node with Min ID " << n->GetKey() << ", H = " << n->GetHeight() << ", Balance = " << n->GetBalance() << std::endl;

	std::cout << "----------------------------------------------------------------------\n";

	Akagi.Remove(22);
	std::cout << "--------------------------------Delete(22)--------------------------------------\n";
	Akagi.Print();

	Akagi.Remove(30);
	std::cout << "--------------------------------Delete(30)--------------------------------------\n";
	Akagi.Print();

	Akagi.Remove(25);
	std::cout << "--------------------------------Delete(25)--------------------------------------\n";
	Akagi.Print();

	Akagi.Remove(7);
	std::cout << "--------------------------------Delete(7)--------------------------------------\n";
	Akagi.Print();

	std::cout << "--------------------------------Sorted Array--------------------------------------\n";
	std::vector<long> array = Akagi.TraverseTree();
	for (long i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------------\n";
	std::shared_ptr<CAVLNode> p = Akagi.Find(20);
	if (p)
		std::cout << "Node ID " << p->GetKey() << ", H = " << p->GetHeight() << ", Balance = " << p->GetBalance() << std::endl;

	std::cout << "----------------------------------------------------------------------\n";
}