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
	int i;
	output_file_p2 << "++++ P2 START ++++" << endl;
	output_file_p2 << "++++ P2 OUTPUT FROM SORT_INFO CONSTRUCTOR:" << endl;	

	for(i = 0; i < n; i++)
	{
		input_file_p2 >> LastName[i] >> FirstName[i];
	}
	output_file_p2 << "++++ P2 AN OBJECT OF SORT_INFO IS CREATED." << endl;
	output_file_p2 << "++++ P2 END ++++" << endl;
}

void
SORT_INFO::SORT_ID(char * DIRECTION)
{
	int i, j, k;
	int min, min_pos, max, max_pos, tempo;
	char tempo_name[12];

	// your code goes below:
char ASCENDING[12] = "ASCENDING";
	char DESCENDING[12] = "DESCENDING";

	// your code goes below:

	output_file_p2 <<"++++ P2 START ++++" <<endl;
	output_file_p2 <<"++++ P2 OUTPUT FROM SORT_ID METHOD:" <<endl;

	if(strcmp(DIRECTION, ASCENDING)==0)
	{
		output_file_p2 <<"++++ P2 BEFORE SORTING IN ASCENDING ORDER:" <<endl;
		LIST_IDS();
		output_file_p2 <<"++++ P2 AFTER SORTING IN ASCENDING ORDER:" <<endl;
		for(i=0; i<n; i++)
		{
			min = ids[i];
			min_pos = i;
			for(j=i; j<n; j++)
			{
				if(ids[j]<min)
				{
					min = ids[j];
					min_pos = j;
				}
				else{}
			}

			tempo = ids[i];
			ids[i] = ids[min_pos];
			ids[min_pos] = tempo;

			strcpy(tempo_name, FirstName[i]);
			strcpy(FirstName[i], FirstName[min_pos]);
			strcpy(FirstName[min_pos], tempo_name);

			strcpy(tempo_name, LastName[i]);
			strcpy(LastName[i], LastName[min_pos]);
			strcpy(LastName[min_pos], tempo_name);

			for(k=0; k<p; k++)
			{
				tempo = grades[i][k];
				grades[i][k] = grades[min_pos][k];
				grades[min_pos][k] = tempo;

				//output_file_p2 <<LastName[i] <<" " <<FirstName[i] <<endl;
				//output_file_p2 <<grades[i][k] <<endl;
			}
		}

		LIST_IDS();
	}
	else if(strcmp(DIRECTION, DESCENDING)==0)
	{
		output_file_p2 <<"++++ P2 BEFORE SORTING IN DESCENDING ORDER:" <<endl;
		LIST_IDS();
		output_file_p2 <<"++++ P2 AFTER SORTING IN DESCENDING ORDER:" <<endl;

		for(i=0; i<n; i++)
		{
			max = ids[i];
			max_pos = i;
			for(j=i; j<n; j++)
			{
				if(ids[j] > max)
				{
					max = ids[j];
					max_pos = j;
				}
				else{}
			}

			tempo = ids[i];
			ids[i] = ids[max_pos];
			ids[max_pos] = tempo;

			strcpy(tempo_name, FirstName[i]);
			strcpy(FirstName[i], FirstName[max_pos]);
			strcpy(FirstName[max_pos], tempo_name);

			strcpy(tempo_name, LastName[i]);
			strcpy(LastName[i], LastName[max_pos]);
			strcpy(LastName[max_pos], tempo_name);

			for(k=0; k<p; k++)
			{
				tempo = grades[i][k];
				grades[i][k] = grades[max_pos][k];
				grades[max_pos][k] = tempo;

				//output_file_p2 <<LastName[i] <<" " <<FirstName[i] <<endl;
				//output_file_p2 <<grades[i][k] <<endl;
			}
		}

		LIST_IDS();
	}
	else
	{
		output_file_p2 <<"++++ P2 INPUT ERROR" <<endl;
	}
	output_file_p2 <<"++++ P2 END ++++" <<endl;

}

