#include <iostream>
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
		return true;
	}
	else
	{
		return m_pRoot->Insert(key, m_pRoot, m_pRoot);
	}
}

bool CAVLTree::Remove(const long & key)
{
	if (m_pRoot == nullptr)
		return false;
	else
		return m_pRoot->Remove(key, m_pRoot, m_pRoot);
}

std::vector<long> CAVLTree::TraverseTree()
{
	std::vector<long> array;
	if (m_pRoot)
		m_pRoot->TraverseTree(array);
	return array;
}

std::shared_ptr<CAVLNode> CAVLTree::Find(const long & key)
{
	if (!m_pRoot)
		return nullptr;
	else
		return m_pRoot->Find(key, m_pRoot);
}

std::shared_ptr<CAVLNode> CAVLTree::FindMax()
{
	if (m_pRoot == nullptr)
		return nullptr;
	else
		return m_pRoot->FindMax(m_pRoot);
}

std::shared_ptr<CAVLNode> CAVLTree::FindMin()
{
	if (m_pRoot == nullptr)
		return nullptr;
	else
		return m_pRoot->FindMin(m_pRoot);
}

std::shared_ptr<CAVLNode> CAVLTree::FindMax(std::shared_ptr<CAVLNode> pRoot)
{
	if (pRoot)
		return pRoot->FindMax(pRoot);
	return nullptr;
}

std::shared_ptr<CAVLNode> CAVLTree::FindMin(std::shared_ptr<CAVLNode> pRoot)
{
	if (pRoot)
		return pRoot->FindMin(pRoot);
	return nullptr;
}

void CAVLTree::Print()
{
	if (m_pRoot)
	{
		std::vector<CAVLNode*> vParent;
		vParent.push_back(m_pRoot.get());

		while (vParent.size() > 0)
		{
			std::vector<CAVLNode*> vChildren;
			long idx = 0;
			size_t step = 0;
			for (size_t i = 0; i < vParent.size(); i++)
			{
				if (vParent[i]->m_pLeft)
					vChildren.push_back(vParent[i]->m_pLeft.get());
				if (vParent[i]->m_pRight)
					vChildren.push_back(vParent[i]->m_pRight.get());

				long key = vParent[i]->GetKey();
				step = FindIndexInArray(key) - idx;
				idx = FindIndexInArray(key);
				for (size_t j = 0; j < step; j++)
					std::cout << "\t";
				std::cout << key;
			}
			std::cout << std::endl;
			//vParent = vChildren;
			vParent.assign(vChildren.begin(), vChildren.end());
		}		
	}
}

long CAVLTree::FindIndexInArray(const long& key)
{
	std::vector<long> arKey = TraverseTree();
	for (size_t i = 0; i < arKey.size(); i++)
	{
		if (arKey[i] == key)
			return i;
	}
	return -1;
}