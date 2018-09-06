#pragma once
#include <iostream>
#include <unordered_map>
#include "Animal.h"


template <class O>
class Animal_Factory
{
private:
	std::unordered_map< std::string, O* > map_;
	Animal_Factory() { map_ = {}; }

public:
	static Animal_Factory& get()
	{
		static Animal_Factory instance;
		return instance;
	}

	template <class ANIMAL>
	void reg(O* A)
	{
		std::string hash = typeid(ANIMAL).name();
		map_[hash] = A;
	}

	O* operation(Animal& a)
	{
		std::string hash = typeid(a).name();
		auto it = map_.find(hash);
		if (it != map_.end())
			return it->second;
		return nullptr;
	}
};

class Animal_Operation
{
public:
	static void perform(Animal& a)
	{
		Animal_Operation* impl = Animal_Factory<Animal_Operation>::get().operation(a);
		if (impl)
			impl->operator()(a);
	}

protected:
	virtual void operator()(Animal& a) = 0;
};

template <class O, class ANIMAL>
class Animal_Implementation : public O
{
private:
	static Animal_Implementation<O, ANIMAL> _instance;

	Animal_Implementation()
	{
		Animal_Factory<O>::get().reg<ANIMAL>(this);
	}

protected:
	virtual void operator()(ANIMAL& a);

public:
	static Animal_Implementation<O, ANIMAL>& get() { return _instance; }
};

//template class Animal_Implementation<Dog>;
//template class Animal_Implementation<Cat>;


void Animal_Implementation<Animal_Operation, Dog>::operator()(Dog& a)
{
	std::cout << "Dog\n";
}

void Animal_Implementation<Animal_Operation, Cat>::operator()(Cat& a)
{
	std::cout << "Cat\n";
}




void Display(Animal& a)
{
	Animal_Operation::perform(a);
}