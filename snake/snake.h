// snake/snake.h
#ifndef SNAKE_H // Include guard to prevent double inclusion
#define SNAKE_H

extern float refresh_time;
extern int k;
// Function declarations
void setupforsnack(char display[30][30], char hs, char bs, char p, char m, int &nb);
void print(char display[30][30], char hs, char bs, char p, char m, int &nb, int jahat, int &np);
int goup(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int godown(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int goleft(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int goright(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int gotoright(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int gotoleft(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int gotodown(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
int gotoup(char display[30][30], char hs, char bs, char p, char m, int &nb, int &np);
void finishgame(int a);

#endif // SNAKE_H