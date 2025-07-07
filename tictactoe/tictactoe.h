// tictactoe/tictactoe.h
#ifndef TICTACTOE_H
#define TICTACTOE_H

void setupfortictactoe();
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

#endif // TICTACTOE_H