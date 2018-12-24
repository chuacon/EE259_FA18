#include "p1.h"
// example program: main1_2.cc
int main ()
{
        STUDENT_GRADE G(5, 4); // instantiate an object C of class STUDENT_GRADE
			// with 5 student ids each with 4 exams

	G.LIST_GRADE(3333); // list the grades of student with id 3333

	G.LIST_GRADE(8888); // no such student
	
	return 0;
}
