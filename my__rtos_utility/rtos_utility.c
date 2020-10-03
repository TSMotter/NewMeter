/***************************************************************************************************
* @file   rtos_utility.c
* @brief  Common infrastructure to access RTOS resources
* @author Giuliano Motter
* @date   09/2020
***************************************************************************************************/

/***************************************************************************************************
* Includes
***************************************************************************************************/
#include "rtos_utility.h"

/***************************************************************************************************
* Private Functions Prototypes
***************************************************************************************************/

/***************************************************************************************************
* Externals
***************************************************************************************************/

/***************************************************************************************************
* Vars
***************************************************************************************************/
static QueueHandle_t QueueHandleVECTOR[QueueIDX_NUMBER_OF_QUEUES];

/***************************************************************************************************
* @brief 
***************************************************************************************************/
QueueHandle_t *RTOS_Get_Queue_Idx (RTOS_QueueIdx_en QueueIDX)
{
	return &QueueHandleVECTOR[QueueIDX];
}

/***************************************************************************************************
* @brief 
***************************************************************************************************/
bool RTOS_Send_Data_To_Specific_Queue(xQueueHandle* posQueHandle, GenericQueueData_st* pstEvt, portTickType xTicksToWait)
{
  if (xQueueSendToBack(*posQueHandle, (void*)pstEvt, xTicksToWait) == pdPASS )
  {
    return true;
  }
  else
  {
    return false;
  }
}

/***************************************************************************************************
* @brief 
***************************************************************************************************/
bool RTOS_Send_Data_To_Energy_Queue(xQueueHandle* posQueHandle, EnergyQueueData_st* pstEvt, portTickType xTicksToWait)
{
  if ( xQueueSendToBack(*posQueHandle, (void*)pstEvt, xTicksToWait) == pdPASS )
  {
    return true;
  }
  else
  {
    return false;
  }
}
