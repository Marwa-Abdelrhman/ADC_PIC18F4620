/* 
 * File:   mcal_internal_interrupt.h
 * Author: Marwa Abdelrahman
 *
 * Created on September 29, 2024, 2:36 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H






/*.....................................Includes.....................................*/
#include "mcal_interrupt_config.h"

/*.....................................Macros Declarations.....................................*/
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
#define ADC_INTERRUPT_ENABLE()             (PIE1bits.ADIE=1)
#define ADC_INTERRUPT_DISABLE()            (PIE1bits.ADIE=0)
#define ADC_INTERRUPT_FLAG_CLEAR()         (PIR1bits.ADIF=0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE  == INTERRUPT_FEATURE_ENABLE
#define ADC_INTERRUPT_HighPrioritySet()    (IPR1bits.ADIP=1)
#define ADC_INTERRUPT_LowPrioritySet()     (IPR1bits.ADIP=0)
#endif
#endif


/*.....................................Macros Functions Declarations.....................................*/



/*.....................................Data Types Declarations.....................................*/
/*.....................................Functions Declarations.....................................*/
#endif	/* MCAL_INTERNAL_INTERRUPT_H */

