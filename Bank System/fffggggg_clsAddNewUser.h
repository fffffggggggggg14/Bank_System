#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsUser.h"

using namespace std;

class clsAddNewUser : protected clsScreenHeader {
private:
static void _PrintUserCard(clsUser User){
cout << "User Card" << endl;
cout << "_____________________________" << endl;
cout << "First Name: " << User.getFristName() << endl;
cout << "Last Name: " << User.getLastName() << endl;
cout << "Full Name: " << User.getFullName() << endl;
cout << "Email: " << User.getEmail() << endl;
cout << "Phone: " << User.getPhone() << endl;
cout << "User Name: " << User.getUserName() << endl;
cout << "Password: " << User.getPassword() << endl;
cout << "Permissions: " << User.getPermissions() << endl;
cout << "_____________________________" << endl;
}


public:
void static AddNewUser(void){

_ScreenHeader("\t     Add New User Screen");

string UserName = clsTools::ReadString("User Name: ");
while(clsUser::IsFindUser(UserName)){
UserName = clsTools::ReadString("User Name is already, choose another one: ");
}

clsUser User = clsUser::ReadUserDate(UserName);

User.AddUser();

cout << "\n\nUser Addeded Successfully (-:\n\n";

_PrintUserCard(User);

}

};