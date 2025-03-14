#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "fffggggg_clsString.h"
#include "fffggggg_clsPerson.h"

using namespace std;

class clsUser : public clsPerson {
private:
string _UserName;
string _Password;
short _Permissions;
enum enMode {Void = 1, Exist = 2};
enMode _Mode;

static clsUser _OneLineToClass(string Line, string Format = "#//#"){
vector <string> vUser = clsString::SplitString(Line, Format);
return clsUser(enMode::Exist, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsTools::DecryptText(vUser[5], 3), stoi(vUser[6]));
}

static clsUser _Void(void){
return clsUser(enMode::Void, "", "", "", "", "", "", 0);
}

string _ClassToOneLine(clsUser User, string F = "#//#"){
return User.getFristName() + F + User.getLastName() + F + User.getEmail() + F + User.getPhone() + F + User._UserName + F 
+ clsTools::EncryptText(User._Password, 3) + F + to_string(User._Permissions);
}

void _VectorToFile(vector <clsUser> vUser){
fstream MyFile;
MyFile.open("Users.txt", ios::out);

if(MyFile.is_open()){

string Line;

for(clsUser &vU : vUser){
Line = _ClassToOneLine(vU);
MyFile << Line << endl;
}

MyFile.close();
}

}

string _TimeAndUserDataToOneLine(void){
return clsDate::TimeNow() + "#//#" + _UserName + "#//#" + _Password + "#//#" + to_string(_Permissions);
}


enum _EditData{FristName = 1, LastName = 2, Email = 3, Phone = 4, Password = 5, Parmission = 6, All = 7};


static short _getPermissions(void){
cout << "Enter Parmission:" << endl;
short Permissions = 0;
if(clsTools::YorN("Do you want to give full access? (Y / N): ") == 'Y'){
Permissions = -1;
}

else {

cout << "\n\nDo you want to give full access to:\n\n";

if(clsTools::YorN("Show client list? (Y / N): ") == 'Y'){
Permissions += 1;
}

cout << endl;

if(clsTools::YorN("Add New client? (Y / N): ") == 'Y'){
Permissions += 2;
}

cout << endl;

if(clsTools::YorN("Delete client? (Y / N): ") == 'Y'){
Permissions += 4;
}

cout << endl;

if(clsTools::YorN("Update client? (Y / N): ") == 'Y'){
Permissions += 8;
}

cout << endl;

if(clsTools::YorN("Find client? (Y / N): ") == 'Y'){
Permissions += 16;
}

cout << endl;

if(clsTools::YorN("Transactions? (Y / N): ") == 'Y'){
Permissions += 32;
}

cout << endl;

if(clsTools::YorN("Manage Users? (Y / N): ") == 'Y'){
Permissions += 64;
}

cout << endl;

if(clsTools::YorN("Login Register? (Y / N): ") == 'Y'){
Permissions += 128;
}

cout << endl;

if(clsTools::YorN("Currency Exhange? (Y / N): ") == 'Y'){
Permissions += 256;
}

cout << endl;

if(Permissions == 511){Permissions = -1;}

return Permissions;
}
}

void _EditData(clsUser &User){
cout << "====================================" << endl;
cout << "[1] Frist Name." << endl;
cout << "[2] List Name." << endl; 
cout << "[3] Email." << endl;
cout << "[4] Phone." << endl;
cout << "[5] Password." << endl;
cout << "[6] Parmission." << endl;
cout << "[7] All" << endl;
cout << "====================================" << endl;
short ChooseNumber = clsTools::ReadShort("What do you want to update? [1 : 7]: ", 1, 7);

cout << endl;

cout << "Update User Info" << endl;
cout << "____________________________\n\n";

if(_EditData::FristName == ChooseNumber){
User.setFristName(clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Enter Frist Name: ")))));
}

if(_EditData::LastName == ChooseNumber){
User.setLastName(clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Enter Last Name: ")))));
}

if(_EditData::Email == ChooseNumber){
User.setEmail(clsTools::ReadString("Enter Email: "));
}

if(_EditData::Phone == ChooseNumber){
User.setPhone(clsTools::ReadString("Enter Phone: "));
}

if(_EditData::Password == ChooseNumber){
User.setPassword(clsTools::ReadString("Enter Password: "));
}

if(_EditData::Parmission == ChooseNumber){
short Permissions = _getPermissions();
User.setPermissions(Permissions);
}


if(_EditData::All == ChooseNumber){
User.setFristName(clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Enter Frist Name: ")))));
User.setLastName(clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Enter Last Name: ")))));
User.setEmail(clsTools::ReadString("Enter Email: "));
User.setPhone(clsTools::ReadString("Enter Phone: "));
User.setPassword(clsTools::ReadString("Enter Password: "));

cout << endl;

short Permissions = _getPermissions();
User.setPermissions(Permissions);

}

}

public:
clsUser(enMode Mode, string FristName, string LastName, string Email, string Phone, string UserName, string Password, short Permissions) 
: clsPerson (FristName, LastName, Email, Phone){
_UserName = UserName;
_Password = Password;
_Permissions = Permissions;
_Mode = Mode;
}

struct stLoginRegister {
string Time;
string UserName;
string Password;
short Permissions;
};

static stLoginRegister OneLineToStruct(string Line, string Format = "#//#"){
vector <string> vUser = clsString::SplitString(Line, Format); 
stLoginRegister User;
User.Time = vUser[0];
User.UserName = vUser[1];
User.Password = vUser[2];
User.Permissions = stoi(vUser[3]);

return User;
}

bool IsMode(void){
return (enMode::Exist == _Mode);
}

/*void setUserName(string UserName){
_UserName = UserName;
}*/

string getUserName(void){
return _UserName;
}

void setPassword(string Password){
_Password = Password;
}

string getPassword(void){
return _Password;
}

void setPermissions(short Permissions){
_Permissions = Permissions;
}

short getPermissions(void){
return _Permissions;
}

static clsUser FindUser(string UserName){
fstream MyFile;
MyFile.open("Users.txt", ios::in);

if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
clsUser User = _OneLineToClass(Line);

if(User._UserName == UserName){
MyFile.close();
return User;
}

}

MyFile.close();
}

return _Void();
}

static clsUser FindUser(string UserName, string Password){
fstream MyFile;
MyFile.open("Users.txt", ios::in);

if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
clsUser User = _OneLineToClass(Line);

if(User._UserName == UserName && User._Password == Password){
MyFile.close();
return User;
}

}

MyFile.close();
}

return _Void();
}


static bool IsFindUser(string UserName){
clsUser User = clsUser::FindUser(UserName);
return User.IsMode();
}

static bool IsFindUser(string UserName, string Password){
clsUser User = clsUser::FindUser(UserName, Password);
return User.IsMode();
}

static vector <clsUser> FileUserToVector(void){
vector <clsUser> vUser;
fstream MyFile;

MyFile.open("Users.txt", ios::in);

if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
clsUser User = _OneLineToClass(Line);
vUser.push_back(User);
}

MyFile.close();
}

