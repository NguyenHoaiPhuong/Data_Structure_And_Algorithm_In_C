#pragma once
#include "AVLNode.h"

class CAVLTree
{
private:
	std::shared_ptr<CAVLNode> m_pRoot;
protected:
	long FindIndexInArray(const long& key);
public:
	CAVLTree();
	~CAVLTree();

	bool Insert(const long& key);
	bool Remove(const long& key);
	std::vector<long> TraverseTree();
	CAVLNode* Find(const long& key);
	CAVLNode* FindMax();					// Tree
	CAVLNode* FindMin();					// Tree
	CAVLNode* FindMax(CAVLNode* pRoot);		// Subtree
	CAVLNode* FindMin(CAVLNode* pRoot);		// Subtree
	void Print();
};