#include "pxt.h"
#include "mbed.h"
#include "SDFileSystem.h"

namespace im01
{
//%
void _mkdir(String s)
{
    SDFileSystem sd(P0_21, P0_22, P0_23, P0_16, "sd");
    mkdir((const char *)s->getUTF8Data(), 0777);
}

//%
void _remove(String s)
{
    SDFileSystem sd(P0_21, P0_22, P0_23, P0_16, "sd");
    remove((const char *)s->getUTF8Data());
}

//%
bool _file(String s, String v, String x)
{
    SDFileSystem sd(P0_21, P0_22, P0_23, P0_16, "sd");
    FILE *fp = fopen((const char *)s->getUTF8Data(), (const char *)x->getUTF8Data());
    if (fp == NULL)
        return false;

    fprintf(fp, (const char *)v->getUTF8Data());
    fclose(fp);
    return true;
}

//%
uint32_t _size(String s)
{
    SDFileSystem sd(P0_21, P0_22, P0_23, P0_16, "sd");
    uint32_t lSize = 0;
    FILE *fp = fopen((const char *)s->getUTF8Data(), "rb");
    fseek(fp, 0, SEEK_END);
    lSize = ftell(fp);
    fclose(fp);
    return lSize;
}

//%
bool _exists(String s)
{
    if (FILE *fp = fopen((const char *)s->getUTF8Data(), "r"))
    {
        fclose(fp);
        return true;
    }
    else
    {
        return false;
    }
}

//%
String _read(String s)
{
    // TO DO
}
} // namespace im01