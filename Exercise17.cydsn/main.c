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


void numCalculator (float num1, float num2[5], int num3);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
       float number1 = 0;
    float number2 = 0;
    float num1 = 0;
    float num2[5] = {};
    int num3 = 5;
    float amount [5]={};
    int j;
    
    do
    {    
    printf("\nEnter Exchange rate: ");
    scanf("%f",&number1);
    printf("\nEnter 1. amount: ");
    scanf("%f",&amount[0]);
    printf("\nEnter 2. amount: ");
    scanf("%f",&amount[1]);
    printf("\nEnter 3. amount: ");
    scanf("%f",&amount[2]);
    printf("\nEnter 4. amount: ");
    scanf("%f",&amount[3]);
    printf("\nEnter 5. amount: ");
    scanf("%f",&amount[4]);
    
    if (number1 >= 0 && amount[0] >= 0 && amount[1] >= 0 && amount[2] >= 0 && amount[3] >= 0 && amount[4] >= 0)
    {
        num1 = number1;
        num2[0] = amount[0];
        num2[1] = amount[1];
        num2[2] = amount[2];
        num2[3] = amount[3];
        num2[4] = amount[4];
       
    }
    else
    {
        printf("\n\aNumber must be positive!");
    }
    }while(number1 <0 && amount[0] <0 && amount[1] <0 && amount[2] <0 && amount[3] <0 && amount[4] <0);
    numCalculator(num1, num2, num3);
    for (j = 0; j<5; j++)
    {
    printf ("Converted values are:[%d]=%f\n",j,num2[j]);
    }
    return 0;
}
void numCalculator (float num1, float num2[5], int num3)
{
    int i;
    for (i = 0; i < num3; i++)
    {
        num2[i] *= num1;
    }
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
