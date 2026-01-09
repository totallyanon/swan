#ifndef __BATTLE_FAINTRECORD_H
#define __BATTLE_FAINTRECORD_H

#include "swantypes.h"

STRUCT_DECLARE(FaintRecord)

C_DECL_BEGIN

void FaintRecord_Init(FaintRecord *rec);
void FaintRecord_StartTurn(FaintRecord *rec);
void FaintRecord_Add(FaintRecord *rec, u8 mon_id);
int FaintRecord_GetCount(FaintRecord *rec, int turn);
int FaintRecord_GetMonID(FaintRecord *rec, int turn, int mon_id);
int FaintRecord_GetExpCheckedFlag(FaintRecord *rec, int turn, int mon_id);
void FaintRecord_SetExpCheckedFlag(FaintRecord *rec, int turn, int mon_id);
int FaintRecord_GetLastFaintedMonID(FaintRecord *rec);

C_DECL_END

struct FaintRecordUnit
{
  u8 count;
  u8 fExpChecked[24];
  u8 faintedMonIDs[24];
};

struct FaintRecord
{
  FaintRecordUnit turnRecord[4];
};

#endif
