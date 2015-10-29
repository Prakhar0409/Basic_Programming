#define N           200
#define ARRAY_SIZE  (N*N)
#define M           100 



/*******************************************************************************
* Function Name  : array_map
* Description    : Maps plain_text_zero_padded to mapped_array using map array 
* Input          : plain_text_zero_padded
* Output         : mapped_array
* Return         : None
* Example        : plain_text_zero_padded "ABCDE00" -> mapped_array "abcd2ii" 
*******************************************************************************/
void array_map(char mapped_array[ARRAY_SIZE], char plain_text_zero_padded[ARRAY_SIZE]);



/*******************************************************************************
* Function Name  : inv_array_map
* Description    : Maps inv_mapped_array to decrypt_plain_text_zero_padded using map array 
* Input          : inv_mapped_array
* Output         : decrypt_plain_text_zero_padded
* Return         : None
* Example        : inv_mapped_array "abcd2ii" -> decrypt_plain_text_zero_padded "ABCDE00" 
*******************************************************************************/
void inv_array_map(char inv_mapped_array[ARRAY_SIZE], char decrypt_plain_text_zero_padded[ARRAY_SIZE]);

