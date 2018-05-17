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

void askingQuestions(char *question,char *answer,int maxLength);
#define STR_SIZE 301
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    char question1[STR_SIZE]="Enter your name: ";
    char question2[STR_SIZE]="Enter your address: ";
    char question3[STR_SIZE]="Enter postal code: ";
    char theAnswer[STR_SIZE]="";
    char question[STR_SIZE]="";
    char answer[STR_SIZE]="";
    int maxLength=STR_SIZE;
    
    strcpy(question,question1);
    askingQuestions(question,answer,maxLength);
    strcpy (theAnswer,answer);
    strcpy(question,question2);
    askingQuestions(question,answer,maxLength);
    strcat (theAnswer,answer);
    strcpy(question,question3);
    askingQuestions(question,answer,maxLength);
    strcat (theAnswer,answer);
    
    printf("\nYour address is: \n%s",theAnswer);
    return 0;

}
void askingQuestions (char *question, char *answer,int maxLength)
{
    int length = strlen(question);
    int length2 = strlen(answer);
    if (length <= STR_SIZE-1 && length2 <= STR_SIZE-1){
    printf("\n%s ",question);
    if (answer[strlen(answer)-1]=='\n'){
        answer[strlen(answer)-1]='\0';   
    }
    fgets(answer,maxLength,stdin);
    }
    else
    {
        printf("Error %d > %d, or %d > %d\n",length,STR_SIZE,length2,STR_SIZE);
    }
    
    
    
    
    //printf("Length = %d\n",strlen(&answer));
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
