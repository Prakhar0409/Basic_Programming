#include <iostream> 	// Allows input output operations
#include <iomanip>
#include<math.h>

#include "compare_functions.h"

using namespace std;

#define N           200
#define ARRAY_SIZE  (N*N)
#define M           100 


void compare(char plain_text[N],char decrypt_plain_text[N], int length_of_input)
{
  int loi;
  for (loi = 0;(plain_text[loi] == decrypt_plain_text[loi] && plain_text[loi]);loi++);
  if(loi == length_of_input)
    cout << "SUCCESS"<<endl;
}

