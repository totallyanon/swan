#ifndef __BATTLE_RECORDER_H
#define __BATTLE_RECORDER_H

#include "swantypes.h"

STRUCT_DECLARE(BtlRecWk)
STRUCT_DECLARE(RecPlayerControl)
STRUCT_DECLARE(BattleRecReader)
STRUCT_DECLARE(BtlRecTool)

struct BtlRecWk
{
  u8 TimingCode;
  u8 field_1;
  u8 gap2[3078];
  u32 dwordC08;
};

struct RecPlayerControl
{
  char seq;
  char controlCode;
  char flags;
  char field_3;
  __int16 handlingTimer;
  u16 turnCount;
  u16 nextTurn;
  u16 maxTurnCount;
  u16 skipTurnCount;
};

struct BattleRecReader
{
  u8 *recData;
  u32 dataSize;
  u32 readPtr[4];
  u8 readBuffer[4][64];
};

struct BtlRecTool
{
  u8 writePtr;
  u8 clientBit;
  u8 numClients;
  u8 flags;
  u8 buffer[60];
};

#endif
