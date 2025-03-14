#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsDeposit.h"
#include "fffggggg_clsWithdraw.h"
#include "fffggggg_clsTotalBalance.h"
#include "fffggggg_clsTransfer.h"
#include "fffggggg_TransferRegister.h"

using namespace std;

class clsTransactions : protected clsScreenHeader {
private:
enum enTransactionsMenue {Deposit = 1, Withdrow = 2, TotalBalance = 3, Transfer = 4, transferRegister = 5, 
GoBackMainMenue = 6};

static void _PrintTransactionsMenue(void){
system("cls");

_ScreenHeader("\t     Transactions Screen");
cout << "=======================================" << endl;
cout << "Transactions Menue" << endl;
cout << "=======================================" << endl;
cout << "[1] Deposit." << endl;
cout << "[2] Withdraw." << endl;
cout << "[3] Total Balances." << endl;
cout << "[4] Transfer." << endl;
cout << "[5] Transfer Register." << endl;
cout << "[6] Go back Main Menue." << endl;
cout << "=======================================" << endl;

}

static void _GoBackTransactionsMenue(void){
system("pause");
TransactionsMenue();
}

static void _Deposit(void){
//cout << "Deposit" << endl;
clsDeposit::Deposit();
}

static void _Withdraw(void){
//cout << "Withdraw" << endl;
clsWithdraw::Withdraw();
}

static void _TotalBalances(void){
//cout << "TotalBalance" << endl;
clsTotalBalances::TotalBalances();
}

static void _Transfer(void){
clsTransfer::Transfer();
}

static void _TransferRegister(void){
clsTransferRegister::TransferRegisterList();
}

public:

static void TransactionsMenue(void){
_PrintTransactionsMenue();

short ChooseNumber = clsTools::ReadShort("Choose what do you want to do? [1 : 6]: ", 1, 6);


if(ChooseNumber == enTransactionsMenue::Deposit){
system("cls");
_Deposit();
_GoBackTransactionsMenue();
}

if(ChooseNumber == enTransactionsMenue::Withdrow){
system("cls");
_Withdraw();
_GoBackTransactionsMenue();
}

if(ChooseNumber == enTransactionsMenue::Transfer){
system("cls");
_Transfer();
_GoBackTransactionsMenue();
}

if(ChooseNumber == enTransactionsMenue::transferRegister){
system("cls");
_TransferRegister();
_GoBackTransactionsMenue();
}

if(ChooseNumber == enTransactionsMenue::TotalBalance){
system("cls");
_TotalBalances();
_GoBackTransactionsMenue();
}

}



};