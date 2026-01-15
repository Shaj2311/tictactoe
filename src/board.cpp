#include "../include/board.h"
#include <ncurses.h>
#include <string>
#include <vector>
using namespace std;

#define XMAX 33
#define YMAX 18

Board::Board(int maxy, int maxx) {
  this->x = (maxx / 2) - 18;
  this->y = 1;
  this->maxx = maxx;
  this->maxy = maxy;
}

vector<int> tokenX = {0, 0, 0, 1,  0, 0, 0, 1,  0, 0, -1, 0, 0, 0, 0,  1, 0, 1,
                      0, 0, 0, -1, 0, 0, 0, 0,  0, 1, 0,  0, 0, 0, -1, 0, 0, 0,
                      0, 1, 0, 1,  0, 0, 0, -1, 0, 0, 0,  1, 0, 0, 0,  1, 0, 0};

vector<int> tokenO = {0, 0, 0, 0,  2, 2, 2, 0,  0, 0, -1, 0, 0, 0, 2,  0, 0, 0,
                      2, 0, 0, -1, 0, 0, 0, 2,  0, 0, 0,  2, 0, 0, -1, 0, 0, 0,
                      2, 0, 0, 0,  2, 0, 0, -1, 0, 0, 0,  0, 2, 2, 2,  0, 0, 0};

string tokenize(const std::vector<int> &arr) {
  string out;

  for (int elem : arr) {
    if (elem == 0)
      out += " ";
    if (elem == 1)
      out += "X";
    if (elem == 2)
      out += "O";
    if (elem == -1)
      out += "\n";
  }

  return out;
}

void printColored(WINDOW* box, int colorPairVal, vector<int>& token) {
  wattron(box, COLOR_PAIR(colorPairVal));
  mvwaddstr(box, 1, 0, tokenize(token).c_str());
  wattroff(box, COLOR_PAIR(colorPairVal));
}

void Board::drawBoard(std::vector<int> gamestate, Board *gameBoard, WINDOW *win,
                      int leny, int lenx) {

  int line = 7, col = 12;
  int centering_factor = maxx / 2 - (36 / 2);
  int height_adjusting_factor = 1;

  WINDOW *box1 =
      newwin(line, col, line * 2 + height_adjusting_factor, centering_factor);

  if (gamestate[0] == 0) {
    printColored(box1, 1, tokenX);
  }
  if (gamestate[0] == 1) {
    printColored(box1, 2, tokenO);
  }
  box(box1, 0, 0);
  mvwaddch(box1, line - 1, col - 2, '1');
  wrefresh(box1);

  WINDOW *box2 = newwin(line, col, line * 2 + height_adjusting_factor,
                        col + centering_factor);

  if (gamestate[1] == 0) {
    printColored(box2, 1, tokenX);
  }
  if (gamestate[1] == 1) {
    printColored(box2, 2, tokenO);
  }
  box(box2, 0, 0);
  mvwaddch(box2, line - 1, col - 2, '2');
  wrefresh(box2);

  WINDOW *box3 = newwin(line, col, line * 2 + height_adjusting_factor,
                        col * 2 + centering_factor);

  if (gamestate[2] == 0) {
    printColored(box3, 1, tokenX);
  }
  if (gamestate[2] == 1) {
    printColored(box3, 2, tokenO);
  }
  box(box3, 0, 0);
  mvwaddch(box3, line - 1, col - 2, '3');
  wrefresh(box3);

  WINDOW *box4 =
      newwin(line, col, line + height_adjusting_factor, centering_factor);

  if (gamestate[3] == 0) {
    printColored(box4, 1, tokenX);
  }
  if (gamestate[3] == 1) {
    printColored(box4, 2, tokenO);
  }
  box(box4, 0, 0);
  mvwaddch(box4, line - 1, col - 2, '4');
  wrefresh(box4);

  WINDOW *box5 =
      newwin(line, col, line + height_adjusting_factor, col + centering_factor);

  if (gamestate[4] == 0) {
    printColored(box5, 1, tokenX);
  }
  if (gamestate[4] == 1) {
    printColored(box5, 2, tokenO);
  }
  box(box5, 0, 0);
  mvwaddch(box5, line - 1, col - 2, '5');
  wrefresh(box5);

  WINDOW *box6 = newwin(line, col, line + height_adjusting_factor,
                        col * 2 + centering_factor);

  if (gamestate[5] == 0) {
    printColored(box6, 1, tokenX);
  }
  if (gamestate[5] == 1) {
    printColored(box6, 2, tokenO);
  }
  box(box6, 0, 0);
  mvwaddch(box6, line - 1, col - 2, '6');
  wrefresh(box6);

  WINDOW *box7 = newwin(line, col, height_adjusting_factor, centering_factor);

  if (gamestate[6] == 0) {
    printColored(box7, 1, tokenX);
  }
  if (gamestate[6] == 1) {
    printColored(box7, 2, tokenO);
  }
  box(box7, 0, 0);
  mvwaddch(box7, line - 1, col - 2, '7');
  wrefresh(box7);

  WINDOW *box8 =
      newwin(line, col, height_adjusting_factor, col + centering_factor);

  if (gamestate[7] == 0) {
    printColored(box8, 1, tokenX);
  }
  if (gamestate[7] == 1) {
    printColored(box8, 2, tokenO);
  }
  box(box8, 0, 0);
  mvwaddch(box8, line - 1, col - 2, '8');
  wrefresh(box8);

  WINDOW *box9 =
      newwin(line, col, height_adjusting_factor, col * 2 + centering_factor);

  if (gamestate[8] == 0) {
    printColored(box9, 1, tokenX);
  }
  if (gamestate[8] == 1) {
    printColored(box9, 2, tokenO);
  }

  box(box9, 0, 0);
  mvwaddch(box9, line - 1, col - 2, '9');
  wrefresh(box9);

  refresh();
};
