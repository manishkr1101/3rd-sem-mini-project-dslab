#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <time.h>

using namespace std;

class User{
    static const string USERS_FILE_NAME;
    char name[20];
    int acc_no;
    int pin;
    int balance;
public:
    User();
    User(char* _name, int _balance);
    ~User();
    void save(); //save user to file
    
    void updateBalance(int);
    void updateName(char*);
    void print(); //print details of user
    void printStatement(); //print mini statement of user
    void deposit(int);
    void withdraw(int);
    int getBalance();

    friend ostream& operator<<(ostream& os, User &user);
    static list<User> getUsers(); //return list of all users
    static User* find(int acc_no);
    static User* login(int acc_no, int pin);
private:
    void update();
    static int generateAccNo();// return next acc no to be created
    static int generatePin(); // return unique 4 digit pin
};



#endif