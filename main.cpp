// carsexualparth made this just by random idea strook. 
#include <iostream>
#include <iomanip>
using namespace std;

class bank {
    char name[20];
    int acno;
    char actype[20];
    int mainBal;  
    int vaultBal;  
    bool vaultCreated; 

public:
    bank() : mainBal(0), vaultBal(0), vaultCreated(false) {} 

    void opbal(void);
    void deposit(void);
    void withdraw(void);
    void display(void);
    void createVault(void);
};

void bank::opbal(void) {
    cout << "\n\n";
    cout << "Enter your Name: ";
    cin >> ws;
    cin.getline(name, 20);

    cout << "Enter A/C no. (up to 4 digits): ";
    cin >> acno;
    if (acno > 9999 || acno < 0) {
        cout << "Invalid account number!" << endl;
        exit(0);
    }

    cout << "Account number accepted: " << acno << endl;

    cout << "Enter A/C Type: ";
    cin >> ws;
    cin.getline(actype, 20);

    cout << "Enter Opening Balance (Main Account): ";
    cin >> mainBal;

    cout << "Procedure completed successfully.\n";
}

void bank::deposit(void) {
    int depositAmount = 0;
    int choice;
    cout << "Enter Deposit Amount: ";
    cin >> depositAmount;

    cout << "Choose where to deposit:\n";
    cout << "1. Main Account\n";
    cout << "2. Vault\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        mainBal += depositAmount;
        cout << "Updated Main Account Balance: " << mainBal << endl;
    } else if (choice == 2) {
        if (vaultCreated) {
            vaultBal += depositAmount;
            cout << "Updated Vault Balance: " << vaultBal << endl;
        } else {
            cout << "Vault not created yet.\n";
        }
    } else {
        cout << "Invalid choice. Deposit canceled.\n";
    }
}

void bank::withdraw(void) {
    int withdrawAmount = 0;
    int choice;
    cout << "Choose where to withdraw from:\n";
    cout << "1. Main Account\n";
    cout << "2. Vault\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter Withdraw Amount: ";
    cin >> withdrawAmount;

    if (choice == 1) {
        if (mainBal >= withdrawAmount) {
            mainBal -= withdrawAmount;
            cout << "Updated Main Account Balance: " << mainBal << endl;
        } else {
            cout << "Not enough balance in Main Account.\n";
        }
    } else if (choice == 2) {
        if (vaultCreated) {
            if (vaultBal >= withdrawAmount) {
                vaultBal -= withdrawAmount;
                cout << "Updated Vault Balance: " << vaultBal << endl;
            } else {
                cout << "Not enough balance in Vault.\n";
            }
        } else {
            cout << "Vault not created yet.\n";
        }
    } else {
        cout << "Invalid choice. Withdrawal canceled.\n";
    }
}

void bank::createVault(void) {
    const int vaultFee = 100; 

    if (vaultCreated) {
        cout << "Vault already exists.\n";
        return;
    }

    if (mainBal >= vaultFee) {
        mainBal -= vaultFee;
        vaultBal = 0; // 
        vaultCreated = true;
        cout << "Vault created successfully! You have been charged " << vaultFee << " rs.\n";
        cout << "Updated Main Account Balance: " << mainBal << endl;
    } else {
        cout << "Insufficient balance to create a vault. You need at least " << vaultFee << " rs \n";
    }
}

void bank::display(void) {
    cout << "\n\n\n";
    cout << setw(40) << "DETAILS" << endl;
    cout << setw(40) << "Name: " << name << endl;
    cout << setw(40) << "A/C no.: " << acno << endl;
    cout << setw(40) << "Account Type: " << actype << endl;
    cout << setw(40) << "Main Account Balance: " << mainBal << endl;

    if (vaultCreated) {
        cout << setw(40) << "Vault Balance: " << vaultBal << endl;
    } else {
        cout << setw(40) << "Vault: Not Created\n";
    }
}

int main() {
    bank o1;
    int choice;

    do {
        cout << "\n\n\n\tBanking System Program";
        cout << "\n\nChoice list\n";
        cout << "1. To Assign Initial Value\n";
        cout << "2. To Deposit\n";
        cout << "3. To Withdraw\n";
        cout << "4. To Create Vault\n";
        cout << "5. To Display All Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                o1.opbal();
                break;
            case 2:
                o1.deposit();
                break;
            case 3:
                o1.withdraw();
                break;
            case 4:
                o1.createVault();
                break;
            case 5:
                o1.display();
                break;
            case 6:
                goto end;
            default:
                cout << "Invalid Option.\n";
        }
    } while (1);

end:
    return 0;
}
