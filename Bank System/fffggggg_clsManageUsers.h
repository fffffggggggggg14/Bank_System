#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsListUsers.h"
#include "fffggggg_clsAddNewUser.h"
#include "fffggggg_clsDeleteUser.h"
#include "fffggggg_clsUpdateUser.h"
#include "fffggggg_clsFindUser.h"

using namespace std;

class clsManageUsers : protected clsScreenHeader {
private:
enum enMenue {List = 1, Add = 2, Delete = 3, Update = 4, Find = 5, GoBackManue = 6};

static void _PrintManageUsersMenue(void){
system("cls");
_ScreenHeader("\t     Manage Users Screen");

cout << "===============================================" << endl;
cout << "    Manage Users Screen" << endl;
cout << "===============================================" << endl;
cout << "[1] List Users." << endl;
cout << "[2] Add New User." << endl;
cout << "[3] Delete User." << endl;
cout << "[4] Update User." << endl;
cout << "[5] Find User." << endl;
cout << "[6] Go back Main Menue." << endl;
cout << "===============================================" << endl;

}

static void _GoBackManagUserMenue(void){
system("pause");
ManageUsersMenue();
}

static void _ListUsers(void){
//cout << "List Users" << endl;
clsListUsers::ListUsers();
}

static void _AddNewUser(void){
//cout << "Add Now User" << endl;
clsAddNewUser::AddNewUser();
}

static void _DeleteUser(void){
//cout << "Delete User" << endl;
clsDeleteUser::DeleteUser();
}


static void _UpdateUser(void){
//cout << "Update User" << endl;
clsUpdateUser::UpdateUser();
}

static void _FindUser(void){
//cout << "Find User" << endl;
clsFindUser::FindUser();
}


public:

static void ManageUsersMenue(void){
_PrintManageUsersMenue();

short ChooseNumber = clsTools::ReadShort("Choose what do you want to do? [1 : 6]: ", 1, 6);

if(ChooseNumber == enMenue::List){
system("cls");
_ListUsers();
_GoBackManagUserMenue();
}

if(ChooseNumber == enMenue::Add){
system("cls");
_AddNewUser();
_GoBackManagUserMenue();
}

if(ChooseNumber == enMenue::Delete){
system("cls");
_DeleteUser();
_GoBackManagUserMenue();
}

if(ChooseNumber == enMenue::Update){
system("cls");
_UpdateUser();
_GoBackManagUserMenue();
}

if(ChooseNumber == enMenue::Find){
system("cls");
_FindUser();
_GoBackManagUserMenue();
}

}

};