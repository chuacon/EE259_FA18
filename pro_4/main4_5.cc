#include "p4.h"
// example program: main4_5.cc
int main ()
{
        OVERLOADED_BURSAR B1("ObjB1", 3, 4); // instantiate an object B1 of 
			// class OVERLOADED_BURSAR with a name ObjB1 with 3 students,
			// each with 4 exams;
        OVERLOADED_BURSAR B2("ObjB2", 1, 4); // instantiate an object B1 of 
			// class OVERLOADED_BURSAR with a name ObjB1 with 1 student,
			// with 4 exams;
	OVERLOADED_BURSAR B3("ObjB3"); // B3 is an empty object of OVERLOADED_BURSAR

	B1.PRINT_IDS();
	B2.PRINT_IDS();
	B3.PRINT_IDS();
	B2.DELETE_STUDENT("ROB", "BUSH", 1111);
	B2.ADD_STUDENT("PEGGY", "HEIDI", 1234);
	B2.PRINT_IDS();
	B3 = B1 + B2;
	B1.PRINT_IDS();
	B2.PRINT_IDS();
	B3.PRINT_IDS();

	return 0;
}
