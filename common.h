#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <termios.h>
#include <stdio.h>
#include <iomanip>

inline void newLine(){std::cout<<'\n';}

static struct termios old, current;

void initTermios(int);
void resetTermios(void);
char getch_(int);
char getch(void);
char getche(void);

const int LEFT_MARGIN = 40;
const int CENTRE = 60;
using namespace std;
void clrscr();
void left_margin();
void centre();
void print_left(string str);
void print_centre(string str);
string to_string(char*);
void to_upper(char*);
string format(double);

#endif