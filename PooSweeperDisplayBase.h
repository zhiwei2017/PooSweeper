// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef PROJEKT_POOSWEEPERDISPLAYBASE_H_
#define PROJEKT_POOSWEEPERDISPLAYBASE_H_

#include "./PooSweeperStateBase.h"

class PooSweeperDisplayBase;
extern PooSweeperDisplayBase* DISPLAY;

// Class for showing a state of the game on the screen.
class PooSweeperDisplayBase {
 public:
  virtual void show(const PooSweeperStateBase* state) const = 0;
};
#endif  // PROJEKT_POOSWEEPERDISPLAYBASE_H_
