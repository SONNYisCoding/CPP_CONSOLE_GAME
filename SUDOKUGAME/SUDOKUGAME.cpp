#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sudoku.h>
using namespace std;
//DATA & VARIABLES
int s[nmax][nmax];
int col,row,k,lvl,minutes,seconds,duration;
string st;
//IMPLEMENTS
void canvas(){
    cout << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" << endl; Sleep(100);
    cout << "0000000000000000000000000000000000000000000000000000000000000000000000``````0``````0``````0000" << endl; Sleep(100);
    cout << "0000       00   000   00        000         00   000   00   000   0000   1  0   2  0   3  0000" << endl; Sleep(100);
    cout << "000   0000000   000   00   000   00   000   00   00   000   000   0000      0      0      0000" << endl; Sleep(100);
    cout << "000   0000000   000   00   000   00   000   00   0   0000   000   0000``````0``````0``````0000" << endl; Sleep(100);
    cout << "0000      000   000   00   000   00   000   00   0   0000   000   0000   4  0      0   8  0000" << endl; Sleep(100);
    cout << "00000000   00   000   00   000   00   000   00   00   000   000   0000      0      0      0000" << endl; Sleep(100);
    cout << "00000000   00   000   00   000   00   000   00   000   00   000   0000``````0``````0``````0000" << endl; Sleep(100);
    cout << "000       000         00        000         00   000   00         0000   5  0   6  0   7  0000" << endl; Sleep(100);
    cout << "0000000000000000000000000000000000000000000000000000000000000000000000      0      0      0000" << endl; Sleep(100);
    cout << "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" << endl; Sleep(100);
    cout << endl;
    cout << "MADE BY SONNY ~ GECT CO.Ltd" << endl;
    cout << "**********************************************************************************************" << endl;
    cout << endl;
    gotoxy(50,19); cout << "START";
    gotoxy(50,20); cout << "QUIT";
    gotoxy(48,19); cout << ">";
    gotoxy(56,19); cout << "<";
    ShowConsoleCursor(false);
    char c;
    int n = 1;
    do{
        while(!kbhit()){
        system("Color 02");
        system("Color 01");
        system("Color 0D");
        system("Color 04");
        system("Color 00");
        system("Color 07");
        }
        c = getch();
        c = tolower(c);
        if(c == 'w'){
            n = 1;
            gotoxy(48,19); cout << ">";
            gotoxy(56,19); cout << "<";
            gotoxy(48,20); cout << " ";
            gotoxy(56,20); cout << " ";
        }else if(c == 's'){
            n = 2;
            gotoxy(48,19); cout << " ";
            gotoxy(56,19); cout << " ";
            gotoxy(48,20); cout << ">";
            gotoxy(56,20); cout << "<";
        }else if(c == char(13)){
            if(n==1){
                make();
                board();
                ShowConsoleCursor(true);
            }else{
                system("cls");
                exit(0);
            }
        }
    }while(c != char(13));
}

void make(){ //USE THIS TO MAKE A NEW SUDOKU
    //DEFAULT
    int rx,ry;
    system("cls");
    cout << "ENTER LEVEL (1 ~ 4): ";
    cin >> lvl;
    system("cls");
    cout << endl;
    srand((int)time(0));
    if(lvl == 1){
        int a[nmax][nmax] = {
             {5,3,8,7,6,4,2,1,9},
             {1,6,2,5,9,8,7,3,4},
             {4,7,9,1,3,2,6,8,5},
             {9,1,3,4,2,7,5,6,8},
             {6,8,7,9,1,5,3,4,2},
             {2,5,4,6,8,3,1,9,7},
             {7,2,6,3,4,9,8,5,1},
             {3,4,5,8,7,1,9,2,6},
             {8,9,1,2,5,6,4,7,3}
            };
        for(int i=1; i<=49; i++){
            rx = rand() % (9 - 0 + 1);
            ry = rand() % (9 - 0 + 1);
            a[rx][ry] = 0;
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << " " << a[i][j] << "  ";
                s[i][j] = a[i][j];
            }
            cout << endl;
            cout << endl;
        }
    }
    else if(lvl == 2){
        int a[nmax][nmax] = {
             {4,2,7,8,6,5,3,9,1},
             {9,1,5,2,4,3,7,6,8},
             {6,8,3,7,9,1,4,2,5},
             {5,9,8,4,3,7,2,1,6},
             {7,6,4,9,1,2,8,5,3},
             {1,3,2,5,8,6,9,4,7},
             {8,7,1,6,2,9,5,3,4},
             {3,4,9,1,5,8,6,7,2},
             {2,5,6,3,7,4,1,8,9}
            };
        for(int i=1; i<=53; i++){
            rx = rand() % (9 - 0 + 1);
            ry = rand() % (9 - 0 + 1);
            a[rx][ry] = 0;
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << " " << a[i][j] << "  ";
                s[i][j] = a[i][j];
            }
            cout << endl;
            cout << endl;
        }
    }
    else if(lvl == 3){
        int a[nmax][nmax] = {
             {9,4,6,8,3,2,1,5,7},
             {5,7,3,1,9,6,2,8,4},
             {1,2,8,7,4,5,3,9,6},
             {4,6,9,2,5,7,8,3,1},
             {3,5,1,9,8,4,6,7,2},
             {2,8,7,6,1,3,5,4,9},
             {6,9,2,3,7,8,4,1,5},
             {8,1,5,4,2,9,7,6,3},
             {7,3,4,5,6,1,9,2,8}
            };
        for(int i=1; i<=57; i++){
            rx = rand() % (9 - 0 + 1);
            ry = rand() % (9 - 0 + 1);
            a[rx][ry] = 0;
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << " " << a[i][j] << "  ";
                s[i][j] = a[i][j];
            }
            cout << endl;
            cout << endl;
        }
    }
    else if(lvl == 4){
        int a[nmax][nmax] = {
             {7,6,3,2,4,9,1,8,5},
             {4,1,5,7,3,8,9,6,2},
             {9,2,8,6,5,1,3,7,4},
             {1,5,7,3,8,2,4,9,6},
             {3,9,6,4,7,5,2,1,8},
             {2,8,4,9,1,6,7,5,3},
             {6,7,2,8,9,4,5,3,1},
             {8,3,1,5,2,7,6,4,9},
             {5,4,9,1,6,3,8,2,7}
            };
        for(int i=1; i<=61; i++){
            rx = rand() % (9 - 0 + 1);
            ry = rand() % (9 - 0 + 1);
            a[rx][ry] = 0;
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << " " << a[i][j] << "  ";
                s[i][j] = a[i][j];
            }
            cout << endl;
            cout << endl;
        }
    }
}

