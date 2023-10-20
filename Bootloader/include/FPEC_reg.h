/*********************************************************/
/***********		Author: TaqiEldeen	 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: FPEC  		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 11 OCT 2023	 	**************/
/*********************************************************/

#ifndef FPEC_REG_H
#define FPEC_REG_H

#define FPEC_BASE_ADDRESS 0x40022000

typedef struct {
    volatile u32 ACR;
    volatile u32 KEYR;
    volatile u32 OPTKEYR;
    volatile u32 SR;
    volatile u32 CR;
    volatile u32 AR;
    volatile u32 RESERVED;
    volatile u32 OBR;
    volatile u32 WRPR;
}FPEC_t;

#define FPEC ((volatile FPEC_t *) FPEC_BASE_ADDRESS)

/*****  FPEC_CR bits  ******/

#define PG      0       /* Programming                       */
#define PER     1       /* Page erase                        */
#define MER     2       /* Mass erase                        */
#define OPTPG   4       /* Option byte programming           */
#define OPTER   5       /* Option byte erase                 */
#define STRT    6       /* Start                             */
#define LOCK    7       /* Lock                              */
#define OPTWRE  9       /* Option bytes write enable         */
#define ERRIE   10      /* Error interrupt enable            */
#define EOPIE   12      /* End of operation interrupt enable */


/*****  FPEC_SR bits  ******/

#define BSY         0   /* Busy                   */
#define PGERR       2   /* Programming error      */
#define WPRTERR    4   /* Write protection error */
#define EOP         5   /* End of operation       */

#endif // FPEC_REG_H
