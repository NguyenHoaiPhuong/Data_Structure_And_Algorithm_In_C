#pragma once
#include <iostream>

class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
private:
	int* p;

public:
	MyIterator(int* x) { p = x; }
	MyIterator(const MyIterator& other) { p = other.p; }

	MyIterator& operator=(const MyIterator& other)
	{
		p = other.p;
		return *this;
	}

	bool operator==(const MyIterator& other)
	{
		return (p == other.p);
	}

	bool operator!=(const MyIterator& other)
	{
		return (p != other.p);
	}

	MyIterator& operator++()
	{
		p++;
		return *this;
	}
	MyIterator operator++(int)
	{
		MyIterator tmp(*this);
		operator++();
		return tmp;
	}

	MyIterator& operator--()
	{
		p--;
		return *this;
	}
	MyIterator& operator--(int)
	{
		p--;
		return *this;
	}

	int operator*()
	{
		return *p;
	}
};

void TestMyIteratorClass()
{
	int num[5] = { 0, 1, 2, 3, 4 };
	//MyIterator begin(num);
	MyIterator begin = num;
	MyIterator end(num + 5);
	for (auto it = begin; it != end; it++)
	{
		std::cout << *it << std::endl;
	}
}