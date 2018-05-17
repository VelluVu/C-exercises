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
    
    int selection;
    int result;
    int op1;
    int op2;
    
    do
    {
        selection = SelectionMenu();
        switch(selection)
        {
            case 1:
            printf("\nEnter operand 1: ");
            scanf("%d",&op1);
            printf("\nEnter operand 2: ");
            scanf("%d",&op2);
              break;
            case 2:
            result=op1*op2;
            printf("result = %d\n",result);
              break;
            case 3:
            result=op1+op2;
            printf("result = %d\n",result);
              break;
            case 4:
            
              break;
        }
        
    }while(selection != 4);
    
    return 0;
}
    int SelectionMenu(void)
    {
        int selection;
        
        printf("Select operation: \n");
        printf("1)enter operands\n");
        printf("2)multiply operands\n");
        printf("3)add operants\n");
        printf("4)quit\n");
        scanf("%d",&selection);
        
        return selection;
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
