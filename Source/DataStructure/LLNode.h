#pragma once

#include <iostream>
#include <memory>

class CLLNode
{
	friend class CLinkedList;

private:
	long m_iKey;	// Cannot be DBL_MIN or DBL_MAX
	std::unique_ptr<CLLNode> m_pNext;

protected:
	void Insert(const long& key);
	CLLNode* Find(const long& key);
	bool IsExisting(const long& key);
	void Remove(const long& key, CLLNode* pParent);
public:
	CLLNode(const long& key);
	~CLLNode();

	long GetKey() const;
	void SetKey(const long& key);

	CLLNode* GetNextNode() const;
	void SetNextNode(CLLNode* pNext);	// Do not destroy the current next node
};