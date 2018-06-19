/* 
 * File:   onewire.h
 * Author: jimeneztuero
 *
 * Created on May 15, 2018, 3:21 PM
 */

#ifndef ONEWIRE_H
#define	ONEWIRE_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*** extern *******************************************************************/
extern unsigned char SENSOR [9];
/*** prototypes ***************************************************************/
unsigned char ow_master_reset (void);
unsigned char ow_read_bit (void);
unsigned char ow_read_byte (void);
void ow_write_bit (unsigned char val);
void ow_write_byte (unsigned char val);
void ow_skip_rom (void);



#ifdef	__cplusplus
}
#endif

#endif	/* ONEWIRE_H */

