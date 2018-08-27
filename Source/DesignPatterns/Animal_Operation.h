#pragma once
#include <iostream>
#include <unordered_map>
#include "Animal.h"

class Animal_Operation
{
public:
	static void perform(Animal* a)
	{
		
	}

protected:
	virtual void operator()(Animal* a) = 0;
};

template <class ANIMAL>
class Animal_Implementation : public Animal_Operation
{
private:
	static Animal_Implementation<ANIMAL> _instance;

	Animal_Implementation()
	{
		Animal_Factory::get().reg(this);
	}

protected:
	virtual void operator()(ANIMAL* a);

public:
	static Animal_Implementation<ANIMAL>& get() { return _instance; }
};

void Animal_Implementation<Dog>::operator()(Dog* a)
{
	std::cout << "Dog\n";
}

void Animal_Implementation<Cat>::operator()(Cat* a)
{
	std::cout << "Cat\n";
}


class Animal_Factory
{
private:
	std::unordered_map< std::string, Animal_Operation* > map_;
	Animal_Factory() { map_ = {}; }

public:
	static Animal_Factory& get()
	{
		static Animal_Factory instance;
		return instance;
	}

	void reg(Animal_Operation* A)
	{
		std::string hash = typeid(A).name();
		map_[hash] = A;
	}

	/*Animal_Operation* operation(Animal& a)
	{

	}*/

};

void Display(Animal* a)
{
	Animal_Operation::perform(a);
}

