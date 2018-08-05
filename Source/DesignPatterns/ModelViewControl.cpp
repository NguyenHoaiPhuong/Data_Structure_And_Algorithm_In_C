#include "ModelViewControl.h"

StudentModel::StudentModel(const std::string & strName, const int & iID)
{
	m_strName = strName;
	m_iID = iID;
}

void StudentModel::setName(const std::string & strName)
{
	m_strName = strName;
}

void StudentModel::setID(const int iID)
{
	m_iID = iID;
}

void StudentView::display(const std::string & strName, const int & iID)
{
	std::cout << "Student:\n";
	std::cout << "Name: " << strName << "\n";
	std::cout << "ID: " << iID << "\n";
}

StudentControl::StudentControl(StudentModel * model, StudentView * view)
{
	m_pModel = model;
	m_pView = view;
}

StudentControl::~StudentControl()
{
	if (m_pModel)	delete m_pModel;
	if (m_pView)	delete m_pView;
}

std::string StudentControl::getName()
{
	_ASSERT(m_pModel);
	return m_pModel->getName();
}

void StudentControl::setName(const std::string & name)
{
	_ASSERT(m_pModel);
	m_pModel->setName(name);
}

int StudentControl::getID()
{
	_ASSERT(m_pModel);
	return m_pModel->getID();
}

void StudentControl::setID(const int& ID)
{
	_ASSERT(m_pModel);
	m_pModel->setID(ID);
}

void StudentControl::display()
{
	_ASSERT(m_pModel);
	_ASSERT(m_pView);
	m_pView->display(m_pModel->getName(), m_pModel->getID());
}