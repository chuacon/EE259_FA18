#include "p0.h"
// example program: main0_4.cc
int main ()
{
        STUDENT_ID C(3); // instantiate an object C of class STUDENT_ID
			// with 3 student ids

	C.LIST_ID(-1);	// list the ids in reverse order
	C.LIST_ID(0);	// input error
	C.LIST_ID(1);	// list the ids 
	return 0;
}
