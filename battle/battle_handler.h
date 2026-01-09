#ifndef __BATTLE_HANDLER_H
#define __BATTLE_HANDLER_H

#include "swantypes.h"

STRUCT_DECLARE(HandlerParam_Header)
STRUCT_DECLARE(HandlerParam_ChangeType)
STRUCT_DECLARE(HandlerParam_RemoveFieldEffect)
STRUCT_DECLARE(HandlerParam_StringSetup)
STRUCT_DECLARE(HandlerParam_AddFieldEffect)
STRUCT_DECLARE(HandlerParam_ChangeStatStage)
STRUCT_DECLARE(HandlerParam_RemoveSideEffect)
STRUCT_DECLARE(HandlerParam_Damage)
STRUCT_DECLARE(HandlerParam_ChangeMove)
STRUCT_DECLARE(HandlerParam_Message)
STRUCT_DECLARE(HandlerParam_CureCondition)
STRUCT_DECLARE(HandlerParam_AddCondition)
STRUCT_DECLARE(HandlerParam_ResetStatStage)
STRUCT_DECLARE(HandlerParam_ChangeHP)
STRUCT_DECLARE(HandlerParam_ChangeAbility)
STRUCT_DECLARE(HandlerParam_Flinch)
STRUCT_DECLARE(HandlerParam_SetCounter)
STRUCT_DECLARE(HandlerParam_Faint)
STRUCT_DECLARE(HandlerParam_SetConditionFlag)
STRUCT_DECLARE(HandlerParam_RecoverHP)
STRUCT_DECLARE(HandlerParam_SetItem)
STRUCT_DECLARE(HandlerParam_SwapItem)
STRUCT_DECLARE(HandlerParam_SetAnimID)
STRUCT_DECLARE(HandlerParam_SetTurnFlag)
STRUCT_DECLARE(HandlerParam_CheckItemReaction)
STRUCT_DECLARE(HandlerParam_DecrementPP)
STRUCT_DECLARE(HandlerParam_SetStatStage)
STRUCT_DECLARE(HandlerParam_SetStat)
STRUCT_DECLARE(HandlerParam_AddSideEffect)
STRUCT_DECLARE(HandlerParam_Transform)
STRUCT_DECLARE(HandlerParam_AddPosEffect)
STRUCT_DECLARE(HandlerParam_Switch)
STRUCT_DECLARE(HandlerParam_AddAnim)
STRUCT_DECLARE(HandlerParam_ForceUseItem)
STRUCT_DECLARE(HandlerParam_ForceSwitch)
STRUCT_DECLARE(HandlerParam_CancelSemiInvuln)
STRUCT_DECLARE(HandlerParam_SetWeight)
STRUCT_DECLARE(HandlerParam_InterruptAction)
STRUCT_DECLARE(HandlerParam_SendLast)
STRUCT_DECLARE(HandlerParam_InterruptMove)
STRUCT_DECLARE(HandlerParam_Shift)
STRUCT_DECLARE(HandlerParam_ChangeForm)
STRUCT_DECLARE(HandlerParam_ChangeWeather)
STRUCT_DECLARE(HandlerParam_IllusionBreak)
STRUCT_DECLARE(HandlerParam_RestorePP)
STRUCT_DECLARE(HandlerParam_ConsumeItem)
STRUCT_DECLARE(HandlerParam_UseHeldItem)
STRUCT_DECLARE(HandlerParam_RestoreStatStage)
STRUCT_DECLARE(HandlerParam_Revive)
STRUCT_DECLARE(HandlerParam_Drain)
STRUCT_DECLARE(HandlerParam_DelayMoveDamage)
STRUCT_DECLARE(HandlerParam_QuitBattle)
STRUCT_DECLARE(HandlerParam_BatonPass)

#include "battle/battle_conditiondata.h"
#include "battle/battle_serverflow.h"

C_DECL_BEGIN

void BattleHandler_StrClear(HandlerParam_StringSetup *str);
bool BattleHandler_StrIsEnabled(HandlerParam_StringSetup *str);
void BattleHandler_StrSetup(HandlerParam_StringSetup *str, u8 a2, u16 str_id);
void BattleHandler_AddArg(HandlerParam_StringSetup *str, int a2);
void BattleHandler_AddSoundEffect(HandlerParam_StringSetup *result, int a2);
HandlerParam_Header *BattleHandler_PushWork(ServerFlow *a1, BattleHandlerEffect a2, int a3);
void BattleHandler_PushRun(ServerFlow *a1, BattleHandlerEffect a2, int a3);
void BattleHandler_PopWork(ServerFlow *a1, void *a2);
int BattleHandler_Result(ServerFlow *a1);
int BattleHandler_SetString(ServerFlow *a1, HandlerParam_StringSetup *a2);

