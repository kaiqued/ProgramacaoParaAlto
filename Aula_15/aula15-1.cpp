#include <iostream>
#include <string>

using namespace std;

class Account{
    private:
        double balance{0.0};
    public:
        void deposit(double amount){
            balance += amount;
            cout << "Deposit of " << amount << " | balance: " << balance << endl;
        }
        void withdraw(double amount){
            balance -= amount;
            cout << "Withdraw of " << amount << " | balance: " << balance << endl;
        }
        Account() {
            cout << "Account created" << endl;
        }
        ~Account(){
            cout << "Account destructed" << endl;
        }
};

class Savings_Account: public Account{
    private:
        double interest_rate{0.0};
    public:
        void deposit(double amount){
            cout << "Savings Account: ";
            Account::deposit(amount);
        }
        void withdraw(double amount){
            cout << "Savings Account: ";
            Account::withdraw(amount);
        }
};

int main() {
    // Account
    cout << "=Account====================" << endl;
    Account acc1;
    acc1.deposit(235.82);
    acc1.withdraw(82.19);
    
    cout << endl;

    // Account com alocação dinâmica
    Account *acc2 = new Account;
    acc2->deposit(878.98);
    acc2->withdraw(45.73);
    delete acc2;

    cout << endl;

    // Savings Account
    cout << "=Savings Account============" << endl;
    Savings_Account sacc1;
    sacc1.deposit(235.82);
    sacc1.withdraw(82.19);
    
    cout << endl;

    // Account com alocação dinâmica
    Savings_Account *sacc2 = new Savings_Account;
    sacc2->deposit(878.98);
    sacc2->withdraw(45.73);
    delete sacc2;
    
    cout << endl;

return 0;
}
