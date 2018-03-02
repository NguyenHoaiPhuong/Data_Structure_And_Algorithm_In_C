#include "LLNode.h"

CLLNode::CLLNode(const long& key)
{
	m_iKey = key;
	m_pNext.reset(nullptr);
}

CLLNode::~CLLNode()
{
}

long CLLNode::GetKey() const
{
	return m_iKey;
}

void CLLNode::SetKey(const long & key)
{
	m_iKey = key;
}

CLLNode * CLLNode::GetNextNode() const
{
	return m_pNext.get();
}

void CLLNode::SetNextNode(CLLNode * pNext)
{
	m_pNext.release();
	m_pNext.reset(pNext);
}

void CLLNode::Insert(const long& key)
{
	if (IsExisting(key) == false)
	{
		if (m_pNext.get() != nullptr)
			m_pNext->Insert(key);
		else
			m_pNext.reset(new CLLNode(key));
	}	
}

CLLNode * CLLNode::Find(const long & key)
{
	if (m_iKey == key)
		return this;
	else
	{
		if (m_pNext.get() == nullptr)
			return nullptr;
		else
			return m_pNext->Find(key);
	}
}

bool CLLNode::IsExisting(const long & key)
{
	if (m_iKey == key)
		return true;
	else
	{
		if (m_pNext.get() == nullptr)
			return false;
		else
			return m_pNext->IsExisting(key);
	}
}
