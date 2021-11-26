#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
//DATA & VARIABLES
const int width = 75;
const int height = 25;
const float maxSpeed = 1.8f;
const int delay = 20;
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
struct pad {
    float x,y;
    int size;
    float ox,oy;
    float vy;
    pad(int _x, int _y, int _size) {
        x = float(_x);
        y = float(_y);
        size = _size;
        ox = float(_x);
        oy = float(_y);
    }
    void draw() {
        COORD p;
        for(int i = -size; i < size; i++){
            p.X = int(ox);
            p.Y = int(oy) - i;
            SetConsoleCursorPosition(hOut,p);
            cout << " ";
        }
        SetConsoleTextAttribute(hOut,7);
        for(int i = -size; i < size; i++){
            p.X = int(x);
            p.Y = int(y) - i;
            SetConsoleCursorPosition(hOut,p);
            cout << char(219) << endl;
        }
        SetConsoleTextAttribute(hOut,15);
        ox = x;
        oy = y;
    }
};

struct ball {
    float x, y, ox, oy;
    float vx, vy;
    ball(int _x, int _y) {
        x = float(_x);
        y = float(_y);
        ox = float(x);
        oy = float(y);
        vx = vy = 0;
    }

    void draw() {
        COORD p;
        p.X = int(ox);
        p.Y = int(oy);
        SetConsoleCursorPosition(hOut,p);
        cout << ' ';
        p.X = int(x);
        p.Y = int(y);
        SetConsoleCursorPosition(hOut,p);
        SetConsoleTextAttribute(hOut,7);
        cout << char(254);
        SetConsoleTextAttribute(hOut,15);
        ox = x;
        oy = y;
    }
};
int player = 0;
//PROTOTYPE
void reset(pad &you, pad &comp, ball &b, bool &started, int &you_score, int &comp_score);
void ShowConsoleCursor(bool showFlag);
void gotoxy(int x, int y);
void canvas();
//IMPLEMENTS
void gotoxy(int x, int y){
    COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void canvas(){
    cout << endl;
    cout << "                           ";
    cout << char(220) << char(220) << char(220) << char(220) << "    ";
    cout << " " << char(220) << char(220) << char(220) << "    ";
    cout << char(220) << "   " << char(220) << "    ";
    cout << char(220) << char(220) << char(220) << char(220) << endl;
    cout << "                           ";
    cout << char(219) << "   " << char(219) << "   " << char(219) << "   " << char(219) << "   ";
    cout << char(219) << char(219) << "  " << char(219) << "   " << char(219) << endl;
    cout << "                           ";
    cout << char(219) << char(223) << char(223) << char(223) << "    " << char(219) << "   " << char(219) << "   ";
    cout << char(219) << " " << char(219) << " " << char(219) << "   " << char(219) << "   " << char(219) << "   " << endl;
    cout << "                           ";
    cout << char(219) << "       " << char(219) << "   " << char(219) << "   ";
    cout << char(219) << "  " << char(219) << char(219) << "   " << char(219) << "   " << char(219) << endl;
    cout << "                           ";
    cout << char(223) << "        " << char(223) << char(223) << char(223) << "    ";
    cout << char(223) << "   " << char(223) << "    " << char(223) << char(223) << char(223) << char(223);
    cout << endl;
    gotoxy(40,9); cout << "START";
    gotoxy(40,10); cout << "QUIT";
    gotoxy(38,9); cout << ">";
    gotoxy(46,9); cout << "<";
    ShowConsoleCursor(false);
    int n = 1;
    char c;
    do{
        if(GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)){
            n = 1;
            gotoxy(38,9); cout << ">";
            gotoxy(46,9); cout << "<";
            gotoxy(38,10); cout << " ";
            gotoxy(46,10); cout << " ";
        }else if(GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)){
            n = 2;
            gotoxy(38,9); cout << " ";
            gotoxy(46,9); cout << " ";
            gotoxy(38,10); cout << ">";
            gotoxy(46,10); cout << "<";
        }else if(GetAsyncKeyState(char(13))){
            if(n==1){
                system("cls");
                gotoxy(40,0); cout << "[1] SINGLEPLAYER" << endl;
                gotoxy(40,1); cout << "[2] MULTIPLAYER" << endl;
                while(player == 0){
                    c = getch();
                    cout << c;
                    if(c == '1') player = 1;
                    if(c == '2') player = 2;
                }
                system("cls");
                return;
            }else{
                system("cls");
                exit(0);
            }
        }
    }while(true);
}

void reset(pad &you, pad &comp, ball &b, bool &started, int &you_score, int &comp_score) {
    b.y = float(height/2);
    b.x = float(width/2 - 1);
    you.y = comp.y = float(height/2);
    comp.vy = 0.0f;
    b.vy = float(rand()%3) - 1.5f;
    b.vx = 1;
    started = false;
    COORD p;
    p.X = 0;
    p.Y = height;
    SetConsoleCursorPosition(hOut,p);
    cout << "\n    Player 1 score: " << comp_score << "\t\tPlayer 2 score: " << you_score << endl;
}

