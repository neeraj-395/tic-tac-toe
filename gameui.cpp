#include "gameui.h"

void GameUi::start()
{
  this->show();
  printf("\n:: Instruction\n");
  printf(":: Use the index numbers on the board to place your X or O based on your turn.\n");

  printf("\n:: Would you like to swap player symbols? (Y/n): ");
  if (toupper(getchar()) == 'Y') this->swapChoice();
  this->setCurrStatus(ONGOING);
  this->clear();

  ushort inx, row, col;
  do {

    this->show();

    if(!getInxInput(inx)){
      this->setInputStatus(UNEXPECTED_MOVE);
      this->clear();
      continue;
    } else this->setInputStatus(VALID_MOVE);

    row = inx / BOARD_DIM;
    col = inx % BOARD_DIM;

    if(!updateBoard(row, col)) {
      this->setInputStatus(INVALID_MOVE);
      this->clear();
      continue;
    }

    if(!checkWinnner(row, col)) this->changeTurn();

    this->clear();

  } while(this->getCurrStatus() == ONGOING);

  evaluateWinner();
  while (getchar() != '\n'); // clear the input buffer
}

void GameUi::evaluateWinner() {
  this->show();

  switch(this->getCurrStatus()) {
    case WIN: printf("\n:: Congratulations! Player %d <%c> has won " 
                     "the game.\n\n", currTurn, choice[currTurn]);
    break;

    case DRAW: printf("\n:: It's a draw! No one has won the game.\n\n");
    break;

    default: printf("\n:: Unexpected result! Please restart the program.\n\n");
    break;
  }
}

bool GameUi::getInxInput(ushort& inx) {
  while(getchar() != '\n'); // clear the input buffer
  printf("\n:: Player %d <%c> - Enter a number to make your move: ", 
         currTurn, choice[currTurn]);

  if (scanf("%hu", &inx) != 1 || inx >= BOARD_DIM*BOARD_DIM) return false;
  return true;
}

void GameUi::showRow(char *data) {
  printf("\t %c | %c | %c\n", data[0], data[1], data[2]);
}

void GameUi::setInputStatus(MoveStatus previous) {
  prevMoveStatus = previous;
}

const char* GameUi::getCurrStatusText()
{
  switch (this->getCurrStatus()) {
    case WIN: return "Win!";
    case DRAW: return "Draw!";
    case ONGOING: return "Ongoing!";
    case OTHER: return "Not started yet!";
    default: return "Unknown status!";
  }
}

const char* GameUi::getInputStatusText()
{
  switch(prevMoveStatus) {
    case VALID_MOVE: return "Move was valid!";
    case INVALID_MOVE: return "Move was invalid! That field is already occupied.";
    case UNEXPECTED_MOVE: return "Move was unexpected! Please enter a number between 0 and 8.";
    default: return "No move made yet!";
  }
}

void GameUi::show()
{
  printf("\n:: Welcome to Tic-Tac-Toe! ::\n");
  printf("\n:: Player 0 <%c> - Player 1 <%c> ::\n\n", choice[PLAYER_0], choice[PLAYER_1]);
  showRow(this->fields[0]);
  printf("\t---|---|---\n");
  showRow(this->fields[1]);
  printf("\t---|---|---\n");
  showRow(this->fields[2]);
  printf("\n:: Current game status: %s\n", getCurrStatusText());
  printf(":: Previous move status: %s\n", getInputStatusText());
}

void GameUi::clear() {
  system("clear");
}