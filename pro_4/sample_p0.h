#include <iostream>
#include <fstream>

using namespace std;

ifstream input_file_p0; // declare a pointer to an input file;
ofstream output_file_p4("out.4.txt", ios::out);

  class STUDENT_ID{
   public:      // public methods for this class

        STUDENT_ID(int); // example usage: STUDENT_ID C(3);
			// constructor;
			// instantiates object C with 3 grades

        void LIST_ID(int); // example usage: C.LIST_ID(x);
			// if x is 1, list the ids
			// if x is -1, list the ids in reverse order
			// returns no values

   // protected vars below can only be accessed within this class and inherited classes
   // they are not directly accessible from main
   protected: 
        int n;  // noof students
	int ids[20]; // student ids
   };

STUDENT_ID::STUDENT_ID(int x)
{
	int i;

	input_file_p0.open("studentId.txt", ios::in); // open input file;

	n = x; // assign x as the noof students in provate data

	for(i = 0; i < n; i++)
	{
		input_file_p0 >> ids[i];	
	}
	input_file_p0.close(); // close input file;
	input_file_p0.clear(); // rewind file pointer to the top of the file;

	if (n>0)
	{
		output_file_p4 << "+ P0 START +" << endl;
		output_file_p4 << "+ P0 OUTPUT FROM STUDENT_ID CONSTRUCTOR:" << endl;
		output_file_p4 << "+ P0 INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH " << n << " STUDENT IDS." << endl;
		output_file_p4 << "+ P0 END +" << endl;
	}
	else {}
}

void
STUDENT_ID::LIST_ID(int x)
{
	int i;

	output_file_p4 << "+ P0 START +" << endl;
	output_file_p4 << "+ P0 OUTPUT FROM LIST_ID METHOD:" << endl;

	if(x == 1)
	{
		output_file_p4 << "+ P0 STUDENT IDS FOR " << n << " STUDENTS:" << endl;
		for(i = 0; i < n; i++)
		{
			output_file_p4 << "+ P0 " << ids[i] << endl;	
		}
	}
	else if (x == -1)
	{
		output_file_p4 << "+ P0 STUDENT IDS FOR " << n << " STUDENTS IN REVERSE ORDER:" << endl;
		for(i = n-1; i >=0; i--)
		{
			output_file_p4 << "+ P0 " << ids[i] << endl;	
		}
	}
	else
	{
		output_file_p4 << "+ P0 INPUT ERROR." << endl;
	}
	output_file_p4 << "+ P0 END +" << endl;
}
