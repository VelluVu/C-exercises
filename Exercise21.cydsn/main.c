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

#define studentAmount 5

struct Students {
    char firstN[22];
    char LastN[22];
    int courseCredit;
};


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    struct Students name1[studentAmount] = {"","",0};
    
    int fillData;
    
    
    for(fillData=0;fillData<studentAmount;fillData++){
    
        printf("Enter first name of \n");
        printf("Student %d: ",fillData+1);
        scanf("%s",name1[fillData].firstN);
        printf("Enter last name of \n");
        printf("Student %d: ",fillData+1);
        scanf("%s",name1[fillData].LastN);
        printf("Enter number of credits of \n");
        printf("Student %d: ",fillData+1);
        scanf("%d",&name1[fillData].courseCredit);
    }
    
    for(fillData=0;fillData<studentAmount;fillData++){
        printf("%-20s%-20s%10d\n",
        name1[fillData].firstN,name1[fillData].LastN,name1[fillData].courseCredit);
    }
    
    
   
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
