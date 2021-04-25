#include <iostream>
#include "string.h"
#include <stdio.h>
#include "sstream"
#include "math.h"
	using namespace std;

	enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

	int closing_time(Day day_of_the_week);

	//void clean_stdin();

	/* MAIN PROGRAM */
	int main()
	{
		int count;
		int nAux=1554;
		stringstream strNum;
		string sAux;



              cout.setf(ios::left);
		/* Print table heading */
		cout.width(17);
		cout << "DAY";
		cout << "CLOSING TIME\n\n";

		/* Print table from Sunday to Saturday */
		for (count = static_cast<int>(Sun) ; count <= static_cast<int>(Sat) ; count++)
		{
			cout.width(19);
			switch (count)
			{
				case Sun: cout << "Sunday"; break;
				case Mon: cout << "Monday"; break;
				case Tue: cout << "Tuesday"; break;
				case Wed: cout << "Wednesday"; break;
				case Thu: cout << "Thursday"; break;
				case Fri: cout << "Friday"; break;
				case Sat: cout << "Saturday"; break;
				default:	cout << "ERROR!";
			}


			cout << closing_time(static_cast<Day>(count)) << "pm\n";

			strNum<< nAux;
			strNum>> sAux;
            char buff = sAux[0];
            sAux[0]= sAux[sAux.size()-1];
            sAux[sAux.size()-1] = buff;

			cout<< sAux<< endl;








		}

		return 0;
	}
	/* END OF MAIN PROGRAM */

	/* FUNCTION TO GENERATE SHOP CLOSING TIMES FROM DAY OF THE WEEK */
	int closing_time(Day day_of_the_week)
	{
		return 5;
	}

	/*void clean_stdin(){
        char c;
        int a;
        do{
            c=getchar();
           }while (c!='/n' || a =fgetc(stdin)!= EOF);
	}*/
