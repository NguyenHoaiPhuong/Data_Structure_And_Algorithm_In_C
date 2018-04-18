#pragma once
#include <memory>
#include <iostream>

enum PrintType
{
	ARRAY = 0,
	TREE
};

class CBinaryHeap
{
private:
	void InOrder(long& idx, long& InOrderIdx);

protected:
	long	m_iCapacity;
	long	m_iSize;
	std::unique_ptr<long[]> m_arKey;
	std::unique_ptr<long[]> m_arInOrderIndex;

	bool IsFull() { return (m_iSize >= m_iCapacity) ? true : false; }
	void Swap(long& a, long& b);
	virtual void PrintArray();
	virtual void PrintTree();

	// Abstract functions, to be overwritten
	virtual void UpdateUp(const long& idx) = 0;
	virtual void UpdateDown(const long& idx) = 0;
	
public:
	// Constructor and Destructor
	CBinaryHeap(const long& iCapacity);
	~CBinaryHeap();

	long GetSize() { return m_iSize; }
	long GetCapacity() { return m_iCapacity; }
	long GetParent(const long& idx);
	long GetLeftChild(const long& idx);
	long GetRightChild(const long& idx);
	long GetLevel(const long& idx);
	void Print(const PrintType& type);
	void InOrder();
	long Find(const long& key);

	// Abstract functions, to be overwritten
	virtual long GetMin() = 0;
	virtual long GetMax() = 0;
	virtual long ExtractMin() = 0;
	virtual long ExtractMax() = 0;
	virtual void ChangeKey(const long& idx, const long& iNewKey) = 0;
	virtual bool Insert(const long& key) = 0;
	virtual bool Remove(const long& key) = 0;
};