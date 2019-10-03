#include <iostream>
#include <fstream>
#include <string.h>
#include "User.h"
#include "machine.h"

using namespace std;


int main()
{
    User::printAllUsers();
    User *user = User::login(654332, 9767);
    if(user){
        cout << *user;
        // char name[20];
        // scanf("%[^\n]s", name);
        // user->updateName(name);
        // cout << *user;
    }
    else{
        cout << "user not found\n";
    }
    return 0;
}

void showLogo(){

}

