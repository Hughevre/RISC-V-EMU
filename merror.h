#ifndef __MERROR_H__
#define __MERROR_H__

void merror(int,int); 

#define OUT_OF_CODE_MEMORY_SPACE_ERROR      0x00000001
#define OUT_OF_DATA_MEMORY_SPACE_ERROR      0x00000002
#define INVALID_REGISTER_GET                0x00000004
#define INVALID_REGISTER_SET                0x00000008
#define INVALID_SET_OF_FLAGS_BIT            0x00000010
#define INVALID_GET_OF_FLAGS_BIT            0x00000020
#define INVALID_RESET_OF_FLAGS_BIT          0x00000040


#endif //__MERROR_H__
