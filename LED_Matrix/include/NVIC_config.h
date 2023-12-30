/****************************************/
/* Author	: Ashraf					*/
/* Version	: V01				   		*/
/* Date		: 27/10/2023				*/
/****************************************/

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H



/* GROUP & SUB_GROUP Prioriy options:
		4G0S	4 bits for group (IPR)=> group
		3G1S	3 bits for group & 1 bit  for sub
		2G2S	2 bits for group & 2 bits for sub
		1G3S	1 bit  for group & 3 bits for sub
		0G4S	0 bits for group & 4 bits for sub
*/

#define PRIORITY_GROUPING_CONFIG	NVIC_4G0S





#endif  /* NVIC_CONFIG_H */
