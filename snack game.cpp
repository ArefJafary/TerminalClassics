// arefjafary
// 401103231
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void finishgame(int a);
int hardmode(int a[3][3], int user, int cpu);
int easymode(int a[3][3], int user, int cpu);
int twousermode(int a[3][3], int user, int cpu);
void printgame(int a[3][3], int user, int cpu);
void userselect(int a[3][3], int user, int c);
void use2rselect(int a[3][3], int user, int cpu);
void cpuselect(int a[3][3], int user, int cpu);
int check2win(int a[3][3], int user, int cpu);
int check2dontlose(int a[3][3], int user, int cpu);
int check2rand(int a[3][3], int user, int cpu);
int winnercheck(int a[3][3], int user, int cpu);
void setupforsnack(char display[30][30], int size, char hs, char bs, char p, char m);
void setup(char display[30][30], char hs, char bs, char p, char m, int &nb);
void print(char display[30][30], char hs, char bs, char p, char m, int &nb, int jahat, int &np);
int goup(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int godown(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int goleft(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int goright(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int gotoright(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int gotoleft(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int gotodown(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int gotoup(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
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
void setupfordooz()
{

    // setup
    int a[3][3];
    int num, user = 11, cpu = 22, c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            num = (i * 3) + j + 1;
            a[j][i] = num;
        }
    }

    cout << "Hi wellcome to Tic-tac-toe" << endl
         << "Do you want to play with computer?   1_Yes    2_ No" << endl;
    cin >> c;
    if (c == 1)
    {
        cout << "Choose the difficulty level of the game :" << endl
             << "1_ Easy mode     2_ hard mode";
        cin >> c;
        if (c == 2)
            hardmode(a, user, cpu);
        else
            easymode(a, user, cpu);
    }
    else
        twousermode(a, user, cpu);
}

void setupforsnack(char display[30][30], char hs, char bs, char p, char m, int &nb)
{
    cout << "  Enter the speed of the snake" << endl;
    cout << "  for example :  " << endl
         << "  100 makes the game difficult" << endl
         << "  10 makes the game easy" << endl;
    float spead;
    int np, nm;
    cin >> spead;
    refresh_time = 1 / (spead / 10000);
    cout << "  Enter the number of foods :   ";
    cin >> np;
    cout << "  Enter the number of Barriers :   ";
    cin >> nm;
    for (int j = 0; j < 30; j++)
    {
        for (int i = 0; i < 30; i++)
        {
            if (i == 0 || i == 29)
            {
                display[j][i] = '|';
            }
            else if (j == 0 || j == 29)
            {
                display[j][i] = '-';
            }
            else
                display[j][i] = ' ';
        }
    }
    int z = rand() % 27;
    int w = rand() % 27;
    display[w + 2][w + 2] = hs;
    for (int i = 0; i < np; i++)
    {
        int z = rand() % 27;
        int t = rand() % 27;
        display[z + 2][t + 2] = p;
    }
    for (int i = 0; i < nm; i++)
    {
        int z = rand() % 27;
        int t = rand() % 27;
        display[z + 2][t + 2] = m;
    }
    cout << "           use arrow key to contorol           stop with : 0" << endl;
    cout << "                             game start in 3s";
    Sleep(3000);
    goup(display, hs, bs, p, m, nb, np);
}

void setup(char display[30][30], char hs, char bs, char p, char m, int &nb)
{
    cout << "                          wellcome to games that make by Aref jafary" << endl;
    cout << "which game do you whant to play" << endl;
    cout << "     1-snack     2-Tic-tac-toe    " << endl;
    while (true)
    {
        int k;
        cin >> k;
        switch (k)
        {
        case 1:
        {
            setupforsnack(display, hs, bs, p, m, nb);
            break;
        }
        case 2:
            setupfordooz();
        }
    }
}

int goup(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np)
{
    for (int k = 0; k < 100; k++)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (display[i][j] == hs)
                {

                    if (display[i - 1][j] == p)
                    {
                        np--;
                        if (np == 0)
                            return 1;
                        nb++;
                        display[i][j] = bs;
                        display[i - 1][j] = hs;
                    }
                    else if (i == 1 || display[i - 1][j] == m)
                    {
                        return (-1);
                    }
                    else
                    {
                        display[i][j] = bs;
                        display[i - 1][j] = hs;
                        display[i + nb][j] = ' ';
                    }
                    print(display, hs, bs, p, m, nb, 0, np);
                }
            }
        }
    }
    return (0);
}

int godown(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np)
{

    for (int k = 0; k < 100; k++)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (display[i][j] == hs)
                {

                    if (display[i + 1][j] == p)
                    {
                        nb++;
                        np--;
                        if (np == 0)
                            return 1;
                        display[i][j] = bs;
                        display[i + 1][j] = hs;
                    }
                    else if (i == 29 || display[i + 1][j] == m)
                    {
                        return (-1);
                    }
                    else
                    {
                        display[i][j] = bs;
                        display[i + 1][j] = hs;
                        display[i - nb][j] = ' ';
                    }
                    print(display, hs, bs, p, m, nb, 0, np);
                }
            }
        }
    }
    return (0);
}

