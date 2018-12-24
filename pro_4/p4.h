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
	output_file_p4 <<"++++++++ P4 START ++++" <<endl;
	output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED_BURSAR CONSTRUCTOR:" <<endl;
	output_file_p4 <<"++++++++ P4 AN OBJECT OF OVERLOADED_BURSAR WITH THE NAME OF " <<objectName <<" IS CREATED." <<endl;
	output_file_p4 <<"++++++++ P4 END ++++" <<endl;
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
	output_file_p4 <<"++++++++ P4 START ++++" <<endl;
	output_file_p4 <<"++++++++ P4 OUTPUT FROM PRINT_IDS METHOD FOR OBJECT "<<objectName<<":" <<endl;
	LIST_IDS();
	output_file_p4 <<"++++++++ P4 END ++++" <<endl;
}

void 
OVERLOADED_BURSAR::ADD_STUDENT(char * F, char *L, int x)
{
	// your code goes below:
	int i,j, new_n;
	output_file_p4 <<"++++++++ P4 START ++++" <<endl;
	output_file_p4 <<"++++++++ P4 OUTPUT FROM ADD_STUDENT METHOD FOR OBJECT "<<objectName<<":" <<endl;

	if(x>0 && x<=9999)
	{
		new_n= n;	
		if(new_n>20)
		{
			output_file_p4 <<"++++++++ P4 INPUT ERROR." <<endl;
		}
		else
		{
			for(i=0; i<p; i++)
			{
				grades[new_n][i] = 0;
			}
			ids[new_n] = x;
			strcpy(FirstName[new_n], F);
			strcpy(LastName[new_n], L);
			new_n++;
			n = new_n;
			output_file_p4 <<"++++++++ P4 STUDENT " <<L <<", " <<F <<" WITH ID " <<x <<" IS ADDED." <<endl;
			output_file_p4 <<"++++++++ P4 NOW THERE ARE " <<n <<" STUDENTS." <<endl;
		}
	
	}
	else
	{
		output_file_p4 <<"++++++++ P4 INPUT ERROR." <<endl;
	}
	/*
	for(i=0; i<n; i++)
	{
		output_file_p4 <<ids[i] <<endl;
	}
	output_file_p4 <<endl;

	for(i=0; i<n; i++)
	{
		output_file_p4 <<LastName[i] <<" " <<FirstName[i] <<endl;
	}
	output_file_p4 <<endl;

	for(i=0; i<n; i++)
	{
		for(j=0; j<p; j++)
		{
			output_file_p4 <<grades[i][j] <<" ";
		}
		output_file_p4 <<endl;
	}
	output_file_p4 <<endl;

	*/

	
	output_file_p4 <<"++++++++ P4 END ++++" <<endl;
}

void 
OVERLOADED_BURSAR::DELETE_STUDENT(char * F, char *L, int x)
{
	// your code goes below:
	int i,j,k, FOUND, FOUND_POS;
	output_file_p4 <<"++++++++ P4 START ++++" <<endl;
	output_file_p4 <<"++++++++ P4 OUTPUT FROM DELETE_STUDENT METHOD FOR OBJECT "<<objectName<<":" <<endl;
	if(x>0 && x<=9999)
	{
		FOUND = 0;
		for(i=0; i<n && FOUND==0; i++)
		{
			if(ids[i]==x && (strcmp(FirstName[i], F)==0)&&(strcmp(LastName[i],L)==0))
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
		}
		if(FOUND==1)
		{
			for(i=FOUND_POS; i<n; i++)
			{
				strcpy(LastName[i], LastName[i+1]);
				strcpy(FirstName[i], FirstName[i+1]);
				ids[i] = ids[i+1];
				for(j=0; j<p; j++)
				{
					grades[i][j]=grades[i+1][j];
				}
			}
			n--;
			output_file_p4 <<"++++++++ P4 STUDENT " <<L <<", " <<F <<" WITH ID " <<x <<" IS DELETED." <<endl;
			output_file_p4 <<"++++++++ P4 NOW THERE ARE " <<n <<" STUDENTS." <<endl;
		}
		else
		{
			output_file_p4 <<"++++++++ P4 NO SUCH STUDENT "<<L<<", " <<F <<" WITH ID " <<x <<" IS FOUND." <<endl;

		}
	}
	else
	{
		output_file_p4 <<"++++++++ P4 INPUT ERROR." <<endl;
	}
	output_file_p4 <<"++++++++ P4 END ++++" <<endl;
}

int 
OVERLOADED_BURSAR::operator == (OVERLOADED_BURSAR Obj)
{
	// your code goes below:

	if(n==Obj.n)
	{
		output_file_p4 <<"++++++++ P4 START ++++" <<endl;
		output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT "<<objectName<<":" <<endl;
		output_file_p4 <<"++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN "<<objectName <<" AND " <<Obj.objectName <<" ARE EQUAL:" <<endl;
		output_file_p4 <<"++++++++ P4 RETURNS TRUE." <<endl;
		output_file_p4 <<"++++++++ P4 END ++++" <<endl;
		return 1; // modify this
	}
	else
	{
		output_file_p4 <<"++++++++ P4 START ++++" <<endl;
		output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT "<<objectName<<":" <<endl;
		output_file_p4 <<"++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN "<<objectName <<" AND " <<Obj.objectName <<" ARE EQUAL:" <<endl;
		output_file_p4 <<"++++++++ P4 RETURNS FALSE." <<endl;
		output_file_p4 <<"++++++++ P4 END ++++" <<endl;
		return 0;
	}

}

