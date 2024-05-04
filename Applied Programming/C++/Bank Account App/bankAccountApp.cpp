#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Account
{
protected:
    string owner;
    double balance;

public:

    Account(string owner, double balance)
    {
        this->owner = owner;
        this->balance = balance;
    }

    string getOwner(){
        return owner;
    }

    double getBalance(){
        return balance;
    }

    static void deleteAccount(vector<Account*>& accounts){

        int index;
        cout << "What is the index of the account you want to delete?";
        cin >> index;

        delete accounts[index];
        accounts.erase(accounts.begin() + index); // Remove the pointer from the vector
        cout << "Account at index " << index << " deleted successfully." << endl;
    }

    // withdraw function
    virtual void withdraw(double amount)
    {
        balance -= amount;
    }

    // addFunds function
    virtual void addFunds(double amount)
    {
        balance += amount;
    }

    // display function
    virtual void display() const
    {
        cout <<"Owner: " << owner << endl << "Balance: "<< balance << endl;
    }

    

    static void displayAccounts(const vector<Account*> &accounts)
    {
        int index = 0;
        for (const auto &account : accounts)
        {
            cout << "Index: " << index << endl;
            account->display();
            cout << "---" << endl;
            index++;
        }
    }

    static void depositToAccount(vector<Account*> &accounts)
    {
        int index;
        double ammount;
        cout << "Enter Account Index: EXP: 0,1,2,3,4" << endl;
        cin >> index;
        cout << "Enter Ammount: " << endl;
        cin >> ammount;

        if (index >= 0 && index < accounts.size())
        {
            accounts[index]->addFunds(ammount);
        }
        else
        {

            cout << "Not a correct Index";
        }
    }

    static void withdrawFromAccount(vector<Account*> &accounts)
    {
        int index;
        double ammount;
        cout << "Enter Account Index: EXP: 0,1,2,3,4" << endl;
        cin >> index;
        cout << "Enter Ammount: " << endl;
        cin >> ammount;

        if (index >= 0 && index < accounts.size())
        {
            accounts[index]->withdraw(ammount);
        }
        else
        {
            cout << "Not a correct Index";
        }
    }

    

    
};







class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(string owner, double balance, double interestRate) : Account(owner, balance), interestRate(interestRate) {}

    double getInterestRate() const {  // Getter for interestRate
        return interestRate;
    }

    void applyInterest()
    {
        balance += balance * (interestRate / 100);
    }

    virtual void addFunds(double amount) override
    {
        Account::addFunds(amount); // Optionally add interest when depositing
        applyInterest();
    }

    virtual void display() const override
    {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

   
};

void writeToFile(vector<Account*>& accounts)
    {
        ofstream file("accounts.txt");
       
        for (const auto& account : accounts) {
        SavingsAccount* savingsAcc = dynamic_cast<SavingsAccount*>(account);
        if (savingsAcc) {
            // It's a savings account, write additional information
            file << "Savings " << savingsAcc->getOwner() << " " << savingsAcc->getBalance() << " " << savingsAcc->getInterestRate() << endl;
        } else {
            // It's a regular account
            file << "Checking " << account->getOwner() << " " << account->getBalance() << endl;
        }
    }

        file.close();
    }

void readFromFile(vector<Account*>& accounts)
    {
        string type,owner;
        double balance, interestRate;
        ifstream file("accounts.txt");

        while (file >> type >> owner >> balance) {
        if (type == "Savings") {
            file >> interestRate;
            accounts.push_back(new SavingsAccount(owner, balance, interestRate));
        } else {
            accounts.push_back(new Account(owner, balance));
        }
    }
    }

 void createAccount(vector<Account*>& accounts)
    {
        string owner;
        double balance;

        cout << "\n";
        cout << "What is the name of the Owner? \n";
        cin >> owner;
        cout << "What is the starting balance? \n";
        cin >> balance;

        Account* tempAccount = new Account(owner, balance);
        accounts.push_back(tempAccount);
    }

 void createSavingsAccount(vector<Account*> &accounts)
    {
        string owner;
        double balance, interestRate;
        cout << "\n";
        cout << "Enter the owner's name: ";
        cin >> owner;
        cout << "Enter the initial balance: $";
        cin >> balance;
        cout << "Enter the interest rate (%): ";
        cin >> interestRate;

        accounts.push_back(new SavingsAccount(owner, balance, interestRate));
    }

int main()
{

    vector<Account*> accounts;

    readFromFile(accounts);

    bool running = true;
    while (running)
    {
        int choice;
        cout << "\n";
        cout << "Welcome to the Bank Account Manager\n";
        cout << "1. Create an Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Save and Exit\n";
        cout << "Enter Your Choice: ";
        

        cin >> choice;

        switch (choice)
        {
        case 1:
            int choice;
            cout<< "Select Account Type\n";
            cout<< "1. Create Checking Account\n";
            cout<< "2. Create Savinges Account\n";
            cin >> choice;
            if(choice == 1)
            {
                createAccount(accounts);
            } else if (choice == 2)
            {
                createSavingsAccount(accounts);
            } else
            {
                cout<<"Invalid Choice";
            }
            break;
        case 2:
            cout<<"\n";
            cout<<"Accounts\n";
            cout<<"-------------\n";
            Account::displayAccounts(accounts);
            break;
        case 3:
            Account::depositToAccount(accounts);
            break;
        case 4:
            Account::withdrawFromAccount(accounts);
            break;
        case 5:
            writeToFile(accounts);
            // Clean up before exiting
            for (Account* acc : accounts) {
                delete acc;
            }
            running = false;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }

    // for (auto acc : accounts)
    // {
    //     delete acc;
    // }

    return 0;
}
