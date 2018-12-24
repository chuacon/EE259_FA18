#include <iostream>
#include <fstream>
#include <string.h>
#include "/ee259/tools/pro_4/sample_p2.h" // implementation of base class

using namespace std;

class BURSAR_INFO:public SORT_INFO{
   public:      // public methods for this class

        BURSAR_INFO(int, int);  
			// Example: BURSAR_INFO b(x, y);
                        // instantiate an object b of class BURSAR_INFO
			// there are x students and y exams;

        void CHANGE_GRADE(int, int, int); 
                        // Example: b.CHANGE_GRADE(x, y, z);
                        // change the grade for student x, and exam y
			// to grade z;
                        // returns no values;

        void VERIFY_GRADE(char *, char*, int, int);    
                        // Example: b.VERIFY_GRADE("First","Last", 2, 50);
                        // check if student First Last received 50 for exam 2;
                        // returns no values;

	void SORT_NAMES();
                        // Example: b.SORT_NAMES();
			// sort students in alphabetical order;
			// returns no values;
   };

BURSAR_INFO::BURSAR_INFO(int x, int y)
	: SORT_INFO(x, y) // call to base class which requires two parameters
{
	int i;
	if (x>0)
	{
		output_file_p4 << "++++++ P3 START ++++" << endl;
		output_file_p4 << "++++++ P3 OUTPUT FROM BURSAR_INFO CONSTRUCTOR:" << endl;	
		output_file_p4 << "++++++ P3 AN OBJECT OF BURSAR_INFO IS CREATED." << endl;
		output_file_p4 << "++++++ P3 END ++++" << endl;
	}
	else{}
}// end method

void
BURSAR_INFO::CHANGE_GRADE(int x, int y, int z)
{
	int i;
	int FOUND, FOUND_POS;

	output_file_p4 << "++++++ P3 START ++++" << endl;
	output_file_p4 << "++++++ P3 OUTPUT FROM CHANGE_GRADE METHOD: " << endl;
	if (x >0 && x <=9999 && y>=0 && y <p && z>=0 && z <=100)
	{
		FOUND = 0;
		for(i = 0; i < n && FOUND == 0; i++)
		{
			if(ids[i] == x)
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
		if (FOUND == 1)
		{
			LIST_GRADE(x);
			grades[FOUND_POS][y] = z;
			output_file_p4 << "++++++ P3 STUDENT " << x << " EXAM " << y << " IS CHANGED AS " 
				<< z <<"." << endl;
			LIST_GRADE(x);
		}
		else
		{
			output_file_p4 << "++++++ P3 NO SUCH STUDENT WITH ID " << x << endl;
		}
	} 
	else
	{
		output_file_p4 << "++++++ P3 INPUT ERROR." << endl;
	}
	output_file_p4 << "++++++ P3 END ++++" << endl;
}// end method

void
BURSAR_INFO::VERIFY_GRADE(char * F, char* L, int x, int y)
{
	int i;
	int FOUND, FOUND_POS;
	
	output_file_p4 << "++++++ P3 START ++++" << endl;
	output_file_p4 << "++++++ P3 OUTPUT FROM VERIFY_GRADE METHOD:" << endl;
	if (x>=0 && x<p && y>=0 && y<=100)
	{
		FOUND = 0;
		for(i =0; i < n && FOUND == 0; i++)
		{
			if(strcmp(FirstName[i], F)== 0 && strcmp(LastName[i], L) == 0 )
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
		if (FOUND == 1)
		{
			if(grades[FOUND_POS][x] == y)
			{
				output_file_p4 << "++++++ P3 STUDENT " << F << " " << L << " RECEIVED " 
					<< y << " GRADE IN EXAM " << x << "." << endl;
			}
			else
			{
				output_file_p4 << "++++++ P3 STUDENT " << F << " " << L << " DID NOT RECEIVE " 
					<< y << " GRADE IN EXAM " << x << "." << endl;
			}
		}
		else
		{
			output_file_p4 << "++++++ P3 NO SUCH STUDENT WITH FIRST NAME " << F 
				<< " AND LAST NAME " << L << "." << endl;
		}
	}
	else
	{
		output_file_p4 << "++++++ P3 INPUT ERROR." << endl;
	}
	output_file_p4 << "++++++ P3 END ++++" << endl;
}// end method

void
BURSAR_INFO::SORT_NAMES()
{
	output_file_p4 << "++++++ P3 START ++++" << endl;
	output_file_p4 << "++++++ P3 OUTPUT FROM SORT_NAMES METHOD: " << endl;
	SORT_NAME("ASCENDING");
	output_file_p4 << "++++++ P3 END ++++" << endl;
}// end method
