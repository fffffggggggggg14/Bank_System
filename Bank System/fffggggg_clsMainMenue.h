#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsShowClientList.h"
#include "fffggggg_clsAddNewClient.h"
#include "fffggggg_clsDeleteClient.h"
#include "fffggggg_clsUpdateClient.h"
#include "fffggggg_clsFindClient.h"
#include "fffggggg_clsTransactions.h"
#include "fffggggg_clsManageUsers.h"
#include "fffggggg_Global.h"
#include "fffggggg_clsLoginRegister.h"
#include "fffggggg_clsCurrencyExchange.h"

using namespace std;

class clsMainMenue : protected clsScreenHeader {
private:
enum enMenue {ShowClient = 1, AddClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Transaction = 6, 
Manage = 7, SaveLoginRegister = 8, Currency = 9, Logout = 10};

static void PrintMainMenue(void){
system("cls");
_ScreenHeader("\t\t Main Screen", 1);
cout << "=======================================" << endl;
cout << "     Main Menue" << endl;
cout << "=======================================" << endl;
cout << "[1]  Show Client List." << endl;
cout << "[2]  Add Now Client." << endl;
cout << "[3]  Delete Client." << endl;
cout << "[4]  Update Client Info." << endl;
cout << "[5]  Fine Client." << endl;
cout << "[6]  Transactions." << endl;
cout << "[7]  Manage Users." << endl;
cout << "[8]  Login Register." << endl;
cout << "[9]  Currency Exchange." << endl;
cout << "[10] Logout." << endl;
cout << "=======================================" << endl;

}

static void _GoBackMainMenue(){
system("pause");
MainMenue();
}

static void _NotAllowed(void){
_ScreenHeader("      Access denien! Coutact your Admin");
}

static bool _Allow(short Value){
return (GlobalUser.getPermissions() & Value) == 0;
}

static void _ShowClientList(void){
//cout << "Show Client List" << endl;
if(_Allow(1)){
_NotAllowed();
}
else{
clsShowClientList::ShowClientList();
}

}

static void _AddNowClient(void){
//cout << "Add Now Client" << endl;
if(_Allow(2)){
_NotAllowed();
}
else{
clsAddNowClient::AddNowClient();
}

}

static void _DeleteClient(void){
//cout << "DeleteClient" << endl;
if(_Allow(4)){
_NotAllowed();
}
else{
clsDeleteClient::DeleteClient();
}

}

static void _UpdateClient(void){
//cout << "Done" << endl;
if(_Allow(8)){
_NotAllowed();
}
else{
clsUpdateClient::UpdateClientInfo();
}


}

static void _FindClient(void){
//cout << "Done" << endl;
if(_Allow(16)){
_NotAllowed();
}
else{
clsFindClient::FindClient();
}

}

static void _Transactions(void){
//cout << "Transactions" << endl;
if(_Allow(32)){
_NotAllowed();
system("pause");
}
else{
clsTransactions::TransactionsMenue();
}

}

static void _ManageUsers(void){
//cout << "Manage" << endl;
if(_Allow(64)){
_NotAllowed();
system("pause");
}
else{
clsManageUsers::ManageUsersMenue();
}

}

static void _LoginRegister(void){
if(_Allow(128)){
_NotAllowed();
}
else{
clsLoginRegister::LoginRegisterList();
}

}

static void _Currency(void){
if(_Allow(256)){
_NotAllowed();
system("pause");
}
else{
clsCurrencyExchange::CurrencyExhangeMenue();
}

}

static void _Logout(void){
//cout << "Logout" << endl;

GlobalUser = clsUser::FindUser("", "");

}

public:
static void MainMenue(void){
PrintMainMenue();

short ChooseNumber = clsTools::ReadNumber("Choose what do you want to do? [1 : 10]: ", 1, 10);

if(ChooseNumber == enMenue::ShowClient){
system("cls");
_ShowClientList();
_GoBackMainMenue();
}
if(ChooseNumber == enMenue::AddClient){
system("cls");
_AddNowClient();
_GoBackMainMenue();
}

if(ChooseNumber == enMenue::DeleteClient){
system("cls");
_DeleteClient();
_GoBackMainMenue();
}

if(ChooseNumber == enMenue::UpdateClient){
system("cls");
_UpdateClient();
_GoBackMainMenue();
}

if(ChooseNumber == enMenue::FindClient){
system("cls");
_FindClient();
_GoBackMainMenue();
}

if(ChooseNumber == enMenue::Transaction){
system("cls");
_Transactions();
//_GoBackMainMenue();
MainMenue();
}
if(ChooseNumber == enMenue::Manage){
system("cls");
_ManageUsers();
//_GoBackMainMenue();
MainMenue();
}

if(ChooseNumber == enMenue::SaveLoginRegister){
system("cls");
_LoginRegister();
_GoBackMainMenue();
}

if(ChooseNumber == enMenue::Currency){
system("cls");
_Currency();
//_GoBackMainMenue();
MainMenue();
}




if(ChooseNumber == enMenue::Logout){
system("cls");
_Logout();
//_GoBackMainMenue();
}

}

};