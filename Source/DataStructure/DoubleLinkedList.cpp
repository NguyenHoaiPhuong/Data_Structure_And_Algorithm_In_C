#include <iostream>
#include "DoubleLinkedList.h"

CDoubleLinkedList::CDoubleLinkedList()
{
}

CDoubleLinkedList::~CDoubleLinkedList()
{
}

bool CDoubleLinkedList::Exist(const long & key)
{
	CDLLNode* p = m_pHead.get();
	while (p)
	{
		if (p->m_iKey == key)
			return true;
		p = p->m_pNext.get();
	}
	return false;
}

CDLLNode * CDoubleLinkedList::Find(const long& key)
{
	CDLLNode* p = m_pHead.get();
	while (p)
	{
		if (p->m_iKey == key)
			return p;
		p = p->m_pNext.get();
	}
	return nullptr;
}

CDLLNode * CDoubleLinkedList::RFind(const long & key)
{
	CDLLNode* p = m_pTail.get();
	while (p)
	{
		if (p->m_iKey == key)
			return p;
		p = p->m_pPrev.get();
	}
	return nullptr;
}

bool CDoubleLinkedList::Insert(const long & key)
{
	if (Exist(key) == true)
		return false;
	if (m_pHead == nullptr)
	{
		std::shared_ptr<CDLLNode> p ( new CDLLNode(key) );
		m_pHead = p;
		m_pTail = m_pHead;
	}
	else
	{
		std::shared_ptr<CDLLNode> p(new CDLLNode(key));
		p->m_pPrev = m_pTail;
		m_pTail->m_pNext = p;
		m_pTail = p;
	}
	return true;
}

bool CDoubleLinkedList::Remove(const long & key)
{
	if (!m_pHead)
		return false;
	if (m_pHead->m_iKey == key)
	{
		std::shared_ptr<CDLLNode> p = m_pHead->m_pNext;
		m_pHead->m_pNext.reset();
		p->m_pPrev.reset();
		CDLLNode* q = m_pHead.get();
		m_pHead = p;
		return true;
	}
	else
	{
		std::shared_ptr<CDLLNode> pCurNode = m_pHead->m_pNext;
		while (pCurNode)
		{
			if (pCurNode->m_iKey == key)
			{
				std::shared_ptr<CDLLNode> pPrevNode = pCurNode->m_pPrev;
				std::shared_ptr<CDLLNode> pNextNode = pCurNode->m_pNext;
				pCurNode->m_pPrev.reset();
				pCurNode->m_pNext.reset();
				pPrevNode->m_pNext = pNextNode;
				if (pNextNode)
					pNextNode->m_pPrev = pPrevNode;
				else
					m_pTail = pPrevNode;
				return true;
			}
			else
			{
				pCurNode = pCurNode->m_pNext;
			}
		}
		return false;
	}
}

void CDoubleLinkedList::Print()
{
	CDLLNode* p = m_pHead.get();
	while (p)
	{
		std::cout << p->m_iKey << "\t";
		p = p->m_pNext.get();
	}
}
