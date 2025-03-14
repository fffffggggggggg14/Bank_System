#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsBankClient.h"

using namespace std;

class clsAddNowClient : protected clsScreenHeader {
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

static void AddNowClient(void){
_ScreenHeader("\t     Add Now Client Screen");

string AccountNumber = clsTools::ReadString("Account Number: ");
while(clsBankClient::IsFindClient(AccountNumber)){
AccountNumber = clsTools::ReadString("Anther Account Number: ");
}

clsBankClient Client = clsBankClient::AddClient(AccountNumber);
Client.AddClient();

cout << "\nAccount Addeded Succrssfully (-:\n\n";

_PrintClientData(Client);

}


};