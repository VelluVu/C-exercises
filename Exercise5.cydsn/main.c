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
    
    float weight;
    float height;
    float heightMetres;
    float bmi;
    
    printf("\nEnter your weight in kilograms: ");
    scanf("%f",&weight);
    printf("\nEnter your height in centimeters: ");
    scanf("%f",&height);
    heightMetres=height/100;
    heightMetres=heightMetres*heightMetres;
    bmi=weight/heightMetres;
    printf("Your BMI is %f.\n",bmi);
    if(bmi<18.5)
    {
        printf("According to BMI you have underweight.\n");
    }
    else
    if(bmi>=18.5&&bmi<25)
    {
        printf("According to BMI you have normal weight.\n");
    }
    else
    if(bmi>=25)
    {
        printf("According to BMI you have overweight.\n");
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
