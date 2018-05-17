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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int cur_d;
    int cur_m;
    int cur_y;
    int next_d;
    int next_m;
    int next_y;
    int next_days;
    
    printf("\nEnter today's date (d.m.y): ");
    scanf("%d.%d.%d\n",&cur_d,&cur_m,&cur_y);
    printf("Today's date is: %d.%d.%d\n",cur_d,cur_m,cur_y);
    next_days=month[cur_m-1];
    if(cur_m==2)
    {
        if(cur_y%100==0)
        {
            if(cur_y%400==0)
            next_days=28;
        }
        else
        if(cur_y%4==0)
        next_days=29;
    }
    next_d=cur_d+1;
    next_m=cur_m;
    next_y=cur_y;
    if(next_d>next_days)
    {
        next_d=1;
        next_m++;
    }
    if (next_m>12)
    {
        next_m=1;
        next_y++;
    }
    printf("Tomorrow is: %d.%d.%d\n",next_d,next_m,next_y);
       
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