int goleft(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np)
{
    for (int k = 0; k < 100; k++)
    {
        for (int j = 0; j < 30; j++)
        {
            for (int i = 0; i < 30; i++)
            {
                if (display[i][j] == hs)
                {

                    if (display[i][j - 1] == p)
                    {
                        nb++;
                        np--;
                        if (np == 0)
                            return 1;
                        display[i][j] = bs;
                        display[i][j - 1] = hs;
                    }
                    else if (j == 1 || display[i][j - 1] == m)
                    {
                        return (-1);
                    }
                    else
                    {
                        display[i][j] = bs;
                        display[i][j - 1] = hs;
                        display[i][j + nb] = ' ';
                    }
                    print(display, hs, bs, p, m, nb, 1, np);
                    i = 30;
                    j = 30;
                }
            }
        }
    }
    return (0);
}

int goright(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np)
{
    for (int k = 0; k < 100; k++)
    {
        for (int j = 0; j < 30; j++)
        {
            for (int i = 0; i < 30; i++)
            {
                if (display[i][j] == hs)
                {

                    if (display[i][j + 1] == p)
                    {
                        nb++;
                        np--;
                        if (np == 0)
                            return 1;
                        display[i][j] = bs;
                        display[i][j + 1] = hs;
                    }
                    else if (j == 29 || display[i][j + 1] == m)
                    {
                        return (-1);
                    }
                    else
                    {
                        display[i][j] = bs;
                        display[i][j + 1] = hs;
                        display[i][j - nb] = ' ';
                    }
                    print(display, hs, bs, p, m, nb, 1, np);
                    i = 30;
                    j = 30;
                }
            }
        }
    }
}

int gotoleft(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np)
{
    int jahat = 1;
    for (int j = 0; j < 30; j++)
    {
        for (int i = 0; i < 30; i++)
        {
            int z = 0;
            if (display[i][j] == hs)
            {

                if (display[i - 1][j] == bs)
                {
                    jahat = 0;
                }
            }
        }
    }
    if (jahat)
    {
        while (k < nb)
        {
            for (int j = 0; j < 30; j++)
            {
                for (int i = 0; i < 30; i++)
                {
                    int z = 0;
                    if (display[i][j] == hs)
                    {

                        if (display[i][j - 1] == p)
                        {
                            nb++;
                            np--;
                            if (np == 0)
                                return 1;
                            display[i + nb - 1][j] = bs;
                            display[i][j] = bs;
                            display[i][j - 1] = hs;
                        }
                        else if (j == 1 || display[i][j - 1] == m)
                        {
                            return (-1);
                        }
                        else
                        {
                            display[i][j] = bs;
                            display[i][j - 1] = hs;
                            display[i + nb - k][j + k] = ' ';
                        }
                        print(display, hs, bs, p, m, nb, 1, np);
                        i = 30;
                        j = 30;
                        k++;
                    }
                }
            }
        }
        return (goleft(display, hs, bs, p, m, nb, np));
    }
    else
    {
        while (k < nb)
        {
            for (int j = 0; j < 30; j++)
            {
                for (int i = 0; i < 30; i++)
                {
                    int z = 0;
                    if (display[i][j] == hs)
                    {

                        if (display[i][j - 1] == p)
                        {
                            nb++;
                            np--;
                            if (np == 0)
                                return 1;
                            display[i][j] = bs;
                            display[i][j - 1] = hs;
                        }
                        else if (j == 1 || display[i][j - 1] == m)
                        {
                            return (-1);
                        }
                        else
                        {
                            display[i][j] = bs;
                            display[i][j - 1] = hs;
                            display[i - nb + k][j + k] = ' ';
                        }
                        print(display, hs, bs, p, m, nb, 1, np);
                        i = 30;
                        j = 30;
                        k++;
                    }
                }
            }
        }
        return (goleft(display, hs, bs, p, m, nb, np));
    }
}

