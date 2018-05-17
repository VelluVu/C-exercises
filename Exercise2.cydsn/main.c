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

    float cur_salary=2117.12;
    float cur_tax_percent=20;
    float one_percent=100;
    float cur_tax_val;
    float cur_money;
    float salary_rise=2000;
    float new_salary;
    float new_tax_percent;
    float new_tax_val;
    float after_tax;
    
    //counting taxes and stuff
    cur_tax_val=cur_salary/one_percent*cur_tax_percent;
    cur_money=cur_salary-cur_tax_val;
    new_salary=cur_salary+salary_rise;
    new_tax_percent=cur_tax_percent*1.675;
    new_tax_val=new_salary/one_percent*new_tax_percent;
    after_tax=new_salary-new_tax_val;
    
    printf("My salary is %.2f euros.\n",cur_salary);
    printf("My tax percentage is %.2f percent.\n",cur_tax_percent);
    printf("I have to pay %.2f euros tax.\n",cur_tax_val);
    printf("I have %.2f euros to spend or save.\n",cur_money);
    printf("My boss raises my salary by %.2f euros.\n",salary_rise);
    printf("My new salary is %.2f euros.\n",new_salary);
    printf("My new Tax percent is %.2f. \n",new_tax_percent);
    printf("After taxes I have %.2f euros.\n",after_tax);
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
