#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsUser.h"
#include "fffggggg_Global.h"

using namespace std;

class clsUpdateUser : protected clsScreenHeader {
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
static bool UpdateUser(void){
_ScreenHeader("\t     Update User Screen");

string UserName = clsTools::ReadString("User Name: ");

if(UserName == GlobalUser.getUserName()){
cout << "\nYou Can not edit yourself." << endl;
return 0;
}

while(!clsUser::IsFindUser(UserName)){
UserName = clsTools::ReadString("User is not found, chooes another one: ");
}




clsUser User = clsUser::FindUser(UserName);

cout << endl;
_PrintUserCard(User);
cout << endl;

if(clsTools::YorN("Are You Sure (Y / N): ") == 'Y'){

cout << endl;

do{

User.Update();

cout << endl;

clsUser NewUser = clsUser::FindUser(UserName);

_PrintUserCard(NewUser);

cout << "\n\nUser Update Sucessfully (-:\n\n";

}while(clsTools::YorN("Do you want to edit again? (Y / N): ") == 'Y');

cout << endl;
}

else {

cout << "\nDone\n\n";

}

}

};