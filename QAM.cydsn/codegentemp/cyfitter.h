/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.1 Update 1
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* CLOCK */
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB05_06_CTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB05_06_CTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB05_06_CTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B1_UDB05_06_CTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B1_UDB05_06_MSK
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B1_UDB05_06_MSK
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B1_UDB05_06_MSK
#define CLOCK_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB05_06_MSK
#define CLOCK_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define CLOCK_PWMUDB_genblk1_ctrlreg__7__POS 7
#define CLOCK_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B1_UDB05_CTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B1_UDB05_ST_CTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B1_UDB05_CTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B1_UDB05_ST_CTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define CLOCK_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define CLOCK_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B1_UDB05_MSK
#define CLOCK_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG CYREG_B1_UDB05_06_A0
#define CLOCK_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG CYREG_B1_UDB05_06_A1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG CYREG_B1_UDB05_06_D0
#define CLOCK_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG CYREG_B1_UDB05_06_D1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define CLOCK_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG CYREG_B1_UDB05_06_F0
#define CLOCK_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG CYREG_B1_UDB05_06_F1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__A0_A1_REG CYREG_B1_UDB05_A0_A1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__A0_REG CYREG_B1_UDB05_A0
#define CLOCK_PWMUDB_sP8_pwmdp_u0__A1_REG CYREG_B1_UDB05_A1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__D0_D1_REG CYREG_B1_UDB05_D0_D1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__D0_REG CYREG_B1_UDB05_D0
#define CLOCK_PWMUDB_sP8_pwmdp_u0__D1_REG CYREG_B1_UDB05_D1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define CLOCK_PWMUDB_sP8_pwmdp_u0__F0_F1_REG CYREG_B1_UDB05_F0_F1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__F0_REG CYREG_B1_UDB05_F0
#define CLOCK_PWMUDB_sP8_pwmdp_u0__F1_REG CYREG_B1_UDB05_F1
#define CLOCK_PWMUDB_sP8_pwmdp_u0__MSK_DP_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define CLOCK_PWMUDB_sP8_pwmdp_u0__PER_DP_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x01u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x02u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x02u

/* Pin_in_clk */
#define Pin_in_clk__0__INTTYPE CYREG_PICU3_INTTYPE2
#define Pin_in_clk__0__MASK 0x04u
#define Pin_in_clk__0__PC CYREG_PRT3_PC2
#define Pin_in_clk__0__PORT 3u
#define Pin_in_clk__0__SHIFT 2u
#define Pin_in_clk__AG CYREG_PRT3_AG
#define Pin_in_clk__AMUX CYREG_PRT3_AMUX
#define Pin_in_clk__BIE CYREG_PRT3_BIE
#define Pin_in_clk__BIT_MASK CYREG_PRT3_BIT_MASK
#define Pin_in_clk__BYP CYREG_PRT3_BYP
#define Pin_in_clk__CTL CYREG_PRT3_CTL
#define Pin_in_clk__DM0 CYREG_PRT3_DM0
#define Pin_in_clk__DM1 CYREG_PRT3_DM1
#define Pin_in_clk__DM2 CYREG_PRT3_DM2
#define Pin_in_clk__DR CYREG_PRT3_DR
#define Pin_in_clk__INP_DIS CYREG_PRT3_INP_DIS
#define Pin_in_clk__INTSTAT CYREG_PICU3_INTSTAT
#define Pin_in_clk__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Pin_in_clk__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Pin_in_clk__LCD_EN CYREG_PRT3_LCD_EN
#define Pin_in_clk__MASK 0x04u
#define Pin_in_clk__PORT 3u
#define Pin_in_clk__PRT CYREG_PRT3_PRT
#define Pin_in_clk__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Pin_in_clk__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Pin_in_clk__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Pin_in_clk__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Pin_in_clk__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Pin_in_clk__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Pin_in_clk__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Pin_in_clk__PS CYREG_PRT3_PS
#define Pin_in_clk__SHIFT 2u
#define Pin_in_clk__SLW CYREG_PRT3_SLW
#define Pin_in_clk__SNAP CYREG_PICU3_SNAP

