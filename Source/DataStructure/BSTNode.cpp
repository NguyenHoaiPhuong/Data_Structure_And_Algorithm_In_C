#include "BSTNode.h"

#define max(a, b)	\
(a>b)? a : b;		\

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

CBSTNode * CBSTNode::FindMax()
{
	if (m_pRight.get() == nullptr)
		return this;
	else
		return m_pRight->FindMax();
}

CBSTNode * CBSTNode::FindMin()
{
	if (m_pLeft.get() == nullptr)
		return this;
	else
		return m_pLeft->FindMin();
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

bool CBSTNode::Insert(const long & key)
{
	if (key < m_iKey)
	{
		if (m_pLeft.get() != nullptr)
			return m_pLeft->Insert(key);
		else
		{
			m_pLeft.reset(new CBSTNode(key));
			return true;
		}
	}
	else if (key > m_iKey)
	{
		if (m_pRight.get() != nullptr)
			return m_pRight->Insert(key);
		else
		{
			m_pRight.reset(new CBSTNode(key));
			return true;
		}
	}
	else
		return false;

}

bool CBSTNode::Remove(const long & key, CBSTNode* pParent)
{
	if (key < m_iKey)
	{
		if (m_pLeft.get() != nullptr)
			return m_pLeft->Remove(key, this);
		else
			return false;
	}
	else if (key > m_iKey)
	{
		if (m_pRight.get() != nullptr)
			return m_pRight->Remove(key, this);
		else
			return false;
	}
	else
	{
		if (m_pLeft.get() == nullptr && m_pRight.get() == nullptr)
		{
			if (pParent->m_pLeft.get() == this)
				pParent->m_pLeft.reset();
			else
				pParent->m_pRight.reset();
		}
		else
		{
			if (m_pLeft.get() == nullptr)
			{
				if (pParent->m_pLeft.get() == this)
				{
					pParent->m_pLeft.swap(m_pRight);
					m_pRight.reset();
				}
				else
				{
					pParent->m_pRight.swap(m_pRight);
					m_pRight.reset();
				}
			}
			else if (m_pRight.get() == nullptr)
			{
				if (pParent->m_pLeft.get() == this)
				{
					pParent->m_pLeft.swap(m_pLeft);
					m_pLeft.reset();
				}
				else
				{
					pParent->m_pRight.swap(m_pLeft);
					m_pLeft.reset();
				}
			}
			else
			{
				CBSTNode* pP = this;
				CBSTNode* p = m_pLeft.get();
				while (p->m_pRight.get() != nullptr)
				{
					pP = p;
					p = p->m_pRight.get();
				}
				m_iKey = p->m_iKey;
				if (p->m_pLeft.get() != nullptr)
				{
					pP->m_pRight.swap(p->m_pLeft);
					p->m_pLeft.reset();
				}
				else
					pP->m_pRight.reset();
			}
		}
		return true;
	}
}

void CBSTNode::Traverse(std::vector<long>& arKey)
{
	if (m_pLeft.get() != nullptr)
		m_pLeft->Traverse(arKey);
	arKey.push_back(m_iKey);
	if (m_pRight.get() != nullptr)
		m_pRight->Traverse(arKey);
}

long CBSTNode::GetHeight()
{
	if (m_pLeft.get() == nullptr && m_pRight.get() == nullptr)
		return 0;
	else if (m_pLeft.get() != nullptr && m_pRight.get() == nullptr)
		return 1 + m_pLeft->GetHeight();
	else if (m_pLeft.get() == nullptr && m_pRight.get() != nullptr)
		return 1 + m_pRight->GetHeight();
	else
	{
		long lH = m_pLeft->GetHeight();
		long rH = m_pRight->GetHeight();
		long MAX = max(lH, rH);
		return 1 + MAX;
	}		
}
