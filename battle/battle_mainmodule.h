#ifndef __BATTLE_MAINMODULE_H
#define __BATTLE_MAINMODULE_H

#include "swantypes.h"

STRUCT_DECLARE(MainModule)
STRUCT_DECLARE(PokeCon)
STRUCT_DECLARE(TrainerParam)
STRUCT_DECLARE(BtlNetServerNotification)
STRUCT_DECLARE(BattleProc)
STRUCT_DECLARE(TriplesAttackRange)

#include "gfl/core/gfl_heap.h"
#include "battle/battle_client.h"
#include "battle/battle_common.h"
#include "battle/battle_field.h"
#include "battle/battle_mon.h"
#include "battle/battle_recorder.h"
#include "battle/battle_server.h"

C_DECL_BEGIN

BattleStyle MainModule_GetBattleStyle(MainModule *a1);
unsigned int MainModule_AreMoveAnimationsEnabled(MainModule *a1);
int MainModule_GetBadgeCount(MainModule *a1);
bool MainModule_IsSwitchMode(MainModule *a1);
bool MainModule_IsExpGainEnabled(MainModule *a1);
int MainModule_IsOnlineBattle(MainModule *a1);
bool MainModule_IsFrontPos(MainModule *a1, unsigned int a2);
BtlType MainModule_GetBattleType(MainModule *a1);
int MainModule_GetBattleSetupType(MainModule *a1);
int MainModule_GetCommMode(MainModule *a1);
bool MainModule_IsMultiBattle(MainModule *a1);
int MainModule_GetWinBGM(MainModule *a1);
int MainModule_GetLoseBGM(MainModule *a1);
int MainModule_GetEscapeMode(MainModule *a1);
BattleFieldStatus *MainModule_GetFieldStatus(MainModule *a1);
void *MainModule_GetPlayerStatus(MainModule *a1);
int MainModule_IsRegisteredInPokedex(MainModule *a1, BattleMon *a2);
int MainModule_GetPokedexRegisteredCount(MainModule *a1);
GameData *MainModule_GetGameData(MainModule *a1);
u8 MainModule_StoreTargetPositionsAndGetNumTargets(MainModule *a1, __int16 a2, u8 *targetPositions);
int MainModule_GetNumBattlePositionsOfClient(MainModule *a1, int a2);
int MainModule_DoesClientExist(MainModule *a1, unsigned int a2);
int MainModule_GetClientSide(MainModule *a1, char a2);
bool MainModule_IsClientIDOnPlayerSide(MainModule *a1, int a2);
unsigned int MainModule_GetClientPokePos(MainModule *a1, int clientID, int partyIndex);
int MainModule_GetEnemyBattlePosFromSlot(MainModule *a1, char currentPos, char a3);
int MainModule_GetAllyBattlePos(MainModule *a1, int a2);
int MainModule_BattlePosToClientID(MainModule *a1, int a2);
unsigned int MainModule_PokeIDToClientID(int a1);
int MainModule_StoreMonIDsOnFieldAndGetCount(MainModule *a1, PokeCon *a2, __int16 currentPosWithTargetType, u8 *ids);
unsigned int MainModule_PokeIDToPokePos(MainModule *a1, PokeCon *a2, unsigned int a3);
int MainModule_PokeIDToViewPos(MainModule *a1, int a2, unsigned int a3);
int MainModule_GetNumBattlePosOfClient(MainModule *a1, int a2);
u8 *MainModule_BattlePosToClientIDAndPartyIndex(MainModule *a1, int battlePos, u8 *clientID, u8 *partyIndex);
int MainModule_BattlePosToViewPos(MainModule *a1, int a2);
int MainModule_ViewPosToBattlePos(MainModule *a1, char a2);
bool MainModule_IsNotTrainerOrWildBattle(MainModule *a1);
PokeParty *MainModule_GetPokeParty(MainModule *a1, int a2);
PokeParty *MainModule_GetAllyPokeParty(MainModule *a1, char a2);
bool MainModule_IsAllyInMultiBattle(MainModule *a1, char a2);
bool MainModule_IsPlayerAlly(MainModule *a1);
int MainModule_GetPlayerClientID(MainModule *a1);
int MainModule_GetPartnerClientID(MainModule *a1);
int MainModule_GetAllyClientID(MainModule *a1, char a2);
bool MainModule_IsAllyClientID(int a1, int a2);
int MainModule_GetPlayerOpponentClientID(MainModule *a1, int a2);
u8 MainModule_GetOpponentClientID(MainModule *a1, char a2, int a3);
void MainModule_SubItem(MainModule *a1, int a2, u16 a3);
void MainModule_AddItem(MainModule *a1, int a2, u16 a3);
BagSaveData *MainModule_GetItemWork(MainModule *a1);
int MainModule_GetBagCursorData(MainModule *a1);
BattleMon *MainModule_GetIllusionDisguise(MainModule *a1, int a2, int a3);
int MainModule_GetNumClientFieldPositions(MainModule *a1, char a2);
TriplesAttackRange *MainModule_GetTriplesAttackRange(int a1);
bool MainModule_IsAllyMonID(unsigned int a1, unsigned int a2);
int MainModule_GetTurnCount(MainModule *a1);
int MainModule_IsWonderLauncherEnabled(MainModule *a1);
int MainModule_IsBagEnabled(MainModule *a1);
bool MainModule_IsCompetitiveBattleType(MainModule *a1);
BtlSetup *MainModule_GetBtlSetup(MainModule *a1);

