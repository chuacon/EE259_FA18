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
	
}

void STUDENT_GRADE::LIST_IDS()
{
	
	
}

void STUDENT_GRADE::LIST_GRADE(int x)
{
	

}// end method

void STUDENT_GRADE::LIST_RANGE(int x)
{

	
}// end method