C_DECL_END

enum BattleHandlerEffect
{
  EFFECT_USE_HELD_ITEM = 0x0,
  EFFECT_USE_HELD_ITEM_ANIMATION = 0x1,
  EFFECT_ABILITY_POPUP_ADD = 0x2,
  EFFECT_ABILITY_POPUP_REMOVE = 0x3,
  EFFECT_MESSAGE = 0x4,
  EFFECT_RECOVER_HP = 0x5,
  EFFECT_DRAIN = 0x6,
  EFFECT_DAMAGE = 0x7,
  EFFECT_CHANGE_HP = 0x8,
  EFFECT_RESTORE_PP = 0x9,
  EFFECT_DECREMENT_PP = 0xA,
  EFFECT_CURE_CONDITION = 0xB,
  EFFECT_ADD_CONDITION = 0xC,
  EFFECT_CHANGE_STAT_STAGE = 0xE,
  EFFECT_SET_STAT_STAGE = 0xF,
  EFFECT_RESET_STAT_STAGE = 0x10,
  EFFECT_SET_STAT = 0x11,
  EFFECT_RESTORE_STAT_STAGE = 0x12,
  EFFECT_FAINT = 0x13,
  EFFECT_CHANGE_TYPE = 0x14,
  EFFECT_SET_TURN_FLAG = 0x15,
  EFFECT_RESET_TURN_FLAG = 0x16,
  EFFECT_SET_CONDITION_FLAG = 0x17,
  EFFECT_RESET_CONDITION_FLAG = 0x18,
  EFFECT_ADD_SIDE_EFFECT = 0x19,
  EFFECT_REMOVE_SIDE_EFFECT = 0x1A,
  EFFECT_ADD_FIELD_EFFECT = 0x1B,
  EFFECT_REMOVE_FIELD_EFFECT = 0x1C,
  EFFECT_CHANGE_WEATHER = 0x1D,
  EFFECT_ADD_POS_EFFECT = 0x1E,
  EFFECT_CHANGE_ABILITY = 0x1F,
  EFFECT_SET_ITEM = 0x20,
  EFFECT_CHECK_ITEM_REACTION = 0x21,
  EFFECT_FORCE_USE_ITEM = 0x22,
  EFFECT_CONSUME_ITEM = 0x23,
  EFFECT_SWAP_ITEM = 0x24,
  EFFECT_CHANGE_MOVE = 0x25,
  EFFECT_SET_COUNTER = 0x26,
  EFFECT_DELAY_MOVE_DAMAGE = 0x27,
  EFFECT_QUIT_BATTLE = 0x28,
  EFFECT_SWITCH = 0x29,
  EFFECT_BATON_PASS = 0x2A,
  EFFECT_FLINCH = 0x2B,
  EFFECT_REVIVE = 0x2C,
  EFFECT_SET_WEIGHT = 0x2D,
  EFFECT_FORCE_SWITCH = 0x2E,
  EFFECT_INTERRUPT_ACTION = 0x2F,
  EFFECT_INTERRUPT_MOVE = 0x30,
  EFFECT_SEND_LAST = 0x31,
  EFFECT_SHIFT = 0x32,
  EFFECT_TRANSFORM = 0x33,
  EFFECT_ILLUSION_BREAK = 0x34,
  EFFECT_GRAVITY_CHECK = 0x35,
  EFFECT_CANCEL_SEMI_INVULN = 0x36,
  EFFECT_ADD_ANIM = 0x37,
  EFFECT_REMOVE_MESSAGE_WINDOW = 0x38,
  EFFECT_CHANGE_FORM = 0x39,
  EFFECT_SET_ANIM_ID = 0x3A,
  EFFECT_PLAY_ANIM = 0x3B,
} SWAN_PACKED;

struct HandlerParam_Header
{
  unsigned __int32 paramType : 8;
  unsigned __int32 monID : 5;
  unsigned __int32 size : 10;
  unsigned __int32 fDisableAbilityPopups : 1;
  unsigned __int32 fDisableExecution1 : 1;
  unsigned __int32 fDisableExecution2 : 1;
  unsigned __int32 pad : 6;
};

struct __attribute__((aligned(4))) HandlerParam_StringSetup
{
  u16 strID;
  u16 flags;
  int type;
  int args[8];
};

