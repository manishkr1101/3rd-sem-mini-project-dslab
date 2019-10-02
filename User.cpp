
#include "User.h"

const string User::USERS_FILE_NAME = "users.txt";

User::User(){

}

User::User(string _fname, string _lname, int _balance):fname(_fname),lname(_lname),balance(_balance) {
    acc_no = User::generateAccNo();
    pin = User::generatePin();
    string acc_no_string = to_string(acc_no);
    
    MINI_ST_FIILE_NAME = acc_no_string + ".txt";
}

User::~User(){

}

void User::save(){
    ofstream file;
    file.open(User::USERS_FILE_NAME, ios::app);

    //acc_no fname lname pin balance FILENAME
    file << acc_no << " " << fname << " " << lname << " " << pin << " " << balance << " " << MINI_ST_FIILE_NAME << "\n";

    file.close();
}

void User::print(){
    cout<< fname << endl << acc_no << endl;
}

ostream& operator<<(ostream& os, User &user){
    os<< "name: "<< user.fname << endl << "a/c: " << user.acc_no <<"\npin: " << user.pin << "\nbalance: " << user.balance << "\nfile: " << user.MINI_ST_FIILE_NAME << endl;
    return os;
}

list<User> User::getUsers(){
    list<User> l;
    ifstream file;
    file.open(User::USERS_FILE_NAME);
    User user;

    // file >>user.acc_no >>user.fname >>user.lname >>user.pin >>user.balance >>user.MINI_ST_FIILE_NAME;
    // l.push_back(user);

    while(!file.eof()){
        file >>user.acc_no >>user.fname >>user.lname >>user.pin >>user.balance >>user.MINI_ST_FIILE_NAME;
        l.push_back(user);
    }
    l.pop_back(); // for a bug which adds last item again in end

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
    file.open(User::USERS_FILE_NAME);
    User *user = new User();

    while(!file.eof()){
        file >>user->acc_no >>user->fname >>user->lname >>user->pin >>user->balance >>user->MINI_ST_FIILE_NAME;
        if(acc_no == user->acc_no){
            file.close();
            return user;
        }
    }
    

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

