#include "DLLNode.h"

CDLLNode::CDLLNode(const long & key)
{
	m_iKey = key;
}

CDLLNode::~CDLLNode()
{
}

long CDLLNode::GetKey()
{
	return m_iKey;
}

void CDLLNode::SetKey(const long& key)
{
	m_iKey = key;
}

CDLLNode * CDLLNode::GetNextNode()
{
	return m_pNext.get();
}

void CDLLNode::SetNextNode(CDLLNode * pHead)
{
	m_pNext.reset(pHead);
}

CDLLNode * CDLLNode::GetPreviousNode()
{
	return m_pPrev.get();
}

void CDLLNode::SetPreviousNode(CDLLNode * pTail)
{
	m_pPrev.reset(pTail);
}
