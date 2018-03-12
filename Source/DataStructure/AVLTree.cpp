#include "AVLTree.h"

CAVLTree::CAVLTree()
{
}

CAVLTree::~CAVLTree()
{
}

bool CAVLTree::Insert(const long & key)
{
	if (m_pRoot == nullptr)
	{
		m_pRoot.reset(new CAVLNode(key));
		m_pRoot->SetHeight(0);
		return true;
	}
	else
	{
		return m_pRoot->Insert(key);
	}
}

std::vector<long> CAVLTree::TraverseTree()
{
	std::vector<long> array;
	if (m_pRoot)
		m_pRoot->TraverseTree(array);
	return array;
}
