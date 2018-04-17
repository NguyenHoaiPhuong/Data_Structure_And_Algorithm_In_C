#include <iostream>
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "BST.h"
#include "AVLTree.h"
#include "MinBinaryHeap.h"

void Test_Shared_PTR()
{
	int* p = new int(3);

	std::shared_ptr<int> a(p);
	std::cout << a.use_count() << std::endl;

	std::shared_ptr<int> b(a);
	std::cout << "b useCnt = " << b.use_count() << std::endl;

	std::shared_ptr<int> c = std::make_shared<int>(10);
	std::cout << "c = " << *c << ", use cnt = " << c.use_count() << std::endl;

	std::shared_ptr<int> d;
	d.swap(a);
	std::cout << d.use_count() << std::endl;
}

void Test_Shared_PTR_1()
{
	int* p = new int(10);

	std::shared_ptr<int> a = std::make_shared<int>(*p);
	std::shared_ptr<int> b = a;

	std::cout << "a use count = " << a.use_count() << std::endl;
}

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

void Test_Heap()
{
	CMinBinaryHeap Akagi(20);

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
	Akagi.ChangeKey(1, 20);
	Akagi.Print(PrintType::TREE);

	std::cout << std::endl;
	std::cout << "---------------- Change Key 14 to 3 ----------------\n";
	Akagi.ChangeKey(2, 3);
	Akagi.Print(PrintType::TREE);
}

int main(int argc, char* argv[])
{
	//Test_Shared_PTR();
	//Test_Shared_PTR_1();
	//Test_Linked_List();
	//Test_Double_Linked_List();
	//Test_BST();
	//Test_AVL_Tree();
	Test_Heap();

	getchar();
	return 0;
}