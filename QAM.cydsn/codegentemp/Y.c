/*******************************************************************************
* File Name: Y.c  
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
#include "Y.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 Y_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 Y_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static Y_backupStruct Y_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Y_Init
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
void Y_Init(void) 
{
    Y_CR0 = (Y_MODE_V );

    /* Set default data source */
    #if(Y_DEFAULT_DATA_SRC != 0 )
        Y_CR1 = (Y_DEFAULT_CNTL | Y_DACBUS_ENABLE) ;
    #else
        Y_CR1 = (Y_DEFAULT_CNTL | Y_DACBUS_DISABLE) ;
    #endif /* (Y_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(Y_DEFAULT_STRB != 0)
        Y_Strobe |= Y_STRB_EN ;
    #endif/* (Y_DEFAULT_STRB != 0) */

    /* Set default range */
    Y_SetRange(Y_DEFAULT_RANGE); 

    /* Set default speed */
    Y_SetSpeed(Y_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: Y_Enable
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
void Y_Enable(void) 
{
    Y_PWRMGR |= Y_ACT_PWR_EN;
    Y_STBY_PWRMGR |= Y_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(Y_restoreVal == 1u) 
        {
             Y_CR0 = Y_backup.data_value;
             Y_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Y_Start
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
*  Y_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Y_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(Y_initVar == 0u)
    { 
        Y_Init();
        Y_initVar = 1u;
    }

    /* Enable power to DAC */
    Y_Enable();

    /* Set default value */
    Y_SetValue(Y_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: Y_Stop
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
void Y_Stop(void) 
{
    /* Disble power to DAC */
    Y_PWRMGR &= (uint8)(~Y_ACT_PWR_EN);
    Y_STBY_PWRMGR &= (uint8)(~Y_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        Y_backup.data_value = Y_CR0;
        Y_CR0 = Y_CUR_MODE_OUT_OFF;
        Y_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Y_SetSpeed
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
void Y_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    Y_CR0 &= (uint8)(~Y_HS_MASK);
    Y_CR0 |=  (speed & Y_HS_MASK);
}


/*******************************************************************************
* Function Name: Y_SetRange
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
void Y_SetRange(uint8 range) 
{
    Y_CR0 &= (uint8)(~Y_RANGE_MASK);      /* Clear existing mode */
    Y_CR0 |= (range & Y_RANGE_MASK);      /*  Set Range  */
    Y_DacTrim();
}


/*******************************************************************************
* Function Name: Y_SetValue
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
void Y_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 Y_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    Y_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        Y_Data = value;
        CyExitCriticalSection(Y_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Y_DacTrim
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
void Y_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((Y_CR0 & Y_RANGE_MASK) >> 2) + Y_TRIM_M7_1V_RNG_OFFSET;
    Y_TR = CY_GET_XTND_REG8((uint8 *)(Y_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
