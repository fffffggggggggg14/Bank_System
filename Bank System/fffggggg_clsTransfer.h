#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsBankClient.h"

using namespace std;

class clsTransfer : protected clsScreenHeader {
private:
static void _PrintShortCard(clsBankClient Client){
cout << "Short Client Card" << endl;
cout << "____________________________" << endl;
cout << "Full Name: " << Client.getFullName() << endl;
cout << "Account Number: " << Client.getAccountNumber() << endl;
cout << "Account Balance: " << Client.getAccountBalance() << endl;
cout << "____________________________" << endl;
}

public:
static void Transfer(void){
_ScreenHeader("\t\tTransfer Screen");

string AccoutNumber1 = clsTools::ReadString("Please Enter Account Number To Transfer From: ");
while(!clsBankClient::IsFindClient(AccoutNumber1)){
AccoutNumber1 = clsTools::ReadString("Not Found, Again Accout Number: ");
}

cout << endl;

clsBankClient Client1 = clsBankClient::FindClient(AccoutNumber1);
_PrintShortCard(Client1);

cout << endl;

string AccoutNumber2 = clsTools::ReadString("Please Enter Account Number To Transfer To: ");
while(!clsBankClient::IsFindClient(AccoutNumber2)){
AccoutNumber2 = clsTools::ReadString("Not Found, Again Accout Number: ");
}

cout << endl;

clsBankClient Client2 = clsBankClient::FindClient(AccoutNumber2);
_PrintShortCard(Client2);

cout << endl;

double Transfer = clsTools::ReadDouble("Enter Transfer Amount? ");

while(Client1.getAccountBalance() < Transfer){
Transfer = clsTools::ReadDouble("Enter exceed the available balance, enter another amount? ");
}

if(clsTools::YorN("Are you sure (Y / N): ") == 'Y'){

Client1.Transfer(Client2, Transfer);

cout << "Transfer done successfully" << endl;

cout << endl;

clsBankClient NewClient1 = clsBankClient::FindClient(AccoutNumber1);
clsBankClient NewClient2 = clsBankClient::FindClient(AccoutNumber2);

_PrintShortCard(NewClient1);
_PrintShortCard(NewClient2);

cout << endl;
}

else {
cout << "Ok..." << endl;
}

}



};