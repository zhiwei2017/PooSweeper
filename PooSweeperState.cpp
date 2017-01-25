// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#include <time.h>
#include <stdio.h>
#include <iostream>
#include "./PooSweeperState.h"
#include "./PooSweeperStateBase.h"

// ____________________________________________________________________________
PooSweeperState::~PooSweeperState() {
  for (int i = 0; i < _numCols; i++) {
    delete[] _squares[i];
  }
  delete[] _squares;
}

// ____________________________________________________________________________
PooSweeperStateBase::CellInfo PooSweeperState::getCellInfo(size_t rowIndex,
                                                       size_t colIndex) const {
  if (_squares[rowIndex][colIndex].revealed == false) {
    if (_squares[rowIndex][colIndex].flag == true) {
      return PooSweeperStateBase::MARKED;
    } else {
      return PooSweeperStateBase::UNREVEALED;
    }
  } else {
    if (_squares[rowIndex][colIndex].poo == true) {
      return PooSweeperStateBase::REVEALED_POO;
    } else {
      if (_squares[rowIndex][colIndex].poosAround == 0) {
        return PooSweeperStateBase::REVEALED_ZERO;
      } else if (_squares[rowIndex][colIndex].poosAround == 1) {
        return PooSweeperStateBase::REVEALED_ONE;
      } else if (_squares[rowIndex][colIndex].poosAround == 2) {
        return PooSweeperStateBase::REVEALED_TWO;
      } else if (_squares[rowIndex][colIndex].poosAround == 3) {
        return PooSweeperStateBase::REVEALED_THREE;
      } else if (_squares[rowIndex][colIndex].poosAround == 4) {
        return PooSweeperStateBase::REVEALED_FOUR;
      } else if (_squares[rowIndex][colIndex].poosAround == 5) {
        return PooSweeperStateBase::REVEALED_FIVE;
      } else if (_squares[rowIndex][colIndex].poosAround == 6) {
        return PooSweeperStateBase::REVEALED_SIX;
      } else if (_squares[rowIndex][colIndex].poosAround == 7) {
        return PooSweeperStateBase::REVEALED_SEVEN;
      } else {
        return PooSweeperStateBase::REVEALED_EIGHT;
      }
    }
  }
}

// ____________________________________________________________________________
void PooSweeperState::initialize(size_t numRows, size_t numCols,
                                 size_t numPoos) {
  squareInit(numRows, numCols);
  createPoos(numPoos);
}

// ____________________________________________________________________________
void PooSweeperState::applyMove(const PooSweeperMove& move) {
  if (check_yx(move.row, move.col) == 0) {
    if (getCellInfo(move.row, move.col) == PooSweeperStateBase::MARKED) {
      if (move.type == PooSweeperMove::TOGGLE_MARK) {
        _squares[move.row][move.col].flag = false;
      }
    } else if (getCellInfo(move.row, move.col)
              == PooSweeperStateBase::UNREVEALED) {
      if (move.type == PooSweeperMove::REVEAL) {
        if (_squares[move.row][move.col].poo == true) {
          GameEnd();
        } else if (_squares[move.row][move.col].poosAround == 0) {
          clean_empty_squares(move.row, move.col);
        }
        _squares[move.row][move.col].revealed = true;
      } else if (move.type == PooSweeperMove::TOGGLE_MARK) {
        _squares[move.row][move.col].flag = true;
      }
    }
  }
}

// ____________________________________________________________________________
PooSweeperStateBase::GameStatus PooSweeperState::status() const {
  for (int i = 0; i < _numRows; i++) {
    for (int j = 0; j < _numCols; j++) {
      if (_squares[i][j].revealed == true &&
          _squares[i][j].poo == true && _squares[i][j].flag == false) {
        return PooSweeperStateBase::LOST;
      }
    }
  }
  if (numRevealed() + numMarkedPoos() == numCols() * numRows()
      || numRevealed() + numPoos() == numCols() * numRows()) {
    return PooSweeperStateBase::WON;
  } else {
    return PooSweeperStateBase::ONGOING;
  }
}

// ____________________________________________________________________________
size_t PooSweeperState::numRows() const {
  return _numRows;
}

// ____________________________________________________________________________
size_t PooSweeperState::numCols() const {
  return _numCols;
}

// ____________________________________________________________________________
size_t PooSweeperState::numPoos() const {
  return _numPoos;
}

// ____________________________________________________________________________
size_t PooSweeperState::numMarkedPoos() const {
  int count = 0;
  for (int i = 0; i < _numRows; i++) {
    for (int j = 0; j < _numCols; j++) {
      if (_squares[i][j].revealed == false && _squares[i][j].poo == true
          && _squares[i][j].flag == true) {
        count++;
      }
    }
  }
  return count;
}

