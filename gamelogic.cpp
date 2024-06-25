#include "gamelogic.h"

bool GameLogic::updateBoard(ushort row, ushort col){
  if(!isdigit(fields[row][col])) return false;
  fields[row][col] = choice[currTurn];
  ++totalMove;
  return true;
}

bool GameLogic::checkWinnner(ushort row, ushort col){
  if(verticleWin(col) || horizontalWin(row) || diagonalWin()) {
    this->currStatus = WIN;
    return true;
  } else if(checkDraw()) {
    this->currStatus = DRAW;
    return true;
  }
  return false;
}

Status GameLogic::getCurrStatus() const {
  return currStatus;
}

void GameLogic::setCurrStatus(Status type) {
  this->currStatus = type;
}

void GameLogic::changeTurn() {
  currTurn = (currTurn == PLAYER_0) ? PLAYER_1 : PLAYER_0;
}

bool GameLogic::horizontalWin(ushort row) const {
  for(int i = 0; i < BOARD_DIM; ++i){
    if(fields[row][i] != choice[currTurn]) return false;
  }
  return true;
}

bool GameLogic::verticleWin(ushort col) const {
  for(int i = 0; i < BOARD_DIM; ++i){
    if(fields[i][col] != choice[currTurn]) return false;
  }
  return true;
}

bool GameLogic::diagonalWin() const {
  bool upSlopWin = true, downSlopWin = true;
  for (int i = 0; i < BOARD_DIM; ++i) {
    if (fields[i][i] != choice[currTurn]) upSlopWin = false;
    if (fields[i][BOARD_DIM - 1 - i] != choice[currTurn]) downSlopWin = false;
    if (!upSlopWin && !downSlopWin) return false;
  }
  return upSlopWin || downSlopWin;
}

bool GameLogic::checkDraw() const {
  if(totalMove != BOARD_DIM*BOARD_DIM) return false;
  if(currStatus != ONGOING) return false;
  return true;
}

void GameLogic::swapChoice()
{
  choice[PLAYER_0] = 'O';
  choice[PLAYER_1] = 'X';
}