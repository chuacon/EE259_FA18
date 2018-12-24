#include "p1.h"
// example program: main1_3.cc
int main ()
{
        STUDENT_GRADE G(5, 4); // instantiate an object C of class STUDENT_GRADE
			// with 5 student ids each with 4 exams

	G.LIST_RANGE(3); // find the range for exam 3
	G.LIST_RANGE(5); // input error
	
	return 0;
}
