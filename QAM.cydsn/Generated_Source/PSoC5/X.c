/*******************************************************************************
* File Name: X.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "X.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 X_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 X_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static X_backupStruct X_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: X_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void X_Init(void) 
{
    X_CR0 = (X_MODE_V );

    /* Set default data source */
    #if(X_DEFAULT_DATA_SRC != 0 )
        X_CR1 = (X_DEFAULT_CNTL | X_DACBUS_ENABLE) ;
    #else
        X_CR1 = (X_DEFAULT_CNTL | X_DACBUS_DISABLE) ;
    #endif /* (X_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(X_DEFAULT_STRB != 0)
        X_Strobe |= X_STRB_EN ;
    #endif/* (X_DEFAULT_STRB != 0) */

    /* Set default range */
    X_SetRange(X_DEFAULT_RANGE); 

    /* Set default speed */
    X_SetSpeed(X_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: X_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void X_Enable(void) 
{
    X_PWRMGR |= X_ACT_PWR_EN;
    X_STBY_PWRMGR |= X_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(X_restoreVal == 1u) 
        {
             X_CR0 = X_backup.data_value;
             X_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: X_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  X_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void X_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(X_initVar == 0u)
    { 
        X_Init();
        X_initVar = 1u;
    }

    /* Enable power to DAC */
    X_Enable();

    /* Set default value */
    X_SetValue(X_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: X_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void X_Stop(void) 
{
    /* Disble power to DAC */
    X_PWRMGR &= (uint8)(~X_ACT_PWR_EN);
    X_STBY_PWRMGR &= (uint8)(~X_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        X_backup.data_value = X_CR0;
        X_CR0 = X_CUR_MODE_OUT_OFF;
        X_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: X_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void X_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    X_CR0 &= (uint8)(~X_HS_MASK);
    X_CR0 |=  (speed & X_HS_MASK);
}


/*******************************************************************************
* Function Name: X_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void X_SetRange(uint8 range) 
{
    X_CR0 &= (uint8)(~X_RANGE_MASK);      /* Clear existing mode */
    X_CR0 |= (range & X_RANGE_MASK);      /*  Set Range  */
    X_DacTrim();
}


/*******************************************************************************
* Function Name: X_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void X_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 X_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    X_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        X_Data = value;
        CyExitCriticalSection(X_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: X_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void X_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((X_CR0 & X_RANGE_MASK) >> 2) + X_TRIM_M7_1V_RNG_OFFSET;
    X_TR = CY_GET_XTND_REG8((uint8 *)(X_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
