/* Copyright 2015, Amr Abdelnaby
 * Copyright 2014, Pablo Ridolfi
 * Copyright 2014, Juan Cecconi
 * Copyright 2014, Gustavo Muro
 * Copyright 2015, Amr Abdelnaby
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief rtos example02 source file
 **
 ** This is a mini example of the CIAA Firmware which only uses the rtos.
 ** It demeonstrates the usage of Tasks and Resources APIs
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup RTOS rtos example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * AmAb         Amr Abdelnaby
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20150123 v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "os.h"               /* <= operating system header */
#include "pc.h"               /* <= pc utility header */
#include "stdlib.h"           /* <= srand and rand header */
#include "stdio.h"	      /* <= sprintf and printf header */
#include "rtos_example02.h"   /* <= own header */

/*==================[macros and definitions]=================================*/
#define _CRT_SECURE_NO_WARNINGS

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
int main(void);
static  void  TaskStartDispInit(void);
DeclareTask(InitTask);
DeclareTask(Task1);
DeclareTask(Task2);

/* Declare AlarmSchedule Callback */
// Add your code here!!!
ALARMCALLBACK(AlarmActivateTask2Callback);
ALARMCALLBACK(AlarmActivateTask2Callback);
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
  
   /* Initialize the display */
   TaskStartDispInit();
   
   /* Initialize Seed */
   srand(3);

    //setting allarm time 
    SetRelAlarm(AlarmActivateTask1,0,500); // set allarm to 5ms
	SetRelAlarm(AlarmActivateTask2,0,1000); // set allarm to 10ms
   TerminateTask();   
}

/** \brief Task 1
 *
 * This task get's random coordinates and prints '1' @ these coordinates.
 *
 */
TASK(Task1)
{
   // calling state machine 1
   ST1();
   
   TerminateTask();

}

/** \brief Task 2
 *
 * This task get's random coordinates and prints '2' @ these coordinates.
 *
 */
TASK(Task2)
{
   // calling state machine 1
   ST1();
   TerminateTask();

}


/** \brief AlarmSchedule Callback 
 *
 * Two allarms to make periodicity 
 *   ALARM 1 ( 5 ms ) 
 */
ALARMCALLBACK(AlarmActivateTask1Callback)
{
    // activate TASK 1 
	ActivateTask(Task1);
}

/** \brief AlarmSchedule Callback 
 *
 * Two allarms to make periodicity 
 *   ALARM 2 ( 10 ms ) 
 */
ALARMCALLBACK(AlarmActivateTask2Callback)
{
    // activate TASK 2 
	ActivateTask(Task2);
}
/*  state machine function 
* ST1
  */
void ST1(void)
{
	// Do ST1
}


/*  state machine function 
* ST2
  */
void ST2(void)
{
	// Do ST2
}