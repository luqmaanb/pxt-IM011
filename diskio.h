#ifndef _DISKIO_DEFINED
#define _DISKIO_DEFINED
#ifdef __cplusplus
extern "C"
{
#endif
#define _USE_WRITE 1
#define _USE_IOCTL 1
#include "integer.h"
	typedef BYTE DSTATUS;
	typedef enum
	{
		RES_OK = 0,
		RES_ERROR,
		RES_WRPRT,
		RES_NOTRDY,
		RES_PARERR
	} DRESULT;
	DSTATUS disk_initialize(BYTE pdrv);
	DSTATUS disk_status(BYTE pdrv);
	DRESULT disk_read(BYTE pdrv, BYTE *buff, DWORD sector, UINT count);
	DRESULT disk_write(BYTE pdrv, const BYTE *buff, DWORD sector, UINT count);
	DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff);
#define STA_NOINIT 0x01
#define STA_PROTECT 0x04
#define CTRL_SYNC 0
#define GET_SECTOR_COUNT 1
#define GET_BLOCK_SIZE 3
#ifdef __cplusplus
}
#endif
#endif
