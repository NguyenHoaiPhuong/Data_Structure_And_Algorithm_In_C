#pragma once

class CHashNode
{
private:
	long		m_iKey;
	double		m_dData;
	CHashNode*	m_pNext;
	CHashNode*	m_pPrev;
protected:
	//
public:
	// Constructor and Destructor
	CHashNode(const long& key, const double& data);
	~CHashNode();

	long		GetKey();
	double		GetData();
};