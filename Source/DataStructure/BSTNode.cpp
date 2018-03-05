#include "BSTNode.h"

CBSTNode::CBSTNode(const long & key)
{
	m_iKey = key;
}

CBSTNode::~CBSTNode()
{
}

long CBSTNode::GetKey()
{
	return m_iKey;
}

void CBSTNode::SetKey(const long & key)
{
	m_iKey = key;
}

CBSTNode * CBSTNode::GetLeftNode()
{
	return m_pLeft.get();
}

void CBSTNode::SetLeftNode(CBSTNode * pLeft)
{
	m_pLeft.reset(pLeft);
}

CBSTNode * CBSTNode::GetRightNode()
{
	return m_pRight.get();
}

void CBSTNode::SetRightNode(CBSTNode * pRight)
{
	m_pRight.reset(pRight);
}

CBSTNode * CBSTNode::Find(const long & key)
{
	if (m_iKey == key)
		return this;
	else if (m_iKey < key)
	{
		if (m_pRight.get() != nullptr)
			return m_pRight->Find(key);
		else
			return nullptr;
	}
	else if (m_iKey > key)
	{
		if (m_pLeft.get() != nullptr)
			return m_pLeft->Find(key);
		else
			return nullptr;
	}	
}

void CBSTNode::Insert(const long & key)
{
	if (key < m_iKey)
	{
		if (m_pLeft.get() != nullptr)
			m_pLeft->Insert(key);
		else
			m_pLeft.reset(new CBSTNode(key));
	}
	else if (key > m_iKey)
	{
		if (m_pRight.get() != nullptr)
			m_pRight->Insert(key);
		else
			m_pRight.reset(new CBSTNode(key));
	}
	else
		return;
}