int 
OVERLOADED_BURSAR::operator == (int x)
{
	// your code goes below:

	if(n == x)
	{
		output_file_p4 <<"++++++++ P4 START ++++" <<endl;
		output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT "<<objectName<<":" <<endl;
		output_file_p4 <<"++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN "<<objectName<<" IS EQUAL TO "<<x<<":" <<endl;
		output_file_p4 <<"++++++++ P4 RETURNS TRUE." <<endl;
		output_file_p4 <<"++++++++ P4 END ++++" <<endl;
		return 1; // modify this
	}
	else
	{
		output_file_p4 <<"++++++++ P4 START ++++" <<endl;
		output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR == METHOD FOR OBJECT "<<objectName<<":" <<endl;
		output_file_p4 <<"++++++++ P4 CHECKING IF NUMBER OF STUDENTS IN "<<objectName<<" IS EQUAL TO "<<x<<":" <<endl;
		output_file_p4 <<"++++++++ P4 RETURNS FALSE." <<endl;
		output_file_p4 <<"++++++++ P4 END ++++" <<endl;
		return 0;
	}
}

int 
OVERLOADED_BURSAR::operator > (OVERLOADED_BURSAR Obj)
{
	// your code goes below:

	int i, j, max_obj1, max_obj2;
	max_obj1 = grades[0][0];
	max_obj2 = Obj.grades[0][0];
	for(i=0; i<n; i++)
	{
		for(j=0; j<p; j++)
		{
			if(grades[i][j]>max_obj1)
			{
				max_obj1 = grades[i][j];
			}
			else{}
		}
	}
	
	for(i=0; i<Obj.n; i++)
	{
		for(j=0; j<Obj.p; j++)
		{
			if(Obj.grades[i][j]>max_obj2)
			{
				max_obj2 = Obj.grades[i][j];
			}
			else{}
		}
	}
	
	//output_file_p4 <<max_obj1 <<" " <<max_obj2 <<endl;

	if(max_obj1>max_obj2)
	{
		output_file_p4 <<"++++++++ P4 START ++++" <<endl;
		output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > METHOD FOR OBJECT "<<objectName<<":" <<endl;
		output_file_p4 <<"++++++++ P4 CHECKING IF MAX IN "<<objectName<<" > MAX IN "<<Obj.objectName<<":" <<endl;
		output_file_p4 <<"++++++++ P4 RETURNS TRUE." <<endl;
		output_file_p4 <<"++++++++ P4 END ++++" <<endl;
		return 1;
	}
	else
	{
		output_file_p4 <<"++++++++ P4 START ++++" <<endl;
		output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > METHOD FOR OBJECT "<<objectName<<":" <<endl;
		output_file_p4 <<"++++++++ P4 CHECKING IF MAX IN "<<objectName<<" > MAX IN "<<Obj.objectName<<":" <<endl;
		output_file_p4 <<"++++++++ P4 RETURNS FALSE." <<endl;
		output_file_p4 <<"++++++++ P4 END ++++" <<endl;
		return 0;
	}
}

void 
OVERLOADED_BURSAR::operator = (OVERLOADED_BURSAR Obj)
{
	// your code goes below:
	output_file_p4 <<"++++++++ P4 START ++++" <<endl;
	output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR = METHOD FOR OBJECT "<<objectName<<":" <<endl;
	int i, j;
	n = Obj.n;
	p = Obj.p;
	//grades[n][p];
	//ids[n];
	//FirstName[n][12];
	//LastName[n][12];
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<p; j++)
		{
			grades[i][j]=Obj.grades[i][j];
		}
		ids[i]=Obj.ids[i];
		strcpy(FirstName[i], Obj.FirstName[i]);
		strcpy(LastName[i], Obj.LastName[i]);
	}
    

	output_file_p4 <<"++++++++ P4 CONTENTS OF OBJECT "<<Obj.objectName<<" IS ASSIGNED TO OBJECT "<<objectName<<"." <<endl;

	output_file_p4 <<"++++++++ P4 END ++++" <<endl;
	strcpy(objectName, Obj.objectName);
}

OVERLOADED_BURSAR 
OVERLOADED_BURSAR::operator + (OVERLOADED_BURSAR Obj)
{
	OVERLOADED_BURSAR TEMP("TempObj"); // create a temp object
	// your code goes below:

	int m,i,j;
	TEMP.n = n + Obj.n;
	TEMP.p = p;

	output_file_p4 <<"++++++++ P4 START ++++" <<endl;
	output_file_p4 <<"++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR + METHOD FOR OBJECT "<<objectName<<":" <<endl;

	if(TEMP.n >20 || p!=Obj.p)
	{
		output_file_p4 <<"++++++++ P4 INPUT ERROR." <<endl;
	}
	else
	{
		for(i=0; i<n; i++)
		{
			TEMP.ids[i] = ids[i];
			strcpy(TEMP.FirstName[i], FirstName[i]);
			strcpy(TEMP.LastName[i], LastName[i]);
			for(j=0; j<p; j++)
			{
				TEMP.grades[i][j] = grades[i][j];
			}	 
		}
		for(i=n; i<TEMP.n; i++)
		{
			TEMP.ids[i] = Obj.ids[i-n];
			strcpy(TEMP.FirstName[i], Obj.FirstName[i-n]);
			strcpy(TEMP.LastName[i], Obj.LastName[i-n]);
			for(j=0; j<TEMP.p; j++)
			{
				TEMP.grades[i][j] = Obj.grades[i-n][j];
			} 
		}
		output_file_p4 <<"++++++++ P4 INFORMATION FROM "<<objectName<<" AND "<<Obj.objectName<<" HAVE BEEN ADDED." <<endl;			

	}
	output_file_p4 <<"++++++++ P4 END ++++" <<endl;
	return TEMP;
}
