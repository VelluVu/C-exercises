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


float numCalculator (float *num1, float *num2);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
       float number1 = 0;
    float number2 = 0;
    float *num1 = 0;
    float *num2 = 0;
    float averageNum = 0;
    
    do{
    printf("\nEnter 1. number: ");
    scanf("%f",&number1);
    if (number1 >= 0)
    {
        num1 = &number1;
    }
    else
    {
        printf("\n\aNumber must be positive!");
    }
    }while(number1 <0);
    do{
    printf("\nEnter 2. number: ");
    scanf("%f",&number2);
    if (number2 >= 0)
    {
        num2 = &number2;
    }
    else
    {
        printf("\n\aNumber must be positive!");
    }
    }while(number2 <0);
    averageNum = numCalculator(num1,num2);
    
    
    printf("Average value is: %f\n",averageNum);
    printf("deviation 1: %f\n", 0-*num2);
    printf("deviation 2: %f\n", *num2);
    return 0;
}
float numCalculator (float *num1, float *num2)
{
    float average = 0;
    average = (*num1 + *num2) / 2;
    *num1 = average;
    *num2 -= *num1;
    return average;
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
