#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <time.h>
#include <limits>
#include "common.h"

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
    
    
    void updateName(char*);
    bool updatePin(int,int);
    void print(); //print details of user
    void printStatement(); //print mini statement of user
    void deposit(int);
    void withdraw(int);
    int getBalance();
    char* getName();

    friend ostream& operator<<(ostream& os, User &user);
    friend istream& operator>>(istream& is, User &user);
    
    static void printAllUsers();
    static User* login(int acc_no, int pin);
    static void checkFile();
private:

    void update();
    void updateBalance(int);
    static User* find(int acc_no);
    static int generateAccNo();// return next acc no to be created
    static int generatePin(); // return unique 4 digit pin
    static list<User> getUsers(); //return list of all users
};



#endif