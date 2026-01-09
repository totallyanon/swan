#ifndef __BATTLE_FIELD_H
#define __BATTLE_FIELD_H

#include "swantypes.h"

STRUCT_DECLARE(BattleField)

ENUM_DECLARE(BattleFieldEffect)

#include "gfl/core/gfl_heap.h"
#include "battle/battle_event.h"
#include "battle/battle_conditiondata.h"
#include "battle/battle_mainmodule.h"
#include "battle/battle_mon.h"
#include "battle/battle_serverflow.h"

C_DECL_BEGIN

void BattleField_ClearEventItems(BattleField *a1, int a2);
void BattleField_Clear(int a1);
int BattleField_GetWeather();
int BattleField_GetWeatherTurns();
void BattleField_SetWeather(int a1, int a2);
int BattleField_TurnCheckWeather();
int BattleField_AddEffect(int a1, int a2, int a3, int a4);
int BattleField_RemoveEffect(int a1);
int BattleField_AddAffectedMon(int a1, int a2);
void BattleField_RemoveAffectedMon(int a1);
int BattleField_CheckImprison(PokeCon *a1, BattleMon *a2, int a3);
void BattleField_TurnCheck(int (*a1)(unsigned int, int), ServerFlow *a2);
u32 BattleField_CheckEffect(BattleFieldEffect a1);
BattleField *BattleField_Init(HeapID a1);
void BattleField_Free(void *heap);

void BattleField_InitCore(BattleField *a1, int a2);
int BattleField_GetWeatherCore(BattleField *a1);
int BattleField_GetWeatherTurnsCore(BattleField *a1);
void BattleField_SetWeatherCore(BattleField *result, int a2, int a3);
void BattleField_EndWeather(BattleField *a1);
int BattleField_TurnCheckWeatherCore(BattleField *a1);
int BattleField_AddEffectCore(BattleField *a1, int a2, int a3, int a4);
int BattleField_RemoveEffectCore(BattleField *a1, int a2);
int BattleField_AddAffectedMonCore(BattleField *a1, int a2, int a3);
void BattleField_RemoveAffectedMonCore(BattleField *a1, int a2);
int BattleField_CheckImprisonCore(BattleField *a1, PokeCon *a2, BattleMon *a3, int a4);
void BattleField_TurnCheckCore(BattleField *a1, int (*a2)(unsigned int, int), ServerFlow *a3);
u32 BattleField_CheckEffectCore(BattleField *a1, BattleFieldEffect a2);

C_DECL_END

enum BattleFieldEffect
#ifdef __cplusplus
: u32
#endif
{
  EFFECT_WEATHER = 0x0,
  EFFECT_TRICK_ROOM = 0x1,
  EFFECT_GRAVITY = 0x2,
  EFFECT_IMPRISON = 0x3,
  EFFECT_WATER_SPORT = 0x4,
  EFFECT_MUD_SPORT = 0x5,
  EFFECT_WONDER_ROOM = 0x6,
  EFFECT_MAGIC_ROOM = 0x7,
};

struct BattleField
{
  int weather;
  int weatherTurns;
  BattleEventItem *battleEventItems[8];
  ConditionData conditionData[8];
  u32 turnCount[8];
  u32 affectedMonIDs[8][6];
  u32 affectedMonCount[8];
  u32 effectEnableFlags[8];
};

#endif
