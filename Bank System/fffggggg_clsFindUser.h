#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsUser.h"
#include "fffggggg_clsScreenHeader.h"

class clsFindUser : protected clsScreenHeader {
private:
static void _PrintUserCard(clsUser User){
cout << "User Card" << endl;
cout << "_____________________________" << endl;
cout << "First Name: " << User.getFristName() << endl;
cout << "Last Name: " << User.getLastName() << endl;
cout << "Email: " << User.getEmail() << endl;
cout << "Phone: " << User.getPhone() << endl;
cout << "User Name: " << User.getUserName() << endl;
cout << "Password: " << User.getPassword() << endl;
cout << "Permissions: " << User.getPermissions() << endl;
cout << "_____________________________" << endl;
}

public:
static void FindUser(void){
_ScreenHeader("\t     Find User Screen");

string UserName = clsTools::ReadString("User Name: ");
while(!clsUser::IsFindUser(UserName)){
UserName = clsTools::ReadString("User is not found, chooes another one: ");
}

cout << "\nUser Found (-:" << endl;

clsUser User = clsUser::FindUser(UserName);

cout << endl;
_PrintUserCard(User);
cout << endl;


}

};