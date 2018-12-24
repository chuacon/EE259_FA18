#include "p2.h"
// example program: main2_3.cc
int main ()
{
        SORT_INFO G(5, 4); // instantiate an object C of class SORT_INFO
			// with 5 student ids each with 4 exams

	G.SORT_GRADE("DESCENDING", 1); // sort exam1 grades in descending order
	
	return 0;
}
