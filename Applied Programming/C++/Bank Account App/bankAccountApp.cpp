#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Account
{
public:
    string owner;
    double balance;

    Account(string owner, double balance)
    {
        this->owner = owner;
        this->balance = balance;
    }

    // withdraw function
    void withdraw(double amount)
    {
        balance -= amount;
    }

    // addFunds function
    void addFunds(double amount)
    {
        balance += amount;
    }

    // display function
    void display() const
    {
        cout << owner << " " << balance << endl;
    }

    static void createAccount(vector<Account> &accounts)
    {
        string owner;
        double balance;

        cout << "What is the name of the Owner? \n";
        cin >> owner;
        cout << "What is the starting balance? \n";
        cin >> balance;

        Account tempAccount(owner, balance);
        accounts.push_back(tempAccount);
    }

    static void displayAccounts(const vector<Account> &accounts)
    {
        for (const auto &account : accounts)
        {
            account.display();
        }
    }

    static void depositToAccount(vector<Account> &accounts)
    {
        int index;
        double ammount;
        cout << "Enter Account Index: EXP: 0,1,2,3,4" << endl;
        cin >> index;
        cout << "Enter Ammount: " << endl;
        cin >> ammount;

        if (index >= 0 && index < accounts.size())
        {
            accounts[index].addFunds(ammount);
        }
        else
        {

            cout << "Not a correct Index";
        }
    }

    static void withdrawFromAccount(vector<Account> &accounts)
    {
        int index;
        double ammount;
        cout << "Enter Account Index: EXP: 0,1,2,3,4" << endl;
        cin >> index;
        cout << "Enter Ammount: " << endl;
        cin >> ammount;

        if (index >= 0 && index < accounts.size())
        {
            accounts[index].withdraw(ammount);
        }
        else
        {
            cout << "Not a correct Index";
        }
    }

    static void readFromFile(vector<Account>& accounts)
    {   
        string owner;
        double balance;
        ifstream file("accounts.txt");

        while(file >> owner >> balance)
        {
            accounts.push_back(Account(owner,balance));
        }

    }

    static void writeToFile(vector<Account>& accounts)
    {
        ofstream file("accounts.txt");
        for (auto account:accounts)
        {
            file<<account.owner<< " " << account.balance << endl;
        }

        file.close();

    }
};

int main()
{

    vector<Account> accounts;

    Account::createAccount(accounts);
    Account::displayAccounts(accounts);
    Account::createAccount(accounts);
    Account::displayAccounts(accounts);

    return 0;
}
