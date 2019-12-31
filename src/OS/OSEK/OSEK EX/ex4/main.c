
/*==================[inclusions]=============================================*/
#include "os.h"               /* <= operating system header */
#include "pc.h"               /* <= pc utility header */
#include "stdlib.h"           /* <= srand and rand header */
#include "stdio.h"	      /* <= sprintf and printf header */
#include "rtos_example04.h"   /* <= own header */

/*==================[macros and definitions]=================================*/
#define _CRT_SECURE_NO_WARNINGS

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
int main(void);
static  void  TaskStartDispInit(void);
DeclareTask(InitTask);
DeclareTask(Task1);
DeclareTask(Task2);

/* Declare AlarmActivateTask1Callback - AlarmActivateTask4Callback */
// Add your code here!!!
ALARMCALLBACK(AlarmActivateTask1Callback);
ALARMCALLBACK(AlarmActivateTask4Callback);



// End of your code!!!

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */
int main(void)
{
   /* Starts the operating system in the AppMode1 */
   StartOS(AppMode1);

   /* main shall never returns, but to avoid compiler warnings or errors
    * 0 is returned */
   return 0;
}

/** \brief Error Hook function
 *
 * This fucntion is called from the os if an os interface (API) returns an
 * error. Is for debugging proposes. If called this function triggers a
 * ShutdownOs which ends in a while(1).
 *
 * The values:
 *    OSErrorGetServiceId
 *    OSErrorGetParam1
 *    OSErrorGetParam2
 *    OSErrorGetParam3
 *    OSErrorGetRet
 *
 * will provide you the interface, the input parameters and the returned value.
 * For more details see the OSEK specification:
 * http://portal.osek-vdx.org/files/pdf/specs/os223.pdf
 *
 */
void ErrorHook(void)
{
   ShutdownOS(0);
}

/** \brief Initial task
 *
 * This task is started automatically in the AppMode1.
 *
 */
TASK(InitTask)
{
   /* Storage for AlarmSchedule base */
   AlarmBaseType AlarmInfo;

   /* Initialize the display */
   TaskStartDispInit();
   
   /* Initialize Seed */
   srand(3);

   /* Get the base of one of the AlarmActivateTaskx */
   /* Note that AlarmActivateTask1 - AlarmActivateTask4 have the same base */ 
   GetAlarmBase(AlarmActivateTask1, &AlarmInfo);

    //setting allarm time 
    SetRelAlarm(AlarmActivateTask1,0,500); // set allarm to 5ms
	SetRelAlarm(AlarmActivateTask2,0,1000); // set allarm to 10ms
   
      


   TerminateTask();   
}

/** 
  *
  * Modify Task1 - Task4 to wait for Task1Event - Task4Event 
  * events  
  *
  */

/** \brief Task 1
 *
 * This task get's random coordinates and prints '1' @ these coordinates.
 * Priority is 2.
 *
 */
TASK(Task1)
{

	while(1)
	{
     WaitEvent(Task1Event);  
      
	  // call state machine function 
        ST1();

 
     ClearEvent(Task1Event);
	}


}

/** \brief Task 2
 *
 * This task get's random coordinates and prints '2' @ these coordinates.
 * Priority is 3.
 * 
 */
TASK(Task2)
{
 	while(1)
	{
     WaitEvent(Task2Event);  
      
      // call state machine function 
        ST2();

 
     ClearEvent(Task2Event);
	}
 

}


/* Define  callbacks for AlarmActivateTask1 - AlarmActivateTask4
 * Each callback should send Task1Event - Task4Event correspondingly
 */
// Add your code here!!!
ALARMCALLBACK(AlarmActivateTask1Callback)
{
	SetEvent(Task1,Task1Event);
}

ALARMCALLBACK(AlarmActivateTask2Callback)
{
	SetEvent(Task2,Task2Event);
}



/////////// state machine functions 
void ST1(void)
{
	// Do ST1
}



void ST2(void)
{
	// Do ST1
}
