/***************************************************************************************************
* @file   tsk_atm90e36a.c
* @brief  Task that describes and controls the behaviour of the ATM90E36A IC
* @author Giuliano Motter
* @date   09/2020
***************************************************************************************************/

/***************************************************************************************************
* Includes
***************************************************************************************************/
#include "api_atm90e36a.h"
#include "cmsis_os.h"

/***************************************************************************************************
* Private Functions Prototypes
***************************************************************************************************/

/***************************************************************************************************
* Externals
***************************************************************************************************/
extern ATM90_app_st ATM;

/***************************************************************************************************
* Vars
***************************************************************************************************/


/***************************************************************************************************
* @brief 
***************************************************************************************************/
void start_atm90e36a_task(void const * argument)
{

  // Initialize ATM instance
  ATM_api_init();

	// Waits a max of 100ms for SPI to be ready
	if(ATM_wait_SPI_available(100) != ATM_RC_OK)
  {
    while(1);
  }

  // Modes of operation are solely changed through Serial commands
  for(;;)
  {
    ATM_api_periodic_checks();
    
    /***************************************************************************************************
    * Suspended
    ***************************************************************************************************/    
    if(ATM.Mode == SuspendedMode)
    {
      ATM_machine_suspended_mode();
    }

    /***************************************************************************************************
    * Configuration
    ***************************************************************************************************/
    else if (ATM.Mode == ConfigMode)
    {
      ATM_machine_config_mode();
    }

    /***************************************************************************************************
    * Calibration
    ***************************************************************************************************/
    else if (ATM.Mode == CalibMode)
    {
      ATM_machine_calib_mode();
    }

    /***************************************************************************************************
    * Operation
    ***************************************************************************************************/
    else if (ATM.Mode == OperationMode)
    {
      ATM_machine_operation_mode();
    }
  }
}
