#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <iostream>
#define BOARD_DIM 3 // tic-tac-toe board dimension

typedef unsigned short int ushort;
enum Player { PLAYER_0, PLAYER_1 };
enum Status { WIN, DRAW, ONGOING, OTHER };

class GameLogic {
  protected:
    char choice[2] = {'X', 'O'};
    Player currTurn = PLAYER_0;

    char fields[BOARD_DIM][BOARD_DIM] = {
      {'0','1','2'},
      {'3','4','5'},
      {'6','7','8'}
    };

    void swapChoice();
    void changeTurn();
    void setCurrStatus(Status);
    Status getCurrStatus() const;
    bool checkWinnner(ushort row, ushort col);
    bool updateBoard(ushort row, ushort col);

  private:
    ushort totalMove = 0;
    Status currStatus = OTHER;
    bool checkDraw() const;
    bool diagonalWin() const;
    bool verticleWin(ushort col) const;
    bool horizontalWin(ushort row) const;
};

#endif