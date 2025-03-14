#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsBankClient.h"

using namespace std;

class clsWithdraw : protected clsScreenHeader {
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
static void Withdraw(void){
_ScreenHeader("\t\tWithdraw Screen");

string AccountNumber = clsTools::ReadString("Account Number: ");
while(!clsBankClient::IsFindClient(AccountNumber)){
AccountNumber = clsTools::ReadString("Accout Number does not exist, Again Account Number: ");
}

clsBankClient Client = clsBankClient::FindClient(AccountNumber);
_PrintClientData(Client);

double ValueWithdraw = clsTools::ReadDouble("How much you want To be Withdraw: ");

if(clsTools::YorN("Are You Sure (Y / N): ") == 'Y'){

if(ValueWithdraw > Client.getAccountBalance()){
cout << endl;
cout << "Amount to Withdrow is: " << ValueWithdraw << endl;
cout << "Your Balance: " << Client.getAccountBalance() << endl;
cout << endl;
}

else {
Client.Withdraw(ValueWithdraw);

cout << "\n\nAmount Withdrow Seccrssfully\n\n";

clsBankClient NowClient = clsBankClient::FindClient(AccountNumber);
cout << "Balance Now: " << NowClient.getAccountBalance() << endl;

}


}

else {
cout << "Done" << endl;
}

}

};