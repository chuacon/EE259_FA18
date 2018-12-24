#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "/ee259/tools/pro_5/sample_p5.h"

using namespace std;

ofstream output("out.6.txt", ios::out);

class LINEAR_SOLVER: public MATRIX{
   public:
	LINEAR_SOLVER(int);  
			// constructor; example: s.LINEAR_SOLVER(5);
			// there are 5 equations and 5 variables;

	void SOLVE_LINEAR_EQUATION(char *); 
			// example: s.SOLVE_LINEAR_EQUATION("ASCEND");
			// solve the linear equations and
			// sort the output in ascending order;
			// if the input is "DESCEND" then the order
			// of the output is descending;
			// returns no values;

	void SOLVE_BY_MATLAB(void); 
			// example: s.SOLVE_BY_MATLAB();
			// generate and run a MATLAB program to 
			// solve a set of linear equations;
			// returns no values;

	void INHERITED_INVERT(void); 
			// example: s.INHERITED_INVERT();
			// perform matrix inversion on
			// the input system by inheriting
			// from PROGRAM_BANK class;
			// returns no values;

	void INVERT_BY_MATLAB(void); 
			// example: s.INVERT_BY_MATLAB();
			// generate and run a MATLAB program to 
			// invert a matrix;
			// returns no values;
   private:
	int n; 		// max of n is 50
	float A[50][50];
	float B[50];
};

LINEAR_SOLVER::LINEAR_SOLVER(int x)
  	:MATRIX(x, x, "in.6.txt") 	// instantiate MATRIX with input file in.6.txt and 
  				// dim1=x, dim2=x;
{
	// your code for LINEAR_SOLVER constructor goes here
	n = x;
        // read the elements of A and B from in.6.txt
	int i, j;
	
	ifstream input("in.6.txt", ios::in);

	output <<"********** P6 BEGIN *************" <<endl;
	output <<"*** OUTPUT FROM P6_LINEAR_SOLVER:" <<endl;
	output <<"*** INSTANTIATED AN OBJECT WITH "<<n<<" EQUATIONS" <<endl;
	
	for(i=0; i<n; i++)
    {
    	B[i]=0;
        for(j=0; j<n; j++)
        {
        	A[i][j]=0;
        }
    }    
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			input >>A[i][j];

		}
	}
	
	for(i=0; i<n; i++)
	{
		input >>B[i];

	}
	

		 
	output <<"*********** P6 END **************" <<endl;
}
 
