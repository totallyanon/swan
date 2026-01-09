#ifndef __BATTLE_SERVERFLOW_H
#define __BATTLE_SERVERFLOW_H

#include "swantypes.h"

STRUCT_DECLARE(ServerFlow)
STRUCT_DECLARE(MoveAnimCtrl)
STRUCT_DECLARE(MoveStealParam)
STRUCT_DECLARE(HitCheckParam)
STRUCT_DECLARE(ClientIDRecord)
STRUCT_DECLARE(ActionOrderWork)
STRUCT_DECLARE(MoveParam)
STRUCT_DECLARE(TargetSet)
STRUCT_DECLARE(calc_damage_record)
STRUCT_DECLARE(CalcDamageRecord)
STRUCT_DECLARE(TargetSetGroup)
STRUCT_DECLARE(PosPokeState)
STRUCT_DECLARE(PosPoke)
STRUCT_DECLARE(CalcExpWork)
STRUCT_DECLARE(EventWorkStack)
STRUCT_DECLARE(HEManager)
STRUCT_DECLARE(EffectivenessCounter)
STRUCT_DECLARE(EffectivenessRecorder)

ENUM_DECLARE(FlowResult)
ENUM_DECLARE(ActionIgnoreReason)

#include "gfl/fs/gfl_archive.h"
#include "battle/battle_action.h"
#include "battle/battle_common.h"
#include "battle/battle_faintrecord.h"
#include "battle/battle_handler.h"
#include "battle/battle_mainmodule.h"
#include "battle/battle_mon.h"
#include "battle/battle_moverecord.h"
#include "battle/battle_server.h"

C_DECL_BEGIN

BattleMon *Handler_GetBattleMon(ServerFlow *a1, int a2);
int Handler_GetExistFrontPokePos(ServerFlow *a1, int a2);
int Handler_GetPokeLastPos(ServerFlow *a1, int a2);
int Handler_GetExistPokeID(ServerFlow *a1, int a2);
int Handler_GetAllOpponentFrontPokeID(ServerFlow *a1, unsigned int a2, int a3);
int Handler_SimulationEffectivenessCore(ServerFlow *a1, int a2, int a3, int a4);
int Handler_SimulationDamage(ServerFlow *a1, int a2, int a3, int a4, bool a5, bool a6);
bool Handler_IsSimulationMode(ServerFlow *a1);
int Handler_GetChatotVoicePower(ServerFlow *a1, unsigned int a2);
int Handler_GetNumClientPositions(ServerFlow *a1, unsigned int a2);
int Handler_GetNumClientFieldPositions(ServerFlow *a1, unsigned int a2);
bool Handler_AreThereBattleReadyMonsInParty(ServerFlow *a1, unsigned int a2);
int Handler_CheckIfSwitchingByBattleEffect(ServerFlow *a1);
int Handler_StoreTargetIDsAndGetNumTargets(ServerFlow *a1, __int16 a2, u8 *a3);
BattleParty *Handler_GetPartyData(int a1, unsigned int a2);
BattleParty *Handler_GetAllyPartyData(int a1, unsigned int a2);
int Handler_PokeIDToPokePos(int a1, unsigned int a2);
int Handler_PokePosToPokeID(ServerFlow *a1, int a2);
int Handler_ReqMoveTargetAuto(ServerFlow *a1, int a2, int a3);
int Handler_GetThisTurnAction(ServerFlow *a1, int a2, BattleAction *a3);
bool Handler_IsMyActionOrderLast(ServerFlow *a1, int a2);
int Handler_GetPrevUsedMove(ServerFlow *a1);
u8 *Handler_GetTempWork(ServerFlow *a1);
MoveRecord *Handler_GetMoveRecord(ServerFlow *a1);
FaintRecord *Handler_GetFaintRecord(ServerFlow *a1);
int Handler_GetTurnCount(ServerFlow *a1);
int Handler_GetSwitchCount(ServerFlow *a1, int a2);
bool Handler_DoesBattleMonExist(ServerFlow *a1, int a2);
BattleStyle Handler_GetBattleStyle(ServerFlow *a1);
BtlType Handler_GetBattleType(ServerFlow *a1);
u32 Handler_GetBattleTerrain(ServerFlow *a1);
int Handler_GetFrontPosNum(ServerFlow *a1);
int Handler_CheckEvolution(ServerFlow *a1, int a2);
int Handler_CalculateSpeed(ServerFlow *a1, BattleMon *a2, int a3);
int Handler_CalcSpeedRank(ServerFlow *a1, BattleMon *a2, int a3);
bool Handler_CheckFloating(ServerFlow *a1, int a2);
bool Handler_CheckItemUsable(int a1, int a2);
int Handler_GetWeather(ServerFlow *a1);
bool Handler_IsTargetInRange(ServerFlow *a1, int a2, int a3, int a4);
bool Handler_IsSideEffectActive(ServerFlow *a1, int a2, int a3);
int Handler_GetSideConditionCount(ServerFlow *a1, char a2, int a3);
bool Handler_IsPosEffectActive(ServerFlow *a1, int a2, int a3);
int Handler_GetAllyClientID(ServerFlow *a1, char a2);
int Handler_IsMonSwitchOutInterrupted(ServerFlow *a1);
void Handler_AddSwitchOutInterrupt(ServerFlow *a1, char a2);
bool Handler_IsHiding(ServerFlow *a1, int a2);
ool Handler_IsSkyDropUser(ServerFlow *a1, int a2);
bool Handler_IsMonInSkyDrop(ServerFlow *a1, int a2);
unsigned int Handler_GetWeight(ServerFlow *a1, int a2);
bool Handler_ShouldBattleEnd(ServerFlow *a1);
void Handler_SetMoveEffectIndex(ServerFlow *a1, char a2);
int Handler_AddBonusMoney(ServerFlow *a1, int a2, int a3);
void Handler_SetDoubleMoney(ServerFlow *a1, unsigned int a2);
void Handler_AddMagicCoatAction(ServerFlow *a1, char a2, char a3);
bool Handler_SkyDropStart(ServerFlow *a1, int a2, int a3, int *a4);
void Handler_SkyDropRelease(ServerFlow *a1, int a2);
int Handler_UseHeldItem(ServerFlow *a1, BattleMon *a2, u8 *a3);
void Handler_AbilityUrge(ServerFlow *a1, BattleMon *a2);
void Handler_ResetRevivedPokeCount(ServerFlow *a1);
void Handler_RecordRevivedPoke(ServerFlow *result, int a2);
int Handler_IsPosOpenForRevivedMon(ServerFlow *a1);

