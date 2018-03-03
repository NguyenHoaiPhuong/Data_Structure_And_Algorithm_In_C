#pragma once
#include <iostream>
#include "LLNode.h"

class CLinkedList
{
private:
	std::unique_ptr<CLLNode> m_pHead;
protected:
	//
public:
	CLinkedList();
	~CLinkedList();

	void Insert(const double& data);
	CLLNode* Find(const long& key);
	void Remove(const long& key);
	void RemoveAll();
	void Print();
};