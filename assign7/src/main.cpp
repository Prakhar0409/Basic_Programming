#include <iostream> 	// Allows input output operations
#include <iomanip>
#include<math.h>

//user defined headers
#include "matrix_functions.h"
#include "map_functions.h"
#include "print_functions.h"
#include "compare_functions.h"

using namespace std;

#define N           200
#define ARRAY_SIZE  (N*N)
#define M           100 

//  Mapping is defined for [a-z] , [A-Z] , [0-9]
//  {'A','6'} maps A to 6 
//


// Define functionality for the following functions
// And call them in main()

/*For calculating Determinant of the Matrix */



// Donot modify the functions below(upto main) 

void keygen(float key[N][N], int marker)
{
  int i,j;

 for(i=0;i<marker;i++){  
    for(j=0;j<marker;j++){
      if(i != j)
        key[i][j] = marker;
      else
        key[i][j] = marker + 1;
    }
  }

}



int main() {

	/*********** DO NOT CHANGE VARIABLE NAMES ************/
	 char plain_text[ARRAY_SIZE];
	char plain_text_zero_padded[ARRAY_SIZE];
	char mapped_array[ARRAY_SIZE];
	float mapped_array_in_2D[N][N];
	int marker;
	char inv_mapped_array[ARRAY_SIZE];
	char decrypt_plain_text_zero_padded[ARRAY_SIZE];
	float key[N][N];

	float cipher_text[N][N];
	float invkey[N][N];
	char decrypt_plain_text[ARRAY_SIZE];


	/***************Get User Input***************/


        cout << "Enter the plain text" << endl;
        cin >> plain_text;

        cout << "Enter the marker" << endl;
        cin >> marker;
        
        // Creating a key matrix of size (marker x marker)
        keygen(key,marker);


        /***************End User Input***************/	
	
	
	/*---------------------------------------------*/

	// Please add your code here 
        //getting string or plain text length.
		int length=0; 	//length of the plain text.
		for(int i=0;plain_text[i]!='\0';i++)
		{
			plain_text_zero_padded[i]=plain_text[i];
			length++;
		}


//		cout<<length<<endl;			//output length of input string



		// Step 1---Padding with zeros-0's
			int tmp=(length%marker);
			if(tmp!=0)tmp=marker-tmp;
			for(int i=0;i<tmp;i++)
				plain_text_zero_padded[length+i]='0';
			length=length+tmp;
			plain_text_zero_padded[length]='\0';



/*			//OUTPUT length and plain text zero padded
			cout<<length<<endl;
			for(int i=0;i<length;i++)
				cout<<plain_text_zero_padded[i];
			cout<<endl;
*/


	   //Step 2---mapping 0 padded plain text (stored in plain text) into mapped_array
			array_map(mapped_array, plain_text_zero_padded);



/*			//OUTPUT mapped array
			for(int i=0;i<length;i++)
			{
				cout<<mapped_array[i];
			}
			cout<<endl;
*/


	   //step 3--generating cipher text
			//3.1)---writing mapped_array in 2 D form
			mapped_array[length]='\0';
			int j1=0;
			for(int i=0;mapped_array[i*marker+j1]!='\0';i++)
			{
				for(j1=0;j1<marker;j1++)
				{
					mapped_array_in_2D[i][j1]=mapped_array[i*marker+j1];
				}
				j1=0;
			}

/*			//OUTPUT 2D array
			for(int i=0;mapped_array[i]!='\0';i++)
			{
				for(int j=0;j<marker;j++)
				{
					cout<<mapped_array_in_2D[i][j];
				}
				cout<<endl;
			}
*/


			//create cipher text

			for(int i=0;i<(length/marker);i++)
			{
				for(int j=0;j<marker;j++)
				{
					cipher_text[i][j]=0;
					for(int k=0;k<marker;k++)
					{
						cipher_text[i][j]+=mapped_array_in_2D[i][k]*key[k][j];
					}
				}
			}

			inverse(invkey,key,marker);

			//transpose
			for(int i=0;i<marker;i++)
			{
				for(int j=0;j<i;j++)
				{
					invkey[i][j]+=invkey[j][i];
					invkey[j][i]=invkey[i][j]-invkey[j][i];
					invkey[i][j]=invkey[i][j]-invkey[j][i];
				}
			}



			for(int i=0;i<(length/marker);i++)
			{
				for(int j=0;j<marker;j++)
				{
					mapped_array_in_2D[i][j]='\0';
					for(int k=0;k<marker;k++)
					{
						mapped_array_in_2D[i][j]+=cipher_text[i][k]*invkey[k][j];
					}
					mapped_array_in_2D[i][j]=round(mapped_array_in_2D[i][j]);
				}
			}

/*			//OUTPUT array mapped in 2D
			cout<<"array mapped in 2d"<<endl;
			for(int i=0;i<length/marker;i++)
			{
				for(int j=0;j<marker;j++)
				{
					cout<<mapped_array_in_2D[i][j];
				}
				cout<<endl;
			}
*/

			//from 2d array to a single 1D array with inverse mappings.
			for(int i=0;i<(length/marker);i++)
			{
				for(int j=0;j<marker;j++)
				{
					inv_mapped_array[(i*marker)+j]=mapped_array_in_2D[i][j];
				}
			}
			inv_mapped_array[length]='\0';

/*			// OUTPUT inverse mapped array
			cout<<"inverse mapped array"<<endl;
			for(int i=0;i<length;i++)
			{
				cout<<inv_mapped_array[i];
			}
*/


		inv_array_map(inv_mapped_array, decrypt_plain_text_zero_padded);

/*    //OUTPUT decrypted plain text zero padded
		cout<<"decrypt plain text zero padded"<<endl;
		for(int i=0;i<length;i++)
		{
			cout<<decrypt_plain_text_zero_padded[i];
		}
*/

		int x=length-1;
		while(decrypt_plain_text_zero_padded[x]=='0')
		{
			x--;
		}
		for(int i=0;i<=x;i++){
			decrypt_plain_text[i]=decrypt_plain_text_zero_padded[i];
		}

/*      // OUTPUT decrypted plain text
		cout<<"decrypted plain text"<<endl;
		for(int i=0;i<=x;i++){
					cout<<decrypt_plain_text[i];
		 }
		cout<<endl;
*/





        /*---------------------------------------------*/
        //  Donot modify 
        //
        int length_of_input;
        for (length_of_input = 0;plain_text[length_of_input];length_of_input++);
       
        cout << "Plain Text entered" << endl;
        cout << plain_text<< "\n";
       
        cout << "Key Used" << endl;
        print(key,marker,marker);
        
        cout << "Cipher Text " << endl;
        print(cipher_text,(int)ceil((float)length_of_input/marker),marker);

        cout << "Key Inverse" << endl;
        print(invkey,marker,marker);
        
        cout << "Decrypted Text" << endl;
        cout << decrypt_plain_text << "\n";

        compare(plain_text,decrypt_plain_text,length_of_input);
            
	return 0;
}

