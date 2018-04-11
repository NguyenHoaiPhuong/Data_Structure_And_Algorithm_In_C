#include "AVLNode.h"

long max(const long& a, const long& b)
{
	return (a > b) ? a : b;
}

CAVLNode::CAVLNode(const long& key, std::shared_ptr<CAVLNode> pParent)
{
	m_iKey = key;
	m_iHeight = 0;
	m_iBalance = 0;
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

long CAVLNode::GetBalance()
{
	return m_iBalance;
}

void CAVLNode::SetBalance(const long & balance)
{
	m_iBalance = balance;
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

bool CAVLNode::UpdateSubTree(std::shared_ptr<CAVLNode>& curNode)
{
	UpdateBalanceAndHeight();
	UnbalancedType type = GetUnbalanceType(curNode);
	switch (type)
	{
	case NONE:
		break;
	case RR:
		RotateLeft(curNode);
		return true;
	case RL:
		RotateRightLeft(curNode);
		return true;
	case LL:
		RotateRight(curNode);
		return true;
	case LR:
		RotateLeftRight(curNode);
		return true;
	default:
		break;
	}
	return false;	// Do not update
}

void CAVLNode::UpdateBalanceAndHeight()
{
	long leftHeight = -1;
	if (m_pLeft)
		leftHeight = m_pLeft->m_iHeight;
	long rightHeight = -1;
	if (m_pRight)
		rightHeight = m_pRight->m_iHeight;

	m_iBalance = rightHeight - leftHeight;
	m_iHeight = 1 + max(rightHeight, leftHeight);
}


UnbalancedType CAVLNode::GetUnbalanceType(std::shared_ptr<CAVLNode>& curNode)
{
	if (curNode->m_iBalance == -2)
	{
		std::shared_ptr<CAVLNode> pLeftChild = curNode->m_pLeft;
		if (pLeftChild->m_iBalance > 0)
			return LR;
		else
			return LL;
	}
	else if (curNode->m_iBalance == 2)
	{
		std::shared_ptr<CAVLNode> pRightChild = curNode->m_pRight;
		if (pRightChild->m_iBalance > 0)
			return RR;
		else
			return RL;
	}
	else
		return NONE;
}

/************************************************************************/
/*	T1, T2 and T3 are subtrees of the tree rooted with y(on left side)	*/
/*	or x(on right side)													*/
/*	    y                                x								*/
/*	   / \     Right Rotation			/ \								*/
/*	  x   T3   – – – – – – – >        T1   y							*/
/*	 / \       < -------				  / \							*/
/*	T1  T2     Left Rotation            T2  T3							*/
/*	Keys in both of the above trees follow the following order			*/
/*	keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)					*/
/*	So BST property is not violated anywhere.							*/
/************************************************************************/
void CAVLNode::RotateRight(std::shared_ptr<CAVLNode>& pCurNode)
{
	std::shared_ptr<CAVLNode> pParent = pCurNode->m_pParent;
	std::shared_ptr<CAVLNode> pLeftChild = pCurNode->m_pLeft;

	if (pParent)
	{
		if (pParent->m_pLeft == pCurNode)
		{
			pParent->m_pLeft = pLeftChild;
		}
		else
		{
			pParent->m_pRight = pLeftChild;
		}
	}

	pLeftChild->m_pParent = pParent;

	pCurNode->m_pParent = pLeftChild;
	pCurNode->m_pLeft = pLeftChild->m_pRight;
	if (pLeftChild->m_pRight)
		pLeftChild->m_pRight->m_pParent = pCurNode;
	pLeftChild->m_pRight = pCurNode;
	
	pCurNode->UpdateBalanceAndHeight();
	pLeftChild->UpdateBalanceAndHeight();

	pCurNode = pLeftChild;
}
void CAVLNode::RotateLeft(std::shared_ptr<CAVLNode>& pCurNode)
{
	std::shared_ptr<CAVLNode> pParent = pCurNode->m_pParent;
	std::shared_ptr<CAVLNode> pRightChild = pCurNode->m_pRight;

	if (pParent)
	{
		if (pParent->m_pLeft == pCurNode)
		{
			pParent->m_pLeft = pRightChild;
		}
		else
		{
			pParent->m_pRight = pRightChild;
		}
	}

	pRightChild->m_pParent = pParent;

	pCurNode->m_pParent = pRightChild;
	pCurNode->m_pRight = pRightChild->m_pLeft;
	if (pRightChild->m_pLeft)
		pRightChild->m_pLeft->m_pParent = pCurNode;
	pRightChild->m_pLeft = pCurNode;

	pCurNode->UpdateBalanceAndHeight();
	pRightChild->UpdateBalanceAndHeight();

	pCurNode = pRightChild;
}

/*********************************************************************/
/*	   z                          z							 x		 */
/*    / \						 / \						/ \		 */
/*   y   T4  Left Rotate(y)     x   T4  Right Rotate(z)	  y     z	 */
/*  / \		  -------->		   / \		  ------->		 / \   / \	 */
/* T1  x                      y   T3                    T1 T2 T3 T4	 */
/*    / \					 / \									 */
/*   T2  T3                 T1  T2									 */
/*********************************************************************/
void CAVLNode::RotateLeftRight(std::shared_ptr<CAVLNode>& pCurNode)
{
	std::shared_ptr<CAVLNode> pLeftChild = pCurNode->m_pLeft;
	pLeftChild->RotateLeft(pLeftChild);
	RotateRight(pCurNode);
}

/*********************************************************************/
/*     z                           z                       x		 */
/*    / \						  / \					  / \		 */
/*   T1  y   Right Rotate(y)    T1   x   Left Rotate(z)  z    y		 */
/*      / \		- -------->			/ \		------->	/ \  / \	 */
/*     x   T4                      T2  y               T1 T2 T3 T4	 */
/*    / \							  / \							 */
/*  T2   T3                          T3  T4							 */
/*********************************************************************/
void CAVLNode::RotateRightLeft(std::shared_ptr<CAVLNode>& pCurNode)
{
	std::shared_ptr<CAVLNode> pRightChild = pCurNode->m_pRight;
	pRightChild->RotateRight(pRightChild);
	RotateLeft(pCurNode);
}

bool CAVLNode::Insert(const long& key, const std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode)
{
	if (m_iKey == key)
		return false;
	else if (key < m_iKey)
	{
		if (m_pLeft == nullptr)
		{
			m_pLeft.reset(new CAVLNode(key, curNode));
			std::shared_ptr<CAVLNode> pParent = curNode;
			while (pParent)
			{
				if (!pParent->UpdateSubTree(pParent))
					pParent = pParent->m_pParent;
				else
				{
					if (!pParent->m_pParent)
						rootNode = pParent;
					pParent = nullptr;
				}
			}
			return true;
		}
		else
		{
			return m_pLeft->Insert(key, m_pLeft, rootNode);
		}
	}
	else
	{
		if (m_pRight == nullptr)
		{
			m_pRight.reset(new CAVLNode(key, curNode));
			std::shared_ptr<CAVLNode> pParent = curNode;
			while (pParent)
			{
				if (!pParent->UpdateSubTree(pParent))
					pParent = pParent->m_pParent;
				else
				{
					if (!pParent->m_pParent)
						rootNode = pParent;
					pParent = nullptr;
				}
					
			}
			return true;
		}
		else
		{
			return m_pRight->Insert(key, m_pRight, rootNode);
		}
	}
}

bool CAVLNode::Remove(const long & key, std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode)
{
	if (key < m_iKey)
		return RemoveLeft(key, curNode, rootNode);
	else if (key > m_iKey)
		return RemoveRight(key, curNode, rootNode);
	else
	{
		if (m_pLeft == nullptr && m_pRight == nullptr)	// Leaf Node
		{
			RemoveLeaf(curNode, rootNode);
		}			
		else
		{
			if (m_pLeft == nullptr || m_pRight == nullptr)	
			{
				// Current Node has 1 child
				RemoveNodeOneChild(curNode, rootNode);
			}
			else
			{
				// Current Node has 2 children
				RemoveNodeTwoChild(curNode, rootNode);
			}
		}
		return true;
	}
}

bool CAVLNode::RemoveLeft(const long & key, std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode)
{
	if (m_pLeft == nullptr)
		return false;
	else
		return m_pLeft->Remove(key, m_pLeft, rootNode);
}

bool CAVLNode::RemoveRight(const long & key, std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode)
{
	if (m_pRight == nullptr)
		return false;
	else
		return m_pRight->Remove(key, m_pRight, rootNode);
}

void CAVLNode::RemoveLeaf(std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode)
{
	std::shared_ptr<CAVLNode> pParent = curNode->m_pParent;
	if (pParent == nullptr)
	{
		curNode.reset();
		return;
	}

	if (pParent->m_pLeft == curNode)
	{
		curNode->m_pParent = nullptr;
		pParent->m_pLeft.reset();
	}
	else
	{
		curNode->m_pParent = nullptr;
		pParent->m_pRight.reset();
	}
	while (pParent)
	{
		if (!pParent->UpdateSubTree(pParent))
			pParent = pParent->m_pParent;
		else
		{
			if (!pParent->m_pParent)
				rootNode = pParent;
			pParent = nullptr;
		}
	}
}

void CAVLNode::RemoveNodeOneChild(std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode)
{
	std::shared_ptr<CAVLNode> p = curNode;
	std::shared_ptr<CAVLNode> pParent = curNode->m_pParent;
	std::shared_ptr<CAVLNode> pChild = (curNode->m_pLeft) ? curNode->m_pLeft : curNode->m_pRight;
	if (pParent)	
	{
		/* curNode is not root node */
		if (pParent->m_pLeft == curNode)
		{
			pParent->m_pLeft = pChild;
			pChild->m_pParent = pParent;
		}
	}
	curNode = pChild;		// curNode is its child now
	if (p->m_pLeft)
		p->m_pLeft = nullptr;
	else
		p->m_pRight = nullptr;
	p->m_pParent = nullptr;
	p.reset();

	while (pParent)
	{
		if (!pParent->UpdateSubTree(pParent))
			pParent = pParent->m_pParent;
		else
		{
			if (!pParent->m_pParent)
				rootNode = pParent;
			pParent = nullptr;
		}
	}
}

void CAVLNode::RemoveNodeTwoChild(std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode)
{
	std::shared_ptr<CAVLNode> p = FindMax(curNode->m_pLeft);
	Swap(curNode, p);
	if (IsLeaf(p))
		RemoveLeaf(p, rootNode);
	else
		RemoveNodeOneChild(p, rootNode);
}

void CAVLNode::Swap(std::shared_ptr<CAVLNode>& p1, std::shared_ptr<CAVLNode>& p2)	// p1 is above p2 on the tree
{
	if (p1 == p2 || p1 == nullptr || p2 == nullptr)
		return;

	/* Reset all nodes connected to p1 and p2*/
	Direction dir1 = UNKNOWN;
	std::shared_ptr<CAVLNode> pParent1 = p1->m_pParent;
	if (pParent1)
	{
		if (pParent1->m_pLeft == p1)
		{
			pParent1->m_pLeft = nullptr;
			dir1 = LEFT;
		}			
		else
		{
			pParent1->m_pRight = nullptr;
			dir1 = RIGHT;
		}
			
	}
	p1->m_pParent = nullptr;

	std::shared_ptr<CAVLNode> pLeft1 = p1->m_pLeft;
	if (pLeft1)
		pLeft1->m_pParent = nullptr;
	p1->m_pLeft = nullptr;

	std::shared_ptr<CAVLNode> pRight1 = p1->m_pRight;
	if (pRight1)
		pRight1->m_pParent = nullptr;
	p1->m_pRight = nullptr;

	Direction dir2 = UNKNOWN;
	std::shared_ptr<CAVLNode> pParent2 = p2->m_pParent;
	if (pParent2)
	{
		if (pParent2->m_pLeft == p2)
		{
			pParent2->m_pLeft = nullptr;
			dir2 = LEFT;
		}			
		else
		{
			pParent2->m_pRight = nullptr;
			dir2 = RIGHT;
		}			
	}
	p2->m_pParent = nullptr;

	std::shared_ptr<CAVLNode> pLeft2 = p2->m_pLeft;
	if (pLeft2)
		pLeft2->m_pParent = nullptr;
	p2->m_pLeft = nullptr;

	std::shared_ptr<CAVLNode> pRight2 = p2->m_pRight;
	if (pRight2)
		pRight2->m_pParent = nullptr;
	p2->m_pRight = nullptr;

	/* Redefine p1 and p2 connections*/
	p1->m_pLeft = pLeft2;
	if (pLeft2)
		pLeft2->m_pParent = p1;
	p1->m_pRight = pRight2;
	if (pRight2)
		pRight2->m_pParent = p1;
	if (pParent2 == p1)
		p1->m_pParent = p2;
	else
		p1->m_pParent = pParent2;
	switch (dir2)
	{
	case LEFT:
		p1->m_pParent->m_pLeft = p1;
		break;
	case RIGHT:
		p1->m_pParent->m_pRight = p1;
		break;
	default:
		break;
	}

	if (pLeft1 == p2)
		p2->m_pLeft = p1;
	else
		p2->m_pLeft = pLeft1;
	if (p2->m_pLeft)
		p2->m_pLeft->m_pParent = p2;
	if (pRight1 == p2)
		p2->m_pRight = p1;
	else
		p2->m_pRight = pRight1;
	if (p2->m_pRight)
		p2->m_pRight->m_pParent = p2;
	p2->m_pParent = pParent1;
	switch (dir1)
	{
	case LEFT:
		pParent1->m_pLeft = p2;
		break;
	case RIGHT:
		pParent1->m_pRight = p2;
		break;
	default:
		break;
	}

	/* Redefine height and balance of p1 and p2*/
	long tmp = p1->m_iHeight;
	p1->m_iHeight = p2->m_iHeight;
	p2->m_iHeight = tmp;
	tmp = p1->m_iBalance;
	p1->m_iBalance = p2->m_iBalance;
	p2->m_iBalance = tmp;

	std::shared_ptr<CAVLNode> pTmp = p2;
	p2 = p1;	
	p1 = pTmp;
}

bool CAVLNode::IsLeaf(std::shared_ptr<CAVLNode>& p)
{
	if (p->m_pLeft == nullptr && p->m_pRight == nullptr)
		return true;
	return false;
}

std::shared_ptr<CAVLNode> CAVLNode::Find(const long & key, std::shared_ptr<CAVLNode>& curNode)
{
	if (m_iKey == key)
	{
		return curNode;
	}
	else if (key < m_iKey)
	{
		if (m_pLeft)
			return m_pLeft->Find(key, m_pLeft);
		else
			return nullptr;
	}
	else
	{
		if (m_pRight)
			return m_pRight->Find(key, m_pRight);
		else
			return nullptr;
	}
}

std::shared_ptr<CAVLNode> CAVLNode::FindMax(std::shared_ptr<CAVLNode>& curNode)
{
	if (curNode->m_pRight)
		return curNode->m_pRight->FindMax(m_pRight);
	else
		return curNode;
}

std::shared_ptr<CAVLNode> CAVLNode::FindMin(std::shared_ptr<CAVLNode>& curNode)
{
	if (curNode->m_pLeft)
		return curNode->m_pLeft->FindMin(m_pLeft);
	else
		return curNode;
}

void CAVLNode::TraverseTree(std::vector<long>& array)
{
	if (m_pLeft)
		m_pLeft->TraverseTree(array);
	array.push_back(m_iKey);
	if (m_pRight)
		m_pRight->TraverseTree(array);
}