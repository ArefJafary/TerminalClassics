// arefjafary
// 401103231
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"

using namespace std;
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