int gotoright(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np)
{
    int jahat = 1;
    for (int j = 0; j < 30; j++)
    {
        for (int i = 0; i < 30; i++)
        {
            int z = 0;
            if (display[i][j] == hs)
            {

                if (display[i - 1][j] == bs)
                {
                    jahat = 0;
                }
            }
        }
    }
    if (jahat)
    {
        while (k < nb)
        {
            for (int j = 0; j < 30; j++)
            {
                for (int i = 0; i < 30; i++)
                {
                    int z = 0;
                    if (display[i][j] == hs)
                    {

                        if (display[i][j + 1] == p)
                        {
                            nb++;
                            np--;
                            if (np == 0)
                                return 1;
                            display[i + nb - 1][j] = bs;
                            display[i][j] = bs;
                            display[i][j + 1] = hs;
                        }
                        else if (j == 29 || display[i][j + 1] == m)
                        {
                            return (-1);
                        }
                        else
                        {
                            display[i][j] = bs;
                            display[i][j + 1] = hs;
                            display[i + nb - k][j - k] = ' ';
                        }
                        print(display, hs, bs, p, m, nb, 1, np);
                        i = 30;
                        j = 30;
                        k++;
                    }
                }
            }
        }
        return (goright(display, hs, bs, p, m, nb, np));
    }
    else
    {
        while (k < nb)
        {
            for (int j = 0; j < 30; j++)
            {
                for (int i = 0; i < 30; i++)
                {
                    int z = 0;
                    if (display[i][j] == hs)
                    {

                        if (display[i][j + 1] == p)
                        {
                            nb++;
                            np--;
                            if (np == 0)
                                return 1;
                            display[i][j] = bs;
                            display[i][j + 1] = hs;
                        }
                        else if (j == 29 || display[i][j + 1] == m)
                        {
                            return (-1);
                        }
                        else
                        {
                            display[i][j] = bs;
                            display[i][j + 1] = hs;
                            display[i - nb + k][j - k] = ' ';
                        }
                        print(display, hs, bs, p, m, nb, 1, np);
                        i = 30;
                        j = 30;
                        k++;
                    }
                }
            }
        }
        return (goright(display, hs, bs, p, m, nb, np));
    }
}

int gotodown(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np)
{
    int jahat = 1;
    for (int j = 0; j < 30; j++)
    {
        for (int i = 0; i < 30; i++)
        {
            if (display[i][j] == hs)
            {

                if (display[i][j - 1] == bs)
                {
                    jahat = 0;
                }
            }
        }
    }
    if (jahat)
    {
        while (k < nb)
        {
            for (int i = 0; i < 30; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    if (display[i][j] == hs)
                    {

                        if (display[i + 1][j] == p)
                        {
                            nb++;
                            np--;
                            if (np == 0)
                                return 1;
                            display[i][j] = bs;
                            display[i + 1][j] = hs;
                        }
                        else if (i == 29 || display[i + 1][j] == m)
                        {
                            return (-1);
                        }
                        else
                        {
                            display[i][j] = bs;
                            display[i + 1][j] = hs;
                            display[i - k][j + nb - k] = ' ';
                        }
                        print(display, hs, bs, p, m, nb, 0, np);
                        i = 30;
                        j = 30;
                        k++;
                    }
                }
            }
        }
        return (godown(display, hs, bs, p, m, nb, np));
    }
    else
    {
        while (k < nb)
        {
            for (int i = 0; i < 30; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    if (display[i][j] == hs)
                    {

                        if (display[i + 1][j] == p)
                        {
                            nb++;
                            np--;
                            if (np == 0)
                                return 1;
                            display[i][j] = bs;
                            display[i + 1][j] = hs;
                        }
                        else if (i == 29 || display[i + 1][j] == m)
                        {
                            return (-1);
                        }
                        else
                        {
                            display[i][j] = bs;
                            display[i + 1][j] = hs;
                            display[i - k][j - nb + k] = ' ';
                        }
                        print(display, hs, bs, p, m, nb, 0, np);
                        i = 30;
                        j = 30;
                        k++;
                    }
                }
            }
        }
        return (godown(display, hs, bs, p, m, nb, np));
    }
}

