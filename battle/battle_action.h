#ifndef __BATTLE_ACTION_H
#define __BATTLE_ACTION_H

#include "swantypes.h"

STRUCT_DECLARE(BattleAction_Base)
STRUCT_DECLARE(BattleAction_Attack)
STRUCT_DECLARE(BattleAction_Item)
STRUCT_DECLARE(BattleAction_Switch)
STRUCT_DECLARE(BattleAction_Run)
STRUCT_DECLARE(BattleAction_Shift)
STRUCT_DECLARE(BattleAction_Rotate)

UNION_DECLARE(BattleAction)

ENUM_DECLARE(BattleActionType)

C_DECL_BEGIN

void BattleAction_SetAttack(BattleAction *action, int move_id, int target_pos);
void BattleAction_ChangeAttackTarget(BattleAction *action, int target_pos);
void BattleAction_SetMoveInfoFlag(BattleAction *action);
unsigned int BattleAction_IsMoveInfoMode(BattleAction *action);
int BattleAction_GetMoveID(BattleAction *action);
void BattleAction_SetItem(BattleAction *action, int item_id, int target_index, int move_index);
void BattleAction_SetSwitch(BattleAction *action, int current_mon_pos, int new_mon_party_index);
void BattleAction_SetPartyEmptyFlag(BattleAction *action);
bool BattleAction_IsPartyEmpty(BattleAction *action);
void BattleAction_SetRotation(BattleAction *action, int rotate_dir);
void BattleAction_SetEscape(BattleAction *action);
void BattleAction_SetShift(BattleAction *action);
void BattleAction_SetNull(BattleAction *action);
void BattleAction_SetSkip(BattleAction *action);
BattleActionType BattleAction_GetActionType(BattleAction *action);
void BattleAction_SetRecPlayerTimeOut(BattleAction *action);
void BattleAction_SetRecPlayerError(BattleAction *action);

C_DECL_END

enum BattleActionType
#ifdef __cplusplus
: u32
#endif
{
  ACTION_BASE = 0x0,
  ACTION_ATTACK = 0x1,
  ACTION_ITEM = 0x2,
  ACTION_SWITCH = 0x3,
  ACTION_RUN = 0x4,
  ACTION_SHIFT = 0x5,
  ACTION_ROTATE = 0x6,
  ACTION_SKIP = 0x7,
  ACTION_RECPLAYER_TIMEOUT = 0x8,
  ACTION_RECPLAYER_ERROR = 0x9,
};

struct BattleAction_Base
{
  unsigned __int32 actionType : 4;
  unsigned __int32 param : 28;
};

struct BattleAction_Attack
{
  unsigned __int32 actionType : 4;
  unsigned __int32 targetPos : 3;
  unsigned __int32 moveID : 16;
  unsigned __int32 rotation : 3;
  unsigned __int32 moveInfoFlag : 1;
  unsigned __int32 pad : 5;
};

struct BattleAction_Item
{
  unsigned __int32 actionType : 4;
  unsigned __int32 targetIdx : 3;
  unsigned __int32 itemID : 16;
  unsigned __int32 param : 8;
  unsigned __int32 pad : 1;
};

struct BattleAction_Switch
{
  unsigned __int32 actionType : 4;
  unsigned __int32 battlePos : 3;
  unsigned __int32 partyIndex : 3;
  unsigned __int32 partyEmptyFlag : 1;
  unsigned __int32 pad : 21;
};

struct BattleAction_Run
{
  unsigned __int32 actionType : 4;
  unsigned __int32 escape : 28;
};

struct BattleAction_Shift
{
  unsigned __int32 actionType : 4;
  unsigned __int32 shift : 28;
};

struct BattleAction_Rotate
{
  unsigned __int32 actionType : 4;
  unsigned __int32 rotation : 3;
  unsigned __int32 pad : 25;
};

union BattleAction
{
  BattleAction_Base Base;
  BattleAction_Attack Attack;
  BattleAction_Item Item;
  BattleAction_Switch Switch;
  BattleAction_Run Run;
  BattleAction_Shift Shift;
  BattleAction_Rotate Rotate;
};

#endif
