#pragma once
#include <memory>
#include <vector>

class CBSTNode
{
	friend class CBST;
private:
	long m_iKey;
	std::unique_ptr<CBSTNode> m_pLeft;
	std::unique_ptr<CBSTNode> m_pRight;
protected:
	CBSTNode* FindMax();
	CBSTNode* FindMin();
	CBSTNode* Find(const long& key);
	bool Insert(const long& key);
	bool Remove(const long& key, CBSTNode* pParent);
	void Traverse(std::vector<long>& arKey);
	long GetHeight();
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