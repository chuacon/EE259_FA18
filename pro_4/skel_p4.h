#include <iostream>
#include <fstream>
#include <string.h>
//#include "/ee259/tools/pro_4/sample_p3.h" // implementation of base class
#include "sample_p3.h" // implementation of base class

using namespace std;

  class OVERLOADED_BURSAR:public BURSAR_INFO{

   public:      // public methods for this class

        OVERLOADED_BURSAR(char *, int, int);  // constructor 1:
			// Example: OVERLOADED_BURSAR B("ObjName1", x, y);
                        // instantiate object B of class OVERLOADED_BURSAR 
			// with nam ObjName1, x students and y exams;

        OVERLOADED_BURSAR(char *);  // constructor 2:
			// Example: OVERLOADED_BURSAR B;
                        // instantiate object B of class OVERLOADED_BURSAR
			// there are 0 students;

	void PRINT_IDS(void); // Example: b.PRINT_IDS();
                        // method prints student ids;
                        // returns no values;

	void ADD_STUDENT(char *, char *, int); 
			// Example: B.ADD_STUDENT("PEGGY", "HEIDI", 1234);
			// Add student to object B;
			// Set all exam grades to 0;
			// returns no values;

	void DELETE_STUDENT(char *, char *, int); 
			// Example: B.DELETE_STUDENT("PEGGY", "HEIDI", 1234);
			// Delete student from object B;
			// returns no values;

        int operator == (OVERLOADED_BURSAR); // Example: if (B1 == B2)
                        // returns 1 if the number of students in B1
                        // and B2 are equal;
                        // returns 0 otherwise;

        int operator == (int); // Example: if (B1 == 4)
                        // returns 1 if the number of students in B1
                        // is equal to 4;
                        // returns 0 otherwise;

        int operator > (OVERLOADED_BURSAR); // Example: if (B1 > B2)
                        // returns 1 if the maximum grade of students
			// received in all exams in B1 is greater than in B2;
                        // returns 0 otherwise;

	void operator = (OVERLOADED_BURSAR); // Example: B1 = B2;
			// assign student ids and exam grades of B2 to B1; 
			// B2 remains unchanged;
			// returns no values;

        OVERLOADED_BURSAR operator + (OVERLOADED_BURSAR); // Example: B1 + B2;
                        // create a TEMP object; 
			// copy the student ids, names and exams of B1 to TEMP
			// and then append B2 elements to TEMP;
			// return TEMP object;
                        // for simplicity, assume all students are unique;
	protected:
		char objectName[12]; // name for this object; max 11 chars
   };

OVERLOADED_BURSAR::OVERLOADED_BURSAR(char * ObjN, int x, int y)
	: BURSAR_INFO(x, y)
{
	strcpy(objectName, ObjN);
	// your code goes below:
}

OVERLOADED_BURSAR::OVERLOADED_BURSAR(char * ObjN)
	: BURSAR_INFO(0, 0)
{
	// no output is generated; base classes assign n=0 and p=0 and do not generate outputs; 
	strcpy(objectName, ObjN);
}

void 
OVERLOADED_BURSAR::PRINT_IDS()
{
	// your code goes below:
}

void 
OVERLOADED_BURSAR::ADD_STUDENT(char * F, char *L, int x)
{
	// your code goes below:
}

void 
OVERLOADED_BURSAR::DELETE_STUDENT(char * F, char *L, int x)
{
	// your code goes below:
}

int 
OVERLOADED_BURSAR::operator == (OVERLOADED_BURSAR Obj)
{
	// your code goes below:

	return 1; // modify this
}

int 
OVERLOADED_BURSAR::operator == (int x)
{
	// your code goes below:

	return 1; // modify this
}

int 
OVERLOADED_BURSAR::operator > (OVERLOADED_BURSAR Obj)
{
	// your code goes below:

	return 1; // modify this
}

void 
OVERLOADED_BURSAR::operator = (OVERLOADED_BURSAR Obj)
{
	// your code goes below:
}

OVERLOADED_BURSAR 
OVERLOADED_BURSAR::operator + (OVERLOADED_BURSAR Obj)
{
	OVERLOADED_BURSAR Temp("TEMP"); // create a temp object
	// your code goes below:

	return Temp;
}
