#include "AVLNode.h"

CAVLNode::CAVLNode(const long& key, std::shared_ptr<CAVLNode> pParent)
{
	m_iKey = key;
	m_iHeight = 0;
	m_pParent = pParent;
}

CAVLNode::~CAVLNode()
{
}

long CAVLNode::GetKey()
{
	return m_iKey;
}

void CAVLNode::SetKey(const long & key)
{
	m_iKey = key;
}

long CAVLNode::GetHeight()
{
	return m_iHeight;
}

void CAVLNode::SetHeight(const long & height)
{
	m_iHeight = height;
}

CAVLNode * CAVLNode::GetLeftNode()
{
	return m_pLeft.get();
}

void CAVLNode::SetLeftNode(std::shared_ptr<CAVLNode> pLeft)
{
	m_pLeft = pLeft;
}

CAVLNode * CAVLNode::GetRightNode()
{
	return m_pRight.get();
}

void CAVLNode::SetRightNode(std::shared_ptr<CAVLNode> pRight)
{
	m_pRight = pRight;
}

CAVLNode * CAVLNode::GetParentNode()
{
	return m_pParent.get();
}

void CAVLNode::SetParentNode(std::shared_ptr<CAVLNode> pParent)
{
	m_pParent = pParent;
}

void CAVLNode::TraverseTree(std::vector<long>& array)
{
	if (m_pLeft)
		m_pLeft->TraverseTree(array);
	array.push_back(m_iKey);
	if (m_pRight)
		m_pRight->TraverseTree(array);
}

bool CAVLNode::Insert(const long & key)
{
	if (m_iKey == key)
		return false;
	else if (key < m_iKey)
	{
		if (m_pLeft == nullptr)
		{
			std::shared_ptr<CAVLNode> p = std::make_shared<CAVLNode>(*this);
			m_pLeft.reset(new CAVLNode(key, p));
			return true;
		}
		else
		{
			return m_pLeft->Insert(key);
		}
	}
	else
	{
		if (m_pRight == nullptr)
		{
			std::shared_ptr<CAVLNode> p = std::make_shared<CAVLNode>(*this);
			m_pRight.reset(new CAVLNode(key, p));
			return true;
		}
		else
		{
			return m_pRight->Insert(key);
		}
	}
}