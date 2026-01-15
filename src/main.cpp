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

  while (1) {
    vector<int> startingState = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    Game game = Game(startingState);
    game.play();
  }
  endwin();

  return 0;
}
