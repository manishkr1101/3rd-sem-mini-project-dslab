
#include "User.h"

const string User::USERS_FILE_NAME = "users.dat";

User::User(){

}

User::User(char* _name, int _balance):balance(_balance) {
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

void User::updateBalance(int newBalance){
    balance = newBalance;
    update();
}

void User::updateName(char* newName){
    strcpy(name, newName);
    update();
}

void User::updatePin(int newPin){
    pin = newPin;
    update();
}

void User::deposit(int amt){
    balance += amt;
    updateBalance(balance);
}

void User::withdraw(int amt){
    balance -= amt;
    updateBalance(balance);
}

int User::getBalance(){
    return balance;
}

char* User::getName(){
    return User::name;
}

void User::print(){
    cout<< name << endl << acc_no << endl;
}

ostream& operator<<(ostream& os, User &user){
    os<< "name: "<< user.name << endl << "a/c: " << user.acc_no <<"\npin: " << user.pin << "\nbalance: " << user.balance  << endl;
    return os;
}

istream& operator>>(istream& is, User &user){
    
    char name[20];
    int bal;
    print_left("enter name: ");
    // scanf("%[^\n]s", name);
    is.getline(name, 20, '\n');
    // is.getline(name, 20,  '\n');
    print_left("enter initial balance: ");
    // scanf("%d", &bal);
    is >> bal;
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

