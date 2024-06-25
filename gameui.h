#ifndef GAMEUI_H
#define GAMEUI_H
#include <iostream>
#include "gamelogic.h"

enum MoveStatus { 
  VALID_MOVE, 
  INVALID_MOVE, 
  UNEXPECTED_MOVE,
  DEFAULT // to trigger switch case default statement!
};

class GameUi : private GameLogic {
  public:
    void start();

  private:
    void show();
    void clear();
    void evaluateWinner();
    bool getInxInput(ushort&);
    static void showRow(char*);
    const char* getCurrStatusText();
    void setInputStatus(MoveStatus);
    const char* getInputStatusText();
    MoveStatus prevMoveStatus = DEFAULT;
};

#endif