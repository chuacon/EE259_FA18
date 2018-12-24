#include <iostream>
#include <fstream>
#include "/ee259/tools/pro_0/sample_p0.h" // implementation of base class

using namespace std;

ifstream input_file_p1("studentGrade.txt", ios::in);
//ofstream output_file_p1("out.1", ios::app);

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
	int grades[20][10]; // 20 students and 8 exams per student max
   };

STUDENT_GRADE::STUDENT_GRADE(int x, int y)
	: STUDENT_ID(x)
{
	int i, j;
	p = y;

	output_file_p1 <<"++ P1 START ++" <<endl;
	output_file_p1 <<"++ P1 OUTPUT FROM STUDENT_GRADE CONSTRUCTOR" <<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			input_file_p1>>grades[i][j];
		}
	}

	output_file_p1 <<"++ P1 AN OBJECT OF STUDENT_GRADE IS CREATED WITH " <<x <<" STUDENTS AND " <<y <<" EXAMS EACH." <<endl;
	output_file_p1 << "++ P1 END ++" << endl;
}

void STUDENT_GRADE::LIST_IDS()
{
	output_file_p1 <<"++ P1 START ++" <<endl;
	output_file_p1 <<"++ P1 OUTPUT FROM LIST_IDS" <<endl;

	LIST_ID(1);

	output_file_p1 <<"++ P1 END ++" <<endl;
	
}

void STUDENT_GRADE::LIST_GRADE(int x)
{
	int i, j;
	int FOUND, FOUND_POS;

	output_file_p1 <<"++ P1 START ++" <<endl;
	output_file_p1 <<"++ P1 OUTPUT FROM LIST_GRADE METHOD:" <<endl;

	if(x<0 || x>9999)
	{
		output_file_p1 <<"++ P1 INPUT ERROR" <<endl;
	}
	else
	{
		FOUND = 0;
		for(i=0; (i<n && FOUND == 0); i++)
		{
			if(ids[i] == x)
			{
				FOUND = 1;
				FOUND_POS = i;
				output_file_p1 <<"++ P1 GRADES FOR STUDENT " <<x <<":" <<endl;
			}
			else{}
		}
		for(j=0; (j<p && FOUND ==1); j++)
		{
			output_file_p1 <<"++ P1 GRADE FOR EXAM " <<j <<" IS: " <<grades[FOUND_POS][j] <<endl;
		}
		if(FOUND == 0)
		{
			output_file_p1 <<"++ P1 NO SUCH STUDENT" <<endl;
		}
		else{}
	}

	output_file_p1 <<"++ P1 END ++" <<endl; 

}// end method

void STUDENT_GRADE::LIST_RANGE(int x)
{
	int i, j;
	int min, max, range;
	min = grades[0][x];
	max = grades[0][x];

	output_file_p1 <<"++ P1 START ++" <<endl;
	output_file_p1 <<"++ P1 OUTPUT FROM LIST_RANGE METHOD:" <<endl;

	if(x<0 || x>=p)
	{
		output_file_p1 <<"++ P1 INPUT ERROR" <<endl;
	}
	else
	{
		for(i=0; i<n; i++)
		{
			if(grades[i][x]< min)
			{
				min = grades[i][x];
				
			}
			else{}
		}
		for(j=0; j<n; j++)
		{
			if(grades[j][x] > max)
			{
				max = grades[j][x];
				
			}
			else{}
		}

		range = max - min;
		output_file_p1 <<"++ P1 RANGE FOR EXAM " <<x <<" IS " <<range <<"." <<endl;
	}

	output_file_p1 <<"++ P1 END ++" <<endl;
	
}// end method
