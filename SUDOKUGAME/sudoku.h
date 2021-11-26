#ifndef sudoku
#define sudoku

const int nmax = 9;
//PROTOTYPE
void canvas();
void make();
void solve(int row, int col);
bool check(int s[nmax][nmax], int row, int col, int k);
void outport();
void interact();
void number(char c, int x, int y);
void startpoint();
void gotoxy(int x, int y);
void board();
void endmenu();
void ShowConsoleCursor(bool showFlag);
void timer();

#endif // sudoku
