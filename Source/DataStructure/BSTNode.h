#pragma once
#include <memory>

class CBSTNode
{
	friend class CBST;
private:
	long m_iKey;
	std::shared_ptr<CBSTNode> m_pLeft;
	std::shared_ptr<CBSTNode> m_pRight;
protected:
	CBSTNode* Find(const long& key);
	void Insert(const long& key);
public:
	CBSTNode(const long& key);
	~CBSTNode();

	long GetKey();
	void SetKey(const long& key);

	CBSTNode* GetLeftNode();
	void SetLeftNode(CBSTNode* pLeft);

	CBSTNode* GetRightNode();
	void SetRightNode(CBSTNode* pRight);
};