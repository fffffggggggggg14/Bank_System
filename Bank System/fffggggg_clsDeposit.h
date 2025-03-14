#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsBankClient.h"

using namespace std;


class clsDeposit : protected clsScreenHeader {
private:
static void _PrintClientData(clsBankClient Client){
cout << "Client Card:" << endl;
cout << "___________________________________" << endl;
cout << "Frist Name: " << Client.getFristName() << endl;
cout << "Last Name: " << Client.getLastName() << endl;
cout << "Email: " << Client.getEmail() << endl;
cout << "Phone: " << Client.getPhone() << endl;
cout << "Account Number: " << Client.getAccountNumber() << endl;
cout << "Pin Code: " << Client.getPinCode() << endl;
cout << "Account Balance: " << Client.getAccountBalance() << endl;
cout << "___________________________________" << endl;
}

public:
static void Deposit(void){
_ScreenHeader("\t\tDeposit Screen");
string AccountNumber = clsTools::ReadString("Account Number: ");
while(!clsBankClient::IsFindClient(AccountNumber)){
AccountNumber = clsTools::ReadString("Accout Number does not exist, Again Account Number: ");
}

clsBankClient Client = clsBankClient::FindClient(AccountNumber);
_PrintClientData(Client);

cout << endl;

double ValueDeposit = clsTools::ReadDouble("How much you want To be Deposited: ");

if(clsTools::YorN("Are You Sure (Y / N): ") == 'Y'){
Client.Deposit(ValueDeposit);

cout << "\n\nAmount Deposited Seccrssfully\n\n";

clsBankClient NowClient = clsBankClient::FindClient(AccountNumber);
cout << "Balance Now: " << NowClient.getAccountBalance() << endl;
}

else {
cout << "Done" << endl;
}

}

};