void TargetSet_Clear(TargetSet *a1);
void TargetSet_AddTarget(TargetSet *set, BattleMon *target);
void TargetSet_AddDamage(TargetSet *set, BattleMon *target, __int16 damage, int is_substitute);
void TargetSet_Remove(TargetSet *set, BattleMon *target);
BattleMon *TargetSet_GetMonAtIndex(TargetSet *a1, unsigned int index);
void TargetSet_ResetIndex(TargetSet *a1);
BattleMon *TargetSet_GetNext(TargetSet *a1);
int TargetSet_GetDamage(TargetSet *set, BattleMon *target, int *damage);
int TargetSet_GetNonSubstituteDamage(TargetSet *set, BattleMon *target, int *damage);
int TargetSet_GetCount(TargetSet *a1);
int TargetSet_GetMaxCount(TargetSet *a1);
void TargetSet_SetTargetCount(TargetSet *set, char count);
bool TargetSet_IsEmpty(TargetSet *a1);
int TargetSet_CopyAliveTargets(TargetSet *a1, TargetSet *a2);
int TargetSet_CopyAllyTargets(TargetSet *a1, BattleMon *a2, TargetSet *a3);
int TargetSet_CopyEnemyTargets(TargetSet *a1, BattleMon *a2, u8 *a3);
void TargetSet_RemoveFaintedMons(TargetSet *a1);
void TargetSet_SortBySpeed(TargetSet *a1, ServerFlow *a2);

void PosPoke_Clear(PosPoke *a1, MainModule *a2, int a3);
void PosPoke_Init(PosPoke *a1, MainModule *a2, int a3);
void PosPoke_SetInitialFrontPokemon(PosPoke *a1, MainModule *a2, int a3, int a4);
void PosPoke_SwitchOut(PosPoke *a1, int a2);
void PosPoke_SwitchIn(PosPoke *a1, int a2, int a3, PokeCon *a4);
void PosPoke_Rotate(PosPoke *result, unsigned int a2, int a3, BattleMon *a4, PokeCon *a5);
void PosPoke_CheckConfrontRec(PosPoke *a1, int a2, PokeCon *a3);
void PosPoke_Swap(PosPoke *a1, int a2, int a3);
void PosPoke_UpdateLastPos(PosPoke *result, int a2);
int PosPoke_GetClientEmptyPos(PosPoke *a1, int a2, u8 *a3);
bool PosPoke_IsExist(PosPoke *a1, int a2);
bool PosPoke_IsExistFrontPos(PosPoke *a1, MainModule *a2, int a3);
int PosPoke_GetPokeExistPos(PosPoke *a1, int a2);
int PosPoke_GetPokeLastPos(PosPoke *a1, int a2);
int PosPoke_GetExistPokeID(PosPoke *a1, int a2);

