#ifndef __BATTLE_SERVER_H
#define __BATTLE_SERVER_H

#include "swantypes.h"

STRUCT_DECLARE(BtlServerWk)
STRUCT_DECLARE(ServerClientWk)
STRUCT_DECLARE(ResultContext)
STRUCT_DECLARE(ServerClientAction)
STRUCT_DECLARE(ServerCommandQueue)

#include "gfl/core/gfl_heap.h"
#include "gfl/str/gfl_strbuf.h"
#include "battle/battle_common.h"
#include "battle/battle_mainmodule.h"
#include "battle/battle_recorder.h"
#include "battle/battle_serverflow.h"

struct ServerClientWork
{
  int adapter;
  BattleParty *party;
  u8 partyCount;
  u8 numBattlePositions;
  u8 isLocalClient;
  u8 id;
};

struct ResultContext
{
  u16 clientID;
  u16 resultCode;
};

struct ServerClientAction
{
  BattleAction param[4][3];
  u8 count[4];
};

struct ServerCommandQueue
{
  u32 writePtr;
  u32 readPtr;
  u8 buffer[3000];
};

struct __attribute__((packed)) BtlServerWk
{
  int mainProc;
  int seq;
  int intrSeq;
  MainModule *mainModule;
  int pokeCon;
  ServerClientWork clientWork[4];
  ServerFlow *serverFlow;
  int serverFlowResult;
  int bagMode;
  RandSet rand;
  BtlRecTool recTool;
  ResultContext resultContext;
  StrBuf *strBuf;
  EscapeInfo *escapeInfo;
  ServerClientAction clientAction;
  int exitTimer;
  char NextEnemyForSwitchMode;
  char quitStep;
  __attribute__((aligned(4))) ServerCommandQueue queueBody;
  ServerCommandQueue *queue;
  u8 switchPositions[6];
  char numSwitchRequests;
  u8 forfeitClientID[4];
  char forfeitClientCount;
  HeapID heapID;
};

#endif
