#include <iostream>
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "BST.h"

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

	CDLLNode* p = Akagi.Find(8);
	CDLLNode* q = Akagi.RFind(8);

	Akagi.Remove(10);
	Akagi.Remove(8);

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

int main(int argc, char* argv[])
{
	//Test_Shared_PTR();
	//Test_Shared_PTR_1();
	//Test_Linked_List();
	Test_Double_Linked_List();
	//Test_BST();

	getchar();
	return 0;
}