// ____________________________________________________________________________
size_t PooSweeperState::numRevealed() const {
  int count = 0;
  for (int i = 0; i < _numRows; i++) {
    for (int j = 0; j < _numCols; j++) {
      if (_squares[i][j].revealed == true && _squares[i][j].poo == false) {
        count++;
      }
    }
  }
  return count;
}

// ____________________________________________________________________________
size_t PooSweeperState::numMarked() const {
  int count = 0;
  for (int i = 0; i < _numRows; i++) {
    for (int j = 0; j < _numCols; j++) {
      if (_squares[i][j].revealed == false && _squares[i][j].flag == true) {
        count++;
      }
    }
  }
  return count;
}

// ____________________________________________________________________________
void PooSweeperState::squareInit(size_t numRows, size_t numCols) {
  _numCols = numCols;
  _numRows = numRows;
  _squares = new square*[numRows];
  for (int i = 0; i < numRows; i++) {
    _squares[i] = new square[numCols];
  }
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      _squares[i][j].poo = false;
      _squares[i][j].poosAround = 0;
      _squares[i][j].isDone = false;
      _squares[i][j].revealed = false;
      _squares[i][j].flag = false;
    }
  }
}

// ____________________________________________________________________________
void PooSweeperState::createPoos(size_t numPoos) {
  _numPoos = numPoos;
  srand((unsigned)time(NULL));
  unsigned int seed = time(0);
  int i = 0;
  while (i < numPoos) {
    int x = rand_r(&seed) % _numRows;
    int y = rand_r(&seed) % _numCols;
    if (_squares[x][y].poo == false) {
      _squares[x][y].poo = true;
      _squares[x][y].poosAround = 0;
      if (check_yx(x, y - 1) == 0 && _squares[x][y - 1].poo == false) {
        ++_squares[x][y - 1].poosAround;
      }
      if (check_yx(x, y + 1) == 0 && _squares[x][y + 1].poo == false) {
        ++_squares[x][y + 1].poosAround;
      }
      if (check_yx(x - 1, y) == 0 && _squares[x - 1][y].poo == false) {
        ++_squares[x - 1][y].poosAround;
      }
      if (check_yx(x + 1, y) == 0 && _squares[x + 1][y].poo == false) {
        ++_squares[x + 1][y].poosAround;
      }
      if (check_yx(x - 1, y - 1) == 0 && _squares[x - 1][y - 1].poo ==
          false) {
        ++_squares[x - 1][y - 1].poosAround;
      }
      if (check_yx(x - 1, y + 1) == 0 && _squares[x - 1][y + 1].poo ==
          false) {
        ++_squares[x - 1][y + 1].poosAround;
      }
      if (check_yx(x + 1, y - 1) == 0 && _squares[x + 1][y - 1].poo ==
          false) {
        ++_squares[x + 1][y - 1].poosAround;
      }
      if (check_yx(x + 1, y + 1) == 0 && _squares[x + 1][y + 1].poo ==
          false) {
        ++_squares[x + 1][y + 1].poosAround;
      }
      i++;
    }
  }
}

// ___________________________________________________________________________
int PooSweeperState::check_yx(int y, int x) const {
  if (y >= 0 && y < _numRows && x >= 0 && x < _numCols) {
    return 0;
  }
  return -1;
}