int gotoup(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np)
{
    int jahat = 1;
    for (int j = 0; j < 30; j++)
    {
        for (int i = 0; i < 30; i++)
        {
            if (display[i][j] == hs)
            {
                if (display[i][j - 1] == bs)
                {
                    jahat = 0;
                }
            }
        }
    }
    if (jahat)
    {
        while (k < nb)
        {
            for (int i = 0; i < 30; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    if (display[i][j] == hs)
                    {

                        if (display[i - 1][j] == p)
                        {
                            nb++;
                            np--;
                            if (np == 0)
                                return 1;
                            display[i][j] = bs;
                            display[i - 1][j] = hs;
                        }
                        else if (i == 1 || display[i - 1][j] == m)
                        {
                            return (-1);
                        }
                        else
                        {
                            display[i][j] = bs;
                            display[i - 1][j] = hs;
                            display[i + k][j + nb - k] = ' ';
                        }
                        print(display, hs, bs, p, m, nb, 0, np);
                        i = 30;
                        j = 30;
                        k++;
                    }
                }
            }
        }
        return (goup(display, hs, bs, p, m, nb, np));
    }
    else
    {
        while (k < nb)
        {
            for (int i = 0; i < 30; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    if (display[i][j] == hs)
                    {

                        if (display[i - 1][j] == p)
                        {
                            nb++;
                            np--;
                            if (np == 0)
                            {
                                return 1;
                            }
                            display[i][j] = bs;
                            display[i - 1][j] = hs;
                        }
                        else if (i == 1 || display[i - 1][j] == m || display[i - 1][j] == bs)
                        {
                            return (-1);
                        }
                        else
                        {
                            display[i][j] = bs;
                            display[i - 1][j] = hs;
                            display[i + k][j - nb + k] = ' ';
                        }
                        print(display, hs, bs, p, m, nb, 0, np);
                        i = 30;
                        j = 30;
                        k++;
                    }
                }
            }
        }
        return (goup(display, hs, bs, p, m, nb, np));
    }
}

void print(char display[30][30], char hs, char bs, char p, char m, int &nb, int jahat, int &np)
{
    Sleep(refresh_time);
    system("cls");
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (j == 0)
            {
                cout << endl;
            }
            cout << display[i][j];
        }
    }
    if (_kbhit() && jahat)
    {
        switch (_getch())
        {
        case '0':
        {
            while (!_kbhit())
                ;
            break;
        }
        case 72:
        {
            k = 0;
            finishgame(gotoup(display, hs, bs, p, m, nb, np));
            break;
        }
        case 80:
        {
            k = 0;
            finishgame(gotodown(display, hs, bs, p, m, nb, np));
            break;
        }
        }
    }
    else if (_kbhit() && !jahat)
    {
        switch (_getch())
        {
        case '0':
        {
            while (!_kbhit())
                ;
            break;
        }
        case 75:
        {
            k = 0;
            finishgame(gotoleft(display, hs, bs, p, m, nb, np));
            break;
        }
        case 77:
        {
            k = 0;
            finishgame(gotoright(display, hs, bs, p, m, nb, np));
            break;
        }
        }
    }
}

void finishgame(int a)
{
    if (a == 1)
    {
        cout << "you win";
        exit(0);
    }
    else
    {
        cout << "you lose";
        exit(0);
    }
}
// doozzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz

