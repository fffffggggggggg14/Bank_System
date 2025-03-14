#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsBankClient.h"

using namespace std;

class clsTransferRegister : protected clsScreenHeader {
private:
static void _PrintDataTransferRegister(clsBankClient::stTransferRegister TransferRegister){
cout << "| " << left << setw(24) << TransferRegister.Time;
cout << "| " << left << setw(15) << TransferRegister.FromAccountNumber;
cout << "| " << left << setw(15) << TransferRegister.ToAccountNumber;
cout << "| " << left << setw(8) << TransferRegister.Amount;
cout << "| " << left << setw(15) << TransferRegister.AccountBalance1;
cout << "| " << left << setw(15) << TransferRegister.AccountBalance2;
cout << "| " << left << setw(8) << TransferRegister.User << endl;

}

public:
static void TransferRegisterList(void){
vector <clsBankClient::stTransferRegister> vTransferRegister = clsBankClient::DataTransferRegisterToVectorStruct();

_ScreenHeader("\tTransfer Register List Screen\n\t\t\t\t\t\t\t(" + to_string(vTransferRegister.size()) + ")" + "Record(S)");

cout << "================================================================================================================" << endl;
cout << "| " << left << setw(24) << "Date/Time";
cout << "| " << left << setw(15) << "Acc.Number(1)";
cout << "| " << left << setw(15) << "Acc.Number(2)";
cout << "| " << left << setw(8) << "Amount";
cout << "| " << left << setw(15) << "Acc.Balance(1)";
cout << "| " << left << setw(15) << "Acc.Balance(2)";
cout << "| " << left << setw(8) << "User" << endl;
cout << "================================================================================================================" << endl;

for(clsBankClient::stTransferRegister &TransferRegister : vTransferRegister){
_PrintDataTransferRegister(TransferRegister);
}

cout << "================================================================================================================" << endl;
}

};