void 
LINEAR_SOLVER::SOLVE_LINEAR_EQUATION(char * commd)
{
	int COL, ROW, i, j, k; 
	int FOUND = 1;
	float MULTIPLY, TEMP, SUM;	
	float TEMP_A[50][50];
    float TEMP_B[50];
	float X[50];
	
	
	int TEMP_POS[50], MIN_POS, MAX_POS, TEMP_1;
	float TEMP_VALUE[50], MIN_VALUE, MAX_VALUE, TEMP_2;

    for( COL=0; COL<n; COL++)
    {
        TEMP_B[COL]=B[COL];
        for(ROW = 0; ROW < n; ROW++)
        {
        	TEMP_A[COL][ROW]=A[COL][ROW];
        }
    }        		
        		
	for( COL=0; COL<n && FOUND==1; COL++)
	{					
		if(TEMP_A[COL][COL]==0)
	 	{
			FOUND = 0;
	 		for(i= COL+1; i<n && FOUND == 0; i++)
	 		{
	 			if(TEMP_A[i][COL] != 0)
	 			{
	 				TEMP = TEMP_B[COL];
	 				TEMP_B[COL] = TEMP_B[i];
	 				TEMP_B[i] = TEMP;
	 				
					for(j=0; j<n; j++)
	 				{
	 					TEMP = TEMP_A[COL][j];
	 					TEMP_A[COL][j] = TEMP_A[i][j];
	 					TEMP_A[i][j] = TEMP;
	 				}

					FOUND = 1;
	 			}
	 		}
	 	}		
		
	 	else
		{	
			for( ROW = COL+1; ROW<n; ROW++)
	 		{
	 			MULTIPLY = (-1*TEMP_A[ROW][COL])/(TEMP_A[COL][COL]);
	 			
	 			for( i= COL; i<n; i++)
	 			{
	 				TEMP_A[ROW][i] = (MULTIPLY*TEMP_A[COL][i])+TEMP_A[ROW][i];
	 			}
	 		
	 			TEMP_B[ROW]=(MULTIPLY*TEMP_B[COL])+TEMP_B[ROW];
	 		}
		}
	}

	if(FOUND == 0)
	{
		output	<<"********** P6 BEGIN *************"
				<<endl
				<<"*** MY GAUSSIAN ELIMINATION SOLUTION:"
				<<endl
				<<"*** EQUATION IS SINGULAR"
				<<endl
				<<"*********** P6 END **************"
				<<endl;
	}
	
	else
	{	
		for(ROW = n-1; ROW >= 0; ROW--)
		{
			SUM = 0;
			for( k = n-1; k > ROW; k--)
			{
				SUM+=TEMP_A[ROW][k]*X[k];
			}
			X[ROW]=(TEMP_B[ROW]-SUM)/TEMP_A[ROW][ROW];
		}
		
		if(strcmp(commd, "NONE")==0)
		{
			output	<<"********** P6 BEGIN *************"
					<<endl
					<<"*** MY GAUSSIAN ELIMINATION SOLUTION "
					<<"(SORTED IN ASCENDING ORDER):"
					<<endl;
			
			for (i=0; i<n; i++)
			{
				output	<<"X["<<TEMP_POS[i]<<"]= "
						<<setprecision(2)
						<<setiosflags(ios::fixed | ios::showpoint)
						<<X[i]
						<<endl;
			}
			
			output	<<"*********** P6 END **************" <<endl;
		}
		else if(strcmp(commd, "ASCEND")==0)
		{
			for (i=0; i<n; i++)
			{
				TEMP_POS[i] = i;
				TEMP_VALUE[i] = X[i];
			}
			
			for(i=0; i<n; i++)
			{
				MIN_VALUE = TEMP_VALUE[i];
				MIN_POS = i;
				
				for(j=i; j<n; j++)
				{
					if (TEMP_VALUE[j] < MIN_VALUE)
					{
						MIN_VALUE = TEMP_VALUE[j];
						MIN_POS = j;
					}
					
					else {}
				}	
				TEMP_1 = TEMP_POS[i];
				TEMP_POS[i]= TEMP_POS[MIN_POS];
				TEMP_POS[MIN_POS]= TEMP_1;
					
				TEMP_2 = TEMP_VALUE[i];
				TEMP_VALUE[i] = TEMP_VALUE[MIN_POS];
				TEMP_VALUE[MIN_POS] = TEMP_2;
					
			}
			
			output	<<"********** P6 BEGIN *************" <<endl
				    <<"*** MY GAUSSIAN ELIMINATION SOLUTION "
				    <<"(SORTED IN ASCENDING ORDER):" <<endl;
			
			for (i=0; i<n; i++)
			{
				output	<<"X["<<TEMP_POS[i]<<"]= " <<setprecision(2) <<setiosflags(ios::fixed | ios::showpoint)
					    <<TEMP_VALUE[i] <<endl;
			}
			
			output	<<"*********** P6 END **************" <<endl;
		}
		
		else if(strcmp(commd, "DESCEND")==0)
		{
			for (i=0; i<n; i++)
			{
				TEMP_POS[i] = i;
				TEMP_VALUE[i] = X[i];
			}
			
			for(i=0; i<n; i++)
			{
				MAX_VALUE = TEMP_VALUE[i];
				MAX_POS = i;
				
				for(j=i; j<n; j++)
				{
					if (TEMP_VALUE[j] > MAX_VALUE)
					{
						MAX_VALUE = TEMP_VALUE[j];
						MAX_POS = j;
					}
					
					else {}
				}	
				TEMP_1 = TEMP_POS[i];
				TEMP_POS[i] = TEMP_POS[MAX_POS];
				TEMP_POS[MAX_POS] = TEMP_1;
					
				TEMP_2 = TEMP_VALUE[i];
				TEMP_VALUE[i] = TEMP_VALUE[MAX_POS];
				TEMP_VALUE[MAX_POS] = TEMP_2;
					
			}
			
			output	<<"********** P6 BEGIN *************" <<endl
					<<"*** MY GAUSSIAN ELIMINATION SOLUTION " <<"(SORTED IN DESCENDING ORDER):"
				    <<endl;
			
			for (i=0; i<n; i++)
			{
				output	<<"X["<<TEMP_POS[i]<<"]= " <<setprecision(2) <<setiosflags(ios::fixed | ios::showpoint)
					    <<TEMP_VALUE[i]
					    <<endl;
			}
			
			output	<<"*********** P6 END **************" <<endl;
		}
				
		else{}
	}			
}

