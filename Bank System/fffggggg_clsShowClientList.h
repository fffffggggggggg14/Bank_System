#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "fffggggg_ClsBankClient.h"
#include "fffggggg_clsScreenHeader.h"

using namespace std;

class clsShowClientList : protected clsScreenHeader {
private:
static void _PrintClientData(vector <clsBankClient> vClient){
for(clsBankClient &vC : vClient){
cout << "| " << left << setw(15) << vC.getAccountNumber();
cout << "| " << left << setw(22) << vC.getFullName();
cout << "| " << left << setw(12) << vC.getPhone();
cout << "| " << left << setw(20) << vC.getEmail();
cout << "| " << left << setw(10) << vC.getPinCode();
cout << "| " << left << setw(12) << vC.getAccountBalance() << endl;
}

}

public:

static void ShowClientList(void){
vector <clsBankClient> vClient = clsBankClient::FileToVector();
int CountVector = vClient.size();


_ScreenHeader("\t      Client List Screen\n\t\t\t\t\t\t\t(" + to_string(CountVector) + ") Client(s)");
cout << "============================================================================================================" << endl;
cout << "| " << left << setw(15) << "Account Number";
cout << "| " << left << setw(22) << "Name";
cout << "| " << left << setw(12) << "Phone";
cout << "| " << left << setw(20) << "Email";
cout << "| " << left << setw(10) << "PinCode";
cout << "| " << left << setw(12) << "Account Balance" << endl;
cout << "============================================================================================================" << endl;

if(CountVector == 0){
cout << "No Client" << endl;
}

else{
_PrintClientData(vClient);
}

cout << "============================================================================================================" << endl;
}

};