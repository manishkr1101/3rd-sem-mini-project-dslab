#include "machine.h"

using namespace std;



void displayLogo(){
    
    left_margin();
    cout << "       ###         ###############     #####         #####    " <<endl; left_margin();
    cout << "      ## ##        ###############     ### ###     ### ###   " <<endl; left_margin();
    cout << "     ##   ##             ###           ###   ##   ##   ###" <<endl; left_margin();
    cout << "    ##     ##            ###           ###    ## ##    ###" <<endl; left_margin();
    cout << "   ###########           ###           ###     ###     ###  " <<endl; left_margin();
    cout << "  ##         ##          ###           ###             ###  " <<endl; left_margin();
    cout << " ##           ##         ###           ###             ###    " <<endl; left_margin();
    cout << endl; left_margin();
    cout << "<<<<<<<<<<<<<<<<<<<<< WELCOME TO MY ATM >>>>>>>>>>>>>>>>>>" <<endl;
    cout << endl;
    
    
    
    
    
}

void showHome(){
    displayLogo();

    left_margin(); cout << "Enter your a/c : "; 
}

void showMenu(char* name){
    newLine();
    displayLogo();

    print_centre("Welcome " + to_string(name) + "\n");
    newLine();
    vector<string> options{"Withdraw", "Deposit", "Balance Enquiry", "Change Pin"};
    int i = 1;
    for(string option: options){
        centre();
        cout << i++ << ". " << option << endl;
    }
    centre(); cout << "x. exit" << endl;
    cout << endl;
}

void createAccount(){
    clrscr();
    displayLogo();
    User user;
    cin >> user;
    user.save();
    cout <<endl ;
    user.print();
    cout << endl;
    print_left("----------------------------------------------------------------------------------\n");
    print_left("User created successfuly.\n");
    print_left("Please note your a/c and pin carefully...\n");

}


int withdraw(){
    print_centre("WITHDRAW\n");
    newLine();
    print_left("1. Saving Account\n");
    print_left("2. Current Account\n");
    print_left("x. Main menu\n");
    newLine();
    print_left("Enter choice: ");
    char ch;
    ch = getch();
    int amount;
    if(ch == '1' || ch == '2'){
        clrscr();
        newLine();
        displayLogo();
        newLine();
        print_centre("Enter Amount\n");
        print_centre("   ");
        
        cin >> amount;
        getch();
    }

    return amount;
}




















