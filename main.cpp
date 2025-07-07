// main.cpp
// arefjafary
// 401103231
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "snake/snake.h"
#include "tictactoe/tictactoe.h"

using namespace std;

void setup(char display[30][30], char hs, char bs, char p, char m, int &nb);

// Global variables (consider moving these to respective game files)
float refresh_time;
int k = 0;

int main()
{
    char p = '$';
    char m = '#';
    char hs = 'V';
    char bs = 'X';
    int nb = 1;
    const int size = 30;
    char display[size][size];

    setup(display, hs, bs, p, m, nb);
    return 0;
}

void setup(char display[30][30], char hs, char bs, char p, char m, int &nb)
{
    cout << "Welcome to games by Aref jafary" << endl;
    cout << "Which game do you want to play?" << endl;
    cout << "     1-Snake     2-Tic-tac-toe" << endl;

    while (true)
    {
        int k;
        cin >> k;
        switch (k)
        {
        case 1:
            setupforsnack(display, hs, bs, p, m, nb);
            break;
        case 2:
            setupfortictactoe();
            break;
        default:
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    }
}
