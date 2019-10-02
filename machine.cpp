#include "machine.h"
#include <iostream>
#include <vector>
using namespace std;

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

void displayLogo(){
    centre();
    cout << "SBI BANK\n";
    
    vector<string> options{"Withdraw", "Deposit", "Check Balance"};
    int i = 1;
    for(string option: options){
        left_margin();
        cout << i++ << ". " << option << endl;
    }
    
    
}
