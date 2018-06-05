#pragma once
#include <memory>
#include "HashNode.h"

#define TABLE_SIZE		100

class CHashTable
{
private:
	CHashNode	**m_pTable;
	long		m_iSize;

	CHashNode*	m_pHead;
	CHashNode*	m_pTail;
protected:
	long Hash(const long& key);

public:
	// Constructor and Destructor
	CHashTable();
	~CHashTable();

	long GetSize();

	bool Add(const long& key, const double& data);
	bool Delete(const long& key);
	CHashNode* Find(const long& key);

	CHashNode* GetHead();
	void Next(CHashNode*& pNode);
};