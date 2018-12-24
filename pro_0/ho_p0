\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_
\_                                                                    \_
\_   THE CITY COLLEGE OF NEW YORK, ELECTRICAL ENGINEERING DEPARTMENT  \_
\_                EE259, DAY-EVENING SECTIONS, FALL 2018              \_
\_                                                                    \_
\_                              PROJECT 0                             \_
\_                                                                    \_
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

PROJECT 0 DESCRIPTION:

Write a C++ class definition called COUNTER which calculates the 
number of passing and failing grades in a list of grades. 

The prototype for the  class COUNTER is defined as follows:

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

The objects of STUDENT_ID class will read the input values from a file called
studentId.txt given with the following format:

	id_1
	id_2
	...
	id_n

After the id values are stored in private data array called ids, the output 
to out.0 file is:

	+ P0 START 
	+ OUTPUT FROM STUDENT_ID CONSTRUCTOR:
	+ INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH n STUDENT IDS.
	+ P0 END

where n is the input parameter for the constructor (defined in the main
program that is instantiating this object).

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Definition of LIST_ID method is as follows:

	C.LIST_ID(x);

where C is an object of class STUDEnT_ID and x is an integer. 

If x is 1, this method lists the ids of students into out.0 file 
in the same order that they are in ids array. The format s as follows:

	+ P0 START 
	+ OUTPUT FROM LIST_ID METHOD:
	+ STUDENT IDS FOR n STUDENTS:
	+ id_1	
	...
	+ id_n	
	+ P0 END

where n is the total number students.

Similarly, if x is -1, the is list is in reverse order as follows:

	+ P0 START 
	+ OUTPUT FROM LIST_ID METHOD:
	+ STUDENT IDS FOR n STUDENTS IN REVERSE ORDER:
	+ id_n	
	...
	+ id_1	
	+ P0 END

If x has any other value, the output to out.0 is:

	+ P0 START 
	+ OUTPUT FROM LIST_ID METHOD:
	+ INPUT ERROR.
	+ P0 END

All outputs to out.0 file must end with endl.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

:::::::::::::: EXAMPLE 1 ::::::::::::::::::::: 
---------CONTENTS OF main0_1.cc FILE:-----------
#include "p0.h"
// example program: main0_1.cc
int main ()
{
        STUDENT_ID C(5); // instantiate an object C of class STUDENT_ID
			// with 5 student ids
	return 0;
}
---------CONTENTS OF studentId.txt FILE:---------------
1111
3333
2222
5555
4444
---------EXPECTED CONTENTS OF out.0 FILE:-----
+ P0 START 
+ OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 5 STUDENT IDS.
+ P0 END
:::::::::::::: EXAMPLE 2 ::::::::::::::::::::: 
---------CONTENTS OF main0_2.cc FILE:-----------
#include "p0.h"
// example program: main0_2.cc
int main ()
{
        STUDENT_ID C(4); // instantiate an object C of class STUDENT_ID
			// with 4 student ids

	C.LIST_ID(1);	// list the ids
	return 0;
}
---------CONTENTS OF in.0 FILE:---------------
1111
3333
2222
5555
---------EXPECTED CONTENTS OF out.0 FILE:-----
+ P0 START 
+ OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 4 STUDENT IDS.
+ P0 END
+ P0 START 
+ OUTPUT FROM LIST_ID METHOD:
+ STUDENT IDS FOR 4 STUDENTS:
+ 1111
+ 3333
+ 2222
+ 5555
+ P0 END
:::::::::::::: EXAMPLE 3 ::::::::::::::::::::: 
---------CONTENTS OF main0_3.cc FILE:-----------
#include "p0.h"
// example program: main0_3.cc
int main ()
{
        STUDENT_ID C(4); // instantiate an object C of class STUDENT_ID
			// with 4 student ids

	C.LIST_ID(-1);	// list the ids in reverse order
	return 0;
}
---------CONTENTS OF in.0 FILE:---------------
1111
3333
2222
5555
---------EXPECTED CONTENTS OF out.0 FILE:-----
+ P0 START 
+ OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 4 STUDENT IDS.
+ P0 END
+ P0 START 
+ OUTPUT FROM LIST_ID METHOD:
+ STUDENT IDS FOR 4 STUDENTS IN REVERSE ORDER:
+ 1111
+ 3333
+ 2222
+ 5555
+ P0 END
:::::::::::::: EXAMPLE 4 ::::::::::::::::::::: 
---------CONTENTS OF main0_4.cc FILE:-----------
#include "p0.h"
// example program: main0_4.cc
int main ()
{
        STUDENT_ID C(3); // instantiate an object C of class STUDENT_ID
			// with 3 student ids

	C.LIST_ID(-1);	// list the ids in reverse order
	C.LIST_ID(0);	// input error
	C.LIST_ID(1);	// list the ids 
	return 0;
}
---------CONTENTS OF in.0 FILE:---------------
1111
3333
2222
---------EXPECTED CONTENTS OF out.0 FILE:-----
+ P0 START 
+ OUTPUT FROM STUDENT_ID CONSTRUCTOR:
+ INSTANTIATED AN OBJECT OF CLASS STUDENT_ID WITH 3 STUDENT IDS.
+ P0 END
+ P0 START 
+ OUTPUT FROM LIST_ID METHOD:
+ STUDENT IDS FOR 3 STUDENTS IN REVERSE ORDER:
+ 2222
+ 3333
+ 1111
+ P0 END
+ P0 START 
+ OUTPUT FROM LIST_ID METHOD:
+ INPUT ERROR.
+ P0 END
+ P0 START 
+ OUTPUT FROM LIST_ID METHOD:
+ STUDENT IDS FOR 3 STUDENTS:
+ 1111
+ 3333
+ 2222
+ P0 END