/* Pin_out_clk1 */
#define Pin_out_clk1__0__INTTYPE CYREG_PICU3_INTTYPE0
#define Pin_out_clk1__0__MASK 0x01u
#define Pin_out_clk1__0__PC CYREG_PRT3_PC0
#define Pin_out_clk1__0__PORT 3u
#define Pin_out_clk1__0__SHIFT 0u
#define Pin_out_clk1__AG CYREG_PRT3_AG
#define Pin_out_clk1__AMUX CYREG_PRT3_AMUX
#define Pin_out_clk1__BIE CYREG_PRT3_BIE
#define Pin_out_clk1__BIT_MASK CYREG_PRT3_BIT_MASK
#define Pin_out_clk1__BYP CYREG_PRT3_BYP
#define Pin_out_clk1__CTL CYREG_PRT3_CTL
#define Pin_out_clk1__DM0 CYREG_PRT3_DM0
#define Pin_out_clk1__DM1 CYREG_PRT3_DM1
#define Pin_out_clk1__DM2 CYREG_PRT3_DM2
#define Pin_out_clk1__DR CYREG_PRT3_DR
#define Pin_out_clk1__INP_DIS CYREG_PRT3_INP_DIS
#define Pin_out_clk1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Pin_out_clk1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Pin_out_clk1__LCD_EN CYREG_PRT3_LCD_EN
#define Pin_out_clk1__MASK 0x01u
#define Pin_out_clk1__PORT 3u
#define Pin_out_clk1__PRT CYREG_PRT3_PRT
#define Pin_out_clk1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Pin_out_clk1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Pin_out_clk1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Pin_out_clk1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Pin_out_clk1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Pin_out_clk1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Pin_out_clk1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Pin_out_clk1__PS CYREG_PRT3_PS
#define Pin_out_clk1__SHIFT 0u
#define Pin_out_clk1__SLW CYREG_PRT3_SLW

/* Pin_out_clk2 */
#define Pin_out_clk2__0__INTTYPE CYREG_PICU3_INTTYPE1
#define Pin_out_clk2__0__MASK 0x02u
#define Pin_out_clk2__0__PC CYREG_PRT3_PC1
#define Pin_out_clk2__0__PORT 3u
#define Pin_out_clk2__0__SHIFT 1u
#define Pin_out_clk2__AG CYREG_PRT3_AG
#define Pin_out_clk2__AMUX CYREG_PRT3_AMUX
#define Pin_out_clk2__BIE CYREG_PRT3_BIE
#define Pin_out_clk2__BIT_MASK CYREG_PRT3_BIT_MASK
#define Pin_out_clk2__BYP CYREG_PRT3_BYP
#define Pin_out_clk2__CTL CYREG_PRT3_CTL
#define Pin_out_clk2__DM0 CYREG_PRT3_DM0
#define Pin_out_clk2__DM1 CYREG_PRT3_DM1
#define Pin_out_clk2__DM2 CYREG_PRT3_DM2
#define Pin_out_clk2__DR CYREG_PRT3_DR
#define Pin_out_clk2__INP_DIS CYREG_PRT3_INP_DIS
#define Pin_out_clk2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Pin_out_clk2__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Pin_out_clk2__LCD_EN CYREG_PRT3_LCD_EN
#define Pin_out_clk2__MASK 0x02u
#define Pin_out_clk2__PORT 3u
#define Pin_out_clk2__PRT CYREG_PRT3_PRT
#define Pin_out_clk2__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Pin_out_clk2__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Pin_out_clk2__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Pin_out_clk2__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Pin_out_clk2__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Pin_out_clk2__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Pin_out_clk2__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Pin_out_clk2__PS CYREG_PRT3_PS
#define Pin_out_clk2__SHIFT 1u
#define Pin_out_clk2__SLW CYREG_PRT3_SLW

/* Pin_x */
#define Pin_x__0__INTTYPE CYREG_PICU0_INTTYPE7
#define Pin_x__0__MASK 0x80u
#define Pin_x__0__PC CYREG_PRT0_PC7
#define Pin_x__0__PORT 0u
#define Pin_x__0__SHIFT 7u
#define Pin_x__AG CYREG_PRT0_AG
#define Pin_x__AMUX CYREG_PRT0_AMUX
#define Pin_x__BIE CYREG_PRT0_BIE
#define Pin_x__BIT_MASK CYREG_PRT0_BIT_MASK
#define Pin_x__BYP CYREG_PRT0_BYP
#define Pin_x__CTL CYREG_PRT0_CTL
#define Pin_x__DM0 CYREG_PRT0_DM0
#define Pin_x__DM1 CYREG_PRT0_DM1
#define Pin_x__DM2 CYREG_PRT0_DM2
#define Pin_x__DR CYREG_PRT0_DR
#define Pin_x__INP_DIS CYREG_PRT0_INP_DIS
#define Pin_x__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Pin_x__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Pin_x__LCD_EN CYREG_PRT0_LCD_EN
#define Pin_x__MASK 0x80u
#define Pin_x__PORT 0u
#define Pin_x__PRT CYREG_PRT0_PRT
#define Pin_x__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Pin_x__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Pin_x__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Pin_x__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Pin_x__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Pin_x__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Pin_x__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Pin_x__PS CYREG_PRT0_PS
#define Pin_x__SHIFT 7u
#define Pin_x__SLW CYREG_PRT0_SLW