// ___________________________________________________________________________
void PooSweeperState::clean_empty_squares(int cur_y, int cur_x) {
  if (check_yx(cur_y - 1, cur_x) == 0
      && _squares[cur_y - 1][cur_x].poo == false
      && _squares[cur_y - 1][cur_x].isDone == false
      && _squares[cur_y - 1][cur_x].flag == false) {
    if (_squares[cur_y - 1][cur_x].poosAround == 0) {
      _squares[cur_y - 1][cur_x].isDone = true;
      clean_empty_squares(cur_y - 1, cur_x);
    } else {
      _squares[cur_y - 1][cur_x].isDone = true;
    }
    _squares[cur_y - 1][cur_x].revealed = true;
  }

  if (check_yx(cur_y + 1, cur_x) == 0
      && _squares[cur_y + 1][cur_x].poo == false
      && _squares[cur_y + 1][cur_x].isDone == false
      && _squares[cur_y + 1][cur_x].flag == false) {
    if (_squares[cur_y + 1][cur_x].poosAround == 0) {
      _squares[cur_y + 1][cur_x].isDone = true;
      clean_empty_squares(cur_y + 1, cur_x);
    } else {
      _squares[cur_y + 1][cur_x].isDone = true;
    }
    _squares[cur_y + 1][cur_x].revealed = true;
  }

  if (check_yx(cur_y, cur_x - 1) == 0
      && _squares[cur_y][cur_x - 1].poo == false
      && _squares[cur_y][cur_x - 1].isDone == false
      && _squares[cur_y][cur_x - 1].flag == false) {
    if (_squares[cur_y][cur_x - 1].poosAround == 0) {
      _squares[cur_y][cur_x - 1].isDone = true;
      clean_empty_squares(cur_y, cur_x - 1);
    } else {
      _squares[cur_y][cur_x - 1].isDone = true;
    }
    _squares[cur_y][cur_x - 1].revealed = true;
  }

  if (check_yx(cur_y, cur_x + 1) == 0
      && _squares[cur_y][cur_x + 1].poo == false
      && _squares[cur_y][cur_x + 1].isDone == false
      && _squares[cur_y][cur_x + 1].flag == false) {
    if (_squares[cur_y][cur_x + 1].poosAround == 0) {
      _squares[cur_y][cur_x + 1].isDone = true;
      clean_empty_squares(cur_y, cur_x + 1);
    } else {
      _squares[cur_y][cur_x + 1].isDone = true;
    }
    _squares[cur_y][cur_x + 1].revealed = true;
  }

  if (check_yx(cur_y - 1, cur_x - 1) == 0
      && _squares[cur_y - 1][cur_x - 1].poo == false
      && _squares[cur_y - 1][cur_x - 1].isDone == false
      && _squares[cur_y - 1][cur_x - 1].flag == false) {
    if (_squares[cur_y - 1][cur_x - 1].poosAround == 0) {
      _squares[cur_y - 1][cur_x - 1].isDone = true;
      clean_empty_squares(cur_y - 1, cur_x - 1);
    } else {
      _squares[cur_y - 1][cur_x - 1].isDone = true;
    }
    _squares[cur_y - 1][cur_x - 1].revealed = true;
  }

  if (check_yx(cur_y - 1, cur_x + 1) == 0
      && _squares[cur_y - 1][cur_x + 1].poo == false
      && _squares[cur_y - 1][cur_x + 1].isDone == false
      && _squares[cur_y - 1][cur_x + 1].flag == false) {
    if (_squares[cur_y - 1][cur_x + 1].poosAround == 0) {
      _squares[cur_y - 1][cur_x + 1].isDone = true;
      clean_empty_squares(cur_y - 1, cur_x + 1);
    } else {
      _squares[cur_y - 1][cur_x + 1].isDone = true;
    }
    _squares[cur_y - 1][cur_x + 1].revealed = true;
  }

  if (check_yx(cur_y + 1, cur_x - 1) == 0
      && _squares[cur_y + 1][cur_x - 1].poo == false
      && _squares[cur_y + 1][cur_x - 1].isDone == false
      && _squares[cur_y + 1][cur_x - 1].flag == false) {
    if (_squares[cur_y + 1][cur_x - 1].poosAround == 0) {
      _squares[cur_y + 1][cur_x - 1].isDone = true;
      clean_empty_squares(cur_y + 1, cur_x - 1);
    } else {
      _squares[cur_y + 1][cur_x - 1].isDone = true;
    }
    _squares[cur_y + 1][cur_x - 1].revealed = true;
  }

  if (check_yx(cur_y + 1, cur_x + 1) == 0
      && _squares[cur_y + 1][cur_x + 1].poo == false
      && _squares[cur_y + 1][cur_x + 1].isDone == false
      && _squares[cur_y + 1][cur_x + 1].flag == false) {
    if (_squares[cur_y + 1][cur_x + 1].poosAround == 0) {
      _squares[cur_y + 1][cur_x + 1].isDone = true;
      clean_empty_squares(cur_y + 1, cur_x + 1);
    } else {
      _squares[cur_y + 1][cur_x + 1].isDone = true;
    }
    _squares[cur_y + 1][cur_x + 1].revealed = true;
  }
}

// ___________________________________________________________________________
void PooSweeperState::GameEnd() const {
  for (int i = 0; i < _numRows; i++) {
    for (int j = 0; j < _numCols; j++) {
      _squares[i][j].revealed = true;
    }
  }
}

// ___________________________________________________________________________
void PooSweeperState::win() const {
  for (int i = 0; i < _numRows; i++) {
    for (int j = 0; j < _numCols; j++) {
      if (_squares[i][j].poo == true) {
        _squares[i][j].flag = true;
      }
    }
  }
}

// ___________________________________________________________________________
bool PooSweeperState::marked(size_t y, size_t x) const {
  if (_squares[y][x].flag == true) {
    return true;
  } else {
    return false;
  }
}

// ___________________________________________________________________________
bool PooSweeperState::poo(size_t y, size_t x) const {
  if (_squares[y][x].poo == true) {
    return true;
  } else {
    return false;
  }
}
