/* 
 * File:   onewire.h
 * Author: jimeneztuero
 *
 * Created on May 15, 2018, 3:21 PM
 */

#ifndef ONEWIRE_H
#define	ONEWIRE_H

#include "input.h"

#ifdef	__cplusplus
extern "C" {
#endif

/*** extern *******************************************************************/
extern unsigned char SENSOR [9]; 
//SENSOR ist der array der die empfangenen Daten speichert
/*** prototypes ***************************************************************/
//sendet master reset impuls auf den 1-Wire (OW) bus
unsigned char ow_master_reset (void); 
//liest ein bit vom OW Bus
unsigned char ow_read_bit (void);
//liest ein byte vom OW Bus
unsigned char ow_read_byte (void);
//schreibt ein bit auf den OW bus
void ow_write_bit (unsigned char val);
//schreibt ein byte auf den OW Bus
void ow_write_byte (unsigned char val);
//sendet den "SKIP ROM" befehlt auf den OW Bus
void ow_skip_rom (void);



#ifdef	__cplusplus
}
#endif

#endif	/* ONEWIRE_H */