return vUser;
}

static int CountUsers(void){
vector <clsUser> vUser = FileUserToVector();
return vUser.size();
}

static clsUser ReadUserDate(string UserName){
string FristName = clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Enter Frist Name: "))));
string LastName = clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Enter Last Name: "))));
string Email = clsTools::ReadString("Enter Email: ");
string Phone = clsTools::ReadString("Enter Phone: ");
string Password = clsTools::ReadString("Enter Password: ");

cout << endl;

short Permissions = _getPermissions();

return clsUser(enMode::Exist, FristName, LastName, Email, Phone, UserName, Password, Permissions);
}

clsUser ReadUserDate(void){
return ReadUserDate(this->_UserName);
}

void AddUser(void){
fstream MyFile;
MyFile.open("Users.txt", ios::out | ios::app);

if(MyFile.is_open()){
string Line = _ClassToOneLine(*this);
MyFile << Line << endl;

MyFile.close();
}

}

void Delete(void){
vector <clsUser> vUser;
fstream MyFile;
MyFile.open("Users.txt", ios::in);

if(MyFile.is_open()){

string Line;

while(getline(MyFile, Line)){
clsUser User = _OneLineToClass(Line);

if(_UserName != User._UserName){
vUser.push_back(User);
}

}

MyFile.close();
}

_VectorToFile(vUser);
}


void Update(void){
vector <clsUser> vUser;
fstream MyFile;
MyFile.open("Users.txt", ios::in);
if(MyFile.is_open()){

string Line;
while(getline(MyFile, Line)){
clsUser User = _OneLineToClass(Line);

if(_UserName == User._UserName){
_EditData(User);
}

vUser.push_back(User);
}

MyFile.close();
}

_VectorToFile(vUser);
}


void SaveLoginRegister(void){
fstream MyFile;
MyFile.open("LoginTime.txt", ios::out | ios::app);

string UserTime = _TimeAndUserDataToOneLine();

if(MyFile.is_open()){
MyFile << UserTime << endl;
MyFile.close();
}

}

static vector <stLoginRegister> FileLoginTimeToVector(void){
vector <stLoginRegister> vUser;
fstream MyFile;
MyFile.open("LoginTime.txt", ios::in);

if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
stLoginRegister User = OneLineToStruct(Line);
vUser.push_back(User);
}

MyFile.close();
}

return vUser;
}

};