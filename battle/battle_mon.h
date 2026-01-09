#ifndef __BATTLE_MON_H
#define __BATTLE_MON_H

#include "swantypes.h"

STRUCT_DECLARE(BattleMonCore)
STRUCT_DECLARE(BattleMonBase)
STRUCT_DECLARE(StatStageParam)
STRUCT_DECLARE(MoveCore)
STRUCT_DECLARE(MoveSlot)
STRUCT_DECLARE(MoveDamageRec)
STRUCT_DECLARE(BattleMon)
STRUCT_DECLARE(BattleParty)
STRUCT_DECLARE(LevelUpInfo)

ENUM_DECLARE(BattleMonValue)
ENUM_DECLARE(TurnFlag)
ENUM_DECLARE(ConditionFlag)
ENUM_DECLARE(Counter)

#include "pml/poke_party.h"
#include "battle/battle_conditiondata.h"

C_DECL_BEGIN

BattleMon *BattleMon_Create(PartyPkm *a1, char a2, HeapID a3);
void BattleMon_SetupBySrcData(BattleMon *a1, PartyPkm *a2, int a3, int a4);
int BattleMon_GetNumMoves(BattleMon *a1, PartyPkm *a2, int a3);
void BattleMon_SetMovesAndPP(BattleMon *a1);
void BattleMon_SetupBySrcDataBase(BattleMon *a1, PartyPkm *a2, int a3);
void BattleMon_ClearFormChange(BattleMon *a1);
void BattleMon_ClearUsedMoveFlags(BattleMon *a1);
void BattleMon_ClearCounters(BattleMon *a1);
void BattleMon_Free(void *heap);
int BattleMon_GetID(BattleMon *a1);
int BattleMon_GetSpecies(BattleMon *a1);
int BattleMon_GetMoveCount(BattleMon *a1);
int BattleMon_GetTypes(BattleMon *a1, u8 *a2, u8 *a3);
int BattleMon_GetPokeTypePair(BattleMon *a1);
bool BattleMon_HasType(BattleMon *a1, PokeType a2);
PartyPkm *BattleMon_GetSrcData(BattleMon *a1);
void BattleMon_SetIllusion(BattleMon *result, PartyPkm *a2);
void BattleMon_RemoveIllusion(BattleMon *result);
PartyPkm *BattleMon_GetViewSrcData(BattleMon *a1);
BattleMonValue BattleMon_SwitchDefensesForWonderRoom(BattleMon *a1, BattleMonValue a2);
int BattleMon_GetRealStat(BattleMon *a1, BattleMonValue a2);
b32 BattleMon_CopyStats(BattleMon *a1, u16 *a2);
void BattleMon_SetRealStat(BattleMon *a1, int a2, __int16 a3);
int BattleMon_GetValue(BattleMon *a1, BattleMonValue a2);
int BattleMon_GetStatsForCritDamage(BattleMon *a1, int a2);
int BattleMon_GetHeldItem(BattleMon *a1);
void BattleMon_SetItem(BattleMon *result, __int16 a2);
bool BattleMon_IsFullHP(BattleMon *a1);
bool BattleMon_IsFainted(BattleMon *a1);
int BattleMon_CanBattle(BattleMon *a1);
int BattleMon_GetTurnCount(BattleMon *a1);
bool BattleMon_GetTurnFlag(BattleMon *a1, TurnFlag a2);
bool BattleMon_GetConditionFlag(BattleMon *a1, ConditionFlag a2);
ConditionFlag BattleMon_GetHideCondition(BattleMon *a1);
bool BattleMon_IsHiding(BattleMon *a1);
int BattleMon_GetHPRatio(BattleMon *a1);
u8 *BattleMon_GetStatStage(BattleMon *a1, unsigned int a2, u8 *a3, u8 *a4);
bool BattleMon_IsStatChangeValid(BattleMon *a1, unsigned int a2, int a3);
int BattleMon_GetStatStageAmountToMax(BattleMon *a1, unsigned int a2);
bool BattleMon_AreStatsLowered(BattleMon *a1);
int BattleMon_StatStageUp(BattleMon *a1, unsigned int a2, int a3);
int BattleMon_StatStageDown(BattleMon *a1, unsigned int a2, int a3);
int BattleMon_StatStageSet(int result, unsigned int a2, int a3);
u8 BattleMon_RecoverStatStages(BattleMon *a1);
void BattleMon_ResetStatStages(BattleMon *a1);
int BattleMon_GetCritStage(BattleMon *a1);
int BattleMon_AddCritStage(BattleMon *a1, int a2);
void BattleMon_SubtractHP(BattleMon *result, unsigned int a2);
void BattleMon_AddHP(BattleMon *result, __int16 a2);
void BattleMon_ZeroHP(BattleMon *result);
void BattleMon_SetTurnFlag(BattleMon *a1, TurnFlag a2);
void BattleMon_SetConditionFlag(BattleMon *a1, ConditionFlag a2);
void BattleMon_ClearConditionFlag(BattleMon *a1, int a2);
void BattleMon_SetMoveCondition(BattleMon *a1, MoveCondition a2, ConditionData a3);
int BattleMon_MoveConditionTurnCheck(BattleMon *a1, int a2, ConditionData *a3, int *a4);
int BattleMon_CheckWakeUp(BattleMon *a1);
int BattleMon_CheckConfusionEnd(BattleMon *a1);
void BattleMon_CureStatusCondition(BattleMon *a1);
void BattleMon_CureNightmare(BattleMon *result, int a2);
void BattleMon_CureMoveCondition(BattleMon *a1, MoveCondition a2);
void BattleMon_CureMonDependentConditions(BattleMon *a1, int a2);
MoveCondition BattleMon_GetStatus(BattleMon *a1);
bool BattleMon_CheckIfMoveCondition(BattleMon *a1, MoveCondition a2);
int BattleMon_GetConditionAffectedMove(BattleMon *a1, MoveCondition a2);
ConditionData BattleMon_GetMoveCondition(BattleMon *a1, MoveCondition a2);
int BattleMon_GetConditionCounter(BattleMon *a1, int a2);
unsigned int BattleMon_CalcConditionDamage(BattleMon *a1, MoveCondition a2);
void BattleMon_ClearAllConditions(BattleMon *a1, int a2);
void BattleMon_SetAppearTurn(BattleMon *a1, __int16 a2);
void BattleMon_TurnCheck(BattleMon *a1);
void BattleMon_ClearTurnFlag(BattleMon *a1, int a2);
void BattleMon_ClearForFainted(BattleMon *a1);
void BattleMon_ClearForSwitchOut(BattleMon *a1);
void BattleMon_ClearForSwitchIn(BattleMon *a1);
void BattleMon_CopyBatonPassParams(BattleMon *target, BattleMon *user);
void BattleMon_ChangePokeType(BattleMon *a1, int a2);
void BattleMon_ChangeAbility(BattleMon *a1, __int16 a2);
b32 BattleMon_ChangeForm(BattleMon *a1, u32 a2);
void BattleMon_ConsumeItem(BattleMon *result, __int16 a2);
void BattleMon_ClearConsumedItem(BattleMon *result);
int BattleMon_GetUsedItem(BattleMon *a1);
void BattleMon_UpdateMoveProcessingResult(BattleMon *result, char a2, int a3, char a4, unsigned __int16 a5, int a6);
int BattleMon_GetConsecutiveMoveCount(BattleMon *a1);
int BattleMon_GetPreviousMoveID(BattleMon *a1);
int BattleMon_GetPreviousMoveType(BattleMon *a1);
int BattleMon_GetPreviousMove(BattleMon *a1);
int BattleMon_GetPrevTargetPos(BattleMon *a1);
unsigned int BattleMon_GetWasInBattleFlag(BattleMon *a1);
void BattleMon_SetWeight(BattleMon *result, int a2);
int BattleMon_GetWeight(BattleMon *a1);
void BattleMon_SetCount(BattleMon *a1, int a2, char a3);
int BattleMon_GetCounter(BattleMon *a1, Counter a2);
int BattleMon_AddExp(BattleMon *a1, int *a2, LevelUpInfo *a3);
u32 BattleMon_GetExpForLevel100(BattleMon *a1);
void BattleMon_UpdateData(BattleMon *a1, int a2);
void BattleMon_UpdatePP(BattleMon *a1);
unsigned int BattleMon_IsIllusionEnabled(BattleMon *a1);
void BattleMon_IllusionBreak(BattleMon *result);
void BattleMon_SetSourceSpecies(BattleMon *a1, PartyPkm *a2);
int BattleMon_TransformSet(BattleMon *a1, BattleMon *a2);
unsigned int BattleMon_TransformCheck(BattleMon *a1);
void BattleMon_CreateSubstitute(BattleMon *a1, __int16 a2);
void BattleMon_RemoveSubstitute(BattleMon *result);
bool BattleMon_IsSubstituteActive(BattleMon *a1);
int BattleMon_GetSubstituteHP(BattleMon *a1);
int BattleMon_AddSubstituteDamage(BattleMon *a1, int a2);
void BattleMon_ClearConfrontRecCount(BattleMon *a1);
void BattleMon_SetConfrontRec(BattleMon *result, int a2);
int BattleMon_GetConfrontRecCount(BattleMon *a1);
int BattleMon_GetConfrontedPokeID(BattleMon *a1, unsigned int a2);
void BattleMon_SetCaptureBallID(BattleMon *a1, u16 a2);
void BattleMon_SetComboMoveData(BattleMon *result, char a2, __int16 a3);
int BattleMon_GetComboMoveData(BattleMon *a1, u8 *a2, u16 *a3);
bool BattleMon_HasComboMovePartner(BattleMon *a1);
void BattleMon_ClearComboMoveData(BattleMon *result);

