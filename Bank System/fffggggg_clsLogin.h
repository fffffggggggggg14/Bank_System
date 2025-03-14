#pragma once
#pragma warning(double : 4996)

#include <iostream>
#include <string>
#include <ctime>
#include "fffggggg_clsDate.h"
#include "fffggggg_clsTools.h"
#include <fstream>
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsMainMenue.h"
#include "fffggggg_clsUser.h"
#include "fffggggg_Global.h"

using namespace std;

class clsLogin : protected clsScreenHeader {

private:

static void _Login(void){
string UserName, Password;
bool Flag = 0;
short Try = 3;

do{
system("cls");
_ScreenHeader("\t\t  Login Screen");

if(Flag){cout << "User Name / Password Error!\n";}
if(Flag){cout << "You have " << to_string(--Try) << " Trial(s) to login\n\n";}
if(Try == 0){
cout << "You Are Locked afer 3 faild trails\n\n";
system("pause");
exit(0);
}

UserName = clsTools::ReadString("Enter User Name: ");
Password = clsTools::ReadString("Enter Password: ");

Flag = 1;


}while(!clsUser::IsFindUser(UserName, Password));

GlobalUser = clsUser::FindUser(UserName, Password);

GlobalUser.SaveLoginRegister();

clsMainMenue::MainMenue();

}

public:

static void Login(void){
_Login();

}


};