void solve(int row, int col){//USE THIS TO SOLVE SUDOKU
    if(col == 9){
        if(row == 8){
            interact();
            return;
        }
        else{
            solve(row+1,0);
        }
    }
    else{
        if(s[row][col] == 0){
            for(int k=1; k<=9; k++){
                if(check(s,row,col,k)){
                    s[row][col] = k;
                    solve(row,col+1);
                    s[row][col] = 0;
                }
            }
        }
        else{
            solve(row,col+1);
        }
    }
}

void outport(){
    cout << endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
            cout << " " << s[i][j] << "  ";
        cout << endl;
        cout << endl;
    }
    board();
}

bool check(int s[nmax][nmax], int row, int col, int k){//CHECK THE NUMBER
    for(int i = 0; i < 9 ; i++){
        if(s[row][i] == k) return false;
    }
    for(int i = 0; i < 9 ; i++){
        if(s[i][col] == k) return false;
    }
    if(row < 3 && col < 3){
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(s[i][j] == k) return false;
    }
    else if(row >= 3 && col < 3 && row < 6){
        for(int i=3; i<6; i++)
            for(int j=0; j<3; j++)
                if(s[i][j] == k) return false;
    }
    else if(row >= 6 && col < 3 && row < 9){
        for(int i=6; i<9; i++)
            for(int j=0; j<3; j++)
                if(s[i][j] == k) return false;
    }
    else if(row < 3 && col >= 3 && col < 6){
        for(int i=0; i<3; i++)
            for(int j=3; j<6; j++)
                if(s[i][j] == k) return false;
    }
    else if(row >= 3 && col >= 3 && col < 6 && row < 6){
        for(int i=3; i<6; i++)
            for(int j=3; j<6; j++)
                if(s[i][j] == k) return false;
    }
    else if(row >= 6 && col >= 3 && col < 6 && row < 9){
        for(int i=6; i<9; i++)
            for(int j=3; j<6; j++)
                if(s[i][j] == k) return false;
    }
    else if(row < 3 && col >= 6 && col < 9){
        for(int i=0; i<3; i++)
            for(int j=6; j<9; j++)
                if(s[i][j] == k) return false;
    }
    else if(row >= 3 && col >= 6 && col < 9 && row < 6){
        for(int i=3; i<6; i++)
            for(int j=6; j<9; j++)
                if(s[i][j] == k) return false;
    }
    else if(row >= 6 && col >= 6 && col < 9 && row < 9){
        for(int i=6; i<9; i++)
            for(int j=6; j<9; j++)
                if(s[i][j] == k) return false;
    }
    return true;
}

