#include <iostream>
#include <fstream>
#include <string.h>
#include "/ee259/tools/pro_2/sample_p1.h" // implementation of base class

using namespace std;

ifstream input_file_p2("studentName.txt", ios::in);
//ofstream output_file_p2("out.1", ios::app);

  class SORT_INFO:public STUDENT_GRADE{
   public:      // public interfaces for this class

        SORT_INFO(int, int); // example: b.SORT_INFO(x, y);
				// constructor;
				// x is noof students, y is noof projects

        void SORT_ID(char *); // example: b.SORT_GRADE("ASCENDING");
				// interface to sort student ids in 
				// ascending order; returns no values;

        void SORT_GRADE(char *, int); // example: b.SORT_GRADE("ASCENDING", 2);
				// interface to sort exam 2 grades in 
				// ascending order; returns no values;

        void SORT_NAME(char *); // example: b.SORT_NAME("ASCENDING");
			    	// interface to sort students by last names
			    	// in alphabetical or reverse alphabetical order; 
			    	// returns no values;

   // protected vars below can only be accessed within this class and inherited classes
   // they are not directly accessible from main
   protected: 
	char LastName[20][12];   // array to hold student's last name
	char FirstName[20][12];  // array to hold student,s first name
   };

SORT_INFO::SORT_INFO(int x, int y)
	: STUDENT_GRADE(x, y) // call to base class which requires two parameters
{
	
}

void
SORT_INFO::SORT_ID(char * DIRECTION)
{
	
}

void
SORT_INFO::SORT_GRADE(char * DIRECTION, int x)
{
	

}

void
SORT_INFO::SORT_NAME(char * DIRECTION)
{

}// end method
