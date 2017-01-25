// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef PROJEKT_POOSWEEPERGAME_H_
#define PROJEKT_POOSWEEPERGAME_H_

#include <string>
#include "./PooSweeperStateBase.h"
#include "./PooSweeperState.h"
#include "./PooSweeperDisplayBase.h"
#include "./PooSweeperDisplay.h"
#include "./PooSweeperMove.h"

class PooSweeperGame {
 public:
  void structure();
  void game();
  void end();
  PooSweeperStateBase* state = new PooSweeperState;
  PooSweeperDisplayBase* DISPLAY = new PooSweeperDisplay;
  std::string level;
  PooSweeperMove move;
};
#endif  // PROJEKT_POOSWEEPERGAME_H_
