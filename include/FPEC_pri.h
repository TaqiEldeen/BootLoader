/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: FPEC  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 11 OCT 2023	 	**************/
/*********************************************************/

#ifndef FPEC_PRI_H
#define FPEC_PRI_H

/**
 * @brief This function checks the last operation to be completed and returns the status
 * 
 * @note It clears the EOP bit after checking
 * 
 * @return FPEC_CheckType   The status of the last operation
 */
static FPEC_CheckType FPEC_eCheckLastOperation(void);

#endif // FPEC_PRI_H
