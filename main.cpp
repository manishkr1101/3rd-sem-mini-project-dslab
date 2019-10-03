#include <iostream>
#include <fstream>
#include <string.h>
#include "User.h"
#include "machine.h"

using namespace std;

class Test{
    static string d;
    char name[20];
    char roll[10];
    public:
    void input(){
        
        strcpy(name, "mithlesh raj");
        strcpy(roll, "12345678");
    }
    void print(){
        cout << d << name << roll;
    }
};
string Test::d = "paap";
void test(){
    fstream file;
    file.open("test.dat", ios::in|ios::app|ios::binary);
    if(file.is_open()){
        Test t;
        // t.input();
        // file.write((char*)&t, sizeof(t));
        file.read((char*)&t, sizeof(t));
        // file.read((char*)&t, sizeof(t));
        t.print();
        file.close();
        
    }
    else{
        ofstream file("test.dat");
    }
    
    file.close();
}



int main()
{
    char name[20];
    int bal;
    scanf("%[^\n]s", name);
    scanf("%d", &bal);
    User user(name, bal);
    cout << user;
    return 0;
}

void showLogo(){

}

