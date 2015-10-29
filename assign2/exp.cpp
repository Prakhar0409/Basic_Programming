#include <iostream> 	// Allows input output operations
#include <iomanip>		// Allows usage of setprecision
#include <math.h>		/* exp */

using namespace std;

int main() {

	/*********** DO NOT CHANGE VARIABLE NAMES ************/
	unsigned int k = 1;	//Keeps track of the count in the loop
	double ex = 1; 		//The summation of each polynomial evaluated
	double err;			//Err
	double x;		 	//Input

	double n=1;		//nth term

	/***************Get User Input***************/
	cout << "x = ";
	cin >> x;
	cout << endl;

	cout << "Error = ";
	cin >> err;
	cout << endl;

	//calculating taylor series ka sum untill

	for(k=1;n>=err || k==1 ;k++)
	{	n=1;
		n=(n*x)/(k);  	//k=n-1 gives the nth term:nth term=(n-1)th term *x/(n-1)
						//this loop with k=1 gives 2nd term

		ex=ex+n;
	}

	//cout<<ex<<endl<<k<<endl;


	/***************End User Input***************/	
	

	/*---------------------------------------------*/
	// Please add your code here for Q1





	/*---------------------------------------------*/

	cout << "exp(" << x << ") = " << setprecision(7) <<  ex << endl;
	cout << "Number of Terms : " << k << endl;

	return 0;
}

