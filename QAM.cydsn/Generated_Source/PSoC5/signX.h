/*******************************************************************************
* File Name: signX.h  
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

#if !defined(CY_PINS_signX_H) /* Pins signX_H */
#define CY_PINS_signX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "signX_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 signX__PORT == 15 && ((signX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    signX_Write(uint8 value);
void    signX_SetDriveMode(uint8 mode);
uint8   signX_ReadDataReg(void);
uint8   signX_Read(void);
void    signX_SetInterruptMode(uint16 position, uint16 mode);
uint8   signX_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the signX_SetDriveMode() function.
     *  @{
     */
        #define signX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define signX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define signX_DM_RES_UP          PIN_DM_RES_UP
        #define signX_DM_RES_DWN         PIN_DM_RES_DWN
        #define signX_DM_OD_LO           PIN_DM_OD_LO
        #define signX_DM_OD_HI           PIN_DM_OD_HI
        #define signX_DM_STRONG          PIN_DM_STRONG
        #define signX_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define signX_MASK               signX__MASK
#define signX_SHIFT              signX__SHIFT
#define signX_WIDTH              1u

/* Interrupt constants */
#if defined(signX__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in signX_SetInterruptMode() function.
     *  @{
     */
        #define signX_INTR_NONE      (uint16)(0x0000u)
        #define signX_INTR_RISING    (uint16)(0x0001u)
        #define signX_INTR_FALLING   (uint16)(0x0002u)
        #define signX_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define signX_INTR_MASK      (0x01u) 
#endif /* (signX__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define signX_PS                     (* (reg8 *) signX__PS)
/* Data Register */
#define signX_DR                     (* (reg8 *) signX__DR)
/* Port Number */
#define signX_PRT_NUM                (* (reg8 *) signX__PRT) 
/* Connect to Analog Globals */                                                  
#define signX_AG                     (* (reg8 *) signX__AG)                       
/* Analog MUX bux enable */
#define signX_AMUX                   (* (reg8 *) signX__AMUX) 
/* Bidirectional Enable */                                                        
#define signX_BIE                    (* (reg8 *) signX__BIE)
/* Bit-mask for Aliased Register Access */
#define signX_BIT_MASK               (* (reg8 *) signX__BIT_MASK)
/* Bypass Enable */
#define signX_BYP                    (* (reg8 *) signX__BYP)
/* Port wide control signals */                                                   
#define signX_CTL                    (* (reg8 *) signX__CTL)
/* Drive Modes */
#define signX_DM0                    (* (reg8 *) signX__DM0) 
#define signX_DM1                    (* (reg8 *) signX__DM1)
#define signX_DM2                    (* (reg8 *) signX__DM2) 
/* Input Buffer Disable Override */
#define signX_INP_DIS                (* (reg8 *) signX__INP_DIS)
/* LCD Common or Segment Drive */
#define signX_LCD_COM_SEG            (* (reg8 *) signX__LCD_COM_SEG)
/* Enable Segment LCD */
#define signX_LCD_EN                 (* (reg8 *) signX__LCD_EN)
/* Slew Rate Control */
#define signX_SLW                    (* (reg8 *) signX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define signX_PRTDSI__CAPS_SEL       (* (reg8 *) signX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define signX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) signX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define signX_PRTDSI__OE_SEL0        (* (reg8 *) signX__PRTDSI__OE_SEL0) 
#define signX_PRTDSI__OE_SEL1        (* (reg8 *) signX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define signX_PRTDSI__OUT_SEL0       (* (reg8 *) signX__PRTDSI__OUT_SEL0) 
#define signX_PRTDSI__OUT_SEL1       (* (reg8 *) signX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define signX_PRTDSI__SYNC_OUT       (* (reg8 *) signX__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(signX__SIO_CFG)
    #define signX_SIO_HYST_EN        (* (reg8 *) signX__SIO_HYST_EN)
    #define signX_SIO_REG_HIFREQ     (* (reg8 *) signX__SIO_REG_HIFREQ)
    #define signX_SIO_CFG            (* (reg8 *) signX__SIO_CFG)
    #define signX_SIO_DIFF           (* (reg8 *) signX__SIO_DIFF)
#endif /* (signX__SIO_CFG) */

/* Interrupt Registers */
#if defined(signX__INTSTAT)
    #define signX_INTSTAT            (* (reg8 *) signX__INTSTAT)
    #define signX_SNAP               (* (reg8 *) signX__SNAP)
    
	#define signX_0_INTTYPE_REG 		(* (reg8 *) signX__0__INTTYPE)
#endif /* (signX__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_signX_H */


/* [] END OF FILE */