/* Pin_y */
#define Pin_y__0__INTTYPE CYREG_PICU2_INTTYPE0
#define Pin_y__0__MASK 0x01u
#define Pin_y__0__PC CYREG_PRT2_PC0
#define Pin_y__0__PORT 2u
#define Pin_y__0__SHIFT 0u
#define Pin_y__AG CYREG_PRT2_AG
#define Pin_y__AMUX CYREG_PRT2_AMUX
#define Pin_y__BIE CYREG_PRT2_BIE
#define Pin_y__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_y__BYP CYREG_PRT2_BYP
#define Pin_y__CTL CYREG_PRT2_CTL
#define Pin_y__DM0 CYREG_PRT2_DM0
#define Pin_y__DM1 CYREG_PRT2_DM1
#define Pin_y__DM2 CYREG_PRT2_DM2
#define Pin_y__DR CYREG_PRT2_DR
#define Pin_y__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_y__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_y__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_y__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_y__MASK 0x01u
#define Pin_y__PORT 2u
#define Pin_y__PRT CYREG_PRT2_PRT
#define Pin_y__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_y__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_y__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_y__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_y__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_y__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_y__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_y__PS CYREG_PRT2_PS
#define Pin_y__SHIFT 0u
#define Pin_y__SLW CYREG_PRT2_SLW

/* Rx_1 */
#define Rx_1__0__INTTYPE CYREG_PICU15_INTTYPE0
#define Rx_1__0__MASK 0x01u
#define Rx_1__0__PC CYREG_IO_PC_PRT15_PC0
#define Rx_1__0__PORT 15u
#define Rx_1__0__SHIFT 0u
#define Rx_1__AG CYREG_PRT15_AG
#define Rx_1__AMUX CYREG_PRT15_AMUX
#define Rx_1__BIE CYREG_PRT15_BIE
#define Rx_1__BIT_MASK CYREG_PRT15_BIT_MASK
#define Rx_1__BYP CYREG_PRT15_BYP
#define Rx_1__CTL CYREG_PRT15_CTL
#define Rx_1__DM0 CYREG_PRT15_DM0
#define Rx_1__DM1 CYREG_PRT15_DM1
#define Rx_1__DM2 CYREG_PRT15_DM2
#define Rx_1__DR CYREG_PRT15_DR
#define Rx_1__INP_DIS CYREG_PRT15_INP_DIS
#define Rx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define Rx_1__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define Rx_1__LCD_EN CYREG_PRT15_LCD_EN
#define Rx_1__MASK 0x01u
#define Rx_1__PORT 15u
#define Rx_1__PRT CYREG_PRT15_PRT
#define Rx_1__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define Rx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define Rx_1__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define Rx_1__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define Rx_1__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define Rx_1__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define Rx_1__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define Rx_1__PS CYREG_PRT15_PS
#define Rx_1__SHIFT 0u
#define Rx_1__SLW CYREG_PRT15_SLW

/* Tx_1 */
#define Tx_1__0__INTTYPE CYREG_PICU12_INTTYPE2
#define Tx_1__0__MASK 0x04u
#define Tx_1__0__PC CYREG_PRT12_PC2
#define Tx_1__0__PORT 12u
#define Tx_1__0__SHIFT 2u
#define Tx_1__AG CYREG_PRT12_AG
#define Tx_1__BIE CYREG_PRT12_BIE
#define Tx_1__BIT_MASK CYREG_PRT12_BIT_MASK
#define Tx_1__BYP CYREG_PRT12_BYP
#define Tx_1__DM0 CYREG_PRT12_DM0
#define Tx_1__DM1 CYREG_PRT12_DM1
#define Tx_1__DM2 CYREG_PRT12_DM2
#define Tx_1__DR CYREG_PRT12_DR
#define Tx_1__INP_DIS CYREG_PRT12_INP_DIS
#define Tx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define Tx_1__MASK 0x04u
#define Tx_1__PORT 12u
#define Tx_1__PRT CYREG_PRT12_PRT
#define Tx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define Tx_1__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define Tx_1__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define Tx_1__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define Tx_1__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define Tx_1__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define Tx_1__PS CYREG_PRT12_PS
#define Tx_1__SHIFT 2u
#define Tx_1__SIO_CFG CYREG_PRT12_SIO_CFG
#define Tx_1__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define Tx_1__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define Tx_1__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define Tx_1__SLW CYREG_PRT12_SLW

