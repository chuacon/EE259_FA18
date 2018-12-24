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
	int i;
	n = x;

	output_file <<"+ P0 START" <<endl;
	output_file <<"+ OUTPUT FROM STUDENT_ID CONSTRUCTOR:" <<endl;
	output_file <<"+ INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH " <<n <<" STUDENT IDS." <<endl;

	for(i=0; i<n; i++)
	{
		input_file >> ids[i];
	}

	output_file <<"+ P0 END" <<endl;
}

void
STUDENT_ID::LIST_ID(int x)
{
	int i;

	output_file <<"+ P0 START" <<endl;
	output_file <<"+ OUTPUT FROM LIST_ID METHOD:" <<endl;

	if(x == 1)
	{
		output_file <<"+ STUDENT IDS FOR " <<n <<" STUDENTS:" <<endl;

		for(i=0; i<n; i++)
		{
			output_file <<"+ " <<ids[i] <<endl;
		}
	}
	else if(x == -1)
	{
		output_file <<"+ STUDENT IDS FOR " <<n <<" STUDENTS IN REVERSE ORDER:" <<endl;

		for(i=n-1; i>=0; i--)
		{
			output_file <<"+ " <<ids[i] <<endl;
		}

	}
	else
	{
		output_file <<"+ INPUT ERROR." <<endl;
	}
	output_file <<"+ P0 END" <<endl;
}