C_DECL_END

enum BattleMonValue
#ifdef __cplusplus
: u32
#endif
{
  VALUE_NULL = 0x0,
  VALUE_ATTACK_STAGE = 0x1,
  VALUE_DEFENSE_STAGE = 0x2,
  VALUE_SPECIAL_ATTACK_STAGE = 0x3,
  VALUE_SPECIAL_DEFENSE_STAGE = 0x4,
  VALUE_SPEED_STAGE = 0x5,
  VALUE_ACCURACY_STAGE = 0x6,
  VALUE_EVASION_STAGE = 0x7,
  VALUE_ATTACK_STAT = 0x8,
  VALUE_DEFENSE_STAT = 0x9,
  VALUE_SPECIAL_ATTACK_STAT = 0xA,
  VALUE_SPECIAL_DEFENSE_STAT = 0xB,
  VALUE_SPEED_STAT = 0xC,
  VALUE_CURRENT_HP = 0xD,
  VALUE_MAX_HP = 0xE,
  VALUE_LEVEL = 0xF,
  VALUE_ABILITY = 0x10,
  VALUE_EFFECTIVE_ABILITY = 0x11,
  VALUE_SEX = 0x12,
  VALUE_FORM = 0x13,
  VALUE_EXPERIENCE = 0x14,
  VALUE_BASE_ATTACK = 0x15,
};

