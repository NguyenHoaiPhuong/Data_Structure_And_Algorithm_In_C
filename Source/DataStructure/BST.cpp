#include <iostream>
#include "BST.h"

CBST::CBST()
{
}

CBST::~CBST()
{
}

bool CBST::Insert(const long & key)
{
	if (m_pRoot.get() != nullptr)
		return m_pRoot->Insert(key);
	else
	{
		m_pRoot.reset(new CBSTNode(key));
		return true;
	}
}

bool CBST::Remove(const long & key)
{
	CBSTNode* p = m_pRoot.release();
	if (p != nullptr)
	{
		CBSTNode pParent(LONG_MIN);
		pParent.m_pRight.reset(p);
		bool bRes = p->Remove(key, &pParent);
		if (pParent.m_pRight.get() != p)
			delete p;
		m_pRoot.reset(pParent.m_pRight.release());
		return bRes;
	}
	else
		return false;
}

std::vector<long> CBST::Traverse()
{
	std::vector<long> arKey;
	if (m_pRoot.get() != nullptr)
		m_pRoot->Traverse(arKey);
	return arKey;
}

long CBST::GetHeight()
{
	if (m_pRoot.get() == nullptr)
		return 0;
	else
		return m_pRoot->GetHeight();
}

void CBST::Print()
{
	std::vector<long> arKey = Traverse();
	CBSTNode* p = m_pRoot.get();
	if (p == nullptr)
		return;

	std::vector<CBSTNode*> vParent;
	vParent.push_back(p);

	while (vParent.size() > 0)
	{
		std::vector<CBSTNode*> vChildren;
		long crPos = 0;
		for (size_t i = 0; i < vParent.size(); i++)
		{
			if (vParent[i]->m_pLeft.get() != nullptr)
				vChildren.push_back(vParent[i]->m_pLeft.get());
			if (vParent[i]->m_pRight.get() != nullptr)
				vChildren.push_back(vParent[i]->m_pRight.get());
			long idx = FindIndex(arKey, vParent[i]->m_iKey);
			for (size_t i = 0; i < (idx - crPos); i++)
				std::cout << "\t";
			crPos = idx;
			std::cout << vParent[i]->m_iKey;
		}
		vParent = vChildren;
		std::cout << std::endl;
	}
}

long CBST::FindIndex(const std::vector<long>& arKey, const long& key)
{
	for (size_t i = 0; i < arKey.size(); i++)
	{
		if (arKey[i] == key)
			return i;
	}
	return -1;
}
