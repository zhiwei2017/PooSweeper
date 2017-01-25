// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef PROJEKT_POOSWEEPERDISPLAY_H_
#define PROJEKT_POOSWEEPERDISPLAY_H_

#include "./PooSweeperStateBase.h"
#include "./PooSweeperState.h"
#include "./PooSweeperDisplayBase.h"

class PooSweeperDisplayBase;
// Class for showing a state of the game on the screen.
class PooSweeperDisplay : public PooSweeperDisplayBase {
 public:
  PooSweeperStateBase* state = new PooSweeperState;
  void show(const PooSweeperStateBase* state) const;
  void title(const PooSweeperStateBase* state) const;
};
#endif  // PROJEKT_POOSWEEPERDISPLAY_H_
