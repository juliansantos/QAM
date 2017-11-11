/*******************************************************************************
* File Name: signY.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_signY_H) /* Pins signY_H */
#define CY_PINS_signY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "signY_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 signY__PORT == 15 && ((signY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    signY_Write(uint8 value);
void    signY_SetDriveMode(uint8 mode);
uint8   signY_ReadDataReg(void);
uint8   signY_Read(void);
void    signY_SetInterruptMode(uint16 position, uint16 mode);
uint8   signY_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the signY_SetDriveMode() function.
     *  @{
     */
        #define signY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define signY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define signY_DM_RES_UP          PIN_DM_RES_UP
        #define signY_DM_RES_DWN         PIN_DM_RES_DWN
        #define signY_DM_OD_LO           PIN_DM_OD_LO
        #define signY_DM_OD_HI           PIN_DM_OD_HI
        #define signY_DM_STRONG          PIN_DM_STRONG
        #define signY_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define signY_MASK               signY__MASK
#define signY_SHIFT              signY__SHIFT
#define signY_WIDTH              1u

/* Interrupt constants */
#if defined(signY__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in signY_SetInterruptMode() function.
     *  @{
     */
        #define signY_INTR_NONE      (uint16)(0x0000u)
        #define signY_INTR_RISING    (uint16)(0x0001u)
        #define signY_INTR_FALLING   (uint16)(0x0002u)
        #define signY_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define signY_INTR_MASK      (0x01u) 
#endif /* (signY__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define signY_PS                     (* (reg8 *) signY__PS)
/* Data Register */
#define signY_DR                     (* (reg8 *) signY__DR)
/* Port Number */
#define signY_PRT_NUM                (* (reg8 *) signY__PRT) 
/* Connect to Analog Globals */                                                  
#define signY_AG                     (* (reg8 *) signY__AG)                       
/* Analog MUX bux enable */
#define signY_AMUX                   (* (reg8 *) signY__AMUX) 
/* Bidirectional Enable */                                                        
#define signY_BIE                    (* (reg8 *) signY__BIE)
/* Bit-mask for Aliased Register Access */
#define signY_BIT_MASK               (* (reg8 *) signY__BIT_MASK)
/* Bypass Enable */
#define signY_BYP                    (* (reg8 *) signY__BYP)
/* Port wide control signals */                                                   
#define signY_CTL                    (* (reg8 *) signY__CTL)
/* Drive Modes */
#define signY_DM0                    (* (reg8 *) signY__DM0) 
#define signY_DM1                    (* (reg8 *) signY__DM1)
#define signY_DM2                    (* (reg8 *) signY__DM2) 
/* Input Buffer Disable Override */
#define signY_INP_DIS                (* (reg8 *) signY__INP_DIS)
/* LCD Common or Segment Drive */
#define signY_LCD_COM_SEG            (* (reg8 *) signY__LCD_COM_SEG)
/* Enable Segment LCD */
#define signY_LCD_EN                 (* (reg8 *) signY__LCD_EN)
/* Slew Rate Control */
#define signY_SLW                    (* (reg8 *) signY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define signY_PRTDSI__CAPS_SEL       (* (reg8 *) signY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define signY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) signY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define signY_PRTDSI__OE_SEL0        (* (reg8 *) signY__PRTDSI__OE_SEL0) 
#define signY_PRTDSI__OE_SEL1        (* (reg8 *) signY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define signY_PRTDSI__OUT_SEL0       (* (reg8 *) signY__PRTDSI__OUT_SEL0) 
#define signY_PRTDSI__OUT_SEL1       (* (reg8 *) signY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define signY_PRTDSI__SYNC_OUT       (* (reg8 *) signY__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(signY__SIO_CFG)
    #define signY_SIO_HYST_EN        (* (reg8 *) signY__SIO_HYST_EN)
    #define signY_SIO_REG_HIFREQ     (* (reg8 *) signY__SIO_REG_HIFREQ)
    #define signY_SIO_CFG            (* (reg8 *) signY__SIO_CFG)
    #define signY_SIO_DIFF           (* (reg8 *) signY__SIO_DIFF)
#endif /* (signY__SIO_CFG) */

/* Interrupt Registers */
#if defined(signY__INTSTAT)
    #define signY_INTSTAT            (* (reg8 *) signY__INTSTAT)
    #define signY_SNAP               (* (reg8 *) signY__SNAP)
    
	#define signY_0_INTTYPE_REG 		(* (reg8 *) signY__0__INTTYPE)
#endif /* (signY__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_signY_H */


/* [] END OF FILE */
