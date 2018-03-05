#include <iostream>
#include "LinkedList.h"

void Test_Shared_PTR()
{
	double *a = new double[3];
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;

	std::shared_ptr<double> akagi(a);
	//std::shared_ptr<double> yushin(a);
	//std::shared_ptr<double> yushin = std::make_shared<double>(*a);
	std::shared_ptr<double> yushin(akagi);

	std::cout << akagi.get()[0] << "\t" << akagi.get()[1] << "\t" << akagi.get()[2] << "\n";

	std::cout << akagi.use_count() << "\n";
	std::cout << yushin.use_count() << "\n";

	std::cout << yushin.unique() << "\n";

#if 0
	yushin.reset();
	std::cout << akagi.use_count() << "\n";
	std::cout << akagi.get()[0] << "\t" << akagi.get()[1] << "\t" << akagi.get()[2] << "\n";
#endif

	akagi.reset();
	std::cout << yushin.use_count() << "\n";
	std::cout << yushin.get()[0] << "\t" << yushin.get()[1] << "\t" << yushin.get()[2] << "\n";
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

void Test_BST()
{
	//
}

int main(int argc, char* argv[])
{
	//Test_Linked_List();

	getchar();
	return 0;
}