void
LINEAR_SOLVER::SOLVE_BY_MATLAB()
{
	ofstream matlabout_file("out_62.m", ios::out); 	
 	
 	int i, j;
 	char copying[100];
 	
 	matlabout_file<<"A=["; 	
 	for(i=0; i<n; i++)
 	{
 		matlabout_file<<A[i][0];
 		for(j=1; j<n; j++)
 		{
 			matlabout_file<<","<<A[i][j];
 		}
 		if( i==n-1 )
 		{
 			matlabout_file<<"];"<<endl;
 		}
 		else
 		{
 			matlabout_file<<";";
 		}
 	}
 	
 	matlabout_file<<"B=["<<B[0];
 	for(i=1; i<n; i++)
 	{
 		matlabout_file<<";"<<B[i];
 	}
 	matlabout_file<<"];"<<endl;
 	
 	matlabout_file<<"X=inv(A)*B;"
	<<endl
		
	<<"fid=fopen('out.6.txt','a');"<<endl
	<<"fprintf(fid,'********** P6 BEGIN *************\\n');"<<endl
	<<"fprintf(fid,'*** RESULT FROM MATLAB (UNSORTED):\\n');"<<endl
	<<"for k=1:"<<n<<endl
	<<"fprintf(fid,'X[%d]=%6.2f\\n',k-1,X(k));"<<endl
	<<"end"<<endl;
	matlabout_file<<"fprintf(fid,'*********** P6 END **************\\n');" <<endl;
		
	system("/bin/csh /ee259/tools/pro_6/run_out_62");
}

void 
LINEAR_SOLVER::INHERITED_INVERT()
{
	
	ofstream out_file2("in.6.txt", ios::out);
	ifstream in_file2("out.5.txt", ios::in);
	
	int i, j;
	char copying[100];
	for(i=0; i< n; i++)
	{
		for(j=0; j< n; j++)
		{
			out_file2 << A[i][j] << " ";
		}
		out_file2 << endl;
	}
	// ...
	
	MATRIX temp_m(n,n,"in.6.txt"); // create a temp matrix from in.6.txt file;
    1/temp_m;
  
    output	<<"********** P6 BEGIN *************"<<endl;
	output	<<"*** AFTER INHERITING FROM MATRIX CLASS, MY RESULT IS:"<<endl;
	

	for( i=0; !in_file2.eof(); i++)
	{
		
		in_file2.getline(copying ,100,'\n');
		if(i>2 && !in_file2.eof())
		{
			output <<copying <<endl;
			
		}
		else {}
	}
	
	output<<"*********** P6 END **************"<<endl;
}

void
LINEAR_SOLVER::INVERT_BY_MATLAB()
{
	ofstream matlabout_file2("out_63.m", ios::out);
	int i, j;
 	char copying[100];
 	
 	matlabout_file2<<"A=["; 	
 	for(i=0; i<n; i++)
 	{
 		matlabout_file2<<A[i][0];
 		for(j=1; j<n; j++)
 		{
 			matlabout_file2<<","<<A[i][j];
 		}
 		if( i==n-1 )
 		{
 			matlabout_file2<<"];"<<endl;
 		}
 		else
 		{
 			matlabout_file2<<";";
 		}
 	}
 	
 	
 	
 	matlabout_file2 <<"X=inv(A);"<<endl
					<<"fid=fopen('out.6.txt','a');"<<endl
					<<"fprintf(fid,'********** P6 BEGIN *************\\n');"<<endl
					<<"fprintf(fid,'*** INVERSION RESULT FROM MATLAB: \\n');"<<endl
					<<"for i=1:"<<n<<endl
					<<"for j=1:"<<n<<endl
					<<"fprintf(fid,'X[%d][%d]=%6.2f ',i-1,j-1,X(i,j));"<<endl
					<<"end"<<endl
					<<"fprintf(fid,'\\n');"<<endl
					<<"end"<<endl
					<<"fprintf(fid,'*********** P6 END **************\\n');"<<endl;
		
					system("/bin/csh /ee259/tools/pro_6/run_out_63");
}