int hardmode(int a[3][3], int user, int cpu)
{
    int c;
    cout << "start" << endl;
    printgame(a, user, cpu);

    int i = 1, j = 1;
    // step 1
    cout << "enter your choice ";
    cin >> c;
    if (c == 5)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == c && a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = user;
                    break;
                }
            }
        }
        while (i == 1)
            i = rand() % 3;
        while (j == 1)
            j = rand() % 3;
        a[i][j] = cpu;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == c && a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = user;
                    break;
                }
            }
        }
        a[1][1] = cpu;
    }
    printgame(a, user, cpu);

    // step 2
    cout << "enter your choice   ";
    userselect(a, user, cpu);
    if (check2dontlose(a, user, cpu))
        printgame(a, user, cpu);
    else
    {
        check2rand(a, user, cpu);
        printgame(a, user, cpu);
    }

    // step3
    cout << "enter your choice   ";
    userselect(a, user, cpu);
    if (check2win(a, user, cpu))
    {
        cout << "you lose";
        return 0;
    }
    if (check2dontlose(a, user, cpu))
        printgame(a, user, cpu);
    else
    {
        check2rand(a, user, cpu);
        printgame(a, user, cpu);
    }
    // step 4
    cout << "choose ";
    userselect(a, user, cpu);
    if (winnercheck)
    {
        cout << "you win";
        return 0;
    }
    if (check2win(a, user, cpu))
    {
        cout << "you lose";
        return 0;
    }
    else
    {
        check2dontlose(a, user, cpu);
        printgame(a, user, cpu);
        cout << "the game dose not have a winner " << endl;
        return 0;
    }
}

void printgame(int a[3][3], int user, int cpu)
{
    system("cls");
    for (int j = 0; j < 3; j++)
    {
        if (j == 0)
            cout << endl
                 << "............." << endl
                 << ": ";
        else
            cout << endl
                 << ":...:...:...:" << endl
                 << ": ";
        for (int i = 0; i < 3; i++)
        {
            if (a[i][j] == user)
                cout << "X"
                     << " : ";
            else if (a[i][j] == cpu)
                cout << "O"
                     << " : ";
            else
                cout << a[i][j] << " : ";
        }
    }
    cout << endl
         << ":...:...:...:" << endl;
}

void userselect(int a[3][3], int user, int cpu)
{
    int t = 0;
    while (t == 0)
    {
        int c;
        cin >> c;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == c && a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = user;
                    t = 1;
                    break;
                }
            }
        }
    }
}

void use2rselect(int a[3][3], int user, int cpu)
{
    int t = 0;
    while (t == 0)
    {
        int c;
        cin >> c;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == c && a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = cpu;
                    t = 1;
                    break;
                }
            }
        }
    }
}

int check2win(int a[3][3], int user, int cpu)
{
    // row check
    for (int i = 0; i < 3; i++)
    {
        if ((a[i][0] == a[i][1] && cpu == a[i][1]) || (a[i][0] == a[i][2] && cpu == a[i][2]) || (a[i][1] == a[i][2] && cpu == a[i][1]))
        {
            for (int j = 0; j < 3; j++)
                if (a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = cpu;
                    return 1;
                }
        }
    }

    // column check
    for (int j = 0; j < 3; j++)
    {
        if ((a[0][j] == a[1][j] && a[0][j] == cpu) || (a[0][j] == a[2][j] && a[2][j] == cpu) || (a[2][j] == a[1][j] && a[2][j] == cpu))
        {
            for (int i = 0; i < 3; i++)
                if (a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = cpu;
                    return 1;
                }
        }
    }

    // main diameter check
    if ((a[1][1] == a[2][2] && cpu == a[2][2]) || (a[0][0] == a[2][2] && cpu == a[2][2]) || (a[0][0] == cpu && a[1][1] == a[0][0]))
    {
        for (int i = 0; i < 3; i++)
            if (a[i][i] != user && a[i][i] != cpu)
            {
                a[i][i] = cpu;
                return 1;
            }
    }

    // ghotr faree check
    if ((a[0][2] == a[2][2] && cpu == a[2][2]) || (a[2][0] == a[2][2] && cpu == a[2][2]) || (a[2][0] == cpu && a[0][2] == a[2][0]))
    {
        for (int i = 0; i < 3; i++)
            if (a[i][i] != user && a[i][i] != cpu)
            {
                a[i][i] = cpu;
                return 1;
            }
    }
    return 0;
}