void HEManager_Init(HEManager *a1);
u32 HEManager_PushState(HEManager *a1);
u32 HEManager_PushStateUseItem(HEManager *a1, __int16 a2);
void HEManager_PopState(HEManager *result, int a2);
int HEManager_GetUseItemNo(HEManager *a1);
u32 HEManager_IsUsed(HEManager *a1);
void HEManager_SetResult(HEManager *result, int a2);
u32 HEManager_GetPrevResult(HEManager *a1);
u32 HEManager_GetTotalResult(HEManager *a1);
char *HEManager_PushWork(unsigned int *a1, int a2, int a3);
void HEManager_PopWork(HEManager *result, void *a2);

C_DECL_END

enum FlowResult
#ifdef __cplusplus
: u32
#endif
{
  RESULT_TURN_STARTING = 0x0,
  RESULT_SWITCH = 0x1,
  RESULT_MON_FAINTED = 0x2,
  RESULT_EXP_GAINED = 0x3,
  RESULT_TEAM_FAINTED = 0x4,
  RESULT_ESCAPE = 0x5,
  RESULT_CAPTURE = 0x6,
};

enum MoveTarget
{
  TARGET_OTHER_SELECT = 0x0,
  TARGET_ALLY_USER_SELECT = 0x1,
  TARGET_ALLY_SELECT = 0x2,
  TARGET_ENEMY_SELECT = 0x3,
  TARGET_OTHER_ALL = 0x4,
  TARGET_ENEMY_ALL = 0x5,
  TARGET_ALLY_ALL = 0x6,
  TARGET_USER = 0x7,
  TARGET_ALL = 0x8,
  TARGET_ENEMY_RANDOM = 0x9,
  TARGET_FIELD = 0xA,
  TARGET_SIDE_ENEMY = 0xB,
  TARGET_SIDE_ALLY = 0xC,
  TARGET_UNKNOWN = 0xD,
  TARGET_LONG_RANGE = 0xE,
} SWAN_PACKED;

enum ActionIgnoreReason
#ifdef __cplusplus
: u32
#endif
{
  REASON_NONE = 0x0,
  REASON_OTHER_MOVE = 0x1,
  REASON_FALL_ASLEEP = 0x2,
  REASON_CONFUSION = 0x3,
  REASON_OVERLEVELED = 0x4,
  REASON_ASLEEP = 0x5,
};

struct MoveAnimCtrl
{
  u16 moveID;
  u8 attackerPos;
  u8 targetPos;
  u8 effectIndex;
  u8 flags;
  u16 subEff;
};

struct MoveStealParam
{
  char stealCount;
  char stealMonID[6];
  char targetPos[6];
  char targetMonID[6];
};

struct HitCheckParam
{
  u8 countMax;
  u8 count;
  u8 fCheckEveryTime;
  u8 fMultiHitMove;
  u8 fPutAnimCmd;
  u8 MultiHitEffectiveness;
};

struct ClientIDRecord
{
  u8 count;
  u8 clientID[4];
};

struct ActionOrderWork
{
  BattleMon *battleMon;
  BattleAction *Action;
  u32 priority;
  u8 clientID;
  u8 fDone;
  u8 InterruptActive;
};

struct MoveParam
{
  u16 MoveID;
  u16 OriginalMoveID;
  u16 userType;
  u8 moveType;
  u8 damageType;
  int category;
  MoveTarget targetType;
  int flags;
};

struct TargetSet
{
  BattleMon *mons[6];
  u16 damage[6];
  u16 substitute_damage[6];
  u8 damage_type[6];
  u16 speed[6];
  u8 count;
  u8 max_count;
  u8 get_index;
  u8 target_pos_count;
};

struct calc_damage_record
{
  u16 damage;
  unsigned __int16 targetID : 5;
  unsigned __int16 effectiveness : 3;
  unsigned __int16 unk : 1;
  unsigned __int16 isEndureActive : 1;
  unsigned __int16 unk2 : 3;
  unsigned __int16 isCritical : 1;
  unsigned __int16 isFixedDamage : 1;
  unsigned __int16 isSubstituteActive : 1;
};

