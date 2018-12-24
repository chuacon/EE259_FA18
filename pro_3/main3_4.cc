#include "p3.h"
// example program: main3_4.cc
int main ()
{
        BURSAR_INFO G(5, 4); // instantiate an object C of class SORT_INFO
			// with 5 student ids each with 4 exams

	G.CHANGE_GRADE(-2222, 1, 53); // input error
	G.CHANGE_GRADE(3333, 6, 53); // input error
	G.VERIFY_GRADE("M", "L", 1, -5); // input error
	
	return 0;
}
