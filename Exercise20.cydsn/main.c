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



struct Months {
    char month[22];
    int monthId;
    
};

void whichMonth(struct Months);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    struct Months num = {"",0};
    struct Months num1 = {"",0};
    
    
    printf ("\nEnter information about first month of year: ");
    
    
    do{
        printf ("\nEnter month number: ");
        scanf("%d",&num.monthId);
        if (num.monthId > 0 && num.monthId < 13){
        }
        else {
            printf("\nMonth number must be in range 1-12!");
            num.monthId=0;
        }
    }while(num.monthId <=0 || num.monthId >12);
    printf ("\nEnter name of the month number %d: ",num.monthId);
    
    scanf("%s",num.month);
    
    printf ("\nEnter information about last month of year: ");
    
    do{
        printf ("\nEnter month number: ");
        scanf("%d",&num1.monthId);
        if (num1.monthId > 0 && num1.monthId < 13){
        }
        else{
            printf("\nMonth number must be in range 1-12!");
            num1.monthId=0;
        }
    }while(num1.monthId <=0 || num1.monthId >12);
    printf ("\nEnter name of the month number %d: ",num1.monthId);
    
    scanf("%s",num1.month);
    
    printf("\nYou entered the following months: \n");
    
    whichMonth(num);
    whichMonth(num1);
   
    return 0;

}
void whichMonth(struct Months m){
    printf("\n%d . %s",m.monthId,m.month);
    printf("\n");
    
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
