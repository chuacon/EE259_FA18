#include <iostream>
#include <fstream>
#include "/ee259/tools/pro_3/sample_p0.h" // implementation of base class

using namespace std;

ifstream input_file_p1("studentGrade.txt", ios::in);

  class STUDENT_GRADE: public STUDENT_ID{
   public:      // public methods for this class

        STUDENT_GRADE(int, int); // example usage: STUDENT_ID C(5, 4);
			// constructor;
			// instantiates object C with 5 students and 4 grades each

	void LIST_IDS(); // list the IDs using p0.h implementation

        void LIST_GRADE(int); // example usage: C.LIST_GRADE(3333);
			// list the grades of student with id 3333
			// returns no values

        void LIST_RANGE(int); // example usage: C.LIST_RANGE(2);
			// list the range of grades in exam 2
			// returns no values

   // protected vars below can only be accessed within this class and inherited classes
   // they are not directly accessible from main
   protected: 	
	int p;
	int grades[20][10]; // 20 students and 10 exams per student max
   };

STUDENT_GRADE::STUDENT_GRADE(int x, int y)
	: STUDENT_ID(x)
{
	int i, j;
	output_file_p3 << "++ P1 START ++" << endl;
	output_file_p3 << "++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR:" << endl;	
	p = y;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < p; j++)
		{
			input_file_p1 >> grades[i][j];
		}
	}
	output_file_p3 << "++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH " << x << " STUDENTS AND " 
		<< y << " EXAMS EACH." << endl;
	output_file_p3 << "++ P1 END ++" << endl;
}

void
STUDENT_GRADE::LIST_IDS()
{
	output_file_p3 << "++ P1 START ++" << endl;
	output_file_p3 << "++ P1 OUTPUT FROM LIST_IDS METHOD:" << endl;	
	LIST_ID(1);
	output_file_p3 << "++ P1 END ++" << endl;
}

void
STUDENT_GRADE::LIST_GRADE(int x)
{
	int i, j;
	int FOUND, FOUND_POS; 

	FOUND = 0;
	output_file_p3 << "++ P1 START ++" << endl;
	output_file_p3 << "++ P1 OUTPUT FROM LIST_GRADE METHOD:" << endl;

	if (x <0 || x >=10000)
	{
		output_file_p3 << "++ P1 INPUT ERROR" << endl;
	}
	else
	{
		for(i = 0; i < n && FOUND == 0; i++)
		{
			if (ids[i] == x)
			{
				FOUND_POS = i;
				FOUND = 1;
			}
			else{}
		}
	//cout << " FOUND is " << FOUND << " FOUND_POS IS " << FOUND_POS << endl;
		if (FOUND == 1)
		{
			output_file_p3 << "++ P1 GRADES FOR STUDENT " << x << ":" << endl;
			for(j = 0; j < p; j++)
			{
				output_file_p3 << "++ P1 GRADE FOR EXAM " << j << " IS: " 
					<< grades[FOUND_POS][j] << endl;
			}
		}
		else
		{
			output_file_p3 << "++ P1 NO SUCH STUDENT" << endl;
		}
	}// end else
	output_file_p3 << "++ P1 END ++" << endl;
}// end method

void
STUDENT_GRADE::LIST_RANGE(int x)
{
	int i, j;
	int min, max, range; 

	output_file_p3 << "++ P1 START ++" << endl;
	output_file_p3 << "++ P1 OUTPUT FROM LIST_RANGE METHOD:" << endl;

	if(x <0 || x >=p)
	{
		output_file_p3 << "++ P1 INPUT ERROR" << endl;
	}
	else
	{

		// find the min for exam x among all students
		min = grades[0][x];
		for(i = 0; i < n; i++)
		{
				// if true, ith student exam x is the new minimum
			if (min > grades[i][x])	
			{
				min = grades[i][x];
			}
			else{}
		}
	
		// find the max for exam x among all students
		max = grades[0][x];
		for(i = 0; i < n; i++)
		{
			// if true, ith student exam x is the new maximum
			if (max < grades[i][x])	
			{
				max = grades[i][x];
			}
			else{}
		}
				
		range = max - min;
		output_file_p3 << "++ P1 RANGE FOR EXAM " << x << " IS " << range << "." << endl;
	} // end else
	output_file_p3 << "++ P1 END ++" << endl;
}// end method
