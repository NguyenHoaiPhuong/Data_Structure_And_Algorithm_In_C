#pragma once
#include <memory>

class CDLLNode
{
	friend class CDoubleLinkedList;
private:
	long m_iKey;
	std::shared_ptr<CDLLNode> m_pNext;
	std::shared_ptr<CDLLNode> m_pPrev;
protected:
	//
public:
	CDLLNode(const long& key);
	~CDLLNode();

	long GetKey();
	void SetKey(const long& key);

	CDLLNode* GetNextNode();
	void SetNextNode(CDLLNode* pHead);

	CDLLNode* GetPreviousNode();
	void SetPreviousNode(CDLLNode* pTail);
};