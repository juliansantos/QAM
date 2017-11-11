/*******************************************************************************
* File Name: CLOCK.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "CLOCK.h"

/* Error message for removed <resource> through optimization */
#ifdef CLOCK_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* CLOCK_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 CLOCK_initVar = 0u;


/*******************************************************************************
* Function Name: CLOCK_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  CLOCK_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void CLOCK_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(CLOCK_initVar == 0u)
    {
        CLOCK_Init();
        CLOCK_initVar = 1u;
    }
    CLOCK_Enable();

}


/*******************************************************************************
* Function Name: CLOCK_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  CLOCK_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CLOCK_Init(void) 
{
    #if (CLOCK_UsingFixedFunction || CLOCK_UseControl)
        uint8 ctrl;
    #endif /* (CLOCK_UsingFixedFunction || CLOCK_UseControl) */

    #if(!CLOCK_UsingFixedFunction)
        #if(CLOCK_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 CLOCK_interruptState;
        #endif /* (CLOCK_UseStatus) */
    #endif /* (!CLOCK_UsingFixedFunction) */

    #if (CLOCK_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        CLOCK_CONTROL |= CLOCK_CFG0_MODE;
        #if (CLOCK_DeadBand2_4)
            CLOCK_CONTROL |= CLOCK_CFG0_DB;
        #endif /* (CLOCK_DeadBand2_4) */

        ctrl = CLOCK_CONTROL3 & ((uint8 )(~CLOCK_CTRL_CMPMODE1_MASK));
        CLOCK_CONTROL3 = ctrl | CLOCK_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        CLOCK_RT1 &= ((uint8)(~CLOCK_RT1_MASK));
        CLOCK_RT1 |= CLOCK_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        CLOCK_RT1 &= ((uint8)(~CLOCK_SYNCDSI_MASK));
        CLOCK_RT1 |= CLOCK_SYNCDSI_EN;

    #elif (CLOCK_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = CLOCK_CONTROL & ((uint8)(~CLOCK_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~CLOCK_CTRL_CMPMODE1_MASK));
        CLOCK_CONTROL = ctrl | CLOCK_DEFAULT_COMPARE2_MODE |
                                   CLOCK_DEFAULT_COMPARE1_MODE;
    #endif /* (CLOCK_UsingFixedFunction) */

    #if (!CLOCK_UsingFixedFunction)
        #if (CLOCK_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            CLOCK_AUX_CONTROLDP0 |= (CLOCK_AUX_CTRL_FIFO0_CLR);
        #else /* (CLOCK_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            CLOCK_AUX_CONTROLDP0 |= (CLOCK_AUX_CTRL_FIFO0_CLR);
            CLOCK_AUX_CONTROLDP1 |= (CLOCK_AUX_CTRL_FIFO0_CLR);
        #endif /* (CLOCK_Resolution == 8) */

        CLOCK_WriteCounter(CLOCK_INIT_PERIOD_VALUE);
    #endif /* (!CLOCK_UsingFixedFunction) */

    CLOCK_WritePeriod(CLOCK_INIT_PERIOD_VALUE);

        #if (CLOCK_UseOneCompareMode)
            CLOCK_WriteCompare(CLOCK_INIT_COMPARE_VALUE1);
        #else
            CLOCK_WriteCompare1(CLOCK_INIT_COMPARE_VALUE1);
            CLOCK_WriteCompare2(CLOCK_INIT_COMPARE_VALUE2);
        #endif /* (CLOCK_UseOneCompareMode) */

        #if (CLOCK_KillModeMinTime)
            CLOCK_WriteKillTime(CLOCK_MinimumKillTime);
        #endif /* (CLOCK_KillModeMinTime) */

        #if (CLOCK_DeadBandUsed)
            CLOCK_WriteDeadTime(CLOCK_INIT_DEAD_TIME);
        #endif /* (CLOCK_DeadBandUsed) */

    #if (CLOCK_UseStatus || CLOCK_UsingFixedFunction)
        CLOCK_SetInterruptMode(CLOCK_INIT_INTERRUPTS_MODE);
    #endif /* (CLOCK_UseStatus || CLOCK_UsingFixedFunction) */

    #if (CLOCK_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        CLOCK_GLOBAL_ENABLE |= CLOCK_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        CLOCK_CONTROL2 |= CLOCK_CTRL2_IRQ_SEL;
    #else
        #if(CLOCK_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            CLOCK_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            CLOCK_STATUS_AUX_CTRL |= CLOCK_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(CLOCK_interruptState);

            /* Clear the FIFO to enable the CLOCK_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            CLOCK_ClearFIFO();
        #endif /* (CLOCK_UseStatus) */
    #endif /* (CLOCK_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CLOCK_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void CLOCK_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (CLOCK_UsingFixedFunction)
        CLOCK_GLOBAL_ENABLE |= CLOCK_BLOCK_EN_MASK;
        CLOCK_GLOBAL_STBY_ENABLE |= CLOCK_BLOCK_STBY_EN_MASK;
    #endif /* (CLOCK_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (CLOCK_UseControl || CLOCK_UsingFixedFunction)
        CLOCK_CONTROL |= CLOCK_CTRL_ENABLE;
    #endif /* (CLOCK_UseControl || CLOCK_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CLOCK_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void CLOCK_Stop(void) 
{
    #if (CLOCK_UseControl || CLOCK_UsingFixedFunction)
        CLOCK_CONTROL &= ((uint8)(~CLOCK_CTRL_ENABLE));
    #endif /* (CLOCK_UseControl || CLOCK_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (CLOCK_UsingFixedFunction)
        CLOCK_GLOBAL_ENABLE &= ((uint8)(~CLOCK_BLOCK_EN_MASK));
        CLOCK_GLOBAL_STBY_ENABLE &= ((uint8)(~CLOCK_BLOCK_STBY_EN_MASK));
    #endif /* (CLOCK_UsingFixedFunction) */
}

