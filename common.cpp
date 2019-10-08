#include "common.h"






/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}









void clrscr(){
    system("clear");
}



void left_margin(){
    for(int i=0;i<LEFT_MARGIN; i++){
        cout << ' ';
    }
}

void centre(){
    for(int i=0;i<CENTRE; i++){
        cout << ' ';
    }
}

void print_left(string str){
    left_margin();
    cout << str;
}

void print_centre(string str){
    centre();
    cout << str;
}

string to_string(char* value){
    string str = "";
    int i = 0;
    while (value[i] != '\0')
    {
        str.push_back(value[i]);
        i++;
    }
    return str;
    
}

void to_upper(char* str){
    int i=0;
    while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }
}

