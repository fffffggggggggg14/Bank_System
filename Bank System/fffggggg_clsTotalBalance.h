#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_ClsBankClient.h"



class clsTotalBalances : protected clsScreenHeader {
private:
static void _PrintClientDataBalances(clsBankClient vClient){
cout << "| " << left << setw(15) << vClient.getAccountNumber();
cout << "| " << left << setw(20) << vClient.getFullName();
cout << "| " << left << setw(12) << vClient.getAccountBalance() << endl;
}

public:
static void TotalBalances(void){
vector <clsBankClient> vClient = clsBankClient::FileToVector();
int CountClient = vClient.size();

_ScreenHeader("\t      Total Balance Screen\n\t\t\t\t\t\t\t(" + to_string(CountClient) + ") Client (s)");

cout << "================================================================" << endl;
cout << "| " << left << setw(15) << "Account Number";
cout << "| " << left << setw(20) << "Name";
cout << "| " << left << setw(12) << "Balance" << endl;
cout << "================================================================" << endl;

if(CountClient == 0){
cout << "No Client" << endl;
}

else{

for(clsBankClient &vC : vClient){
_PrintClientDataBalances(vC);
}

}

cout << "================================================================" << endl;

cout << "Total balances: " << clsBankClient::getTotalBalances() << endl;

}


};