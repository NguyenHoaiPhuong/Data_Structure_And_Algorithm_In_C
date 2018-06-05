#include "HashNode.h"

CHashNode::CHashNode(const long & key, const double & data)
	: m_iKey(key), m_dData(data), m_pNext(0), m_pPrev(0)
{
}

CHashNode::~CHashNode()
{
}

long CHashNode::GetKey()
{
	return m_iKey;
}

double CHashNode::GetData()
{
	return m_dData;
}
