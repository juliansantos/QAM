/*******************************************************************************
* File Name: CLOCK_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CLOCK.h"

static CLOCK_backupStruct CLOCK_backup;


/*******************************************************************************
* Function Name: CLOCK_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  CLOCK_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void CLOCK_SaveConfig(void) 
{

    #if(!CLOCK_UsingFixedFunction)
        #if(!CLOCK_PWMModeIsCenterAligned)
            CLOCK_backup.PWMPeriod = CLOCK_ReadPeriod();
        #endif /* (!CLOCK_PWMModeIsCenterAligned) */
        CLOCK_backup.PWMUdb = CLOCK_ReadCounter();
        #if (CLOCK_UseStatus)
            CLOCK_backup.InterruptMaskValue = CLOCK_STATUS_MASK;
        #endif /* (CLOCK_UseStatus) */

        #if(CLOCK_DeadBandMode == CLOCK__B_PWM__DBM_256_CLOCKS || \
            CLOCK_DeadBandMode == CLOCK__B_PWM__DBM_2_4_CLOCKS)
            CLOCK_backup.PWMdeadBandValue = CLOCK_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(CLOCK_KillModeMinTime)
             CLOCK_backup.PWMKillCounterPeriod = CLOCK_ReadKillTime();
        #endif /* (CLOCK_KillModeMinTime) */

        #if(CLOCK_UseControl)
            CLOCK_backup.PWMControlRegister = CLOCK_ReadControlRegister();
        #endif /* (CLOCK_UseControl) */
    #endif  /* (!CLOCK_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CLOCK_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  CLOCK_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void CLOCK_RestoreConfig(void) 
{
        #if(!CLOCK_UsingFixedFunction)
            #if(!CLOCK_PWMModeIsCenterAligned)
                CLOCK_WritePeriod(CLOCK_backup.PWMPeriod);
            #endif /* (!CLOCK_PWMModeIsCenterAligned) */

            CLOCK_WriteCounter(CLOCK_backup.PWMUdb);

            #if (CLOCK_UseStatus)
                CLOCK_STATUS_MASK = CLOCK_backup.InterruptMaskValue;
            #endif /* (CLOCK_UseStatus) */

            #if(CLOCK_DeadBandMode == CLOCK__B_PWM__DBM_256_CLOCKS || \
                CLOCK_DeadBandMode == CLOCK__B_PWM__DBM_2_4_CLOCKS)
                CLOCK_WriteDeadTime(CLOCK_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(CLOCK_KillModeMinTime)
                CLOCK_WriteKillTime(CLOCK_backup.PWMKillCounterPeriod);
            #endif /* (CLOCK_KillModeMinTime) */

            #if(CLOCK_UseControl)
                CLOCK_WriteControlRegister(CLOCK_backup.PWMControlRegister);
            #endif /* (CLOCK_UseControl) */
        #endif  /* (!CLOCK_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: CLOCK_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  CLOCK_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void CLOCK_Sleep(void) 
{
    #if(CLOCK_UseControl)
        if(CLOCK_CTRL_ENABLE == (CLOCK_CONTROL & CLOCK_CTRL_ENABLE))
        {
            /*Component is enabled */
            CLOCK_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            CLOCK_backup.PWMEnableState = 0u;
        }
    #endif /* (CLOCK_UseControl) */

    /* Stop component */
    CLOCK_Stop();

    /* Save registers configuration */
    CLOCK_SaveConfig();
}


/*******************************************************************************
* Function Name: CLOCK_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  CLOCK_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void CLOCK_Wakeup(void) 
{
     /* Restore registers values */
    CLOCK_RestoreConfig();

    if(CLOCK_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        CLOCK_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