enum TurnFlag
#ifdef __cplusplus
: u32
#endif
{
  TURNFLAG_ACTION_START = 0x0,
  TURNFLAG_ACTION_DONE = 0x1,
  TURNFLAG_DAMAGED = 0x2,
  TURNFLAG_MOVE_PROC_DONE = 0x3,
  TURNFLAG_FLINCH = 0x4,
  TURNFLAG_FOCUS_PUNCH_READY = 0x5,
  TURNFLAG_FOCUS_PUNCH_FAIL = 0x6,
  TURNFLAG_PROTECT = 0x7,
  TURNFLAG_ITEM_CONSUMED = 0x8,
  TURNFLAG_CANT_USE_ITEM = 0x9,
  TURNFLAG_COMBO_MOVE_READY = 0xA,
  TURNFLAG_SEMI_INVULN_END = 0xB,
  TURNFLAG_MOVED = 0xC,
  TURNFLAG_TURN_CHECK_CONDITION_PASSED = 0xD,
  TURNFLAG_ACCURACY_UP = 0xE,
  TURNFLAG_USING_FLING = 0xF,
};

enum ConditionFlag
#ifdef __cplusplus
: u32
#endif
{
  CONDITIONFLAG_ACTION_DONE = 0x0,
  CONDITIONFLAG_NO_SWITCH = 0x1,
  CONDITIONFLAG_CHARGE = 0x2,
  CONDITIONFLAG_FLY = 0x3,
  CONDITIONFLAG_DIVE = 0x4,
  CONDITIONFLAG_DIG = 0x5,
  CONDITIONFLAG_SHADOW_FORCE = 0x6,
  CONDITIONFLAG_DEFENSE_CURL = 0x7,
  CONDITIONFLAG_MINIMIZE = 0x8,
  CONDITIONFLAG_FOCUS_ENERGY = 0x9,
  CONDITIONFLAG_POWER_TRICK = 0xA,
  CONDITIONFLAG_MICLE_BERRY = 0xB,
  CONDITIONFLAG_NO_ACTION = 0xC,
  CONDITIONFLAG_FLASH_FIRE = 0xD,
  CONDITIONFLAG_BATON_PASS = 0xE,
  CONDITIONFLAG_NULL = 0xF,
};