/* UART_BUART */
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB06_07_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB06_07_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB06_07_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB06_07_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB06_07_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB06_07_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB06_07_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB06_07_MSK
#define UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB06_CTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB06_ST_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB06_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB06_ST_CTL
#define UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB06_MSK
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB06_07_ST
#define UART_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB06_MSK
#define UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB06_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB06_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB06_ST
#define UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B0_UDB06_07_A0
#define UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B0_UDB06_07_A1
#define UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B0_UDB06_07_D0
#define UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B0_UDB06_07_D1
#define UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B0_UDB06_07_F0
#define UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B0_UDB06_07_F1
#define UART_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B0_UDB06_A0_A1
#define UART_BUART_sRX_RxShifter_u0__A0_REG CYREG_B0_UDB06_A0
#define UART_BUART_sRX_RxShifter_u0__A1_REG CYREG_B0_UDB06_A1
#define UART_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B0_UDB06_D0_D1
#define UART_BUART_sRX_RxShifter_u0__D0_REG CYREG_B0_UDB06_D0
#define UART_BUART_sRX_RxShifter_u0__D1_REG CYREG_B0_UDB06_D1
#define UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define UART_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B0_UDB06_F0_F1
#define UART_BUART_sRX_RxShifter_u0__F0_REG CYREG_B0_UDB06_F0
#define UART_BUART_sRX_RxShifter_u0__F1_REG CYREG_B0_UDB06_F1
#define UART_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB07_08_ACTL
#define UART_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B1_UDB07_08_ST
#define UART_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_BUART_sRX_RxSts__3__POS 3
#define UART_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_BUART_sRX_RxSts__4__POS 4
#define UART_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_BUART_sRX_RxSts__5__POS 5
#define UART_BUART_sRX_RxSts__MASK 0x38u
#define UART_BUART_sRX_RxSts__MASK_REG CYREG_B1_UDB07_MSK
#define UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B1_UDB07_ACTL
#define UART_BUART_sRX_RxSts__STATUS_REG CYREG_B1_UDB07_ST
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG CYREG_B1_UDB04_05_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG CYREG_B1_UDB04_05_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG CYREG_B1_UDB04_05_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG CYREG_B1_UDB04_05_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG CYREG_B1_UDB04_05_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG CYREG_B1_UDB04_05_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B1_UDB04_A0_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B1_UDB04_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B1_UDB04_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B1_UDB04_D0_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B1_UDB04_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B1_UDB04_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B1_UDB04_F0_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B1_UDB04_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B1_UDB04_F1
#define UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B1_UDB07_08_A0
#define UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B1_UDB07_08_A1
#define UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B1_UDB07_08_D0
#define UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B1_UDB07_08_D1
#define UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB07_08_ACTL
#define UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B1_UDB07_08_F0
#define UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B1_UDB07_08_F1
#define UART_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B1_UDB07_A0_A1
#define UART_BUART_sTX_TxShifter_u0__A0_REG CYREG_B1_UDB07_A0
#define UART_BUART_sTX_TxShifter_u0__A1_REG CYREG_B1_UDB07_A1
#define UART_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B1_UDB07_D0_D1
#define UART_BUART_sTX_TxShifter_u0__D0_REG CYREG_B1_UDB07_D0
#define UART_BUART_sTX_TxShifter_u0__D1_REG CYREG_B1_UDB07_D1
#define UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B1_UDB07_ACTL
#define UART_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B1_UDB07_F0_F1
#define UART_BUART_sTX_TxShifter_u0__F0_REG CYREG_B1_UDB07_F0
#define UART_BUART_sTX_TxShifter_u0__F1_REG CYREG_B1_UDB07_F1
#define UART_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_BUART_sTX_TxSts__0__POS 0
#define UART_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_BUART_sTX_TxSts__1__POS 1
#define UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define UART_BUART_sTX_TxSts__16BIT_STATUS_REG CYREG_B1_UDB04_05_ST
#define UART_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_BUART_sTX_TxSts__2__POS 2
#define UART_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_BUART_sTX_TxSts__3__POS 3
#define UART_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_BUART_sTX_TxSts__MASK_REG CYREG_B1_UDB04_MSK
#define UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define UART_BUART_sTX_TxSts__STATUS_REG CYREG_B1_UDB04_ST