void ShowConsoleCursor(bool showFlag){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out,&cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out,&cursorInfo);
}

int main()
{
    canvas();
    //DRAW BORDER
    for(int i = 0; i < width - 1; i++)
        cout << char(219);
    for(int i = 0; i < height - 1; i++) {
        cout << endl << char(219);
        for(int j = 0; j < width - 3; j++)
            cout << " ";
        cout << char(219);
    }
    cout << endl;
    for(int i = 0; i < width - 1; i++)
        cout << char(219);
    cout << "\n    Player 1 score: 0\t\tPlayer 2 score: 0\n";
    for(int i = 0; i < width - 1; i++)
        cout << char(219);
    // End drawing border
    bool started = false;
    pad you(width-4,height/2,2);
    pad comp(2,height/2,2);
    ball b(width/2, height/2-1);
    int you_score = 0;
    int comp_score = 0;
    // Ball's start velocity, always starts towards you
    b.vx = 1;
    b.vy = float(rand()%3) - 1.5f;
    comp.vy = 0;
    while(true){
        ShowConsoleCursor(false);
        if(started){
            for(int i = 1; i < height; i++){
                gotoxy(width/2-1,i); cout << char(254) << endl;
            }
            if(player == 1){
                // Arrow keys
                if(GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)){
                    you.y -= 1;
                }
                else if(GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)){
                    you.y += 1;
                }
                else if(GetAsyncKeyState('Q')){
                    system("cls");
                    exit(0);
                }
                // Move comp.x towards the ball
                if(b.x <= width/2){
                    comp.vy -= float(comp.y - b.y) / 10.0f;
                    comp.vy *= 0.83f;
                }
                // Apply comp's velocity to current location
                comp.y += comp.vy;
            }
            if(player == 2){
                // Player 1 keys
                if(GetAsyncKeyState(VK_UP)){
                    you.y -= 1;
                }
                else if(GetAsyncKeyState(VK_DOWN)){
                    you.y += 1;
                }
                else if(GetAsyncKeyState('Q')){
                    system("cls");
                    exit(0);
                }
                //Player 2 keys
                if(GetAsyncKeyState('W')){
                    comp.y -= 1;
                }
                else if(GetAsyncKeyState('S')){
                    comp.y += 1;
                }
                else if(GetAsyncKeyState('Q')){
                    system("cls");
                    exit(0);
                }
            }
            // Add player boundaries
            if(you.y < you.size + 1){
                you.y = float( you.size + 1 );
            }
            else if (you.y > height - you.size - 2){
                you.y = float(height - you.size - 2);
            }

            // Add comp boundaries
            if (comp.y < comp.size + 1){
                comp.y = float (comp.size + 1);
            }
            else if(comp.y > height - comp.size - 2){
                comp.y = float (height - comp.size - 2);
            }

            // Make sure ball doesn't exceed it's maximum speed
            if ( b.vy < -maxSpeed ) {
                b.vy = -maxSpeed;
            } else if ( b.vy > maxSpeed ) {
                b.vy = maxSpeed;
            }

            // Apply velocity to balls current location
            b.x += b.vx;
            b.y += b.vy;

            // Check if ball is hitting your pad
            if ( b.x >= you.x - 1 && b.x <= you.x + 1 ) {
                if (b.y > you.y - you.size && b.y <= you.y + you.size + 1) {
                    b.vx *= -1;
                    b.vy += float(b.y - you.y) / 3;
                    b.x = you.x - 1;
                }
            }

            // Check if ball is hitting the computer pad
            if ( b.x <= comp.x + 1 && b.x >= comp.x - 1 ) {
                if (b.y > comp.y - comp.size && b.y <= comp.y + comp.size + 1) {
                    b.vx *= -1;
                    b.vy += float(b.y - comp.y) / 3;
                    b.x = comp.x + 1;
                }
            }

            // Check if ball has gone out of boundaries (a player won/lost)
            if ( b.x >= width-2 ) {
                ++comp_score;
                reset( you, comp, b, started, you_score, comp_score );
            } else if ( b.x <= 0 ) {
                ++you_score;
                reset( you, comp, b, started, you_score, comp_score );
            }

            if ( b.y <= 1 ) {
                b.vy *= -1;
                b.y = 1.0f;
            } else if ( b.y >= height - 1 ) {
                b.vy *= -1;
                b.y = float( height - 1 );
            }
        } else {
            // Wait for user to press the space bar
            COORD p;

            p.X = int ( width / 2 - 16 );
            p.Y = int ( height / 2.0f );

            SetConsoleCursorPosition( hOut, p );

            cout << "Press the space bar to start ...";

            if ( GetAsyncKeyState(VK_SPACE) ) {
                COORD p;

                p.X = int ( width / 2 - 16 );
                p.Y = int ( height / 2.0f );

                SetConsoleCursorPosition( hOut, p );

                cout << "                                ";
                started = true;
            }else if (GetAsyncKeyState('Q')){
                system("cls");
                exit(0);
            }
        }
        // Draw all objects
        you.draw();
        comp.draw();
        b.draw();
        // Delay
        Sleep( delay );
    }
    return 0;
}
