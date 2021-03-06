#include <iostream> 	// Allows input output operations
#include <iomanip>
#include<math.h>

#include "print_functions.h"

using namespace std;

#define N           200
#define ARRAY_SIZE  (N*N)
#define M           100 



void print(char c[N][N], int row, int col)
{

  int i,j;

  for(i=0;i<row;i++){  
    for(j=0;j<col;j++){
     cout << c[i][j]<< " ";
    }
  cout << endl;
  }

}

void print(float f[N][N], int row, int col)
{

  int i,j;

  for(i=0;i<row;i++){  
    for(j=0;j<col;j++){
     std::cout << std::fixed << std::setprecision(3) << setw(15) << f[i][j] ;
    }
  cout << endl;
  }

}
