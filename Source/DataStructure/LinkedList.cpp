#include "LinkedList.h"

CLinkedList::CLinkedList()
{
}

CLinkedList::~CLinkedList()
{
}

void CLinkedList::Insert(const long & data)
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

void CLinkedList::Remove(const long & key)
{
	if (m_pHead.get() != nullptr)
	{
		CLLNode* pParent = new CLLNode(LONG_MIN);
		if (m_pHead->m_iKey == key)
		{
			CLLNode* p = m_pHead.release();
			p->Remove(key, pParent);
		}
		else
			m_pHead->Remove(key, pParent);
		if (pParent->m_pNext != nullptr)
			m_pHead.reset(pParent->m_pNext.release());
		delete pParent;
	}	
}

void CLinkedList::RemoveAll()
{
	if (m_pHead.get() != nullptr)
		m_pHead.reset(nullptr);
}

void CLinkedList::Print()
{
	CLLNode* p = m_pHead.get();
	if (p == nullptr)
		std::cout << "Empty List" << std::endl;
	else
	{
		while (p != nullptr)
		{
			std::cout << p->GetKey() << "\t";
			p = p->GetNextNode();
		}
		std::cout << std::endl;
	}	
}