struct __attribute__((aligned(4))) HandlerParam_ChangeType
{
  HandlerParam_Header header;
  u16 nextType;
  u8 monID;
  u8 pad;
};

struct HandlerParam_RemoveFieldEffect
{
  HandlerParam_Header header;
  int effect;
};

struct __attribute__((aligned(4))) HandlerParam_AddFieldEffect
{
  HandlerParam_Header header;
  int effect;
  ConditionData conditionData;
  u8 fAddDependPoke;
  char field_D;
  char field_E;
  char field_F;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_ChangeStatStage
{
  HandlerParam_Header header;
  int changedStat;
  u32 showStatStageChangeAnimation;
  s8 changeAmount;
  u8 fDisableMessage;
  u8 fPlayAnim;
  u8 affectedMonCount;
  u8 affectedMonIDs[6];
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(4))) HandlerParam_RemoveSideEffect
{
  HandlerParam_Header header;
  u8 flags[3];
  u8 side;
};

struct __attribute__((aligned(4))) HandlerParam_Damage
{
  HandlerParam_Header header;
  u16 amount;
  u8 monID;
  char flags;
  u16 animID;
  u8 posFrom;
  u8 posTo;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_ChangeMove
{
  HandlerParam_Header header;
  u8 monID;
  u8 moveIndex;
  u8 ppMax;
  u8 fPermanent;
  u16 moveID;
};

struct HandlerParam_Message
{
  HandlerParam_Header header;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_CureCondition
{
  HandlerParam_Header header;
  MoveCondition condition;
  u8 affectedMonIDs[12];
  u8 affectedMonCount;
  u8 fDisableMessage;
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(4))) HandlerParam_AddCondition
{
  HandlerParam_Header header;
  MoveCondition condition;
  ConditionData conditionData;
  u8 fDisplayFailMessage;
  u8 reserved;
  u8 fDisableItemReaction;
  u8 monID;
  u8 overwriteMode;
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(2))) HandlerParam_ResetStatStage
{
  HandlerParam_Header header;
  u8 affectedMonCount;
  u8 affectedMonIDs[6];
};

struct HandlerParam_ChangeHP
{
  HandlerParam_Header header;
  u8 affectedMonCount;
  u8 fAnimDisable;
  u8 fItemReactionDisable;
  u8 affectedMonIDs[6];
  u32 amount[6];
};

struct HandlerParam_ChangeAbility
{
  HandlerParam_Header header;
  u16 abilityID;
  u8 monID;
  u8 fSameAbilityEffective;
  u8 fSkipSwitchInEvent;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_Flinch
{
  HandlerParam_Header header;
  u8 monID;
  u8 chance;
};

struct __attribute__((aligned(2))) HandlerParam_SetCounter
{
  HandlerParam_Header header;
  u8 monID;
  u8 counter;
  u8 value;
};

struct __attribute__((aligned(4))) HandlerParam_Faint
{
  HandlerParam_Header header;
  u8 monID;
  u8 pad[3];
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(4))) HandlerParam_SetConditionFlag
{
  HandlerParam_Header header;
  int flag;
  u8 monID;
};

