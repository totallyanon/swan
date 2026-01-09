#ifndef __BATTLE_CLIENT_H
#define __BATTLE_CLIENT_H

#include "swantypes.h"

STRUCT_DECLARE(BtlClientWk)
STRUCT_DECLARE(RotationMoveSelectMon)
STRUCT_DECLARE(RotationMoveSelect)
STRUCT_DECLARE(PokeSelectParam)
STRUCT_DECLARE(PokeSelectResult)
STRUCT_DECLARE(Btlv_StringParam)

#include "battle/battle_field.h"
#include "battle/battle_mainmodule.h"
#include "battle/battle_mon.h"
#include "battle/battle_recorder.h"
#include "battle/battle_server.h"

struct RotationMoveSelectMon
{
  BattleMon *mon;
  u8 isMoveUsable[4];
};

struct RotationMoveSelect
{
  RotationMoveSelectMon mons[3];
  BattleAction *action;
  BattleAction *action2;
};

struct PokeSelectParam
{
  BattleParty *party;
  u8 numToSelect;
  u8 selectionStatus[6];
  u8 PokeListMode;
};

struct PokeSelectResult
{
  u8 selIdx[3];
  u8 outPokeIdx[3];
  u8 count;
  char numToSelect;
  char fCancel;
};

struct Btlv_StringParam
{
  u16 strID;
  u8 wait;
  u8 strTypeAndArgCount;
  int args[9];
};

struct __attribute__((packed)) __attribute__((aligned(4))) BtlClientWk
{
  MainModule *mainModule;
  PokeCon *pokeCon;
  BattleMon *currentMon;
  BattleAction *currentAction;
  BtlRecWk *recData;
  int recReader;
  RecPlayerControl recPlayer;
  int (*mainProc)(BtlClientWk *) __attribute__((aligned(4)));
  EscapeInfo escapeInfo;
  BattleField *battleField;
  RandSet rand;
  void *adapter;
  void *btlvCore;
  Btlv_StringParam strParam;
  Btlv_StringParam secondaryStrParam;
  BtlServerWk *cmdCheckServer;
  RotationMoveSelect UsableMovesForMonsOnField;
  u8 PrevRotation;
  int (*subproc)(BtlClientWk *, int *) __attribute__((aligned(4)));
  int subseq;
  int (*ActionSelectProc)(BtlClientWk *a1, unsigned int *a2);
  unsigned int ActionSelectSeq;
  void *returnDataPtr;
  int returnDataSize;
  int dummyReturnData;
  u16 cmdLimitTime;
  u16 gameLimitTime;
  u16 AIBagItems[4];
  void *VM;
  RandSet aiRand;
  u8 bestMonToSwitchIn[6];
  u8 doTrainerMessage[4];
  __attribute__((aligned(4))) BattleParty *actPokeParty;
  u8 numBattlePositions;
  u8 procPokeIdx;
  u8 prevPokeIdx;
  u8 firstPokeIdx;
  u8 fStdMsgChanged;
  u8 basePos;
  __attribute__((aligned(4))) BattleAction actionParam[3];
  u8 LauncherCost[3];
  __attribute__((aligned(2))) int cmdQueue;
  int ServerCmdArgs[16];
  int serverCmd;
  int ServerCmdProc;
  int ServerCmdSeq;
  PokeSelectParam pokeSelectParam;
  PokeSelectResult pokeSelectResult;
  __attribute__((aligned(2))) HeapID TrainerMsgHeapID;
  u16 EnemyMonHP;
  u16 AITrainerMsgID;
  u16 SelItemWork[3];
  u8 myID;
  u8 myType;
  u8 state;
  u8 commWaitInfoOn;
  u8 bagMode;
  u8 WonderLauncherEnergy;
  u8 changeEscapeCode;
  u8 forceQuitActionSelect;
  u8 cmdCheckTimingCode;
  u8 currentActionCount;
  u8 moveInfoPokeIdx;
  u8 moveInfoMoveIdx;
  u8 actSelectFlags;
  u8 myChangePokeCount;
  u8 NumValidSwitchIns;
  u8 clientTurnCount;
  u8 myChangePokePos[6];
  u8 pokestarSeqWork[0x8C];
  u8 commonWait;
};

#endif
