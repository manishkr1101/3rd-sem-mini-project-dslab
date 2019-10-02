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
    string fname;
    string lname;
    int acc_no;
    int pin;
    int balance;
    string MINI_ST_FIILE_NAME;
public:
    User();
    User(string _fname, string _lname, int _balance);
    ~User();
    void save(); //save user to file
    void update();
    void print(); //print details of user
    void printStatement(); //print mini statement of user
    void deposit();
    void withdraw();
    void getBalance();

    friend ostream& operator<<(ostream& os, User &user);
    static list<User> getUsers(); //return list of all users
    static User* find(int acc_no);
    static User* login(int acc_no, int pin);
private:
    static int generateAccNo();// return next acc no to be created
    static int generatePin(); // return unique 4 digit pin
};



#endif