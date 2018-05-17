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
    
    int sleepTimeHours = 0;
    int sleepTimeMinutes = 0;
    int curHours = 0;
    int curMinutes = 0;
    int hoursPerDayMin=0;
    int hoursPerDayMax=24;
    int minutesPerHourMin=0;
    int minutesPerHourMax=60;
    int hoursToWakeUp = 0;
    int minutesToWakeUp = 0;
    int difHours = 0;
    int difMins= 0;
    
    printf("\nEnter current time (hh:mm): ");
    scanf("%d:%d",&curHours,&curMinutes);
    printf("How long do you want to sleep (h:mm): \n");
    scanf("%d:%d",&sleepTimeHours,&sleepTimeMinutes);
    //adds hours and minutes to curtime and stores it in new variable
    difHours=curHours+sleepTimeHours;
    difMins=curMinutes+sleepTimeMinutes;
    
    //checks if difhours is bigger than max hours per day and minutes per hour.
    
    if(difHours<hoursPerDayMax&&difMins<minutesPerHourMax)
    {
        hoursToWakeUp=difHours;
        minutesToWakeUp=difMins;
    }
    else if (difHours>= hoursPerDayMax && difMins<minutesPerHourMax)
        {
        hoursToWakeUp = difHours&hoursPerDayMax;
        minutesToWakeUp=difMins;
        }
    else if (difHours<hoursPerDayMax&&difMins>=minutesPerHourMax)
    {
        hoursToWakeUp = difHours;
        minutesToWakeUp = difMins-minutesPerHourMax;
        hoursToWakeUp += 1;
    }
    else if (difHours>=hoursPerDayMax&&difMins>=minutesPerHourMax)
    {
        hoursToWakeUp=difHours%hoursPerDayMax;
        minutesToWakeUp=difMins-minutesPerHourMax;
        hoursToWakeUp += 1;
    }
    
    printf("If you go to bed now you must wake up at %d:%d\n",hoursToWakeUp,minutesToWakeUp);
    
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
