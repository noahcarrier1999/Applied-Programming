#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account{
    string name;
    int accountNumber;
    double balance;

    Account(string n, int num, double bal) : name(n), accountNumber(num), balance(bal){}

    void displayAccount(){
        cout << "Account Holder: " << name
                  << "\nAccount Number: " << accountNumber
                  << "\nBalance: " << balance <<std::endl;
    }
};

void createAccount(std::vector<Account>& accounts){
    string name;
    int number;
    double initialBalance;
    
    cout << "Enter a Name";
    cin >> name;
    cout << "Enter a Number";
    cin >> number;
    cout << "Enter an Initial Balance";
    cin >> initialBalance;

    accounts.emplace_back(name,number,initialBalance);
    cout << "Account created\n";



}

void displayMenu(std::vector<Account>& accounts){
    
    int choice;

    while(true){
        cout<< "\nBanking Menu\n";
        cout<< "----------------";
        cout<< "1. Create Account\n";
        cout<< "2. Display All Accounts\n";
        cout<< "3. Exit\n";
        cout<< "Enter your choice: ";

        switch(choice){
            case 1: 
                createAccount(accounts);
                break;
            case 2: displayMenu;
        }
    }
}

int main(){

}