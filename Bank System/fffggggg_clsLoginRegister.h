#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "fffggggg_clsString.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsuser.h"

using namespace std;
class clsLoginRegister : protected clsScreenHeader {
private:
static void _PrintLoginRegisterData(clsUser::stLoginRegister vUser){
cout << "| " << left << setw(25) << vUser.Time;
cout << "| " << left << setw(10) << vUser.UserName;
cout << "| " << left << setw(10) << vUser.Password;
cout << "| " << left << setw(10) << vUser.Permissions << endl;

}

static vector <string> _FileToVector(void){
vector <string> vUser;
fstream MyFile;
MyFile.open("LoginTime.txt", ios::in);

if(MyFile.is_open()){

string Line;
while(getline(MyFile, Line)){
vUser.push_back(Line);
}

MyFile.close();
}

return vUser;
}
static vector <string> _OneLineToSplit(string S, string Format = "#//#"){
vector <string> vString  = clsString::SplitString(S, Format);
return vString;
}

public:

static void LoginRegisterList(void){
vector <clsUser::stLoginRegister> vUser = clsUser::FileLoginTimeToVector();

_ScreenHeader("\t  Login Register List Screen\n\t\t\t\t\t\t\t(" + to_string(vUser.size()) + ") Record(s)");
cout << "============================================================================================" << endl;
cout << "| " << left << setw(25) << "Date/Time";
cout << "| " << left << setw(10) << "User Name";
cout << "| " << left << setw(10) << "Password";
cout << "| " << left << setw(10) << "Parmissions" << endl;
cout << "============================================================================================" << endl;


//vector <string> vUSerData;
for(clsUser::stLoginRegister &vU : vUser){
//vUSerData = _OneLineToSplit(vU);
//_PrintLoginRegisterData(vUSerData);
_PrintLoginRegisterData(vU);
}



cout << "============================================================================================" << endl;
}

};