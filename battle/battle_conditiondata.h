#ifndef __BATTLE_CONDITIONDATA_H
#define __BATTLE_CONDITIONDATA_H

#include "swantypes.h"

STRUCT_DECLARE(ConditionData_Permanent)
STRUCT_DECLARE(ConditionData_DependsOnMon)
STRUCT_DECLARE(ConditionData_TurnBased)
STRUCT_DECLARE(ConditionData_DependsOnMonTurnBased)

UNION_DECLARE(ConditionData)

ENUM_DECLARE(ConditionDataType)
ENUM_DECLARE(MoveCondition)

C_DECL_BEGIN

ConditionData ConditionData_SetNull();
bool ConditionData_IsNull(ConditionData *a1);
ConditionData ConditionData_SetTurnBased(int turns);
ConditionData ConditionData_SetTurnBasedData(int turns, int data);
ConditionData ConditionData_SetDependsOnMon(int mon_id);
ConditionData ConditionData_SetPermanent();
ConditionData ConditionData_SetPermanentData(int data);
ConditionData ConditionData_SetPermanentMaxCountAndData(int max_count, int data);
ConditionData ConditionData_SetDependsOnMonTurnBased(int mon_id, int turns);
ConditionData ConditionData_SetBadlyPoisoned();
bool ConditionData_IsBadlyPoisoned(ConditionData condition);
u8 ConditionData_GetMonID(ConditionData condition);
void ConditionData_SetMonID(ConditionData *condition, int mon_id);
u8 ConditionData_GetMaxTurns(ConditionData condition);
void ConditionData_SetData(ConditionData *condition, int data);
u16 ConditionData_GetData(ConditionData condition);
void ConditionData_SetFlag(ConditionData *condition, int value);
bool ConditionData_GetFlag(ConditionData condition);
void ConditionData_IncreaseTurnCount(ConditionData *condition, u8 amount);
void ConditionData_SetTurnCount(ConditionData *condition, u8 turn_count);

C_DECL_END

enum ConditionDataType
#ifdef __cplusplus
: u32
#endif
{
  TYPE_BASE = 0x0,
  TYPE_PERMANENT = 0x1,
  TYPE_TURN_BASED = 0x2,
  TYPE_DEPENDS_ON_MON = 0x3,
  TYPE_DEPENDS_ON_MON_TURN_BASED = 0x4,
};

enum MoveCondition
#ifdef __cplusplus
: u32
#endif
{
  CONDITION_NONE = 0x0,
  CONDITION_PARALYSIS = 0x1,
  CONDITION_SLEEP = 0x2,
  CONDITION_FREEZE = 0x3,
  CONDITION_BURN = 0x4,
  CONDITION_POISON = 0x5,
  CONDITION_CONFUSION = 0x6,
  CONDITION_ATTRACT = 0x7,
  CONDITION_BIND = 0x8,
  CONDITION_NIGHTMARE = 0x9,
  CONDITION_CURSE = 0xA,
  CONDITION_TAUNT = 0xB,
  CONDITION_TORMENT = 0xC,
  CONDITION_DISABLE = 0xD,
  CONDITION_YAWN = 0xE,
  CONDITION_HEAL_BLOCK = 0xF,
  CONDITION_GASTRO_ACID = 0x10,
  CONDITION_FORESIGHT = 0x11,
  CONDITION_LEECH_SEED = 0x12,
  CONDITION_EMBARGO = 0x13,
  CONDITION_PERISH_SONG = 0x14,
  CONDITION_INGRAIN = 0x15,
  CONDITION_BLOCK = 0x16,
  CONDITION_ENCORE = 0x17,
  CONDITION_ROOST = 0x18,
  CONDITION_MOVE_LOCK = 0x19,
  CONDITION_CHARGE_LOCK = 0x1A,
  CONDITION_CHOICE_LOCK = 0x1B,
  CONDITION_MUST_HIT = 0x1C,
  CONDITION_LOCK_ON = 0x1D,
  CONDITION_FLOATING = 0x1E,
  CONDITION_KNOCKED_DOWN = 0x1F,
  CONDITION_TELEKINESIS = 0x20,
  CONDITION_SKY_DROP = 0x21,
  CONDITION_ACCURACY_UP = 0x22,
  CONDITION_AQUA_RING = 0x23,
  CONDITION_MAX = 0x24,
};

struct ConditionData_Permanent
{
  unsigned __int32 type : 3;
  unsigned __int32 max_count : 6;
  unsigned __int32 param : 16;
  unsigned __int32 flag : 1;
  unsigned __int32 pad : 6;
};

struct ConditionData_DependsOnMon
{
  unsigned __int32 type : 3;
  unsigned __int32 monID : 6;
  unsigned __int32 param : 16;
  unsigned __int32 flag : 1;
  unsigned __int32 pad : 6;
};

struct ConditionData_TurnBased
{
  unsigned __int32 type : 3;
  unsigned __int32 turns : 6;
  unsigned __int32 param : 16;
  unsigned __int32 flag : 1;
  unsigned __int32 pad : 6;
};

struct ConditionData_DependsOnMonTurnBased
{
  unsigned __int32 type : 3;
  unsigned __int32 turns : 6;
  unsigned __int32 monID : 6;
  unsigned __int32 param : 16;
  unsigned __int32 flag : 1;
};

union ConditionData
{
  u32 raw;
  ConditionData_Permanent permanent;
  ConditionData_DependsOnMon poke;
  ConditionData_DependsOnMonTurnBased poketurn;
  ConditionData_TurnBased turn;
};

#endif
