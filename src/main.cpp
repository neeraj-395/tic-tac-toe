#include <iostream>
#include "gameui.h"

int main()
{
  while (true)
  {
    GameUi tic_tac_toe;
    tic_tac_toe.start();

    printf(":: Would you like to play again? (Y/n): ");
    if (toupper(getchar()) != 'Y') break;
    
    while (getchar() != '\n'); // clear the input buffer

    system("clear");
  }

  printf("\n:: Exiting the game. Goodbye!\n");
  return 0;
}