struct HandlerParam_RecoverHP
{
  HandlerParam_Header header;
  u16 amount;
  u8 monID;
  u8 fBypassFailCheck;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_SetItem
{
  HandlerParam_Header header;
  u16 itemID;
  u8 monID;
  u8 fClearConsumedItem;
  u8 fClearOtherMonConsumedItem;
  u8 clearConsumedItemMonID;
  u8 pad[2];
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_SwapItem
{
  HandlerParam_Header header;
  u8 pokeID;
  u8 fIncRecordCount;
  HandlerParam_StringSetup strParam;
  HandlerParam_StringSetup subStrParam1;
  HandlerParam_StringSetup subStrParam2;
};

struct HandlerParam_SetAnimID
{
  HandlerParam_Header header;
  u8 animID;
};

struct __attribute__((aligned(4))) HandlerParam_SetTurnFlag
{
  HandlerParam_Header header;
  int flag;
  u8 monID;
};

struct __attribute__((aligned(4))) HandlerParam_CheckItemReaction
{
  HandlerParam_Header header;
  u8 monID;
  int reactionType;
};

struct HandlerParam_DecrementPP
{
  HandlerParam_Header header;
  u8 amount;
  u8 monID;
  u8 moveIndex;
  u8 pad;
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(4))) HandlerParam_SetStatStage
{
  HandlerParam_Header header;
  u8 pokeID;
  u8 attack;
  u8 defense;
  u8 sp_attack;
  u8 sp_defense;
  u8 speed;
  u8 accuracy;
  u8 evasion;
};

struct HandlerParam_SetStat
{
  HandlerParam_Header header;
  u16 attack;
  u16 defense;
  u16 sp_attack;
  u16 sp_defense;
  u16 speed;
  u8 monID;
  unsigned __int8 setAttack : 1;
  unsigned __int8 setDefense : 1;
  unsigned __int8 setSpAttack : 1;
  unsigned __int8 setSpDefense : 1;
  unsigned __int8 setSpeed : 1;
  unsigned __int8 pad : 3;
  HandlerParam_StringSetup exStr;
};

struct HandlerParam_AddSideEffect
{
  HandlerParam_Header header;
  u32 effect;
  ConditionData conditionData;
  u8 side;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_Transform
{
  HandlerParam_Header header;
  u8 monID;
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(4))) HandlerParam_AddPosEffect
{
  HandlerParam_Header header;
  int effect;
  u8 pos;
  u32 effects[4];
  u8 effect_count;
};

struct __attribute__((aligned(4))) HandlerParam_Switch
{
  HandlerParam_Header header;
  HandlerParam_StringSetup preStrParam;
  HandlerParam_StringSetup strParam;
  u8 monID;
  u8 fDisableInterrupt;
};

struct HandlerParam_AddAnim
{
  HandlerParam_Header header;
  u16 animID;
  u8 posFrom;
  u8 posTo;
  u16 reservedQueuePos;
  u8 fQueueReserve;
  u8 fHideMsgWindow;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_ForceUseItem
{
  HandlerParam_Header header;
  u8 monID;
  u16 itemID;
};

struct __attribute__((aligned(4))) HandlerParam_ForceSwitch
{
  HandlerParam_Header header;
  u16 animID;
  u8 monID;
  unsigned __int8 fUseNonWildEffect : 4;
  unsigned __int8 fDisableLevelCheck : 4;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_CancelSemiInvuln
{
  HandlerParam_Header header;
  u8 monID;
  u32 flag;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_SetWeight
{
  HandlerParam_Header header;
  u8 monID;
  u16 weight;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_InterruptAction
{
  HandlerParam_Header header;
  u8 monID;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_SendLast
{
  HandlerParam_Header header;
  u8 monID;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_InterruptMove
{
  HandlerParam_Header header;
  u16 moveID;
};

struct HandlerParam_Shift
{
  HandlerParam_Header header;
  u8 monID1;
  u8 monID2;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_ChangeForm
{
  HandlerParam_Header header;
  u8 monID;
  u8 form;
  u8 fDontResetOnSwitch;
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(4))) HandlerParam_ChangeWeather
{
  HandlerParam_Header header;
  u8 weather;
  u8 turnCount;
  u8 fAirLock;
  u8 pad;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_IllusionBreak
{
  HandlerParam_Header header;
  u8 monID;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_RestorePP
{
  HandlerParam_Header header;
  u8 amount;
  u8 monID;
  u8 moveIndex;
  unsigned __int8 fOnlyRestoreSurface : 1;
  unsigned __int8 fAllowOnFaintedMons : 1;
  unsigned __int8 pad : 6;
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(4))) HandlerParam_ConsumeItem
{
  HandlerParam_Header header;
  int fDontActivateItem;
  HandlerParam_StringSetup strParam;
};

struct HandlerParam_UseHeldItem
{
  HandlerParam_Header header;
  unsigned __int32 fAllowAtFullHP : 1;
  unsigned __int32 fAllowOnFaintedMons : 1;
  unsigned __int32 pad : 30;
};

struct HandlerParam_RestoreStatStage
{
  HandlerParam_Header header;
  u8 monID;
};

struct HandlerParam_Revive
{
  HandlerParam_Header header;
  u8 monID;
  u16 recoverHP;
  HandlerParam_StringSetup strParam;
};

struct __attribute__((aligned(4))) HandlerParam_Drain
{
  HandlerParam_Header header;
  u16 recoverHP;
  u8 recoverMonID;
  u8 damagedMonID;
  HandlerParam_StringSetup exStr;
};

struct __attribute__((aligned(4))) HandlerParam_DelayMoveDamage
{
  HandlerParam_Header header;
  u8 attackerID;
  u8 targetID;
  __int16 moveID;
};

struct HandlerParam_QuitBattle
{
  HandlerParam_Header header;
};

struct HandlerParam_BatonPass
{
  HandlerParam_Header header;
  u8 userMonID;
  u8 targetMonID;
};

#endif
