#include <iostream>
#include "HashTable.h"

CHashTable::CHashTable()
	:m_iSize(0), m_pHead(0), m_pTail(0)
{
	m_pTable = (CHashNode**)malloc(TABLE_SIZE * sizeof(CHashNode*));
	for (long i = 0; i < TABLE_SIZE; i++)
	{
		m_pTable[i] = nullptr;
	}
}

CHashTable::~CHashTable()
{
	for (long i = 0; i < TABLE_SIZE; i++)
	{
		if (m_pTable[i])
		{
			free(m_pTable[i]);
			m_pTable[i] = nullptr;
		}
	}
	free(m_pTable);
	m_pTable = nullptr;
}

long CHashTable::GetSize()
{
	return m_iSize;
}

bool CHashTable::Add(const long & key, const double & data)
{
	if (m_iSize == TABLE_SIZE - 1)
	{
		std::cout << "The table is FULL now.Operation Add cannot be implemented next time.\n";
		return false;
	}
	long idx = Hash(key);
	if (idx == -1)
		return false;	// The key already exists in the table
	m_pTable[idx] = new CHashNode(key, data);
	m_iSize++;
	return true;
}

bool CHashTable::Delete(const long & key)
{
	long idx = Hash(key);
	if (idx == -1)
		return false;
	free(m_pTable[idx]);
	m_pTable[idx] = nullptr;
	return true;
}

CHashNode * CHashTable::Find(const long & key)
{
	long idx = Hash(key);
	if (idx == -1)
		return nullptr;
	else
		return m_pTable[idx];
}

CHashNode * CHashTable::GetHead()
{
	if (m_iSize == 0)
		return nullptr;
	long i = 0;
	while (m_pTable[i] == nullptr)
	{
		i++;
	}
	return m_pTable[i];
}

void CHashTable::Next(CHashNode *& pNode)
{

}

long CHashTable::Hash(const long& key)
{
	long idx = key % TABLE_SIZE;
	while (m_pTable[idx])
	{
		if (m_pTable[idx]->GetKey() == key)
			return -1;
		idx = (idx + 1) % TABLE_SIZE;
	}
	return idx;
}