void gotoxy(int x, int y){//USE THIS TO GO ANYWHERE IN OUTPUT SCREEN
    COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void startpoint(){//SET THE START POINT FOR THE CONSOLE
    gotoxy(1,1);
}

void interact(){//USE THIS TO INTERACT WITH THE OUTPUT SCREEN
    startpoint();
    clock_t s,e;
    char c;
    int x = 1;
    int y = 1;
    s = clock();
    while(c != 'q'){
        c = getch();
        c = tolower(c);
        if(c == 'w' && x>=1 && y>=1){
            gotoxy(x,y-2);
            y = y-2;
        }
        else if(c == 'a' && x>=1 && y>=1){
            gotoxy(x-4,y);
            x = x-4;
        }
        else if(c == 's' && x<=33 && y<17){
            gotoxy(x,y+2);
            y = y+2;
        }
        else if(c == 'd' && x<33 && y<=17){
            gotoxy(x+4,y);
            x = x+4;
        }
        else if(c == 'r'){
            system("color 07");
            system("cls");
            outport();
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "PRESS Q TO QUIT" << endl;
        }
        else if(c != 'q' && static_cast<int>(c) > 48 && static_cast<int>(c) <= 57){
            number(c,x,y);
            gotoxy(x,y);
        }
        else if(c == 'f'){
            system("color 07");
            system("cls");
            outport();
            e = clock();
            duration = (e-s)/CLOCKS_PER_SEC;
            timer();
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "EXCELLENT!!!" << endl;
            cout << "DURATION: " << minutes << " minutes " << seconds << " seconds" << endl;
            cout << "PRESS Q TO QUIT" << endl;
        }
    }
}

void number(char c, int x, int y){
    int n = static_cast<int>(c) - 48;
    int col = 0;
    int row = 0;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    if(x>0) col = x/4;
    if(y>0) row = y/2;
    if(n == s[row][col]){
        SetConsoleTextAttribute(color, FOREGROUND_BLUE); // BLUE FONT WHEN RIGHT
        cout << n;
    }
    else{
        SetConsoleTextAttribute(color, FOREGROUND_RED); // RED FONT WHEN WRONG
        cout << n;
    }
}

void board(){//MAKE THE BORDER FOR THE SUDOKU
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, FOREGROUND_INTENSITY);
    for(int i=1; i<=33; i++){
        gotoxy(i,0); cout << char(219);
        gotoxy(i,18); cout << char(219);
        gotoxy(0,i-15); cout << char(219);
        gotoxy(34,i-15); cout << char(219);
        if(i==11 || i==23){
            gotoxy(i,6); cout << "+";
            gotoxy(i,12); cout << "+";
        }
        else{
            gotoxy(i,6); cout << "-";
            gotoxy(i,12); cout << "-";
        }
    }
    for(int i=1; i<=17; i++){
        if(i != 6 && i != 12){
            gotoxy(11,i); cout << "|";
            gotoxy(23,i); cout << "|";
        }
    }
    HANDLE logo = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(logo, FOREGROUND_GREEN);
    gotoxy(40,4); cout <<  "  ______    __    __    ______      ________    __    __    __    __ ";
    gotoxy(40,5); cout <<  " (______)  (__)  (__)  (______)    (________)  (__)  (__)  (__)  (__)";
    gotoxy(40,6); cout <<  "(__)       (__)  (__)  (__) (__)   (__)  (__)  (__) (__)   (__)  (__)";
    gotoxy(40,7); cout <<  "(__)___    (__)  (__)  (__)  (__)  (__)  (__)  (__)(__)    (__)  (__)";
    gotoxy(40,8); cout <<  " (_____)   (__)  (__)  (__)  (__)  (__)  (__)  (____)__    (__)  (__)";
    gotoxy(40,9); cout <<  "     (__)  (__)  (__)  (__)  (__)  (__)  (__)  (__) (__)   (__)  (__)";
    gotoxy(40,10); cout << " ____(__)  (__)__(__)  (__)_(__)   (__)__(__)  (__)  (__)  (__)__(__)";
    gotoxy(40,11); cout << "(______)   (________)  (_____)     (________)  (__)  (__)  (________)";
    gotoxy(40,12); cout << " ___________________________________________________________________ ";
    gotoxy(40,13); cout << "(___________________________________________________________________)";
    gotoxy(40,14); cout << " ___________________________________________________________________ ";
    gotoxy(40,15); cout << "(___________________________________________________________________)";
    gotoxy(40,18); cout << endl;
}

void timer(){
    minutes = duration/60;
    seconds = duration%60;
}

void endmenu(){
    system("color 07");
    system("cls");
    cout << "Play again? [y/n]: ";
}

void ShowConsoleCursor(bool showFlag){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
    string c = "y";
    do{
        system("cls");
        canvas();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "TRY YOUR BEST TO SOLVE IT" << endl;
        cout << "USE W,A,S,D TO INTERACT" << endl;
        cout << "PRESS F TO SUBMIT" << endl;
        cout << "PRESS Q TO QUIT" << endl;
        cout << "PRESS R TO SHOW RESULT" << endl;
        solve(0,0);
        endmenu();
        cin >> c;
    }while(c == "y");
    return 0;
}
