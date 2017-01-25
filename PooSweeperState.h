// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef PROJEKT_POOSWEEPERSTATE_H_
#define PROJEKT_POOSWEEPERSTATE_H_

#include <vector>
#include "gtest/gtest.h"
#include "./PooSweeperMove.h"
#include "./PooSweeperStateBase.h"

// Class representing a state of the Minesweeper game.
//
// NOTE: This class *must* be used both by the people programming the game (to
// be played by a human via the keyboard), as well as by the people programming
// a solver (which automatically generates a move given a state).
class PooSweeperState : public PooSweeperStateBase {
 public:
  // Virtual destructor.
  ~PooSweeperState();

  CellInfo getCellInfo(size_t rowIndex, size_t colIndex) const;

  // Initialize (randomly).
  void initialize(size_t numRows, size_t numCols, size_t numPoos);

  // Apply move.
  void applyMove(const PooSweeperMove& move);

  GameStatus status() const;

  // Getters.
  size_t numRows() const;
  size_t numCols() const;
  size_t numPoos() const;
  size_t numMarkedPoos() const;
  size_t numRevealed() const;
  size_t numMarked() const;

  // define the structure of the square
  struct square {
    bool poo;    // is poo or not
    bool isDone;   // is already handled by rekursion or not
    int poosAround;   // how many poos around this square
    bool revealed;   // is already revealed or not
    bool flag;
  };

  // init the map _squares
  void squareInit(size_t numRows, size_t numCols);
  FRIEND_TEST(PooSweeperStateTest, squareInit);

  // create the Poo and avoid more than 6 Poos stay together
  void createPoos(size_t numPoos);

  // make sure, if the current position out of the limit of _numRows and
  // _numCols
  int check_yx(int y, int x) const;

  // if under the klicked square is null, then open all the not Poo
  // square around the klicked square.
  void clean_empty_squares(int cur_y, int cur_x);

  // end the game
  void GameEnd() const;

  // check the square is marked or not
  bool marked(size_t y, size_t x) const;

  // check the square is poo or not
  bool poo(size_t y, size_t x) const;

  // if win the game, marked all the poos
  void win() const;

 private:
  // define the area of the game
  size_t _numRows;
  size_t _numCols;

  // define the number of the Poos
  size_t _numPoos;

  // the map of the PooSweeper
  square** _squares;
};

#endif  // PROJEKT_POOSWEEPERSTATE_H_
