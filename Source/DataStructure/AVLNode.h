#pragma once
#include <memory>
#include <vector>

class CAVLNode
{
	friend class CAVLTree;
private:
	long m_iKey;
	long m_iHeight;
	std::shared_ptr<CAVLNode> m_pLeft;
	std::shared_ptr<CAVLNode> m_pRight;
	std::shared_ptr<CAVLNode> m_pParent;

protected:
	void TraverseTree(std::vector<long>& array);
	bool Insert(const long& key);

public:
	CAVLNode(const long& key, std::shared_ptr<CAVLNode> pParent = nullptr);
	~CAVLNode();

	long GetKey();
	void SetKey(const long& key);

	long GetHeight();
	void SetHeight(const long& height);

	CAVLNode* GetLeftNode();
	void SetLeftNode(std::shared_ptr<CAVLNode> pLeft);

	CAVLNode* GetRightNode();
	void SetRightNode(std::shared_ptr<CAVLNode> pRight);

	CAVLNode* GetParentNode();
	void SetParentNode(std::shared_ptr<CAVLNode> pParent);
};