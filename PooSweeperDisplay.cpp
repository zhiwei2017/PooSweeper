// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "./PooSweeperStateBase.h"
#include "./PooSweeperState.h"
#include "./PooSweeperDisplay.h"
#include "./PooSweeperDisplayBase.h"

// ____________________________________________________________________________
void PooSweeperDisplay::show(const PooSweeperStateBase* state) const {
  title(state);
  for (int i = 0; i < dynamic_cast<const PooSweeperState*>(state)->numRows();
       i++) {
    for (int j = 0; j < dynamic_cast<const PooSweeperState*>(state)->numCols();
         j++) {
      if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
          == PooSweeperStateBase::UNREVEALED
          && dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
          != PooSweeperStateBase::MARKED) {
        printf("\x1b[%d;%dH\x1b[1m?\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::MARKED) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[31mF\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_ZERO) {
        printf("\x1b[%d;%dH ", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_ONE) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[30m1\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_TWO) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[31m2\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_THREE) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[32m3\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_FOUR) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[35m4\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_FIVE) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[34m5\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_SIX) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[35m6\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_SEVEN) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[36m7\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_EIGHT) {
        printf("\x1b[%d;%dH\x1b[1m\x1b[31m8\x1b[0m", i * 2 + 6, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      } else if (dynamic_cast<const PooSweeperState*>(state)->getCellInfo(i, j)
                 == PooSweeperStateBase::REVEALED_POO) {
        if (dynamic_cast<const PooSweeperState*>(state)->marked(i, j) == true) {
          printf("\x1b[%d;%dH\x1b[1m\x1b[30m@\x1b[0m", i * 2 + 6, j * 3 + 20);
        } else {
          printf("\x1b[%d;%dH\x1b[7m\x1b[30m@\x1b[0m", i * 2 + 6, j * 3 + 20);
        }
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 20);
        printf("\x1b[%d;%dH\x1b[36m[\x1b[0m", i * 2 + 6, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m]\x1b[0m", i * 2 + 6, j * 3 + 21);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 19);
        printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", i * 2 + 7, j * 3 + 21);
      }
    }
  }
}

// ____________________________________________________________________________
void PooSweeperDisplay::title(const PooSweeperStateBase* state) const {
  printf("\x1b[%d;%dH\x1b[30mP\x1b[0m", 3, 23);
  printf("\x1b[%d;%dH\x1b[30mO\x1b[0m", 3, 24);
  printf("\x1b[%d;%dH\x1b[30mO\x1b[0m", 3, 25);
  printf("\x1b[%d;%dH\x1b[30mS\x1b[0m", 3, 26);
  printf("\x1b[%d;%dH\x1b[30mW\x1b[0m", 3, 27);
  printf("\x1b[%d;%dH\x1b[30mE\x1b[0m", 3, 28);
  printf("\x1b[%d;%dH\x1b[30mE\x1b[0m", 3, 29);
  printf("\x1b[%d;%dH\x1b[30mP\x1b[0m", 3, 30);
  printf("\x1b[%d;%dH\x1b[30mE\x1b[0m", 3, 31);
  printf("\x1b[%d;%dH\x1b[30mR\x1b[0m", 3, 32);
  printf("\x1b[%d;%dH\x1b[30m(\x1b[0m", 3, 34);
  printf("\x1b[%d;%dH\x1b[30mb\x1b[0m", 3, 35);
  printf("\x1b[%d;%dH\x1b[30my\x1b[0m", 3, 36);
  printf("\x1b[%d;%dH\x1b[30m \x1b[0m", 3, 37);
  printf("\x1b[%d;%dH\x1b[30mz\x1b[0m", 3, 38);
  printf("\x1b[%d;%dH\x1b[30mz\x1b[0m", 3, 39);
  printf("\x1b[%d;%dH\x1b[30m2\x1b[0m", 3, 40);
  printf("\x1b[%d;%dH\x1b[30m0\x1b[0m", 3, 41);
  printf("\x1b[%d;%dH\x1b[30m)\x1b[0m", 3, 42);

  // print the number of marked squares
  printf("\x1b[%d;%dH\x1b[30mM\x1b[0m", 6, 3);
  printf("\x1b[%d;%dH\x1b[30ma\x1b[0m", 6, 4);
  printf("\x1b[%d;%dH\x1b[30mr\x1b[0m", 6, 5);
  printf("\x1b[%d;%dH\x1b[30mk\x1b[0m", 6, 6);
  printf("\x1b[%d;%dH\x1b[30me\x1b[0m", 6, 7);
  printf("\x1b[%d;%dH\x1b[30md\x1b[0m", 6, 8);
  printf("\x1b[%d;%dH\x1b[30m:\x1b[0m", 6, 9);
  printf("\x1b[%d;%dH\x1b[30m%lu\x1b[0m", 6, 10,
         dynamic_cast<const PooSweeperState*>(state)->numMarked());

  // print the score
  printf("\x1b[%d;%dH\x1b[34mS\x1b[0m", 12, 3);
  printf("\x1b[%d;%dH\x1b[34mc\x1b[0m", 12, 4);
  printf("\x1b[%d;%dH\x1b[34mo\x1b[0m", 12, 5);
  printf("\x1b[%d;%dH\x1b[34mr\x1b[0m", 12, 6);
  printf("\x1b[%d;%dH\x1b[34me\x1b[0m", 12, 7);
  printf("\x1b[%d;%dH\x1b[34m:\x1b[0m", 12, 8);

  // print the number of Poos
  printf("\x1b[%d;%dH\x1b[30mP\x1b[0m", 9, 3);
  printf("\x1b[%d;%dH\x1b[30mo\x1b[0m", 9, 4);
  printf("\x1b[%d;%dH\x1b[30mo\x1b[0m", 9, 5);
  printf("\x1b[%d;%dH\x1b[30ms\x1b[0m", 9, 6);
  printf("\x1b[%d;%dH\x1b[30mN\x1b[0m", 9, 7);
  printf("\x1b[%d;%dH\x1b[30mu\x1b[0m", 9, 8);
  printf("\x1b[%d;%dH\x1b[30mm\x1b[0m", 9, 9);
  printf("\x1b[%d;%dH\x1b[30m:\x1b[0m", 9, 10);
  printf("\x1b[%d;%dH\x1b[30m%lu\x1b[0m", 9, 11,
         dynamic_cast<const PooSweeperState*>(state)->numPoos());

  // print the right now game status
  printf("\x1b[%d;%dH\x1b[30mG\x1b[0m", 15, 3);
  printf("\x1b[%d;%dH\x1b[30ma\x1b[0m", 15, 4);
  printf("\x1b[%d;%dH\x1b[30mm\x1b[0m", 15, 5);
  printf("\x1b[%d;%dH\x1b[30me\x1b[0m", 15, 6);
  printf("\x1b[%d;%dH\x1b[30m \x1b[0m", 15, 7);
  printf("\x1b[%d;%dH\x1b[30mS\x1b[0m", 15, 8);
  printf("\x1b[%d;%dH\x1b[30mt\x1b[0m", 15, 9);
  printf("\x1b[%d;%dH\x1b[30ma\x1b[0m", 15, 10);
  printf("\x1b[%d;%dH\x1b[30mt\x1b[0m", 15, 11);
  printf("\x1b[%d;%dH\x1b[30mu\x1b[0m", 15, 12);
  printf("\x1b[%d;%dH\x1b[30ms\x1b[0m", 15, 13);
  printf("\x1b[%d;%dH\x1b[30m:\x1b[0m", 15, 14);
  if (dynamic_cast<const PooSweeperState*>(state)->status() ==
      PooSweeperStateBase::WON) {
    printf("\x1b[%d;%dHWON!!! ", 16, 6);
    for (int i = 0; i <
         dynamic_cast<const PooSweeperState*>(state)->numRows();
         i++) {
      for (int j = 0; j <
           dynamic_cast<const PooSweeperState*>(state)->numCols(); j++) {
        if (dynamic_cast<const PooSweeperState*>(state)->poo(i, j) == true) {
          dynamic_cast<const PooSweeperState*>(state)->win();
        }
      }
    }
  } else if (dynamic_cast<const PooSweeperState*>(state)->status() ==
      PooSweeperStateBase::ONGOING) {
    printf("\x1b[%d;%dHONGOING", 16, 6);
  } else {
    printf("\x1b[%d;%dHLOST!!!", 16, 6);
  }

  // print the help
  printf("\x1b[%d;%dH'q'---leave", 23, 3);

  // print the structure
  for (int j = 0; j < dynamic_cast<const PooSweeperState*>(state)->numCols();
       j++) {
    printf("\x1b[%d;%dH\x1b[36m=\x1b[0m", 4, j * 3 + 20);
    printf("\x1b[%d;%dH\x1b[36m=\x1b[0m", 4, j * 3 + 19);
    printf("\x1b[%d;%dH\x1b[36m=\x1b[0m", 4, j * 3 + 21);
    printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", 5, j * 3 + 20);
    printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", 5, j * 3 + 19);
    printf("\x1b[%d;%dH\x1b[36m~\x1b[0m", 5, j * 3 + 21);
    printf("\x1b[%d;%dH\x1b[36m=\x1b[0m",
           static_cast<int>(dynamic_cast<const PooSweeperState*>(state)->
                            numRows()) * 2 + 6,
           j * 3 + 20);
    printf("\x1b[%d;%dH\x1b[36m=\x1b[0m",
           static_cast<int>(dynamic_cast<const PooSweeperState*>(state)->
                            numRows()) * 2 + 6,
           j * 3 + 19);
    printf("\x1b[%d;%dH\x1b[36m=\x1b[0m",
           static_cast<int>(dynamic_cast<const PooSweeperState*>(state)->
                            numRows()) * 2 + 6,
           j * 3 + 21);
    for (int i = 0; i < dynamic_cast<const PooSweeperState*>(state)->numRows();
         i++) {
      printf("\x1b[%d;%dH\x1b[36m|\x1b[0m", i * 2 + 7, 18);
      printf("\x1b[%d;%dH\x1b[36m|\x1b[0m", i * 2 + 7,
             static_cast<int>(dynamic_cast<const PooSweeperState*>(state)->
                              numCols()) * 3 + 19);
      printf("\x1b[%d;%dH\x1b[36m|\x1b[0m", i * 2 + 5, 18);
      printf("\x1b[%d;%dH\x1b[36m|\x1b[0m", i * 2 + 5,
             static_cast<int>(dynamic_cast<const PooSweeperState*>(state)->
                              numCols()) * 3 + 19);
      printf("\x1b[%d;%dH\x1b[36m|\x1b[0m", i * 2 + 6, 18);
      printf("\x1b[%d;%dH\x1b[36m|\x1b[0m", i * 2 + 6,
             static_cast<int>(dynamic_cast<const PooSweeperState*>(state)->
                              numCols()) * 3 + 19);
    }
  }
}
