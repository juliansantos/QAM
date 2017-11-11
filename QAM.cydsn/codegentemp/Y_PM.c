/*******************************************************************************
* File Name: Y_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Y.h"

static Y_backupStruct Y_backup;


/*******************************************************************************
* Function Name: Y_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Y_SaveConfig(void) 
{
    if (!((Y_CR1 & Y_SRC_MASK) == Y_SRC_UDB))
    {
        Y_backup.data_value = Y_Data;
    }
}


/*******************************************************************************
* Function Name: Y_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void Y_RestoreConfig(void) 
{
    if (!((Y_CR1 & Y_SRC_MASK) == Y_SRC_UDB))
    {
        if((Y_Strobe & Y_STRB_MASK) == Y_STRB_EN)
        {
            Y_Strobe &= (uint8)(~Y_STRB_MASK);
            Y_Data = Y_backup.data_value;
            Y_Strobe |= Y_STRB_EN;
        }
        else
        {
            Y_Data = Y_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Y_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  Y_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Y_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Y_ACT_PWR_EN == (Y_PWRMGR & Y_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Y_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Y_backup.enableState = 0u;
    }
    
    Y_Stop();
    Y_SaveConfig();
}


/*******************************************************************************
* Function Name: Y_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Y_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Y_Wakeup(void) 
{
    Y_RestoreConfig();
    
    if(Y_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Y_Enable();

        /* Restore the data register */
        Y_SetValue(Y_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