void
SORT_INFO::SORT_GRADE(char * DIRECTION, int x)
{
	int i, j, k;
	int min, min_pos, max, max_pos, tempo;
	char tempo_name[12];

	// your code goes below:

	output_file_p2 <<"++++ P2 START ++++" <<endl;
	output_file_p2 <<"++++ P2 OUTPUT FROM SORT_GRADE METHOD:" <<endl;

	
	if((DIRECTION != "ASCENDING" && DIRECTION != "DESCENDING") || (x<0 || x>=p))
	{
		output_file_p2 <<"++++ P2 INPUT ERROR" <<endl;
	}
	else
	{
		if(DIRECTION == "DESCENDING")
		{
			output_file_p2 <<"++++ P2 BEFORE SORTING IN DESCENDING ORDER:" <<endl;
			LIST_IDS();

			for(i=0; i<n; i++)
			{
				max = grades[i][x];
				max_pos = i;
				for(j=i; j<n; j++)
				{
					if(grades[j][x] > max)
					{
						max = grades[j][x];
						max_pos = j;
					}
					else{}
				}
				for(k=i; k<max_pos; k++)
				{
					tempo = grades[k][x];
					grades[k][x] = grades[max_pos][x];
					grades[max_pos][x] = tempo;
				}
				//output_file_p2 <<grades[i][x] <<endl;
				for(k=i; k<max_pos; k++)
				{
					tempo = ids[k];
					ids[k] = ids[max_pos];
					ids[max_pos] = tempo;

					strcpy(tempo_name, FirstName[k]);
					strcpy(FirstName[k], FirstName[max_pos]);
					strcpy(FirstName[max_pos], tempo_name);

					strcpy(tempo_name, LastName[k]);
					strcpy(LastName[k], LastName[max_pos]);
					strcpy(LastName[max_pos], tempo_name);
				}
			}

			output_file_p2 <<"++++ P2 AFTER SORTING IN DESCENDING ORDER:" <<endl;
			LIST_IDS();
		}
		else if(DIRECTION == "ASCENDING")
		{
			output_file_p2 <<"++++ P2 BEFORE SORTING IN ASCENDING ORDER:" <<endl;
			LIST_IDS();
			
			for(i=0; i<n; i++)
			{
				min = grades[i][x];
				min_pos = i;
				for(j=i; j<n; j++)
				{
					if(grades[j][x] < min)
					{
						min = grades[j][x];
						min_pos = j;
					}
					else{}
				}
				for(k=i; k<min_pos; k++)
				{
					tempo = grades[k][x];
					grades[k][x] = grades[min_pos][x];
					grades[min_pos][x] = tempo;
				}
				//output_file_p2 <<grades[i][x] <<endl;
				for(k=i; k<min_pos; k++)
				{
					tempo = ids[k];
					ids[k] = ids[min_pos];
					ids[min_pos] = tempo;

					strcpy(tempo_name, FirstName[k]);
					strcpy(FirstName[k], FirstName[min_pos]);
					strcpy(FirstName[min_pos], tempo_name);

					strcpy(tempo_name, LastName[k]);
					strcpy(LastName[k], LastName[min_pos]);
					strcpy(LastName[min_pos], tempo_name);
				}
			}

			output_file_p2 <<"++++ P2 AFTER SORTING IN ASCENDING ORDER:" <<endl;
			LIST_IDS();
		}
	}

	output_file_p2 <<"++++ P2 END ++++" <<endl;

}

void
SORT_INFO::SORT_NAME(char * DIRECTION)
{
	int i, j, k;
	int min_pos, max_pos, tempo;
	char min_name[12], max_name[12], tempo_name[12];

	// your code goes below:

	output_file_p2 <<"++++ P2 START ++++" <<endl;
	output_file_p2 <<"++++ P2 OUTPUT FROM SORT_NAME METHOD:" <<endl;

	if(DIRECTION == "ASCENDING")
	{
		output_file_p2 <<"++++ P2 BEFORE SORTING LAST NAMES IN ALPHABETICAL ORDER:" <<endl;
		LIST_IDS();

		for(i=0; i<n; i++)
		{
			strcpy(min_name, LastName[i]);
			min_pos = i;
			//output_file_p2 <<min_pos <<endl;
			for(j=i; j<n; j++)
			{		
				if(strcmp(LastName[j], min_name)<0)
				{
					strcpy(min_name, LastName[j]);
					min_pos = j;
				}
				else{}
			}
			for(k=i; k<min_pos; k++)
			{
				strcpy(tempo_name, LastName[k]);
				strcpy(LastName[k], LastName[min_pos]);
				strcpy(LastName[min_pos], tempo_name);

				strcpy(tempo_name, FirstName[k]);
				strcpy(FirstName[min_pos], FirstName[min_pos]);
				strcpy(FirstName[min_pos], tempo_name);

				tempo = ids[k];
				ids[k] = ids[min_pos];
				ids[min_pos] = tempo;
			}
			for(k=0; k<p; k++)
			{
				tempo = grades[i][k];
				grades[i][k] = grades[min_pos][k];
				grades[min_pos][k] = tempo;

				//output_file_p2 <<grades[i][k] <<endl;
			}
		}

		output_file_p2 <<"++++ P2 AFTER SORTING LAST NAMES IN ALPHABETICAL ORDER:" <<endl;
		LIST_IDS();		
	}

	else if(DIRECTION == "DESCENDING")
	{
		output_file_p2 <<"++++ P2 BEFORE SORTING LAST NAMES IN REVERSE ALPHABETICAL ORDER:" <<endl;
		LIST_IDS();

		for(i=0; i<n; i++)
		{
			strcpy(max_name, LastName[i]);
			max_pos = i;
			//output_file_p2 <<min_pos <<endl;
			for(j=i; j<n; j++)
			{		
				if(strcmp(LastName[j], max_name)>0)
				{
					strcpy(max_name, LastName[j]);
					max_pos = j;
				}
				else{}
			}
			for(k=i; k<max_pos; k++)
			{
				strcpy(tempo_name, LastName[k]);
				strcpy(LastName[k], LastName[max_pos]);
				strcpy(LastName[max_pos], tempo_name);

				strcpy(tempo_name, FirstName[k]);
				strcpy(FirstName[max_pos], FirstName[max_pos]);
				strcpy(FirstName[max_pos], tempo_name);

				tempo = ids[k];
				ids[k] = ids[max_pos];
				ids[max_pos] = tempo;
			}
			for(k=0; k<p; k++)
			{
				tempo = grades[i][k];
				grades[i][k] = grades[max_pos][k];
				grades[max_pos][k] = tempo;

				//output_file_p2 <<grades[i][k] <<endl;
			}
		}

		output_file_p2 <<"++++ P2 AFTER SORTING LAST NAMES IN REVERSE ALPHABETICAL ORDER:" <<endl;
		LIST_IDS();		
	}
	else
	{
		output_file_p2 <<"++++ P2 INPUT ERROR" <<endl;
	}

	output_file_p2 <<"++++ P2 END ++++" <<endl;


}// end method
