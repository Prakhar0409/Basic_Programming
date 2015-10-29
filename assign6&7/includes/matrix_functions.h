#define N           200
#define ARRAY_SIZE  (N*N)
#define M           100 



/*******************************************************************************
* Function Name  : determinant
* Description    : Given a square matrix array[][]. Calculates determinant. 
* Input          : array,order
* Output         : Determinant  
* Return         : determinant value(type float)
* Example        : Order = 2 
Array [ 3 2   ]   -> Returns 5.3000
      [ 2 3.1 ]     

 *******************************************************************************/
float determinant(float array[N][N],float order);


/*******************************************************************************
* Function Name  : inverse
* Description    : Given a square matrix array[][]. Calculates inverse_array. 
* Input          : array,order
* Output         : inv
* Return         : None
* Example        : Order = 2 

Array [ 3 2 ]   -> inv [  (3/5)   (-2/5)  ]
      [ 2 3 ]          [  (-2/5)  (3/5)   ]
 
*******************************************************************************/


void inverse(float inv[N][N],float array[N][N],float order);

