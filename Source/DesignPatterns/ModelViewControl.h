#pragma once
#include <iostream>
#include <string>

// Model to store data
class StudentModel
{
private:
	std::string		m_strName;		// student name
	int				m_iID;			// student ID
public:
	StudentModel() {}
	StudentModel(const std::string&	strName, const int& iID);

	std::string		getName() { return m_strName; }
	void			setName(const std::string& strName);
	int				getID() { return m_iID; }
	void			setID(const int iID);
};

// View to display / visualize data
class StudentView
{
public:
	void display(const std::string& strName, const int& iID);
};


class StudentControl
{
private:
	StudentModel*	m_pModel;
	StudentView*	m_pView;
public:
	StudentControl(StudentModel* model, StudentView* view);
	~StudentControl();

	std::string		getName();
	void			setName(const std::string& name);
	int				getID();
	void			setID(const int& ID);
	void			display();
};