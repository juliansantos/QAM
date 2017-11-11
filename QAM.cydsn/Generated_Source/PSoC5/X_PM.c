/*******************************************************************************
* File Name: X_PM.c  
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

#include "X.h"

static X_backupStruct X_backup;


/*******************************************************************************
* Function Name: X_SaveConfig
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
void X_SaveConfig(void) 
{
    if (!((X_CR1 & X_SRC_MASK) == X_SRC_UDB))
    {
        X_backup.data_value = X_Data;
    }
}


/*******************************************************************************
* Function Name: X_RestoreConfig
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
void X_RestoreConfig(void) 
{
    if (!((X_CR1 & X_SRC_MASK) == X_SRC_UDB))
    {
        if((X_Strobe & X_STRB_MASK) == X_STRB_EN)
        {
            X_Strobe &= (uint8)(~X_STRB_MASK);
            X_Data = X_backup.data_value;
            X_Strobe |= X_STRB_EN;
        }
        else
        {
            X_Data = X_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: X_Sleep
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
*  X_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void X_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(X_ACT_PWR_EN == (X_PWRMGR & X_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        X_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        X_backup.enableState = 0u;
    }
    
    X_Stop();
    X_SaveConfig();
}


/*******************************************************************************
* Function Name: X_Wakeup
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
*  X_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void X_Wakeup(void) 
{
    X_RestoreConfig();
    
    if(X_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        X_Enable();

        /* Restore the data register */
        X_SetValue(X_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
