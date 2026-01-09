#ifndef __BATTLE_COMMON_H
#define __BATTLE_COMMON_H

#include "swantypes.h"

STRUCT_DECLARE(BattleFieldStatus)
STRUCT_DECLARE(TrainerBattleSetup)
STRUCT_DECLARE(BtlSetup)
STRUCT_DECLARE(TrainerData)
STRUCT_DECLARE(RandSet)
STRUCT_DECLARE(EscapeInfo)

ENUM_DECLARE(TypeEffectiveness)
ENUM_DECLARE(SimpleEffectiveness)
ENUM_DECLARE(BattleStyle)
ENUM_DECLARE(BtlType)
ENUM_DECLARE(BtlSetupFlag)
ENUM_DECLARE(PokeType)

#include "gfl/str/gfl_strbuf.h"
#include "pml/poke_party.h"
#include "system/game_data.h"
#include "battle/btl_result.h"

C_DECL_BEGIN

int BattleRandom(unsigned int a1);
int GetBoostFromStatStage(__int16 a1, int a2);
unsigned int Calc_MulRatio(int result, int a2);
bool RollCritical(int a1);
TypeEffectiveness GetTypeEffectiveness(int a1, int a2);
int GetTypeEffectivenessVsMon(int a1, int a2);
TypeEffectiveness GetTypeEffectivenessMultiplier(int a1, int a2);
unsigned int CalcBaseDamage(int power, int attack, int level, unsigned int defense);
unsigned int TypeEffectivenessPowerMod(unsigned int result, unsigned int a2);
int GetTypeWeaknesses(int a1, int a2);
SimpleEffectiveness ConvertTypeEffectivenessToSimpleEffectiveness(TypeEffectiveness a1);
bool RollEffectChance(unsigned int a1);
int GetGreaterValue(int result, int a2);
unsigned int fixed_round(int a1, int a2);
unsigned int GetRatioOverZero(int a1, int a2);
unsigned int MultiplyValueByRatio(int a1, int a2);
unsigned int RandomInRange(unsigned int a1, unsigned int a2);
unsigned int RollMultiHitHits(unsigned int result);

C_DECL_END

enum TypeEffectiveness
#ifdef __cplusplus
: u32
#endif
{
  EFFECTIVENESS_IMMUNE = 0x0,
  EFFECTIVENESS_1_4 = 0x1,
  EFFECTIVENESS_1_2 = 0x2,
  EFFECTIVENESS_1 = 0x3,
  EFFECTIVENESS_2 = 0x4,
  EFFECTIVENESS_4 = 0x5,
};

enum SimpleEffectiveness
#ifdef __cplusplus
: u32
#endif
{
  EFF_NONE = 0x0,
  EFF_NEUTRAL = 0x1,
  EFF_SUPEREFFECTIVE = 0x2,
  EFF_NOTVERYEFFECTIVE = 0x3,
};

enum BattleStyle
#ifdef __cplusplus
: u32
#endif
{
  BTL_STYLE_SINGLE = 0x0,
  BTL_STYLE_DOUBLE = 0x1,
  BTL_STYLE_TRIPLE = 0x2,
  BTL_STYLE_ROTATION = 0x3,
};

enum BtlType
#ifdef __cplusplus
: u32
#endif
{
  BtlType_Wild = 0x0,
  BtlType_Trainer = 0x1,
  BtlType_Facility = 0x2,
  BtlType_Online = 0x3,
  BtlType_Demo = 0x4,
  BtlType_Max = 0x5,
};

enum BattleSetupType
{
  TYPE_STANDARD = 0x0,
  TYPE_NET_MULTI = 0x1,
  TYPE_NET_MULTI_VS_AI = 0x2,
  TYPE_AI_MULTI = 0x3,
  TYPE_AI_1V2 = 0x4,
  TYPE_AI_MULTI_VS_WILD = 0x5,
} SWAN_PACKED;

enum BtlSetupFlag
#ifdef __cplusplus
: u32
#endif
{
  BTL_SETUP_FLAG_FISHING = 0x1,
  BTL_SETUP_FLAG_PC_NAME_DISCOVERED = 0x2,
  BTL_SETUP_FLAG_LEGENDARY = 0x4,
  BTL_SETUP_FLAG_ROAMING = 0x8,
  BTL_SETUP_FLAG_DREAM_WORLD = 0x10,
  BTL_SETUP_FLAG_DOUBLE = 0x20,
  BTL_SETUP_FLAG_ALL_BOXES_FULL = 0x40,
  BTL_SETUP_FLAG_STATIC_ENCOUNTER = 0x80,
  BTL_SETUP_FLAG_NO_AUTO_DEFEAT = 0x100,
  BTL_SETUP_FLAG_NPOKE = 0x2000,
  BTL_SETUP_FLAG_PHENOMENON = 0x4000,
  BTL_SETUP_FLAG_MUSHROOM = 0x8000,
  BTL_SETUP_FLAG_NO_CATCH_KYUREM = 0x10000,
};

