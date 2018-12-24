#include "p4.h"
// example program: main4_2.cc
int main ()
{
        OVERLOADED_BURSAR B1("ObjB1", 5, 4); // instantiate an object B1 of 
			// class SORT_INFO with a name ObjB1 with 5 students,
			// each with 4 exams;
        OVERLOADED_BURSAR B2("ObjB2", 2, 4); // instantiate an object B2 of 
			// class SORT_INFO with a name ObjB2 with 2 students,
			// each with 3 exams;
	if (B1 > B2)
	{
		B1.PRINT_IDS(); // this should print
	}
	else
	{
		B2.PRINT_IDS();
	}

	if (B2 == 2)
	{
		B2.PRINT_IDS(); // this should print
	}
	else
	{
		B1.PRINT_IDS();
	}
	return 0;
}
