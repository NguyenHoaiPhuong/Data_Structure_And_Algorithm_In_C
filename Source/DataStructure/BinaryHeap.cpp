#include "BinaryHeap.h"

void CBinaryHeap::Swap(long & a, long & b)
{
	long tmp = a;
	a = b;
	b = tmp;
}

CBinaryHeap::CBinaryHeap(const long & iCapacity)
{
	m_iSize = 0;

	m_iCapacity = iCapacity;
	m_arKey = std::make_unique<long[]>(m_iCapacity);
	m_arInOrderIndex = std::make_unique<long[]>(m_iCapacity);
}

CBinaryHeap::~CBinaryHeap()
{
}

long CBinaryHeap::GetParent(const long & idx)
{
	_ASSERT(m_iSize > 0);
	if (idx < 0 || idx >= m_iSize)
		return -1;
	return (long)0.5*(idx - 1);
}

long CBinaryHeap::GetLeftChild(const long & idx)
{
	_ASSERT(m_iSize > 0);
	if (idx < 0 || idx >= m_iSize)
		return -1;
	long res = 2 * idx + 1;
	return (res < m_iSize) ? res : -1;
}

long CBinaryHeap::GetRightChild(const long & idx)
{
	_ASSERT(m_iSize > 0);
	if (idx < 0 || idx >= m_iSize)
		return -1;
	long res = 2 * idx + 2;
	return (res < m_iSize) ? res : -1;
}

long CBinaryHeap::GetLevel(const long & idx)
{
	/*	Level 0: node idx 0 -- totally 2^0 node
		Level 1: node idx 1, 2 -- totally 2^1 nodes
		Level 2: node idx 3, 4, 5, 6 -- totally 2^2 nodes
		Level k: node idx starting from ( 2^0 + 2^1 + ... + 2^(k-1) ) -- totally 2^k nodes 
				 start idx = 2^k -1, end idx = 2^(k+1) - 2 */
	_ASSERT(m_iSize > 0);
	if (idx < 0 || idx >= m_iSize)
		return -1;
	//const long lowBound = log2(idx + 2) - 1;
	const long upBound = log2(idx + 1);
	return (long)upBound;
}

void CBinaryHeap::Print(const PrintType & type)
{
	switch (type)
	{
	case PrintType::ARRAY:
		PrintArray();
		break;
	case PrintType::TREE:
		PrintTree();
	default:
		break;
	}
}

/* Left - Root - Right */
void CBinaryHeap::InOrder()
{
	long idx = 0;
	long InOrderIdx = 0;
	InOrder(idx, InOrderIdx);
}

/* Find the index of the element with the given key */
long CBinaryHeap::Find(const long & key)
{
	for (long i = 0; i < m_iSize; i++)
	{
		if (m_arKey[i] == key)
			return i;
	}
	return -1;
}

void CBinaryHeap::InOrder(long& idx, long& InOrderIdx)
{
	if (idx >= m_iSize)
		return;
	long leftIdx = 2 * idx + 1;
	long rightIdx = 2 * idx + 2;
	if (leftIdx < m_iSize)
		InOrder(leftIdx, InOrderIdx);
	m_arInOrderIndex[idx] = InOrderIdx;
	InOrderIdx++;
	if (rightIdx < m_iSize)
		InOrder(rightIdx, InOrderIdx);
}