enum PokeType
#ifdef __cplusplus
: u32
#endif
{
  TYPE_NORMAL = 0x0,
  TYPE_FIGHT = 0x1,
  TYPE_FLY = 0x2,
  TYPE_POIS = 0x3,
  TYPE_GROUND = 0x4,
  TYPE_ROCK = 0x5,
  TYPE_BUG = 0x6,
  TYPE_GHOST = 0x7,
  TYPE_STEEL = 0x8,
  TYPE_FIRE = 0x9,
  TYPE_WATER = 0xA,
  TYPE_GRASS = 0xB,
  TYPE_ELEC = 0xC,
  TYPE_PSY = 0xD,
  TYPE_ICE = 0xE,
  TYPE_DRAGON = 0xF,
  TYPE_DARK = 0x10,
  TYPE_NULL = 0x11,
};

struct BattleFieldStatus
{
  u32 BattleBGID;
  u32 BattlePedestalID;
  u8 BtlWeather;
  u8 Season;
  u16 ZoneID;
  u8 Hour;
  u8 Minute;
};

struct TrainerBattleSetup
{
  u32 TrID;
  u32 TrClass;
  u32 TrAIBits;
  u16 TrItems[4];
  StrBuf *TrainerName;
  u16 winMessage[4];
  u16 loseMessage[4];
};

struct BtlSetup
{
  BtlType btlType;
  BattleStyle BtlStyle;
  BattleFieldStatus m_FieldStatus;
  u16 BattleBGMID;
  u16 WinBGMID;
  int field_1C;
  char commMode;
  char commPos;
  BattleSetupType BtlSetupType;
  char IsRecordedBattle;
  PokeParty *Parties[4];
  int m_PlayerInfo[4];
  u8 chatotVolume[4];
  TrainerBattleSetup *TrainerSetups[4];
  int field_58;
  int field_5C;
  int field_60;
  int field_64;
  int PWTLoseMsg;
  int PWTWinMsg;
  GameData *m_GameData;
  TrainerData *m_TrainerData;
  BagSaveData *m_ItemWork;
  int bagCursorData;
  int m_Dex;
  int m_RecordData;
  int field_88;
  int field_8C;
  u8 launcherSetup[6];
  char field_96;
  char field_97;
  char BadgeCount;
  char field_99;
  char field_9A;
  char field_9B;
  int field_9C;
  u16 field_A0;
  u16 field_A2;
  int EarnedMoney;
  BattleResult battleResult;
  char CapturedPkmIdx;
  char field_AD;
  u16 field_AE;
  void *recBuffer;
  int field_B4;
  int field_B8;
  int field_BC;
  int field_C0;
  int field_C4;
  int field_C8;
  int field_CC;
  u16 HPSum;
  u8 CurrentTurn;
  u8 SwitchCount;
  u8 NoEffectHits;
  u8 SuperEffectiveHits;
  u8 NotVeryEffectiveHits;
  u8 OpponentNoEffectHits;
  u8 OpponentNotVeryEffectiveHits;
  u8 BattlesWon;
  u8 OpponentFainted;
  u8 AllyFainted;
  u8 UniqueMovesUsed;
  char field_DD;
  char field_DE;
  u8 PokestarScenario;
  int field_E0;
  u8 PartyState[4][6];
  int field_FC;
  int TeamHPPercentage[4];
  char field_110;
  int field_114;
  int field_118;
  int field_11C;
  int field_120;
  int field_124;
  char field_128;
  u8 field_129;
  int field_12C;
  int field_130;
  int recPlayCancel;
  u16 LoseBGMID;
  u16 StrangeEndingBGMID;
  u8 KeySystemLevelAdjust;
  char field_13D;
  char field_13E;
  char field_13F;
  int field_140;
  int field_144;
  int field_148;
};

struct TrainerData
{
  u8 Flags;
  u8 Class;
  u8 BattleType;
  u8 PokemonCount;
  u16 Items[4];
  u32 AI;
  u8 Healer;
  u8 Money;
  u16 ItemAfterBattle;
};

struct RandSet
{
  unsigned __int64 seed;
  unsigned __int64 mul;
  unsigned __int64 add;
};

struct EscapeInfo
{
  u32 count;
  u8 clientID[4];
};

#endif
