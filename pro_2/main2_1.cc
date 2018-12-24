#include "p2.h"
// example program: main2_1.cc
int main ()
{
        SORT_INFO G(5, 4); // instantiate an object C of class SORT_INFO
			// with 5 student ids each with 4 exams

	G.LIST_IDS(); // call to method in one of the base classes
	
	return 0;
}
