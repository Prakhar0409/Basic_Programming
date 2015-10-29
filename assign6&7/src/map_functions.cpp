#include <iostream> 	// Allows input output operations
#include <iomanip>
#include<math.h>

#include "map_functions.h"

using namespace std;

#define N           200
#define ARRAY_SIZE  (N*N)
#define M           100 

char map[M][2] = 
{
{'A','6'}, {'B','b'}, {'C','c'}, {'D','d'}, {'E','2'}, {'F','1'}, {'G','g'}, {'H','h'}, {'I','9'}, {'J','j'}, {'K','k'}, 
{'L','S'}, {'M','m'}, {'N','n'}, {'O','o'}, {'P','p'}, {'Q','q'}, {'R','r'}, {'S','s'}, {'T','t'}, {'U','u'}, {'V','v'}, 
{'W','w'}, {'X','x'}, {'Y','y'}, {'Z','z'}, {'a','A'}, {'b','B'}, {'c','C'}, {'d','D'}, {'e','E'}, {'f','F'}, {'g','G'}, 
{'h','H'}, {'i','I'}, {'j','J'}, {'k','K'}, {'l','L'}, {'m','M'}, {'n','N'}, {'o','O'}, {'p','P'}, {'q','Q'}, {'r','R'}, 
{'s','l'}, {'t','T'}, {'u','U'}, {'v','V'}, {'w','W'}, {'x','X'}, {'y','Y'}, {'z','Z'}, {'0','i'}, {'1','8'}, {'2','7'}, 
{'3','a'}, {'4','5'}, {'5','4'}, {'6','3'}, {'7','e'}, {'8','f'}, {'9','0'}
};



/*******************************************************************************
* Function Name  : array_map
* Description    : Maps plain_text_zero_padded to mapped_array using map array 
* Input          : plain_text_zero_padded
* Output         : mapped_array
* Return         : None
* Example        : plain_text_zero_padded "ABCDE00" -> mapped_array "abcd2ii" 
*******************************************************************************/


void array_map(char mapped_array[ARRAY_SIZE], char plain_text_zero_padded[ARRAY_SIZE])
{
	int i=0;
		while(plain_text_zero_padded[i]!='\0')
		{
			for(int j=0;j<M;j++)
			{
				if(plain_text_zero_padded[i]==map[j][0])
				{
					mapped_array[i]=map[j][1];
		//			cout<<"i m inside for loop i="<<i<<"j="<<j<<"mapped array="<<mapped_array[i]<<endl;
				}
			}
			i++;
		}
}



/*******************************************************************************
* Function Name  : inv_array_map
* Description    : Maps inv_mapped_array to decrypt_plain_text_zero_padded using map array 
* Input          : inv_mapped_array
* Output         : decrypt_plain_text_zero_padded
* Return         : None
* Example        : inv_mapped_array "abcd2ii" -> decrypt_plain_text_zero_padded "ABCDE00" 
*******************************************************************************/

void inv_array_map(char inv_mapped_array[ARRAY_SIZE], char decrypt_plain_text_zero_padded[ARRAY_SIZE])
{
	int i=0;
		while(inv_mapped_array[i]!='\0')
		{
			for(int j=0;j<M;j++)
			{
				if(map[j][1]==inv_mapped_array[i])
				{
					decrypt_plain_text_zero_padded[i]=map[j][0];
				}
			}
			i++;
		}
}

