#pragma once
#include "BSTNode.h"

class CBST
{
private:
	std::unique_ptr<CBSTNode> m_pRoot;
protected:
	long FindIndex(const std::vector<long>& arKey, const long& key);
public:
	CBST();
	~CBST();

	bool Insert(const long& key);
	bool Remove(const long& key);
	std::vector<long> Traverse();
	void Print();
};