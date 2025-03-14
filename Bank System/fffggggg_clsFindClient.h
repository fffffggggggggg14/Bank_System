#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsBankClient.h"
#include "fffggggg_clsFindClient.h"

using namespace std;

class clsFindClient : protected clsScreenHeader {
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
static void FindClient(){
_ScreenHeader("\t     Find Client Screen");

string AccountNumber = clsTools::ReadString("Account Number: ");
while(!clsBankClient::IsFindClient(AccountNumber)){
AccountNumber = clsTools::ReadString("Accout Number does not exist, Again Account Number: ");
}

cout << "\nClinet Found (-:\n\n";

clsBankClient Client = clsBankClient::FindClient(AccountNumber);
_PrintClientData(Client);

cout << endl;

}

};