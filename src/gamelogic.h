#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <iostream>

#define BOARD_DIM 3 // tic-tac-toe board dimension

typedef unsigned short int ushort;
enum Player
{
  PLAYER_0,
  PLAYER_1
};
enum Status
{
  WIN,
  DRAW,
  ONGOING,
  OTHER
};

class GameLogic
{
protected:
  char choice[2] = {'X', 'O'};
  Player current_turn = PLAYER_0;

  char fields[BOARD_DIM][BOARD_DIM] = {
      {'0', '1', '2'},
      {'3', '4', '5'},
      {'6', '7', '8'}};

  void swapChoice();
  void changeTurn();
  void setCurrentStatus(Status);
  Status getCurrentStatus() const;
  bool checkWinnner(ushort row, ushort col);
  bool updateBoard(ushort row, ushort col);

private:
  ushort move_count = 0;
  Status current_status = OTHER;
  bool checkDraw() const;
  bool diagonalWin() const;
  bool verticleWin(ushort col) const;
  bool horizontalWin(ushort row) const;
};

#endif