#include "gamelogic.h"

bool GameLogic::updateBoard(ushort row, ushort col)
{
  if (!isdigit(fields[row][col])) return false;
  fields[row][col] = choice[current_turn];
  ++move_count;
  return true;
}

bool GameLogic::checkWinnner(ushort row, ushort col)
{
  if (verticleWin(col) || horizontalWin(row) || diagonalWin())
  {
    this->current_status = WIN;
    return true;
  }
  else if (this->checkDraw())
  {
    this->current_status = DRAW;
    return true;
  }
  return false;
}

Status GameLogic::getCurrentStatus() const
{
  return current_status;
}

void GameLogic::setCurrentStatus(Status type)
{
  this->current_status = type;
}

void GameLogic::changeTurn()
{
  current_turn = (current_turn == PLAYER_0) ? PLAYER_1 : PLAYER_0;
}

bool GameLogic::horizontalWin(ushort row) const
{
  for (int i = 0; i < BOARD_DIM; ++i)
  {
    if (fields[row][i] != choice[current_turn])
      return false;
  }
  return true;
}

bool GameLogic::verticleWin(ushort col) const
{
  for (int i = 0; i < BOARD_DIM; ++i)
  {
    if (fields[i][col] != choice[current_turn])
      return false;
  }
  return true;
}

bool GameLogic::diagonalWin() const
{
  bool main_diagonal = true, anti_diagonal = true;
  for (int i = 0; i < BOARD_DIM; ++i)
  {
    if (fields[i][i] != choice[current_turn])
      main_diagonal = false;
    if (fields[i][BOARD_DIM - 1 - i] != choice[current_turn])
      anti_diagonal = false;
    if (!main_diagonal && !anti_diagonal)
      return false;
  }
  return main_diagonal || anti_diagonal;
}

bool GameLogic::checkDraw() const
{
  if (move_count != BOARD_DIM * BOARD_DIM)
    return false;
  if (current_status != ONGOING)
    return false;
  return true;
}

void GameLogic::swapChoice()
{
  choice[PLAYER_0] = 'O';
  choice[PLAYER_1] = 'X';
}