#include "MaxBinaryHeap.h"

CMaxBinaryHeap::CMaxBinaryHeap(const long & iCapacity)
	: CBinaryHeap(iCapacity)
{
}

long CMaxBinaryHeap::GetMin()
{
	long iLevel = GetLevel(m_iSize - 1);
	const long sIdx = pow(2, iLevel) - 1;
	long minKey = m_arKey[sIdx];
	for (size_t k = sIdx + 1; k < m_iSize; k++)
	{
		if (m_arKey[k] < minKey)
			minKey = m_arKey[k];
	}
	return minKey;
}

long CMaxBinaryHeap::GetMax()
{
	_ASSERT(m_iSize > 0);
	return m_arKey[0];
}

long CMaxBinaryHeap::ExtractMin()
{
	long res = GetMin();
	Remove(res);
	return res;
}

long CMaxBinaryHeap::ExtractMax()
{
	long res = GetMax();
	Remove(res);
	return res;
}

void CMaxBinaryHeap::ChangeKey(const long & idx, const long & iNewKey)
{
	long curKey = m_arKey[idx];
	m_arKey[idx] = iNewKey;
	if (iNewKey > curKey)
		UpdateUp(idx);
	else if (iNewKey < curKey)
		UpdateDown(idx);
}

bool CMaxBinaryHeap::Insert(const long & key)
{
	if (IsFull())
		return false;
	m_arKey[m_iSize++] = key;
	if (m_iSize > 1)
		UpdateUp(m_iSize-1);
	return true;
}

bool CMaxBinaryHeap::Remove(const long & key)
{
	long idx = Find(key);
	if (idx != -1)
	{
		Swap(m_arKey[idx], m_arKey[m_iSize - 1]);
		m_iSize--;
		UpdateDown(idx);
		return true;	// Remove 1 element
	}
	return false;	// No element was removed
}

void CMaxBinaryHeap::UpdateUp(const long & idx)
{
	long parentIdx = GetParent(idx);
	if (m_arKey[idx] > m_arKey[parentIdx])
	{
		Swap(m_arKey[idx], m_arKey[parentIdx]);
		if (parentIdx != 0)
			UpdateUp(parentIdx);
	}
}

void CMaxBinaryHeap::UpdateDown(const long & idx)
{
	long leftIdx = GetLeftChild(idx);
	long rightIdx = GetRightChild(idx);
	long maxIdx = idx;
	if (leftIdx != -1 && m_arKey[leftIdx] > m_arKey[idx])
		maxIdx = leftIdx;
	if (rightIdx != -1 && m_arKey[rightIdx] > m_arKey[maxIdx])
		maxIdx = rightIdx;
	if (maxIdx != idx)
	{
		Swap(m_arKey[idx], m_arKey[maxIdx]);
		UpdateDown(maxIdx);
	}
}