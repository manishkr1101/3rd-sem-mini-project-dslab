
#include "User.h"

const string User::USERS_FILE_NAME = "users.dat";

User::User(){

}

User::User(char* _name, double _balance):balance(_balance) {
    strcpy(name, _name);
    acc_no = User::generateAccNo();
    pin = User::generatePin();
    // string acc_no_string = to_string(acc_no);
    
    // MINI_ST_FIILE_NAME = acc_no_string + ".txt";
}

User::~User(){

}

void User::save(){
    ofstream file;
    if(find(acc_no)) return;
    file.open(User::USERS_FILE_NAME, ios::app|ios::binary);

    file.write((char*)this, sizeof(*this));

    //acc_no fname lname pin balance FILENAME
    // file << acc_no << " " << fname << " " << lname << " " << pin << " " << balance << " " << MINI_ST_FIILE_NAME << "\n";

    file.close();
}

void User::update(){
    fstream file;
    file.open(User::USERS_FILE_NAME, ios::in|ios::out|ios::ate|ios::binary);

    file.seekg(0);
    User user;
    file.read((char*)&user, sizeof(user));
    if(file.is_open()){
        while(!file.eof()){
            
            if(user.acc_no == this->acc_no){
                file.seekp(file.tellp() - sizeof(user));
                file.write((char*)this, sizeof(*this));
                break;
            }
            file.read((char*)&user, sizeof(user));
        }
        
    }
    file.close();

}

void User::updateBalance(double newBalance){
    balance = newBalance;
    update();
}

void User::updateName(char* newName){
    strcpy(name, newName);
    update();
}

bool User::updatePin(int oldPin, int newPin){
    if(oldPin == pin){
        pin = newPin;
        update();
        return true;
    }
    return false;
}

void User::deposit(double amt){
    balance += amt;
    updateBalance(balance);
}

void User::withdraw(double amt){
    balance -= amt;
    updateBalance(balance);
}

double User::getBalance(){
    return balance;
}

char* User::getName(){
    return User::name;
}

void User::print(){
    print_centre("NAME      : " + to_string(name) + "\n");
    print_centre("A/C       : " + to_string(acc_no) + "\n");
    print_centre("PIN       : " + to_string(pin) + "\n");
    print_centre("BALANCE   : " + format(balance) + "\n");
}

ostream& operator<<(ostream& os, User &user){
    os<< "name: "<< user.name << endl << "a/c: " << user.acc_no <<"\npin: " << user.pin << "\nbalance: " << user.balance  << endl;
    return os;
}

istream& operator>>(istream& is, User &user){
    
    char name[20];
    double bal;
    print_left("Enter Name              : ");
    // scanf("%[^\n]s", name);
    is.getline(name, 20, '\n');
    to_upper(name);
    // is.getline(name, 20,  '\n');
    print_left("Enter Initial Balance   : ");
    // scanf("%d", &bal);
    is >> bal;
    // char bal_str[10];
    // is.getline(bal_str, 10, '\n');
    // bal = stoi(bal_str);
    // print_centre("balace scanned");
    // to_upper(name);
    User u(name, bal);
    user = u;
    return is;
}

list<User> User::getUsers(){
    list<User> l;
    ifstream file;
    file.open(User::USERS_FILE_NAME, ios::in|ios::binary);
    User user;

    if(file.is_open()){
        while (!file.eof())
        {
            // cout << file.tellg() << " ";
            file.read((char*)&user, sizeof(user));
            l.push_back(user);
            // cout << user;
        }
        l.pop_back();
        
    }


    // file >>user.acc_no >>user.fname >>user.lname >>user.pin >>user.balance >>user.MINI_ST_FIILE_NAME;
    // l.push_back(user);
    // while(!file.eof()){
    //     cout << file.tellg() << " ";
    //     file >>user.acc_no >>user.fname >>user.lname >>user.pin >>user.balance >>user.MINI_ST_FIILE_NAME;
    //     l.push_back(user);
    // }
    // l.pop_back(); // for a bug which adds last item again in end



    file.close();

    return l;
}

// STATIC FUNCTIONS

void User::checkFile(){
    fstream file(User::USERS_FILE_NAME);
    if(!file.is_open()){
        ofstream file(User::USERS_FILE_NAME, ios::out);
        file.close();
    }
    file.close();

    // check global.txt
    file.open("global.txt");
    if(!file.is_open()){
        ofstream file("global.txt", ios::out);
        file.close();
    }
}

int User::generateAccNo(){
    ifstream file;
    file.open("global.txt");
    int acc_no;
    file >> acc_no;
    
    file.close();

    ofstream ofile("global.txt");
    ofile << (acc_no + 1);
    ofile.close();

    
    return acc_no;
}

int User::generatePin(){
    srand(time(0));
    return rand()%10000;
}

User* User::find(int acc_no){
    ifstream file;
    file.open(User::USERS_FILE_NAME, ios::in|ios::binary);
    User *user = new User();

    while (!file.eof())
    {
        file.read((char*)user, sizeof(*user));
        if(acc_no == user->acc_no){
            file.close();
            return user;
        }
    }
    

    // while(!file.eof()){
    //     file >>user->acc_no >>user->fname >>user->lname >>user->pin >>user->balance >>user->MINI_ST_FIILE_NAME;
    //     if(acc_no == user->acc_no){
    //         file.close();
    //         return user;
    //     }
    // }
    

    file.close();
    return NULL;

}

User* User::login(int acc_no, int pin){
    User* user = find(acc_no);
    if(user && user->pin == pin){
        return user;
    }
    return NULL;
}

void User::printAllUsers(){
    list<User> users = User::getUsers();
    for(auto user: users){
        cout << user << endl;
    }
}

