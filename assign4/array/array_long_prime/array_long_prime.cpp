#include <iostream> 	// Allows input output operations
#include <iomanip>		// Allows usage of setprecision
#include <math.h>		/* exp */

using namespace std;

bool isPrime(int x)
{
	if(x==1 || x==0)
		return false;
	if(x==2)
		return true;
	else if(x!=2 && x%2==0)
		return false;
	else
	{
		int y=x/2;
		for(int i=3;i<y;i+=2)
		{
			if(x%i==0)
			{
				return false;
			}

		}
		return true;

	}
	return true;
}

int main() {

	/*********** DO NOT CHANGE VARIABLE NAMES ************/
	int array[100];	    //  Input Array entered by the user
	int N ;             //  Number of elements, N <=100

        int len =0;
        int start = 0;

	/***************Get User Input***************/
	cout << "Enter number of elements ";
	cin >> N;
	cout << endl;

	if(N<0 || N>100 || cin.fail()){
		cout<<"INVALID INPUT"<<endl;
		return 0;
	}

	cout << "Enter " << N << " integers ";
	cout << endl;



        //Taking input in array  
        for(int i = 0; i < N; i++){
        	cin>>array[i];
        	if(cin.fail() || array[i]<0)
        	{
        		cout<<"INVALID INPUT"<<endl;
        		return 0;
        	}

        }
        cout<<endl; 

	/***************End User Input***************/	
	
	
	/*---------------------------------------------*/
	// Please add your code here for Q1
        int start1=0,len1=0;
	for(int i=0;i<N;i++)
	{
		if(isPrime(array[i]))
		{
			start1=i;
			len1=1;
			int j=start1+1;
			while(isPrime(array[j]) && j<N)
			{
				len1++;
				j++;
			}
			i+=len1;
		}
		if(len1>len)
		{
			start=start1;
			len=len1;
		}
	}



        /*---------------------------------------------*/

        for(int j = start; j< (len + start); j++)
           cout<<array[j]<<" ";
        cout<<endl;
           
        cout<<"Start  =  " << start<<endl;
        cout<<"Length =  " << len<<endl;
	
	return 0;
}