struct CalcDamageRecord
{
  u8 real_hit_count;
  u8 substitute_hit_count;
  u8 total_hit_count;
  u8 pad;
  calc_damage_record record[6];
};

struct TargetSetGroup
{
  TargetSet original_targets;
  TargetSet targets;
  TargetSet allies;
  TargetSet enemies;
  TargetSet damaged_mons;
  TargetSet move_steal_targets;
  TargetSet temp;
  MoveAnimCtrl anim_ctrl;
  MoveParam move_param;
  MoveParam original_move_param;
  HitCheckParam hit_check_param;
  MoveStealParam move_steal_param;
  MoveStealParam magic_coat_param;
  CalcDamageRecord ally_calc_damage;
  CalcDamageRecord enemy_calc_damage;
  u8 default_target_pos;
  u8 switch_in_mon_count;
  u8 display_fail_message;
};

struct PosPokeState
{
  u8 enabled;
  u8 clientID;
  u8 monID;
};

struct PosPoke
{
  PosPokeState positions[6];
  u8 lastPos[24];
};

struct CalcExpWork
{
  u32 level;
  u8 isBoosted;
  u8 hp;
  u8 atk;
  u8 def;
  u8 spatk;
  u8 spdef;
  u8 spe;
};

struct EventWorkStack
{
  u8 work[512];
  u16 size[16];
  u32 sp;
};

struct HEManager
{
  u32 state;
  u8 buffer[500];
};

struct EffectivenessCounter
{
  u16 NoEffectHits;
  u16 SuperEffectiveHits;
  u16 NotVeryEffectiveHits;
  u16 OpponentNoEffectHits;
  u16 OpponentSuperEffectiveHits;
  u16 OpponentNotVeryEffectiveHits;
};

struct EffectivenessRecorder
{
  int effectiveness[24];
};

struct ServerFlow
{
  BtlServerWk *server;
  MainModule *main_module;
  PokeCon *pokeCon;
  ServerCommandQueue *scqueue;
  int turn_count;
  FlowResult flow_result;
  int heap;
  MoveRecord move_record;
  FaintRecord faint_record;
  ArcTool *evo_data;
  MoveAnimCtrl *move_anim_ctrl;
  MoveStealParam *move_steal_param;
  MoveStealParam *magic_coat_param;
  HitCheckParam *hit_check_param;
  EscapeInfo escape_info;
  LevelUpInfo level_up_info;
  ClientIDRecord client_id_record;
  int rotationHandlerWork[24][7];
  int is_simulation;
  int stat_stage_change_count;
  u8 command_build_step;
  u8 action_order_step;
  u8 turn_check_step;
  u8 default_target_pos;
  u16 heap_id;
  u8 action_order_index;
  u8 action_order_end_index;
  u8 ball_target_pos;
  u8 revive_count;
  u8 escape_attempts;
  u8 move_anim_id;
  u8 switch_interrupt_count;
  u8 current_fainted_mon_id;
  u8 flags;
  u8 SwitchOutInterruptingMonIDs[6];
  u8 RevivedMonIDs[24];
  u8 FaintedMonFlag[24];
  u8 WasInBattleFlag[24];
  u8 ClientSwitchCount[4];
  ActionOrderWork action_order_work[6];
  ActionOrderWork temp_action_order_work;
  TargetSet *original_targets;
  TargetSet *targets;
  TargetSet *allies;
  TargetSet *enemies;
  TargetSet *damaged_mons;
  TargetSet *move_steal_targets;
  TargetSet *temp_targets;
  CalcDamageRecord *ally_calc_damage;
  CalcDamageRecord *enemy_calc_damage;
  TargetSetGroup target_sets[7];
  int target_set_id;
  TargetSet switching_in_mons;
  MoveParam *move_param;
  MoveParam *original_move_param;
  PosPoke posPoke;
  HandlerParam_StringSetup str;
  CalcExpWork calc_exp_work[6];
  EventWorkStack event_work_stack;
  HEManager heManager;
  MoveDamageRec move_damage_record;
  u16 prev_used_move;
  ActionIgnoreReason action_ignore_reason;
  EffectivenessCounter effectiveness_counter;
  EffectivenessRecorder effectiveness_recorder;
  u8 flowFlags[4];
  u8 temp_storage[320];
  int pokestar_result;
};

#endif