int check2dontlose(int a[3][3], int user, int cpu)
{
    // row check
    for (int i = 0; i < 3; i++)
    {
        if ((a[i][0] == a[i][1] && user == a[i][1]) || (a[i][0] == a[i][2] && user == a[i][2]) || (a[i][1] == a[i][2] && user == a[i][1]))
        {
            for (int j = 0; j < 3; j++)
                if (a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = cpu;
                    return 1;
                }
        }
    }

    // column check
    for (int j = 0; j < 3; j++)
    {
        if ((a[0][j] == a[1][j] && a[0][j] == user) || (a[0][j] == a[2][j] && a[2][j] == user) || (a[2][j] == a[1][j] && a[2][j] == user))
        {
            for (int i = 0; i < 3; i++)
                if (a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = cpu;
                    return 1;
                }
        }
    }

    // main diameter check
    if ((a[1][1] == a[2][2] && user == a[2][2]) || (a[0][0] == a[2][2] && user == a[2][2]) || (a[0][0] == user && a[1][1] == a[0][0]))
    {
        for (int i = 0; i < 3; i++)
            if (a[i][i] != user && a[i][i] != cpu)
            {
                a[i][i] = cpu;
                return 1;
            }
    }

    // ghotr faree check
    if ((a[0][2] == a[2][2] && user == a[2][2]) || (a[2][0] == a[2][2] && user == a[2][2]) || (a[2][0] == user && a[0][2] == a[2][0]))
    {
        for (int i = 0; i < 3; i++)
            if (a[i][i] != user && a[i][i] != cpu)
            {
                a[i][i] = cpu;
                return 1;
            }
    }
    return 0;
}

int check2rand(int a[3][3], int user, int cpu)
{
    int r = rand() % 2;

    // row check
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] != user && a[i][1] != user && a[i][2] == cpu)
        {
            a[i][r] = cpu;
            return 0;
        }
        else if (a[i][2] != user && a[i][1] != user && a[i][0] == cpu)
        {
            if (r == 0)
                r = 2;
            a[i][r] = cpu;
            return 0;
        }
        else if (a[i][0] != user && a[i][2] != user && a[i][1] == cpu)
        {
            if (r == 1)
                r = 2;
            a[i][r] = cpu;
            return 0;
        }
    }

    // column check
    for (int j = 0; j < 3; j++)
    {
        if (a[0][j] != user && a[1][j] != user && a[2][j] == cpu)
        {
            a[r][j] = cpu;
            return 0;
        }
        else if (a[2][j] != user && a[1][j] != user && a[0][j] == cpu)
        {
            if (r == 0)
                r = 2;
            a[r][j] = cpu;
            return 0;
        }
        else if (a[0][j] != user && a[2][j] != user && a[1][j] == cpu)
        {
            if (r == 1)
                r = 2;
            a[r][j] = cpu;
            return 0;
        }
    }
    // main diameter check

    if (a[0][0] != user && a[1][1] != user && a[2][2] == cpu)
    {
        a[r][r] = cpu;
        return 0;
    }
    else if (a[2][2] != user && a[1][1] != user && a[0][0] == cpu)
    {
        if (r == 0)
            r = 2;
        a[r][r] = cpu;
        return 0;
    }
    else if (a[0][0] != user && a[2][2] != user && a[1][1] == cpu)
    {
        if (r == 1)
            r = 2;
        a[r][r] = cpu;
        return 0;
    }

    // ghotr faree check
    if (a[0][2] != user && a[1][1] != user && a[2][0] == cpu)
    {
        if (r == 0)
            a[0][2] = cpu;
        else
            a[1][1] = cpu;
        return 0;
    }
    else if (a[2][0] != user && a[1][1] != user && a[0][2] == cpu)
    {
        if (r == 0)
            a[0][2] = cpu;
        else
            a[1][1] = cpu;
        return 0;
    }
    else if (a[0][2] != user && a[2][0] != user && a[1][1] == cpu)
    {
        if (r == 0)
            a[0][2] = cpu;
        else
            a[2][0] = cpu;
        return 0;
    }
}

int easymode(int a[3][3], int user, int cpu)
{
    // step 1
    printgame(a, user, cpu);
    cpuselect(a, user, cpu);
    printgame(a, user, cpu);
    userselect(a, user, cpu);
    printgame(a, user, cpu);
    // step 2
    cpuselect(a, user, cpu);
    printgame(a, user, cpu);
    userselect(a, user, cpu);
    printgame(a, user, cpu);
    // step 3
    cpuselect(a, user, cpu);
    printgame(a, user, cpu);
    userselect(a, user, cpu);
    printgame(a, user, cpu);
    if (winnercheck(a, user, cpu) == 1)
        cout << "you win";
    else if (winnercheck(a, user, cpu) == 0)
        cout << "you lose";
    // step4
    else
    {
        cpuselect(a, user, cpu);
        printgame(a, user, cpu);
        userselect(a, user, cpu);
        printgame(a, user, cpu);
        if (winnercheck(a, user, cpu) == 1)
            cout << "you win";
        else if (winnercheck(a, user, cpu) == 0)
            cout << "you lose";
        else
        {
            cpuselect(a, user, cpu);
            if (winnercheck(a, user, cpu) == 0)
                cout << "you lose";
            else
                cout << "game dose not have a winner";
        }
    }

    return 0;
}

