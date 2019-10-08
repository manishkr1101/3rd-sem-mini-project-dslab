#include <iostream>
#include <fstream>
#include <string.h>

#include "User.h"
#include "machine.h"
#include "common.h"
using namespace std;

// g++ main.cpp User.cpp common.cpp machine.cpp && ./a.out

void test(){
    User::printAllUsers();
    
}



int main()
{
    // test();
    // return 0;
    User::checkFile();
    clrscr();
    newLine();
    displayLogo();
    int acc_no, pin;
    char ch;

    print_centre("1. Create an account.\n");
    print_centre("2. Already have an account.\n");

    print_left("Enter your choice : ");
    // cin >> ch;
    cin.getline(&ch, 2, '\n');
    

    if(ch == '1'){
        createAccount();
    }
    else if(ch == '2'){
        left_margin(); cout << "Enter your a/c : "; cin>>acc_no;
        left_margin(); cout << "Enter your pin : "; cin>>pin;
        acc_no = 654358; pin = 1111;
        User *user = User::login(acc_no, pin);
        if(user){
            // user successfuly logged in
            // getch();

            do{
                clrscr();
                showMenu(user->getName());
                cout << endl;
                print_left("Enter your choice: ");
                ch = getch();

                clrscr();
                newLine();
                displayLogo();
                newLine();


                switch (ch)
                {
                case '1':
                    {
                        int amount = withdraw();
                        if(amount>0){
                            user->withdraw(amount);
                            newLine();
                            newLine();
                            print_left("Rs." + to_string(amount) + " has been deducted succesfuly..");
                        }
                        getch();
                    }
                    break;
                case '2':
                    {
                        print_centre("DEPOSIT\n");
                        newLine();
                        print_left("Enter amount to deposite: ");
                        int amount;
                        cin >> amount; getch();
                        user->deposit(amount);

                        print_left("Rs. " + to_string(amount) + " deposited successfully...");
                        getch();

                    }
                    break;
                case '3':
                    {
                        print_centre("BALANCE ENQUIRY\n");
                        newLine();
                        print_left("1. Saving Account\n");
                        print_left("2. Current Account\n");
                        print_left("x. Main menu\n");
                        newLine();
                        print_left("Enter choice: ");
                        char ch;
                        ch = getch();

                        if(ch == '1' || ch == '2'){
                            clrscr();
                            newLine();
                            displayLogo();
                            newLine();
                            print_centre("Your Current Balance is\n");
                            print_centre("    ");
                            
                            cout << "Rs." << user->getBalance() ;
                            getch();
                        }

                    }
                    break;

                case '4':
                    {
                        newLine();
                        print_centre("Enter your pin\n");
                        print_centre("        ");
                        int oldPin, newPin;
                        cin>>oldPin;
                        newLine();
                        print_centre("Enter your new pin\n");
                        print_centre("        ");
                        cin>>newPin;

                        while(newPin/10000 != 0){
                            print_centre("invalid pin.\n");
                            newLine();
                            print_centre("Try Again.\n");
                            print_centre("         ");
                            cin>>newPin;
                        }



                        getch();
                        newLine();
                        if(user->updatePin(oldPin, newPin)){
                            print_left("Your pin has been changed successfuly...");
                        }
                        else{
                            print_left("your pin didn't match... ");

                        }
                        getch();
                    }
                    break;
                
                default:
                    break;
                }



            }while(ch != 'x');

            clrscr();

            

        }
        else{
            print_left("Authentication failed.\n");

        }
    }

    
    
    
    return 0;
}



