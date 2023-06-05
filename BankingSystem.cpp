// import os
#include<iostream>
#include<fstream>
#include<map>
using namespace std;
#include<ctime>

// import random
// import datetime
int main(){
    map<int, int> balances;
    map<int, string> details;
    ifstream f;
    f.open("AccountBalances.csv");
    string line;
    while(getline(f, line)){
        int account = stoi(line.substr(0, line.find(',')));
        int balance = stoi(line.substr(line.find(',') + 1));
        balances[account] = balance;
    }
    f.close();

    f.open("AccountDetails.csv");
    while (getline(f, line)){
        int account = stoi(line.substr(0, line.find(',')));
        string name = line.substr(line.find(',') + 1, line.find(',', line.find(',') + 1) - line.find(',') - 1);
        string address = line.substr(line.find(',', line.find(',') + 1) + 1, line.find(',', line.find(',', line.find(',') + 1) + 1) - line.find(',', line.find(',') + 1) - 1);
        string phone = line.substr(line.find(',', line.find(',', line.find(',') + 1) + 1) + 1, line.find(',', line.find(',', line.find(',', line.find(',') + 1) + 1) + 1) - line.find(',', line.find(',', line.find(',') + 1) + 1) - 1);
        string email = line.substr(line.find(',', line.find(',', line.find(',', line.find(',') + 1) + 1) + 1) + 1);
        details[account] = name + "," + address + "," + phone + "," + email;
    }
    f.close();

    cout << "Accounts and Balances" << endl;
    for(auto account: balances){
        cout << account.first << " " << account.second << endl;
    }
    printf("\n");
    
    while(true){
        cout<<"Banking System"<<endl;
        cout<<"1. Create Account"<<endl;
        cout<<"2. Show Account Details"<<endl;
        cout<<"3. Show Account Balance"<<endl;
        cout<<"4. Deposit"<<endl;
        cout<<"5. Withdraw"<<endl;
        cout<<"6. Exit"<<endl;

        int choice;
        cin>>choice;
        
        switch (choice)
        {
        case 1:
        {
            int account = rand() % 900000 + 100000;
            string name, address, phone, email;
            cout<<"Enter your name: ";
            cin>>name;
            cout<<"Enter your address: ";
            cin>>address;
            cout<<"Enter your phone number: ";
            cin>>phone;
            cout<<"Enter your email address: ";
            cin>>email;
            balances[account] = 0;
            details[account] = name + "," + address + "," + phone + "," + email;
            cout<<"Account created successfully. Your account number is "<<account<<endl;
            break;
        }
        case 2:
        {
            int account;
            cout<<"Enter your account number: ";
            cin>>account;
            if(details.find(account) != details.end()){
                cout<<"Name: "<<details[account].substr(0, details[account].find(','))<<endl;
                cout<<"Address: "<<details[account].substr(details[account].find(',') + 1, details[account].find(',', details[account].find(',') + 1) - details[account].find(',') - 1)<<endl;
                cout<<"Phone: "<<details[account].substr(details[account].find(',', details[account].find(',') + 1) + 1, details[account].find(',', details[account].find(',', details[account].find(',') + 1) + 1) - details[account].find(',', details[account].find(',') + 1) - 1)<<endl;
                cout<<"Email: "<<details[account].substr(details[account].find(',', details[account].find(',', details[account].find(',') + 1) + 1) + 1)<<endl;
            }
            else{
                cout<<"Account not found"<<endl;
            }
            break;
        }
        case 3:
        {
            int account;
            cout<<"Enter your account number: ";
            cin>>account;
            if(balances.find(account) != balances.end()){
                cout<<"Balance: "<<balances[account]<<endl;
            }
            else{
                cout<<"Account not found"<<endl;
            }
            break;
        }
        case 4:
        {
            int account, amount;
            cout<<"Enter your account number: ";
            cin>>account;
            if(balances.find(account) != balances.end()){
                cout<<"Enter amount to deposit: ";
                cin>>amount;
                balances[account] += amount;
                cout<<"Amount deposited successfully"<<endl;
            }
            else{
                cout<<"Account not found"<<endl;
            }
            break;
        }
        case 5:
        {
            int account, amount;
            cout<<"Enter your account number: ";
            cin>>account;
            if(balances.find(account) != balances.end()){
                cout<<"Enter amount to withdraw: ";
                cin>>amount;
                if(amount > balances[account]){
                    cout<<"Insufficient balance"<<endl;
                }
                else{
                    balances[account] -= amount;
                    cout<<"Amount withdrawn successfully"<<endl;
                }
            }
            else{
                cout<<"Account not found"<<endl;
            }
            break;
        }
        case 6:
        {
            ofstream f;
            f.open("AccountBalances.csv");
            for(auto account: balances){
                f<<account.first<<","<<account.second<<endl;
            }
            f.close();

            f.open("AccountDetails.csv");
            for(auto account: details){
                f<<account.first<<","<<account.second<<endl;
            }
            f.close();
            return 0;
        }
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }

        printf("\n");  
        // git add .
        // git commit -m "commited at time"

        system("pause");
        system("git add .");
        system("git commit -m \"commited at time\"");
    }
}
// def main():
//     balances = {}
//     details = {}
//     with open('AccountBalances.csv') as f:
//         for line in f:
//             account, balance = line.split(',')
//             balances[account] = int(balance)
//     with open('AccountDetails.csv') as f:
//         for line in f:
//             account, name, address, phone, email = line.split(',')
//             details[account] = [name, address, phone, email]
//     print("Accounts and Balances")
//     for account in balances:
//         print(account, balances[account])
//     while True:
//         print("Banking System")
//         print("1. Create Account")
//         print("2. Show Account Details")
//         print("3. Show Account Balance")
//         print("4. Deposit")
//         print("5. Withdraw")
//         print("6. Exit")
//         choice = int(input("Enter your choice: "))
//         if choice == 1:
//             account = random.randint(100000, 999999)
//             name = input("Enter your name: ").strip()
//             address = input("Enter your address: ").strip()
//             phone = input("Enter your phone number: ").strip()
//             email = input("Enter your email address: ").strip()
//             balances[account] = 0
//             details[account] = [name, address, phone, email]
//             print("Account created successfully. Your account number is", account)
//         elif choice == 2:
//             account = (input("Enter your account number: ")).strip()
//             if account in details:
//                 print("Name:", details[account][0])
//                 print("Address:", details[account][1])
//                 print("Phone:", details[account][2])
//                 print("Email:", details[account][3])
//             else:
//                 print("Account not found")
//         elif choice == 3:
//             account = (input("Enter your account number: ")).strip()
//             if account in balances:
//                 print("Balance:", balances[account])
//             else:
//                 print("Account not found")
//         elif choice == 4:
//             account = (input("Enter your account number: ")).strip()
//             if account in balances:
//                 amount = int(input("Enter amount to deposit: "))
//                 balances[account] += amount
//                 print("Balance:", balances[account])
//             else:
//                 print("Account not found")
//         elif choice == 5:
//             account = (input("Enter your account number: ")).strip()
//             if account in balances:
//                 amount = int(input("Enter amount to withdraw: "))
//                 if amount > balances[account]:
//                     print("Insufficient balance")
//                 else:
//                     balances[account] -= amount
//                     print("Balance:", balances[account])
//             else:
//                 print("Account not found")
//         elif choice == 6:
//             break
//         else:
//             print("Invalid choice")
//         print()
//         with open('AccountBalances.csv', 'w') as f:
//             for account in balances:
//                 f.write(str(account) + ',' + str(balances[account]) + '\n')
//         with open('AccountDetails.csv', 'w') as f:
//             for account in details:
//                 line = (str(account) + ',' + details[account][0] + ',' + details[account][1] + ',' + details[account][
//                     2] + ',' + details[account][3])
//                 f.write(line.strip() + '\n')

//             os.system('git add .')
//             time = datetime.datetime.now()
//             os.system('git commit -m "commit at ' + str(time) + '"')


// if __name__ == '__main__':
//     main()
