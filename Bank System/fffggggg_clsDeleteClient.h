#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsBankClient.h"

using namespace std;

class clsDeleteClient : protected clsScreenHeader {
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
static void DeleteClient(void){
_ScreenHeader("\t     Delete Client Screen");

string AccountNumber = clsTools::ReadString("Accout Number: ");
while(!clsBankClient::IsFindClient(AccountNumber)){
AccountNumber = clsTools::ReadString("Accout Number does not exist, Again Account Number: ");
}

clsBankClient Client = clsBankClient::FindClient(AccountNumber);
_PrintClientData(Client);

if(clsTools::YorN("Are You Sure (Y / N): ") == 'Y'){
Client.DeleteClient();
cout << "\nDeleted Succrssfully (-:\n\n";
}

else {
cout << "\nDone...\n\n";
}

}

};