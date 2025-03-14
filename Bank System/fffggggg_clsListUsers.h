#pragma

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "fffggggg_clsUser.h"
#include "fffggggg_clsScreenHeader.h"

using namespace std;

class clsListUsers : protected clsScreenHeader {
private:
static void _PrintUsersData(clsUser vU){
cout << "| " << left << setw(10) << vU.getUserName();
cout << "| " << left << setw(22) << vU.getFullName();
cout << "| " << left << setw(15) << vU.getPhone();
cout << "| " << left << setw(17) << vU.getEmail();
cout << "| " << left << setw(10) << vU.getPassword();
cout << "| " << left << setw(10) << vU.getPermissions() << endl;;

}


public:
static void ListUsers(void){
vector <clsUser> vUser = clsUser::FileUserToVector();
int CountUsers = clsUser::CountUsers();

_ScreenHeader("\t     Users List Screen\n\t\t\t\t\t\t\t(" + to_string(CountUsers) + ") User(s)");
cout << "===================================================================================================" << endl;
cout << "| " << left << setw(10) << "User Name";
cout << "| " << left << setw(22) << "Name";
cout << "| " << left << setw(15) << "Phone";
cout << "| " << left << setw(17) << "Email";
cout << "| " << left << setw(10) << "Password";
cout << "| " << left << setw(10) << "Pormissions" << endl;
cout << "===================================================================================================" << endl;

if(CountUsers == 0){
cout << "No User" << endl;
}

else {
for(clsUser &vU : vUser){
_PrintUsersData(vU);
}

}


cout << "===================================================================================================" << endl;

}


};