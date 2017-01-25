// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "./PooSweeperGame.h"


void PooSweeperGame::structure() {
  while (true) {
    std::cout << "whick level do you want to challenge?" <<
    " (Beginner, Intermediate or Expert) : ";
    std::cin >> PooSweeperGame::level;
    break;
  }
  initscr();
  nodelay(stdscr, true);
  noecho();
  cbreak();
  curs_set(false);
  keypad(stdscr, true);
}

void PooSweeperGame::game() {
  if (PooSweeperGame::level == "Beginner"
      || PooSweeperGame::level == "beginner"
      || PooSweeperGame::level == "B"
      || PooSweeperGame::level == "b") {
    PooSweeperGame::state->initialize(9, 9, 10);
  } else if (PooSweeperGame::level == "Intermediate"
             || PooSweeperGame::level == "intermadiate"
             || PooSweeperGame::level == "I"
             || PooSweeperGame::level == "i") {
    PooSweeperGame::state->initialize(16, 16, 40);
  } else if (PooSweeperGame::level == "Expert"
             || PooSweeperGame::level == "expert"
             || PooSweeperGame::level == "E"
             || PooSweeperGame::level == "e") {
    PooSweeperGame::state->initialize(16, 30, 99);
  }

  MEVENT me;
  mousemask(ALL_MOUSE_EVENTS, NULL);
  int i = 0;
  while (true) {
    if (dynamic_cast<const PooSweeperState*>(PooSweeperGame::state)->
        status() ==
        PooSweeperStateBase::ONGOING) {
      printf("\x1b[%d;%dH%d", 12, 9, 1000 - i);
    } else if (dynamic_cast<const PooSweeperState*>
               (PooSweeperGame::state)->status() ==
               PooSweeperStateBase::LOST) {
      printf("\x1b[%d;%dH0000", 12, 9);
    }
    PooSweeperGame::DISPLAY->show(PooSweeperGame::state);
    int ch = getch();
    if (ch == -1) continue;
    if (getmouse(&me) == OK) {
      if (me.bstate & BUTTON1_CLICKED) {
        move.set((me.y - 5) / 2, (me.x - 19) / 3, 0);
        fflush(stdout);
      } else if (me.bstate & BUTTON3_CLICKED) {
        move.set((me.y - 5) / 2, (me.x - 19) / 3, 1);
        fflush(stdout);
      }
    }
    PooSweeperGame::state->applyMove(move);
    i++;
    if (ch == 'q') break;
  }
}

void PooSweeperGame::end() {
  endwin();
}
