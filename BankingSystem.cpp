
#include<iostream>
#include<fstream>
#include<map>
using namespace std;
#include<ctime>

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


        system("git add .");
        time_t now = time(NULL);
        string time = ctime(&now);
        string commitMessage = "commited at " + time;
        system(("git commit -m \"" + commitMessage + "\"").c_str());
    }
    return 0;
}

