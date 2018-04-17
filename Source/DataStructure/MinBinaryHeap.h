#pragma once
#include "BinaryHeap.h"

class CMinBinaryHeap : public CBinaryHeap
{
private:
	//
protected:
	void UpdateUp(const long& idx);
	void UpdateDown(const long& idx);

	void PrintArray() override;
	void PrintTree() override;
public:
	// Constructor and destructor
	CMinBinaryHeap(const long& iCapacity);

	long GetMin() override;
	long GetMax() override;
	long ExtractMin() override;
	long ExtractMax() override;
	void ChangeKey(const long& idx, const long& iNewKey) override;
	bool Insert(const long& key) override;
	bool Remove(const long& key) override;
};