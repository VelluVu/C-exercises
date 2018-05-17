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
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int numSolver (int num1, int num2);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    int num1 = 10;
    int num2 = 20;
    
    int number=numSolver (num1,num2);
    
    num1 = 0;
    num2 = 5;
    
    int multiplyer=numSolver (num1,num2);
    
    printf("%d multiplied by %d is: \n",number,multiplyer);
    
    int numbersEqual = number*multiplyer;
    
    printf("%d\n",numbersEqual);
    
    return 0;
}
int numSolver (int num1, int num2)
{
    int result = 0;
    int inputNum1,inputNum2 = 0;
    
    do{
        printf("Enter a number [%d-%d]: \n",num1,num2);
        scanf("%d",&inputNum1);
        if (inputNum1 >= num1 && inputNum2 <= num2)
        {
            result = inputNum1; 
        }
        else
        {
            printf("Invalid value! number must be between %d and %d.\n",num1,num2); 
        }
    }while (result == 0);
    
    
    return result;
    
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
