/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"
#define Array_Size 10
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    int array[Array_Size]={0};
    int i=0;
    int positiveNum=0;
    int sum=0;
    
    for(i=0;i<Array_Size;i++)
    { 
        printf("\nEnter value for element[%d]: ",i);
        scanf("%d",&positiveNum);
        if (!(positiveNum>=0))
        {  
            printf("\nValue must be positive!\a\n");
            i--;
        }
        else
        {
            array[i]+=positiveNum;
            
        }
    }
    for(i=0;i<Array_Size;i++)
    {
    sum=sum+array[i];
    }
    printf("The sum of 10 numbers in your array is:%d \n",sum);
    return 0;
    
}
int _write(int file, char *ptr, int len)
{
    (void)file; /* Parameter is not used, suppress unused argument warning */
	int n;
	for(n = 0; n < len; n++) {
        if(*ptr == '\n') UART_1_PutChar('\r');
		UART_1_PutChar(*ptr++);
	}
	return len;
}

int _read (int file, char *ptr, int count)
{
    int chs = 0;
    char ch;
 
    (void)file; /* Parameter is not used, suppress unused argument warning */
    while(count > 0) {
        ch = UART_1_GetChar();
        if(ch != 0) {
            UART_1_PutChar(ch);
            chs++;
            if(ch == '\r') {
                ch = '\n';
                UART_1_PutChar(ch);
            }
            *ptr++ = ch;
            count--;
            if(ch == '\n') break;
        }
    }
    return chs;
}
/* [] END OF FILE */
