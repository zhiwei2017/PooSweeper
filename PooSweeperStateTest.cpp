// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmanna@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include <vector>
#include "./PooSweeperState.h"

// _____________________________________________________________________________
TEST(PooSweeperStateTest, squareInit) {
  PooSweeperStateBase* POO = new PooSweeperState;
  dynamic_cast<PooSweeperState*>(POO)->squareInit(2, 2);
  ASSERT_FALSE(dynamic_cast<PooSweeperState*>(POO)->poo(1, 1));
}

// _____________________________________________________________________________
TEST(PooSweeperStateTest, initialize) {
  PooSweeperStateBase* POO = new PooSweeperState;
  dynamic_cast<PooSweeperState*>(POO)->initialize(9, 9, 10);
  ASSERT_EQ(10, dynamic_cast<PooSweeperState*>(POO)->numPoos());
}

// _____________________________________________________________________________
TEST(PooSweeperStateTest, PooSweeperState) {
  PooSweeperStateBase* POO = new PooSweeperState;
  dynamic_cast<PooSweeperState*>(POO)->initialize(16, 30, 99);
  ASSERT_EQ(PooSweeperStateBase::UNREVEALED,
            dynamic_cast<PooSweeperState*>(POO)->getCellInfo(15, 16));
  ASSERT_EQ(PooSweeperStateBase::ONGOING,
            dynamic_cast<PooSweeperState*>(POO)->status());
  ASSERT_EQ(16,
            dynamic_cast<PooSweeperState*>(POO)->numRows());
  ASSERT_EQ(30,
            dynamic_cast<PooSweeperState*>(POO)->numCols());
  ASSERT_EQ(0,
            dynamic_cast<PooSweeperState*>(POO)->numRevealed());
  ASSERT_EQ(0,
            dynamic_cast<PooSweeperState*>(POO)->numMarked());
  ASSERT_EQ(-1,
            dynamic_cast<PooSweeperState*>(POO)->check_yx(16, 30));
}
