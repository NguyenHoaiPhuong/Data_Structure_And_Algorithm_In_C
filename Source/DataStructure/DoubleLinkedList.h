#pragma once
#include "DLLNode.h"

/****************************************************/
/* Each element in this double linked list is unique*/
/****************************************************/
class CDoubleLinkedList
{
private:
	std::shared_ptr<CDLLNode> m_pHead;
	std::shared_ptr<CDLLNode> m_pTail;
protected:
	//
public:
	CDoubleLinkedList();
	~CDoubleLinkedList();

	bool Exist(const long& key);

	CDLLNode* Find(const long& key);
	CDLLNode* RFind(const long& key);

	bool Insert(const long& key);
	bool Remove(const long& key);

	void Print();
};