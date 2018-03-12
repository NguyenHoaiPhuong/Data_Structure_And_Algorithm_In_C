#pragma once
#include "AVLNode.h"

class CAVLTree
{
private:
	std::shared_ptr<CAVLNode> m_pRoot;
protected:
	//
public:
	CAVLTree();
	~CAVLTree();

	bool Insert(const long& key);
	std::vector<long> TraverseTree();
};