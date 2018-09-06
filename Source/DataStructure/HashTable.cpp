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
	if (IsEmpty(idx))
		return;

	int bucketSize = m_pBucketSize[idx];
	Node** arNode = new Node*[m_pBucketSize[idx]];
	int i = 0, j = 0;
	Node* curNode = m_pHead[idx];
	while (curNode != nullptr)
	{
		arNode[i++] = curNode;
		curNode = curNode->next;
	}
	for (i = 0; i < bucketSize - 1; i++)
	{
		if (arNode[i]->currentItem > arNode[i + 1]->currentItem)
		{
			Node* temp = arNode[i + 1];
			arNode[i + 1] = arNode[i];
			arNode[i] = temp;

			for (j = i; j > 0; j--)
			{
				if (arNode[j]->currentItem < arNode[j - 1]->currentItem)
				{
					Node* temp = arNode[j];
					arNode[j] = arNode[j - 1];
					arNode[j - 1] = temp;
				}
				else
					break;
			}
		}
	}
	m_pHead[idx] = arNode[0];
	curNode = m_pHead[idx];
	for (i = 0; i < bucketSize - 1; i++)
	{
		curNode->next = arNode[i + 1];
		curNode = curNode->next;
	}
	curNode->next = nullptr;
}

template<typename Item>
void HashTable<Item>::Print(const int & idx)
{
	if (IsEmpty(idx))
		return;
	Node* curNode = m_pHead[idx];
	while (curNode != nullptr)
	{
		std::cout << curNode->currentItem << "\t";
		curNode = curNode->next;
	}
	std::cout << "\n";
}

template<typename Item>
int HashTable<Item>::GetTableSize()
{
	return m_iHashSize;
}

template<typename Item>
int HashTable<Item>::GetTotalElements()
{
	return m_iTotElems;
}

template<typename Item>
int HashTable<Item>::GetBucketSize(const int & idx)
{
	return ( !IsEmpty(idx) )? m_pBucketSize[idx] : 0;
}

template<typename Item>
int HashTable<Item>::Count(Item searchItem)
{
	int idx = Hash(searchItem);
	if (IsEmpty(idx))
		return 0;
	int cnt = 0;
	Node* curNode = m_pHead[idx];
	while (curNode)
	{
		if (curNode->currentItem == searchItem)
			cnt++;
		curNode = curNode->next;
	}
	return cnt;
}

template<typename Item>
void HashTable<Item>::MakeEmpty()
{
	m_iTotElems = 0;
	for (int i = 0; i < m_iHashSize; i++)
	{
		if (IsEmpty(i) == false)
		{
			m_pBucketSize[i] = 0;
			Node* curNode = m_pHead[i];
			while (curNode)
			{
				Node* tmp = curNode;
				curNode = curNode->next;
				delete tmp;
			}
			m_pHead[i] = nullptr;
		}
	}
}

template<typename Item>
HashTable<Item>::~HashTable()
{
	MakeEmpty();
	delete[] m_pHead;
	delete[] m_pBucketSize;
}

template<typename Item>
Iterator HashTable<Item>::begin(const int & idx)
{
	return Iterator();
}

template<typename Item>
Iterator HashTable<Item>::end(const int & idx)
{
	return Iterator();
}
