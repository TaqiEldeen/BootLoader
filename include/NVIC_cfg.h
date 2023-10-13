/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: NVIC			**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 16 APRIL 2023	 	**************/
/*********************************************************/


#ifndef NVIC_CFG_H_
#define NVIC_CFG_H_

/* 
 * Options: 
 * 1- NVIC_PRIORITY_GROUPING_0      (No Subgrouping)
 * 2- NVIC_PRIORITY_GROUPING_1      (Three bits for group priority and one bit for subpriority)
 * 3- NVIC_PRIORITY_GROUPING_2      (Two bits for group priority and two bits for subpriority)
 * 4- NVIC_PRIORITY_GROUPING_3      (One bit for group priority and three bits for subpriority)
 * 5- NVIC_PRIORITY_GROUPING_4      (Zero bits for group priority and four bits for subpriority)
 */
#define NVIC_PRIORITY_GROUPING  NVIC_PRIORITY_GROUPING_4

#endif  /* NVIC_CFG_H_ */