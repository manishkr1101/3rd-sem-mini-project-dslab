#include <iostream>
#include <fstream>
#include <string.h>

#include "User.h"
#include "machine.h"
#include "common.h"
using namespace std;

void test(){
    // User::printAllUsers();
    char ch;
    ch = getch();
    cout << ch;
    ch = getch();
    cout << ch;ch = getch();
    cout << ch;ch = getch();
    cout << ch;ch = getch();
    cout << ch;
}



int main()
{
    test();

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
        acc_no = 654357; pin = 6793;
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
                        
                        getch();
                    }
                    break;
                case '2':
                    {
                        
                    }
                    break;
                case '3':
                    {
                        
                    }
                    break;

                case '4':
                    {
                        
                    }
                    break;
                
                default:
                    break;
                }



            }while(ch != 'x');



            

        }
        else{
            print_left("Authentication failed.\n");

        }
    }


    
    
    return 0;
}