/* UART_IntClock */
#define UART_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define UART_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define UART_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define UART_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_IntClock__INDEX 0x00u
#define UART_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_IntClock__PM_ACT_MSK 0x01u
#define UART_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_IntClock__PM_STBY_MSK 0x01u

/* UART_RXInternalInterrupt */
#define UART_RXInternalInterrupt__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define UART_RXInternalInterrupt__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define UART_RXInternalInterrupt__INTC_MASK 0x01u
#define UART_RXInternalInterrupt__INTC_NUMBER 0u
#define UART_RXInternalInterrupt__INTC_PRIOR_NUM 7u
#define UART_RXInternalInterrupt__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define UART_RXInternalInterrupt__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define UART_RXInternalInterrupt__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* X */
#define X_viDAC8__CR0 CYREG_DAC2_CR0
#define X_viDAC8__CR1 CYREG_DAC2_CR1
#define X_viDAC8__D CYREG_DAC2_D
#define X_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define X_viDAC8__PM_ACT_MSK 0x04u
#define X_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define X_viDAC8__PM_STBY_MSK 0x04u
#define X_viDAC8__STROBE CYREG_DAC2_STROBE
#define X_viDAC8__SW0 CYREG_DAC2_SW0
#define X_viDAC8__SW2 CYREG_DAC2_SW2
#define X_viDAC8__SW3 CYREG_DAC2_SW3
#define X_viDAC8__SW4 CYREG_DAC2_SW4
#define X_viDAC8__TR CYREG_DAC2_TR
#define X_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC2_M1
#define X_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC2_M2
#define X_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC2_M3
#define X_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC2_M4
#define X_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC2_M5
#define X_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC2_M6
#define X_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC2_M7
#define X_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC2_M8
#define X_viDAC8__TST CYREG_DAC2_TST

/* Y */
#define Y_viDAC8__CR0 CYREG_DAC0_CR0
#define Y_viDAC8__CR1 CYREG_DAC0_CR1
#define Y_viDAC8__D CYREG_DAC0_D
#define Y_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define Y_viDAC8__PM_ACT_MSK 0x01u
#define Y_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define Y_viDAC8__PM_STBY_MSK 0x01u
#define Y_viDAC8__STROBE CYREG_DAC0_STROBE
#define Y_viDAC8__SW0 CYREG_DAC0_SW0
#define Y_viDAC8__SW2 CYREG_DAC0_SW2
#define Y_viDAC8__SW3 CYREG_DAC0_SW3
#define Y_viDAC8__SW4 CYREG_DAC0_SW4
#define Y_viDAC8__TR CYREG_DAC0_TR
#define Y_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC0_M1
#define Y_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC0_M2
#define Y_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC0_M3
#define Y_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC0_M4
#define Y_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC0_M5
#define Y_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC0_M6
#define Y_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC0_M7
#define Y_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC0_M8
#define Y_viDAC8__TST CYREG_DAC0_TST

/* data_out */
#define data_out__0__INTTYPE CYREG_PICU3_INTTYPE5
#define data_out__0__MASK 0x20u
#define data_out__0__PC CYREG_PRT3_PC5
#define data_out__0__PORT 3u
#define data_out__0__SHIFT 5u
#define data_out__AG CYREG_PRT3_AG
#define data_out__AMUX CYREG_PRT3_AMUX
#define data_out__BIE CYREG_PRT3_BIE
#define data_out__BIT_MASK CYREG_PRT3_BIT_MASK
#define data_out__BYP CYREG_PRT3_BYP
#define data_out__CTL CYREG_PRT3_CTL
#define data_out__DM0 CYREG_PRT3_DM0
#define data_out__DM1 CYREG_PRT3_DM1
#define data_out__DM2 CYREG_PRT3_DM2
#define data_out__DR CYREG_PRT3_DR
#define data_out__INP_DIS CYREG_PRT3_INP_DIS
#define data_out__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define data_out__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define data_out__LCD_EN CYREG_PRT3_LCD_EN
#define data_out__MASK 0x20u
#define data_out__PORT 3u
#define data_out__PRT CYREG_PRT3_PRT
#define data_out__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define data_out__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define data_out__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define data_out__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define data_out__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define data_out__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define data_out__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define data_out__PS CYREG_PRT3_PS
#define data_out__SHIFT 5u
#define data_out__SLW CYREG_PRT3_SLW

