// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmanna@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include <vector>
#include "./PooSweeperMove.h"

// _____________________________________________________________________________
void PooSweeperMove::set(size_t y, size_t x, int z) {
  row = y;
  col = x;
  if (z == 1) {
    type = TOGGLE_MARK;
  } else if (z == 0) {
    type = REVEAL;
  }
}