enum Counter
#ifdef __cplusplus
: u32
#endif
{
  COUNTER_STOCKPILE = 0x0,
  COUNTER_STOCKPILE_DEF = 0x1,
  COUNTER_STOCKPILE_SPDEF = 0x2,
  COUNTER_PROTECT = 0x3,
  COUNTER_SKY_DROP = 0x4,
};

struct BattleMonCore
{
  PartyPkm *source;
  PartyPkm *disguise_source;
  u32 exp;
  u16 species;
  u16 max_hp;
  u16 current_hp;
  u16 held_item;
  u16 used_item;
  u16 ability;
  u8 level;
  u8 id;
  u8 base_attack;
  unsigned __int8 default_form : 5;
  unsigned __int8 is_transformed : 1;
  unsigned __int8 is_illusion : 1;
  unsigned __int8 was_in_battle : 1;
  ConditionData condition_data[36];
  u8 condition_counters[36];
  u8 seen_enemies_count;
  u8 seen_enemies[24];
};

struct BattleMonBase
{
  u16 species;
  u16 attack;
  u16 defense;
  u16 sp_attack;
  u16 sp_defense;
  u16 speed;
  u8 type1;
  u8 type2;
  u8 sex;
};

struct StatStageParam
{
  u8 attack_stage;
  u8 defense_stage;
  u8 sp_attack_stage;
  u8 sp_defense_stage;
  u8 speed_stage;
  u8 accuracy_stage;
  u8 evasion_stage;
};

struct MoveCore
{
  u16 move_id;
  u8 current_pp;
  u8 max_pp;
  u8 pp_up_count;
  unsigned __int8 was_used : 4;
  unsigned __int8 was_used_permanent : 4;
};

struct MoveSlot
{
  MoveCore real_move;
  MoveCore temp_move;
  u8 is_unchanged;
};

struct MoveDamageRec
{
  u16 move_id;
  u16 damage;
  u8 damage_type;
  u8 move_type;
  u8 mon_id;
  u8 pos;
};

struct BattleMon
{
  BattleMonCore core;
  BattleMonBase base;
  StatStageParam stat_stages;
  MoveSlot moves[4];
  u16 current_ability;
  u16 weight;
  u8 move_count;
  u8 form;
  u8 critical_stage;
  u8 used_move_count;
  u8 prev_move_type;
  u16 turn_count;
  u16 entered_turn;
  u16 prev_move;
  u16 prev_move_index;
  u16 consecutive_move_count;
  u16 prev_hit_by_move;
  u8 prev_target_pos;
  u8 turn_flag[2];
  u8 condition_flag[2];
  u8 counters[5];
  MoveDamageRec damage_rec[3][6];
  u8 damage_rec_count[3];
  u8 damage_rec_turn;
  u8 damage_rec_ptr;
  u16 substitute_hp;
  u16 combo_move_id;
  u8 combo_partner_id;
};

struct BattleParty
{
  BattleMon *mons[6];
  u8 count;
  u8 numFieldPos;
};

struct LevelUpInfo
{
  u8 level;
  u16 hp;
  u16 atk;
  u16 def;
  u16 spa;
  u16 spd;
  u16 spe;
};

#endif