void PokeCon_Init(PokeCon *a1, MainModule *a2, int a3);
void PokeCon_Free(PokeCon *a1);
void PokeCon_SetParty(PokeCon *a1, MainModule *a2, int a3);
void PokeCon_Clear(PokeCon *a1);
void PokeCon_UpdateParty(PokeCon *a1, MainModule *a2, int a3, int a4);
void PokeCon_UpdatePartyStartOrder(PokeCon *a1, MainModule *a2, int a3);
PokeParty *PokeCon_GetSrcParty(PokeCon *a1, int a2);
int PokeCon_GetPartyIndexOfMon(PokeCon *a1, int a2, int a3);
BattleMon *PokeCon_GetMonDataAtBattlePos(PokeCon *a1, int a2);
BattleMon *PokeCon_GetClientPokeData(PokeCon *a1, int a2, unsigned int a3);
BattleMon *PokeCon_GetClientMonData(PokeCon *a1, int a2, unsigned int a3);
BattleMon *PokeCon_GetBattleMon(PokeCon *a1, int a2);
BattleMon *PokeCon_GetBattleMonConst(PokeCon *a1, int a2);
BattleParty *PokeCon_GetBattleParty(PokeCon *a1, int a2);
BattleParty *PokeCon_GetBattlePartyConst(PokeCon *a1, int a2);
int PokeCon_GetAlivePartyCount(PokeCon *a1, int a2);

C_DECL_END

struct PokeCon
{
  MainModule *mainModule;
  BattleParty party[4];
  PokeParty *srcParty[4];
  BattleMon *ActiveBattleMon[24];
  int fForServer;
};

struct TrainerParam
{
  int pTrainerInfo;
  int Name;
  __int16 Class;
  __int16 ID;
  int AIFlags;
  u16 Items[4];
  int winMessage;
  int field_1C;
  int loseMessage;
  int field_24;
};

struct BtlNetServerNotification
{
  RandSet rand;
  u16 debugFlag;
  u16 gameLimitTime;
  u16 commandLimitTime;
  u8 msgSpeed;
  u8 flags;
};

struct BattleProc
{
  int initFunc;
  int loopFunc;
  int work;
  int seq;
};

struct TriplesAttackRange
{
  u16 numEnemies;
  u16 numAllies;
  u8 enemyPos[3];
  u8 allyPos[3];
};

struct __attribute__((aligned(32))) MainModule
{
  BtlSetup *btlSetup;
  void *btlvCore;
  BtlServerWk *server[2];
  BtlClientWk *clients[4];
  TrainerParam trainerParam[4];
  int playerInfo;
  u8 fClientQuit[4];
  PokeCon pokeconClient;
  PokeCon pokeconServer;
  PokeParty *srcParty[4];
  PokeParty *srcPartyForServer[4];
  PokeParty *tempParty;
  BattleField *battleField;
  PartyPkm *IllusionDisguiseMon;
  int AIDataContainer;
  BattleRecReader recReader;
  int chatotChatterBlk[4];
  RandSet rand;
  BtlNetServerNotification serverNotif;
  unsigned __int8 ClientIDOfBattlePos[6];
  int winMoney;
  int bonusMoney;
  int loseMoney;
  int msgSpeed;
  __int16 gameLimitTime;
  __int16 CmdLimitTime;
  int serverResult;
  EscapeInfo escapeInfo;
  BattleProc proc;
  int subSeq;
  int mainLoop;
  HeapID heapID;
  char sendClientID;
  char numClients;
  char playerClientID;
  char slot0pos;
  char isServer;
  char changeMode;
  char MultiAIDataSeq;
  char MultiAIClientNum;
  char MultiAIClientID;
  char flags;
  void *pokestarScenario;
  int pokestarWork;
  int pokestarCutin;
};

#endif
