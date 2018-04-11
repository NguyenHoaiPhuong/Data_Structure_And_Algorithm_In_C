#pragma once
#include <memory>
#include <vector>

enum Direction
{
	UNKNOWN = 0,
	LEFT,
	RIGHT
};

enum UnbalancedType
{
	NONE = 0,
	RR,
	RL,
	LL,
	LR
};

class CAVLNode
{
	friend class CAVLTree;
private:
	long m_iKey;
	long m_iHeight;
	long m_iBalance;
	std::shared_ptr<CAVLNode> m_pLeft;
	std::shared_ptr<CAVLNode> m_pRight;
	std::shared_ptr<CAVLNode> m_pParent;

protected:
	bool UpdateSubTree(std::shared_ptr<CAVLNode>& curNode);
	void UpdateBalanceAndHeight();
	UnbalancedType GetUnbalanceType(std::shared_ptr<CAVLNode>& curNode);

	void RotateRight(std::shared_ptr<CAVLNode>& pCurNode);
	void RotateLeft(std::shared_ptr<CAVLNode>& pCurNode);
	void RotateLeftRight(std::shared_ptr<CAVLNode>& pCurNode);
	void RotateRightLeft(std::shared_ptr<CAVLNode>& pCurNode);
	
	bool Insert(const long& key, const std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode);
	bool Remove(const long& key, std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode);
	bool RemoveLeft(const long& key, std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode);
	bool RemoveRight(const long& key, std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode);
	void RemoveLeaf(std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode);
	void RemoveNodeOneChild(std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode);
	void RemoveNodeTwoChild(std::shared_ptr<CAVLNode>& curNode, std::shared_ptr<CAVLNode>& rootNode);

	void Swap(std::shared_ptr<CAVLNode>& p1, std::shared_ptr<CAVLNode>& p2);
	bool IsLeaf(std::shared_ptr<CAVLNode>& p);

	std::shared_ptr<CAVLNode> Find(const long& key, std::shared_ptr<CAVLNode>& curNode);
	std::shared_ptr<CAVLNode> FindMax(std::shared_ptr<CAVLNode>& curNode);
	std::shared_ptr<CAVLNode> FindMin(std::shared_ptr<CAVLNode>& curNode);
	void TraverseTree(std::vector<long>& array);


public:
	CAVLNode(const long& key, std::shared_ptr<CAVLNode> pParent = nullptr);
	~CAVLNode();

	long GetKey();
	void SetKey(const long& key);

	long GetHeight();
	void SetHeight(const long& height);

	long GetBalance();
	void SetBalance(const long& balance);

	CAVLNode* GetLeftNode();
	void SetLeftNode(std::shared_ptr<CAVLNode> pLeft);

	CAVLNode* GetRightNode();
	void SetRightNode(std::shared_ptr<CAVLNode> pRight);

	CAVLNode* GetParentNode();
	void SetParentNode(std::shared_ptr<CAVLNode> pParent);
};