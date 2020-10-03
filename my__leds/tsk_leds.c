/***************************************************************************************************
* @file   tsk_leds.c
* @brief  Task designed to take care of the leds blinking patterns
* @author Giuliano Motter
* @date   09/2020
***************************************************************************************************/

/***************************************************************************************************
* Includes
***************************************************************************************************/
#include "cmsis_os.h"
#include "api_leds.h"

/***************************************************************************************************
* Private Functions Prototypes
***************************************************************************************************/

/***************************************************************************************************
* Externals
***************************************************************************************************/
extern osThreadId task_atm90e36aHandle;

/***************************************************************************************************
* Vars
***************************************************************************************************/

/***************************************************************************************************
* @brief 
***************************************************************************************************/
void start_leds_task(void const * argument)
{

  if(!LEDS_api_init())
  {
    while(1);
  }

  xTaskNotify(task_atm90e36aHandle, 0, eIncrement);

  LEDS_blink_pattern1(SLOW_LED);

  for(;;)
  {
    LEDS_check_queue();
  }

}
