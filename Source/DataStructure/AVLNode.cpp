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

bool CAVLNode::Remove(const long & key, const std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode)
{
	if (key < m_iKey)
	{
		if (m_pLeft == nullptr)
			return false;
		else
			return m_pLeft->Remove(key, m_pLeft, rootNode);
	}
	else if (key > m_iKey)
	{
		if (m_pRight == nullptr)
			return false;
		else
			return m_pRight->Remove(key, m_pRight, rootNode);
	}
	else
	{
		if (m_pLeft == nullptr && m_pRight == nullptr)	// Leaf
		{
			if (m_pParent == nullptr)	// Root
			{
				rootNode.reset();
			}
			else
			{
				std::shared_ptr<CAVLNode> pParent = m_pParent;
				m_pParent.reset();
				if (pParent->m_pLeft == curNode)
					pParent->m_pLeft.reset();
				else
					pParent->m_pRight.reset();
			}
		}
		else if (m_pLeft == nullptr && m_pRight != nullptr)
		{
			if (m_pParent == nullptr)	// Root
			{
				rootNode = m_pRight;
				m_pRight.reset();
				rootNode->m_pParent.reset();
			}
			else
			{
				std::shared_ptr<CAVLNode> pParent = m_pParent;
				pParent->SetRightNode(m_pRight);
				m_pRight.reset();
				m_pParent.reset();
				pParent->m_pRight->m_pParent.reset();
				pParent->m_pRight->m_pParent = pParent;
			}
		}
		else if (m_pLeft != nullptr && m_pRight == nullptr)
		{
			if (m_pParent == nullptr)	// Root
			{
				rootNode = m_pLeft;
				m_pLeft.reset();
				rootNode->m_pParent.reset();
			}
			else
			{
				std::shared_ptr<CAVLNode> pParent = m_pParent;
				pParent->SetLeftNode(m_pLeft);
				m_pParent.reset();
				m_pLeft.reset();
				pParent->m_pLeft->m_pParent.reset();
				pParent->m_pLeft->m_pParent = pParent;
			}
		}
		else
		{
			if (m_pLeft->GetHeight() < m_pRight->GetHeight())
			{
				CAVLNode* pLeaf = m_pLeft->FindMax();
				m_iKey = pLeaf->GetKey();

				std::shared_ptr<CAVLNode> pParent = pLeaf->m_pParent;
				pLeaf->m_pParent.reset();
				pParent->m_pRight.reset();
			}
			else
			{
				CAVLNode* pLeaf = m_pRight->FindMin();
				m_iKey = pLeaf->GetKey();

				std::shared_ptr<CAVLNode> pParent = pLeaf->m_pParent;
				pLeaf->m_pParent.reset();
				pParent->m_pLeft.reset();
			}
		}
		return true;
	}
}

CAVLNode * CAVLNode::Find(const long & key)
{
	if (m_iKey == key)
	{
		return this;
	}
	else if (key < m_iKey)
	{
		if (m_pLeft)
			return m_pLeft->Find(key);
		else
			return nullptr;
	}
	else
	{
		if (m_pRight)
			return m_pRight->Find(key);
		else
			return nullptr;
	}
}

CAVLNode * CAVLNode::FindMax()
{
	if (m_pRight)
		return m_pRight->FindMax();
	else
		return this;
}

CAVLNode * CAVLNode::FindMin()
{
	if (m_pLeft)
		return m_pLeft->FindMin();
	else
		return this;
}

void CAVLNode::TraverseTree(std::vector<long>& array)
{
	if (m_pLeft)
		m_pLeft->TraverseTree(array);
	array.push_back(m_iKey);
	if (m_pRight)
		m_pRight->TraverseTree(array);
}