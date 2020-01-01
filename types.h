#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdint.h>

//definicje nowych typow danych
typedef uint32_t            DataType;
typedef uint32_t            CodeType;
typedef uint16_t            AddressType;
typedef int32_t             OffsetType;
typedef int32_t             SignedType; //do przemyślenia

//najwieksze wartosci 
#define MAX_ADDRESS         0xFFFF
#define MAX_DATA_VAL        0xFFFF

//Numer ostatniego rejestru
#define MAX_REGISTER        31

#define MAX_MEMD            2000

//Znaczenie flag
#define FLAG_C              0x01

#endif //__TYPES_H__