#if (CLOCK_UseOneCompareMode)
    #if (CLOCK_CompareMode1SW)


        /*******************************************************************************
        * Function Name: CLOCK_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void CLOCK_SetCompareMode(uint8 comparemode) 
        {
            #if(CLOCK_UsingFixedFunction)

                #if(0 != CLOCK_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << CLOCK_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != CLOCK_CTRL_CMPMODE1_SHIFT) */

                CLOCK_CONTROL3 &= ((uint8)(~CLOCK_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                CLOCK_CONTROL3 |= comparemodemasked;

            #elif (CLOCK_UseControl)

                #if(0 != CLOCK_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << CLOCK_CTRL_CMPMODE1_SHIFT)) &
                                                CLOCK_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & CLOCK_CTRL_CMPMODE1_MASK;
                #endif /* (0 != CLOCK_CTRL_CMPMODE1_SHIFT) */

                #if(0 != CLOCK_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << CLOCK_CTRL_CMPMODE2_SHIFT)) &
                                               CLOCK_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & CLOCK_CTRL_CMPMODE2_MASK;
                #endif /* (0 != CLOCK_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                CLOCK_CONTROL &= ((uint8)(~(CLOCK_CTRL_CMPMODE1_MASK |
                                            CLOCK_CTRL_CMPMODE2_MASK)));
                CLOCK_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (CLOCK_UsingFixedFunction) */
        }
    #endif /* CLOCK_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (CLOCK_CompareMode1SW)


        /*******************************************************************************
        * Function Name: CLOCK_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void CLOCK_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != CLOCK_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << CLOCK_CTRL_CMPMODE1_SHIFT)) &
                                           CLOCK_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & CLOCK_CTRL_CMPMODE1_MASK;
            #endif /* (0 != CLOCK_CTRL_CMPMODE1_SHIFT) */

            #if (CLOCK_UseControl)
                CLOCK_CONTROL &= ((uint8)(~CLOCK_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                CLOCK_CONTROL |= comparemodemasked;
            #endif /* (CLOCK_UseControl) */
        }
    #endif /* CLOCK_CompareMode1SW */

#if (CLOCK_CompareMode2SW)


    /*******************************************************************************
    * Function Name: CLOCK_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void CLOCK_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != CLOCK_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << CLOCK_CTRL_CMPMODE2_SHIFT)) &
                                                 CLOCK_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & CLOCK_CTRL_CMPMODE2_MASK;
        #endif /* (0 != CLOCK_CTRL_CMPMODE2_SHIFT) */

        #if (CLOCK_UseControl)
            CLOCK_CONTROL &= ((uint8)(~CLOCK_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            CLOCK_CONTROL |= comparemodemasked;
        #endif /* (CLOCK_UseControl) */
    }
    #endif /*CLOCK_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!CLOCK_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: CLOCK_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void CLOCK_WriteCounter(uint8 counter) \
                                       
    {
        CY_SET_REG8(CLOCK_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: CLOCK_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint8 CLOCK_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(CLOCK_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG8(CLOCK_CAPTURE_LSB_PTR));
    }

    #if (CLOCK_UseStatus)


        /*******************************************************************************
        * Function Name: CLOCK_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void CLOCK_ClearFIFO(void) 
        {
            while(0u != (CLOCK_ReadStatusRegister() & CLOCK_STATUS_FIFONEMPTY))
            {
                (void)CLOCK_ReadCapture();
            }
        }

    #endif /* CLOCK_UseStatus */

#endif /* !CLOCK_UsingFixedFunction */


/*******************************************************************************
* Function Name: CLOCK_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void CLOCK_WritePeriod(uint8 period) 
{
    #if(CLOCK_UsingFixedFunction)
        CY_SET_REG16(CLOCK_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG8(CLOCK_PERIOD_LSB_PTR, period);
    #endif /* (CLOCK_UsingFixedFunction) */
}

#if (CLOCK_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: CLOCK_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void CLOCK_WriteCompare(uint8 compare) \
                                       
    {
        #if(CLOCK_UsingFixedFunction)
            CY_SET_REG16(CLOCK_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG8(CLOCK_COMPARE1_LSB_PTR, compare);
        #endif /* (CLOCK_UsingFixedFunction) */

        #if (CLOCK_PWMMode == CLOCK__B_PWM__DITHER)
            #if(CLOCK_UsingFixedFunction)
                CY_SET_REG16(CLOCK_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG8(CLOCK_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (CLOCK_UsingFixedFunction) */
        #endif /* (CLOCK_PWMMode == CLOCK__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: CLOCK_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void CLOCK_WriteCompare1(uint8 compare) \
                                        
    {
        #if(CLOCK_UsingFixedFunction)
            CY_SET_REG16(CLOCK_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG8(CLOCK_COMPARE1_LSB_PTR, compare);
        #endif /* (CLOCK_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: CLOCK_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void CLOCK_WriteCompare2(uint8 compare) \
                                        
    {
        #if(CLOCK_UsingFixedFunction)
            CY_SET_REG16(CLOCK_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG8(CLOCK_COMPARE2_LSB_PTR, compare);
        #endif /* (CLOCK_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (CLOCK_DeadBandUsed)


    /*******************************************************************************
    * Function Name: CLOCK_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void CLOCK_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!CLOCK_DeadBand2_4)
            CY_SET_REG8(CLOCK_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            CLOCK_DEADBAND_COUNT &= ((uint8)(~CLOCK_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(CLOCK_DEADBAND_COUNT_SHIFT)
                CLOCK_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << CLOCK_DEADBAND_COUNT_SHIFT)) &
                                                    CLOCK_DEADBAND_COUNT_MASK;
            #else
                CLOCK_DEADBAND_COUNT |= deadtime & CLOCK_DEADBAND_COUNT_MASK;
            #endif /* (CLOCK_DEADBAND_COUNT_SHIFT) */

        #endif /* (!CLOCK_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: CLOCK_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 CLOCK_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!CLOCK_DeadBand2_4)
            return (CY_GET_REG8(CLOCK_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(CLOCK_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(CLOCK_DEADBAND_COUNT & CLOCK_DEADBAND_COUNT_MASK)) >>
                                                                           CLOCK_DEADBAND_COUNT_SHIFT));
            #else
                return (CLOCK_DEADBAND_COUNT & CLOCK_DEADBAND_COUNT_MASK);
            #endif /* (CLOCK_DEADBAND_COUNT_SHIFT) */
        #endif /* (!CLOCK_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (CLOCK_UseStatus || CLOCK_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: CLOCK_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void CLOCK_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(CLOCK_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: CLOCK_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 CLOCK_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(CLOCK_STATUS_PTR));
    }

#endif /* (CLOCK_UseStatus || CLOCK_UsingFixedFunction) */


#if (CLOCK_UseControl)


    /*******************************************************************************
    * Function Name: CLOCK_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 CLOCK_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(CLOCK_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: CLOCK_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void CLOCK_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(CLOCK_CONTROL_PTR, control);
    }

#endif /* (CLOCK_UseControl) */


#if (!CLOCK_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: CLOCK_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint8 CLOCK_ReadCapture(void) 
    {
        return (CY_GET_REG8(CLOCK_CAPTURE_LSB_PTR));
    }

#endif /* (!CLOCK_UsingFixedFunction) */


#if (CLOCK_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: CLOCK_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint8 CLOCK_ReadCompare(void) 
    {
        #if(CLOCK_UsingFixedFunction)
            return ((uint8)CY_GET_REG16(CLOCK_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG8(CLOCK_COMPARE1_LSB_PTR));
        #endif /* (CLOCK_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: CLOCK_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint8 CLOCK_ReadCompare1(void) 
    {
        return (CY_GET_REG8(CLOCK_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: CLOCK_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint8 CLOCK_ReadCompare2(void) 
    {
        return (CY_GET_REG8(CLOCK_COMPARE2_LSB_PTR));
    }

#endif /* (CLOCK_UseOneCompareMode) */


/*******************************************************************************
* Function Name: CLOCK_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint8 CLOCK_ReadPeriod(void) 
{
    #if(CLOCK_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(CLOCK_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(CLOCK_PERIOD_LSB_PTR));
    #endif /* (CLOCK_UsingFixedFunction) */
}

#if ( CLOCK_KillModeMinTime)


    /*******************************************************************************
    * Function Name: CLOCK_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void CLOCK_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(CLOCK_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: CLOCK_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 CLOCK_ReadKillTime(void) 
    {
        return (CY_GET_REG8(CLOCK_KILLMODEMINTIME_PTR));
    }

#endif /* ( CLOCK_KillModeMinTime) */

/* [] END OF FILE */
