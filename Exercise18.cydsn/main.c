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
#include "string.h"
#include <stdlib.h>
#include <time.h>

#define NAME_SIZE 50

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    char fName[NAME_SIZE] = {""};
    char lName[NAME_SIZE] = {""};
    char wName[NAME_SIZE] = {""};
    int length, length2, lengthMax, lengthTotal;
    
    printf("\nEnter your first name: ");
    
    scanf("%s",fName);
    length = strlen(fName);
    
    printf("Enter your last name: ");
    
    scanf("%s",lName);
    length2 = strlen(lName);
    lengthTotal= length+length2;
    lengthMax = NAME_SIZE-1;
    if (lengthTotal <= lengthMax)
    {
        strcpy(wName,lName);
        strcat(wName,(" "));
        strcat(wName,fName);
    }
    else {
        printf("Length of names %d and %d is too long to copy %d.",length,length2,lengthMax);
    }
    printf("Hello, %s\n",wName);
    printf("Length of your name = %d\n",strlen(wName));
    
    
    
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
