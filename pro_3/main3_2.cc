#include "p3.h"
// example program: main3_2.cc
int main ()
{
        BURSAR_INFO G(5, 4); // instantiate an object C of class SORT_INFO
			// with 5 student ids each with 4 exams

	G.VERIFY_GRADE("MARIA", "LEE", 1, 92); // verify that student's exam 1 grade is 92
	G.CHANGE_GRADE(2222, 1, 52); // change student 2222 exam 1 grade to 52
	G.VERIFY_GRADE("MARIA", "LEE", 1, 52); // verify that student's exam 1 grade is 52
	
	return 0;
}
