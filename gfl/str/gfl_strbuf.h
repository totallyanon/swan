#ifndef __GFL_STRBUF_H
#define __GFL_STRBUF_H

#include "swantypes.h"

STRUCT_DECLARE(StrBuf)

struct StrBuf
{
  u16 CharCapacity;
  u16 CharCount;
  u32 Magic;
  __int16 String[];
};

#endif
