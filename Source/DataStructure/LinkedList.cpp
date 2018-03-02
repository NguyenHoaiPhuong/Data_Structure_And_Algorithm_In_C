#include "LinkedList.h"

CLinkedList::CLinkedList()
{
}

CLinkedList::~CLinkedList()
{
}

void CLinkedList::Insert(const double & data)
{
	if (m_pHead.get() == nullptr)
		m_pHead.reset(new CLLNode(data));
	else
		m_pHead->Insert(data);
}

CLLNode * CLinkedList::Find(const long & key)
{
	if (m_pHead.get() == nullptr)
		return nullptr;
	else
		return m_pHead->Find(key);
}

void CLinkedList::Print()
{
	CLLNode* p = m_pHead.get();
	while (p != nullptr)
	{
		std::cout << p->GetKey() << "\t";
		p = p->GetNextNode();
	}
}
