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

//Nazwy plików
#define FILE_CODE           "file_code.bin"
#define FILE_DATA_IN        "file_data_in.bin"
#define FILE_REG_IN         "file_reg_in.bin"
#define FILE_DATA_OUT       "file_data_out.bin"
#define FILE_REG_OUT        "file_reg_out.bin"

#endif //__TYPES_H__
