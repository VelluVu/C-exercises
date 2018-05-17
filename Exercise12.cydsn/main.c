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

float moneyWasher(int euros, int dollars);
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    int euros = 0;
    int dollars = 0;
    float resultFromWasher;
    
    
    printf("\nEnter amount of euros: ");
    scanf("%d",&euros);
    printf("\nEnter amount of dollars: ");
    scanf("%d",&dollars);
    
    resultFromWasher = moneyWasher(euros,dollars);
    
    printf("You'll get %f dollars. \n",resultFromWasher);
    
    return 0;
}
float moneyWasher(int euros,int dollars)
{
    float result=0;
    float exchangeRate;
    exchangeRate = dollars/euros;
    printf("\nexchange rate:%.4f\n",exchangeRate);
    printf("\nHow many euros do want to exchange: ");
    scanf("%d",&euros);
    
    result = euros * exchangeRate;
    
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