/* isr_bluetooth */
#define isr_bluetooth__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_bluetooth__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_bluetooth__INTC_MASK 0x02u
#define isr_bluetooth__INTC_NUMBER 1u
#define isr_bluetooth__INTC_PRIOR_NUM 7u
#define isr_bluetooth__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define isr_bluetooth__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_bluetooth__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_clk */
#define isr_clk__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_clk__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_clk__INTC_MASK 0x80u
#define isr_clk__INTC_NUMBER 7u
#define isr_clk__INTC_PRIOR_NUM 7u
#define isr_clk__INTC_PRIOR_REG CYREG_NVIC_PRI_7
#define isr_clk__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_clk__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* signX */
#define signX__0__INTTYPE CYREG_PICU0_INTTYPE2
#define signX__0__MASK 0x04u
#define signX__0__PC CYREG_PRT0_PC2
#define signX__0__PORT 0u
#define signX__0__SHIFT 2u
#define signX__AG CYREG_PRT0_AG
#define signX__AMUX CYREG_PRT0_AMUX
#define signX__BIE CYREG_PRT0_BIE
#define signX__BIT_MASK CYREG_PRT0_BIT_MASK
#define signX__BYP CYREG_PRT0_BYP
#define signX__CTL CYREG_PRT0_CTL
#define signX__DM0 CYREG_PRT0_DM0
#define signX__DM1 CYREG_PRT0_DM1
#define signX__DM2 CYREG_PRT0_DM2
#define signX__DR CYREG_PRT0_DR
#define signX__INP_DIS CYREG_PRT0_INP_DIS
#define signX__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define signX__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define signX__LCD_EN CYREG_PRT0_LCD_EN
#define signX__MASK 0x04u
#define signX__PORT 0u
#define signX__PRT CYREG_PRT0_PRT
#define signX__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define signX__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define signX__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define signX__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define signX__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define signX__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define signX__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define signX__PS CYREG_PRT0_PS
#define signX__SHIFT 2u
#define signX__SLW CYREG_PRT0_SLW

/* signY */
#define signY__0__INTTYPE CYREG_PICU0_INTTYPE3
#define signY__0__MASK 0x08u
#define signY__0__PC CYREG_PRT0_PC3
#define signY__0__PORT 0u
#define signY__0__SHIFT 3u
#define signY__AG CYREG_PRT0_AG
#define signY__AMUX CYREG_PRT0_AMUX
#define signY__BIE CYREG_PRT0_BIE
#define signY__BIT_MASK CYREG_PRT0_BIT_MASK
#define signY__BYP CYREG_PRT0_BYP
#define signY__CTL CYREG_PRT0_CTL
#define signY__DM0 CYREG_PRT0_DM0
#define signY__DM1 CYREG_PRT0_DM1
#define signY__DM2 CYREG_PRT0_DM2
#define signY__DR CYREG_PRT0_DR
#define signY__INP_DIS CYREG_PRT0_INP_DIS
#define signY__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define signY__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define signY__LCD_EN CYREG_PRT0_LCD_EN
#define signY__MASK 0x08u
#define signY__PORT 0u
#define signY__PRT CYREG_PRT0_PRT
#define signY__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define signY__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define signY__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define signY__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define signY__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define signY__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define signY__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define signY__PS CYREG_PRT0_PS
#define signY__SHIFT 3u
#define signY__SLW CYREG_PRT0_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "QAM"
#define CY_VERSION "PSoC Creator  4.1 Update 1"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 16u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 16u
#define CYDEV_CHIP_MEMBER_4D 12u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 17u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 15u
#define CYDEV_CHIP_MEMBER_4I 21u
#define CYDEV_CHIP_MEMBER_4J 13u
#define CYDEV_CHIP_MEMBER_4K 14u
#define CYDEV_CHIP_MEMBER_4L 20u
#define CYDEV_CHIP_MEMBER_4M 19u
#define CYDEV_CHIP_MEMBER_4N 9u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 18u
#define CYDEV_CHIP_MEMBER_4Q 11u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 22u
#define CYDEV_CHIP_MEMBER_FM3 26u
#define CYDEV_CHIP_MEMBER_FM4 27u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 23u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 24u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 25u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 0u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000003u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
