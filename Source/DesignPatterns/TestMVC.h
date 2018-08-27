#pragma once
#include "ModelViewControl.h"

void TestMVC()
{
	StudentModel* model = new StudentModel("Bill", 2010);
	StudentView* view = new StudentView();
	StudentControl student(model, view);

	student.display();

	student.setName("Akagi");
	student.display();
}