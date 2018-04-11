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
	std::shared_ptr<CAVLNode> Find(const long& key);
	std::shared_ptr<CAVLNode> FindMax();					// Tree
	std::shared_ptr<CAVLNode> FindMin();					// Tree
	std::shared_ptr<CAVLNode> FindMax(std::shared_ptr<CAVLNode> pRoot);		// Subtree
	std::shared_ptr<CAVLNode> FindMin(std::shared_ptr<CAVLNode> pRoot);		// Subtree
	void Print();
};