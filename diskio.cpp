#include "diskio.h"
#include "FATFileSystem.h"
using namespace mbed;
DSTATUS disk_status(
    BYTE pdrv)
{
    return (DSTATUS)FATFileSystem::_ffs[pdrv]->disk_status();
}
DSTATUS disk_initialize(
    BYTE pdrv)
{
    return (DSTATUS)FATFileSystem::_ffs[pdrv]->disk_initialize();
}
DRESULT disk_read(
    BYTE pdrv,
    BYTE *buff,
    DWORD sector,
    UINT count)
{
    if (FATFileSystem::_ffs[pdrv]->disk_read((uint8_t *)buff, sector, count))
        return RES_PARERR;
    else
        return RES_OK;
}
#if _USE_WRITE
DRESULT disk_write(
    BYTE pdrv,
    const BYTE *buff,
    DWORD sector,
    UINT count)
{
    if (FATFileSystem::_ffs[pdrv]->disk_write((uint8_t *)buff, sector, count))
        return RES_PARERR;
    else
        return RES_OK;
}
#endif
#if _USE_IOCTL
DRESULT disk_ioctl(
    BYTE pdrv,
    BYTE cmd,
    void *buff)
{
    switch (cmd)
    {
    case CTRL_SYNC:
        if (FATFileSystem::_ffs[pdrv] == NULL)
        {
            return RES_NOTRDY;
        }
        else if (FATFileSystem::_ffs[pdrv]->disk_sync())
        {
            return RES_ERROR;
        }
        return RES_OK;
    case GET_SECTOR_COUNT:
        if (FATFileSystem::_ffs[pdrv] == NULL)
        {
            return RES_NOTRDY;
        }
        else
        {
            DWORD res = FATFileSystem::_ffs[pdrv]->disk_sectors();
            if (res > 0)
            {
                *((DWORD *)buff) = res;
                return RES_OK;
            }
            else
            {
                return RES_ERROR;
            }
        }
    case GET_BLOCK_SIZE:
        *((DWORD *)buff) = 1;
        return RES_OK;
    }
    return RES_PARERR;
}
#endif