void cpuselect(int a[3][3], int user, int cpu)
{
    int y = 0;
    while (y == 0)
    {
        int z = rand() % 9 + 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == z && a[i][j] != user && a[i][j] != cpu)
                {
                    a[i][j] = cpu;
                    y = 1;
                    break;
                }
            }
        }
    }
}

int winnercheck(int a[3][3], int user, int cpu)
{

    // row
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][0] == a[i][2])
        {
            if (a[i][0] == user)
                return 1;
            else
                return 0;
        }
    }

    // column check
    for (int j = 0; j < 3; j++)
    {
        if (a[0][j] == a[1][j] && a[1][j] == a[2][j])
        {
            if (a[0][j] == user)
                return 1;
            else
                return 0;
        }
    }
    // main diameter check
    if (a[0][0] == a[1][1] && a[0][0] == a[2][2])
    {
        if (a[0][0] == user)
            return 1;
        else
            return 0;
    }

    // ghotr faree
    if (a[0][2] == a[1][1] && a[2][0] == a[1][1])
    {
        if (a[1][1] == user)
            return 1;
        else
            return 0;
    }
}

int twousermode(int a[3][3], int user, int cpu)
{
    // setap
    char user1[80], user2[80];
    int b;
    b = rand() % 2;
    cout << "enter the player one name" << endl
         << "player 1 : ";
    cin >> user1;
    cout << "enter the player two name" << endl
         << "player 2 : ";
    cin >> user2;
    if (b == 0)
        cout << endl
             << user1 << " is O and he should start the game ." << endl
             << user2 << " is X";
    else
        cout << endl
             << user2 << " is O and he should start the game ." << endl
             << user1 << " is X";
    // step 1
    printgame(a, user, cpu);
    cout << "O enter your choice";
    use2rselect(a, user, cpu);
    printgame(a, user, cpu);
    cout << "X enter your choice";
    userselect(a, user, cpu);
    // step 2
    printgame(a, user, cpu);
    cout << "O enter your choice";
    use2rselect(a, user, cpu);
    printgame(a, user, cpu);
    cout << "X enter your choice";
    userselect(a, user, cpu);

    // step 3
    printgame(a, user, cpu);
    cout << "O enter your choice";
    use2rselect(a, user, cpu);
    printgame(a, user, cpu);
    if (winnercheck(a, user, cpu) == 0)
    {
        if (b == 0)
            cout << user1 << " is winner";
        else
            cout << user2 << " is winner";
        return 0;
    }
    else if (winnercheck(a, user, cpu) == 1)
    {
        if (b != 0)
            cout << user1 << " is winner";
        else
            cout << user2 << " is winner";
        return 0;
    }
    else
    {
        cout << "X enter your choose";
        userselect(a, user, cpu);
        if (winnercheck(a, user, cpu) == 0)
        {
            if (b == 0)
                cout << user1 << " is winner";
            else
                cout << user2 << " is winner";
            return 0;
        }
        else if (winnercheck(a, user, cpu) == 1)
        {
            if (b != 0)
                cout << user1 << " is winner";
            else
                cout << user2 << " is winner";
            return 0;
        }
        else
        {
            // step 4
            printgame(a, user, cpu);
            cout << "X enter your choice";
            use2rselect(a, user, cpu);
            printgame(a, user, cpu);
            cout << "O enter your choice";
            userselect(a, user, cpu);
            if (winnercheck(a, user, cpu) == 0)
            {
                if (b == 0)
                    cout << user1 << " is winner";
                else
                    cout << user2 << " is winner";
            }
            else if (winnercheck(a, user, cpu) == 1)
            {
                if (b != 0)
                    cout << user1 << " is winner";
                else
                    cout << user2 << " is winner";
            }
            else
                cout << "The game does not have winner";
            return 0;
        }
    }
}
