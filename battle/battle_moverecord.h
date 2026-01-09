#ifndef __BATTLE_MOVERECORD_H
#define __BATTLE_MOVERECORD_H

#include "swantypes.h"

STRUCT_DECLARE(m_record)
STRUCT_DECLARE(MoveRecord)

C_DECL_BEGIN

void MoveRecord_Clear(MoveRecord *a1);
void MoveRecord_Init(MoveRecord *a1);
void MoveRecord_Add(MoveRecord *a1, __int16 MoveID, unsigned int TurnCount, char PokeID);
void MoveRecord_SetEffectiveLast(MoveRecord *a1);
int MoveRecord_IsUsedMove(MoveRecord *a1, int a2, int a3);
int MoveRecord_GetUsedMoveCount(MoveRecord *a1, int a2, int a3);
int MoveRecord_GetPrevEffectiveMove(MoveRecord *a1, int a2);

C_DECL_END

struct m_record
{
  u32 Turn;
  u16 MoveID;
  u8 PokeID;
  u8 fEffective;
};

struct MoveRecord
{
  u32 ptr;
  m_record record[120];
};

#endif
