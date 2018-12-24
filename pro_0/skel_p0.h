#include <iostream>
#include <fstream>

using namespace std;

ifstream input_file("studentId.txt", ios::in);
ofstream output_file("out.0", ios::out);

  class STUDENT_ID{
   public:      // public methods for this class

        STUDENT_ID(int); // example usage: STUDENT_ID C(3);
			// constructor;
			// instantiates object C with 3 grades

        void LIST_ID(int); // example usage: C.LIST_ID(x);
			// if x is 1, list the ids
			// if x is -1, list the ids in reverse order
			// returns no values

   private: // private vars to at can be accessed within this class only (not from main)
        int n;  // noof students
	int ids[20]; // student ids
   };

STUDENT_ID::STUDENT_ID(int x)
{
	
}

void
STUDENT_ID::LIST_ID(int x)
{
	
}
