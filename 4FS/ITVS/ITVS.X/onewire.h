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
extern uint8_t ds18x20 [9];
/*** prototypes ***************************************************************/
uint8_t ow_master_reset (void);
uint8_t ow_read_bit (void);
uint8_t ow_read_byte (void);
void ow_write_bit (uint8_t val);
void ow_write_byte (uint8_t val);
void ow_skip_rom (void);



#ifdef	__cplusplus
}
#endif

#endif	/* ONEWIRE_H */

