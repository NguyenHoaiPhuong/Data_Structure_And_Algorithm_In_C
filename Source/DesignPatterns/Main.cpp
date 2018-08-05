#include "ModelViewControl.h"


int main(int argc, char* argv[])
{
	StudentModel* model = new StudentModel("Bill", 2010);
	StudentView* view = new StudentView();
	StudentControl student(model, view);

	student.display();

	student.setName("Akagi");
	student.display();

	getchar();
}