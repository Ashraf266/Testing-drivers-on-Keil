/********************************************************************
 * Module       : nvic                                              *
 * File Name    : nvic_cfg.h                                        *
 * Description  : nvic driver static configurations                 *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef NVIC_CFG_H
#define NVIC_CFG_H

/******************************************************************
[Required] : Choose GROUP & SUB_GROUP Prioriy Bits                *
[Options]  : 1- NVIC_4G0S	4 bits for group (IPR)=> group        *
             2- NVIC_3G1S	3 bits for group & 1 bit  for sub     *
             3- NVIC_1G3S	1 bit  for group & 3 bits for sub     *
             4- NVIC_0G4S	0 bits for group & 4 bits for sub     *
*******************************************************************/
#define PRIORITY_GROUPING_CONFIG	NVIC_4G0S


#endif /* NVIC_CFG_H */
