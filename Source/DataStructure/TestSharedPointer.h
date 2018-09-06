#pragma once
#include <iostream>
#include <memory>

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
	std::cout << a.use_count() << std::endl;
}

void Test_Shared_PTR_1()
{
	int* p = new int(10);

	std::shared_ptr<int> a = std::make_shared<int>(*p);
	std::shared_ptr<int> b = a;

	std::cout << "a use count = " << a.use_count() << std::endl;
	std::cout << "b use count = " << b.use_count() << std::endl;
}