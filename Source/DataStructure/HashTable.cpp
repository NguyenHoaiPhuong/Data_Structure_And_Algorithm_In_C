#include "HashTable.h"

template<typename Item>
inline HashTable<Item>::HashTable(const int hashSize)
{
	m_iHashSize = hashSize;	
	m_iTotElems = 0;
	m_pHead = new Node*[hashSize];	
	m_pBucketSize = new int[hashSize];
	for (int i = 0; i < hashSize; i++)
	{
		m_pHead[i] = NULL;
		m_pBucketSize[i] = 0;
	}
}

template<typename Item>
bool HashTable<Item>::IsEmpty(const int & idx)
{
	if (idx >= 0 && idx < m_iHashSize)
		return m_pBucketSize[idx] == 0;
	return true;
}

template<typename Item>
bool HashTable<Item>::IsFull()
{
	try
	{
		Node* p = new Node;
		delete p;
		return false;
	}
	catch (std::bad_alloc&)
	{
		return true;
	}
}

template<typename Item>
int HashTable<Item>::Hash(const Item& newItem)
{
	int h = 19937;
	std::stringstream convert;
	convert << newItem;
	std::string temp = convert.str();
	for (size_t x = 0; x < temp.length(); x++)
	{
		h = (h << 6) ^ (h >> 26) ^ temp[x];
	}
	return abs(h % m_iHashSize);
}

template<typename Item>
void HashTable<Item>::Insert(const Item& newItem)
{
	if (IsFull() == true)
	{
		std::cout << "INSERT ERROR - HASH TABLE FULL\n";
	}
	else
	{
		int idx = Hash(newItem);
		Append(idx, newItem);
	}
}

template<typename Item>
void HashTable<Item>::Append(const int & idx, const Item& newItem)
{
	if (IsFull() == true)
	{
		std::cout << "APPEND ERROR - HASH TABLE FULL\n";
	}
	else
	{
		Node* newNode = new Node;
		newNode->currentItem = newItem;
		newNode->next = NULL;

		if (IsEmpty(idx))
		{
			m_pHead[idx] = newNode;
		}
		else
		{
			Node* pTmp = m_pHead[idx];
			while (pTmp->next != NULL)
			{
				pTmp = pTmp->next;
			}
			pTmp->next = newNode;
		}

		m_pBucketSize[idx]++;
		m_iTotElems++;
	}
}

template<typename Item>
bool HashTable<Item>::Remove(Item delItem, int idx)
{
	if (idx == -1)
	{
		idx = Hash(delItem);
	}
	if (IsEmpty(idx))
	{
		return false;
	}
	else
	{
		bool bFound = false;
		Node* curNode = m_pHead[idx];
		if (curNode->currentItem == delItem)
		{
			m_pHead[idx] = curNode->next;
			delete curNode;
			m_iTotElems--;
			m_pBucketSize[idx]--;
			bFound = true;
		}
		else
		{
			while (curNode->next != NULL)
			{
				if (curNode->next->currentItem == delItem)
				{
					Node* delNode = curNode->next;
					curNode->next = delNode->next;
					delete delNode;
					m_iTotElems--;
					m_pBucketSize[idx]--;
					bFound = true;
					break;
				}
			}
		}
		return bFound;
	}
}

template<typename Item>
void HashTable<Item>::Sort(const int & idx)
{

}
