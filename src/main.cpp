#include "../include/game.h"
#include <ncurses.h>
#include <vector>
using namespace std;

int main(int argc, char **argv) {

  /* Start ncurses */
  initscr();
  cbreak();

  /* Initialize colors */
  start_color();
  use_default_colors();
  init_pair(0, COLOR_WHITE, -1);
  init_pair(1, COLOR_RED, -1);
  init_pair(2, COLOR_GREEN, -1);

  while (1) {
    vector<int> startingState = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    Game game = Game(startingState);
    game.play();
  }
  endwin();

  return 0;
}
