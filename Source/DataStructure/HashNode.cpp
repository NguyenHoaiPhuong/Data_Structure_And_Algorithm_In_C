#include "HashNode.h"

CHashNode::CHashNode(const long & key, const double & data)
	: m_iKey(key), m_dData(data)
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
