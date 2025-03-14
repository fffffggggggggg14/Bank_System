#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "fffggggg_clsString.h"
#include "fffggggg_clsPerson.h"
#include "fffggggg_Global.h"
#include "fffggggg_clsDate.h"
#include "fffggggg_clsTools.h"

using namespace std;

class clsBankClient : public clsPerson {
private:
string _AccountNumber;
string _PinCode;
double _AccountBalance;

enum enMode {Void = 1, Exist = 2};
enMode _Mode;

static clsBankClient _OneLineToClass(string Line, string Format = "#//#"){
vector <string> vClient = clsString::SplitString(Line, Format);
return clsBankClient(enMode::Exist, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], clsTools::DecryptText(vClient[5], 3), stod(vClient[6]));
}

static clsBankClient _Void(void){
return clsBankClient(enMode::Void, "", "", "", "", "", "", 0);
}

string _ClassToOneLine(clsBankClient C, string F = "#//#"){
return C.getFristName() + F + C.getLastName() + F + C.getEmail() + F + C.getPhone() + F + C.getAccountNumber() + 
F + clsTools::EncryptText(C.getPinCode(), 3) + F + to_string(C.getAccountBalance());
}

void _VectorToFile(vector <clsBankClient> vClient){
fstream MyFile;
MyFile.open("Clients.txt", ios::out);

if(MyFile.is_open()){
string Line;
for(clsBankClient &vC : vClient){
Line = _ClassToOneLine(vC);
MyFile << Line << endl;
}

MyFile.close();
}

}

enum EditData{FristName = 1, LastName = 2, Email = 3, Phone = 4, PinCode = 5, AccountBalance = 6, All = 7};

void _EditData(clsBankClient &Client){
cout << "====================================" << endl;
cout << "[1] Frist Name." << endl;
cout << "[2] List Name." << endl; 
cout << "[3] Email." << endl;
cout << "[4] Phone." << endl;
cout << "[5] PinCode." << endl;
cout << "[6] Account Balance." << endl;
cout << "[7] All" << endl;
cout << "====================================" << endl;
short ChooseNumber = clsTools::ReadShort("What do you want to update? [1 : 7]: ", 1, 7);

cout << endl;

cout << "Edit Data" << endl;
cout << "____________________________________" << endl;

cout << endl;

if(EditData::All == ChooseNumber){
Client.setFristName(clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Frist Name: ")))));
Client.setLastName(clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Last Name: ")))));
Client.setEmail(clsTools::ReadString("Email: "));
Client.setPhone(clsTools::ReadString("Phone: "));
Client.setPinCode(clsTools::ReadString("Pin Code: "));
Client.setAccountBalance(clsTools::ReadDouble("Account Balance: "));
}

if(EditData::FristName == ChooseNumber){
Client.setFristName(clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Frist Name: ")))));
}

if(EditData::LastName == ChooseNumber){
Client.setLastName(clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Last Name: ")))));
}

if(EditData::Email == ChooseNumber){
Client.setEmail(clsTools::ReadString("Email: "));
}

if(EditData::Phone == ChooseNumber){
Client.setPhone(clsTools::ReadString("Phone: "));
}

if(EditData::PinCode == ChooseNumber){
Client.setPinCode(clsTools::ReadString("PinCode: "));
}

if(EditData::AccountBalance == ChooseNumber){
Client.setAccountBalance(clsTools::ReadDouble("Account Balance: "));
}

}

string _OneLineTransferRegister(clsBankClient Client2, double Transfer, string F = "#//#"){
return clsDate::TimeNow() + F + getAccountNumber() + F + Client2.getAccountNumber() + F + 
to_string(Transfer) + F + to_string(getAccountBalance() - Transfer) + F + to_string(Client2.getAccountBalance() + Transfer) 
+ F + GlobalUser.getUserName();
}

void _SaveTransferRegister(clsBankClient Client2, double Transfer){
fstream MyFile;
MyFile.open("TransferRegister.txt", ios::out | ios::app);
if(MyFile.is_open()){
MyFile << _OneLineTransferRegister(Client2, Transfer) << endl;

MyFile.close();
}

}


public:
clsBankClient(enMode Mode, string FristName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance)
: clsPerson(FristName, LastName, Email, Phone){
_AccountNumber = AccountNumber;
_PinCode = PinCode;
_AccountBalance = AccountBalance;
_Mode = Mode;
}

struct stTransferRegister {
string Time;
string FromAccountNumber;
string ToAccountNumber;
double Amount;
double AccountBalance1;
double AccountBalance2;
string User;
};

bool IsMode(void){
return (enMode::Exist == _Mode);
}

/*void setAccountNumber(string AccountNumber){
_AccountNumber = AccountNumber;
}*/

string getAccountNumber(void){
return _AccountNumber;
}

void setPinCode(string PinCode){
_PinCode = PinCode;
}


string getPinCode(void){
return _PinCode;
}

void setAccountBalance(double AccountBalance){
_AccountBalance = AccountBalance;
}

double getAccountBalance(void){
return _AccountBalance;
}

static stTransferRegister _OneLineTostTransferRegister(string Line, string F = "#//#"){
vector <string> vS = clsString::SplitString(Line, F);
stTransferRegister TransferRegister;

TransferRegister.Time = vS[0];
TransferRegister.FromAccountNumber = vS[1];
TransferRegister.ToAccountNumber = vS[2];
TransferRegister.Amount = stod(vS[3]);
TransferRegister.AccountBalance1 = stod(vS[4]);
TransferRegister.AccountBalance2 = stod(vS[5]);
TransferRegister.User = vS[6];

return TransferRegister;
}


static vector <stTransferRegister> DataTransferRegisterToVectorStruct(void){
vector <stTransferRegister> vTransferRegister;
fstream MyFile;
MyFile.open("TransferRegister.txt", ios::in);
if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
stTransferRegister TransferRegister = _OneLineTostTransferRegister(Line);
vTransferRegister.push_back(TransferRegister);
}

MyFile.close();
}

return vTransferRegister;
}

static vector <clsBankClient> FileToVector(void){
vector <clsBankClient> vClinet;
fstream MyFile;
MyFile.open("Clients.txt", ios::in);
if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
clsBankClient Clinet = _OneLineToClass(Line);
vClinet.push_back(Clinet);
}

MyFile.close();
}

return vClinet;
}


static clsBankClient FindClient(string AccountNumber){
fstream MyFile;
MyFile.open("Clients.txt", ios::in);

if(MyFile.is_open()){
string Line;

while(getline(MyFile, Line)){
clsBankClient Client = _OneLineToClass(Line);

if(Client._AccountNumber == AccountNumber){
return Client;
}

}

MyFile.close();
}

return _Void();
}

/*static clsBankClient FindClient(string AccountNumber, string PinCode){
fstream MyFile;
MyFile.open("Clients.txt", ios::in);

if(MyFile.is_open()){
string Line;

while(getline(MyFile, Line)){
clsBankClient Client = _OneLineToClass(Line);
if(Client._AccountNumber == AccountNumber && Client._PinCode == PinCode){
return Client;
}

}

MyFile.close()
}

return _Void();
}*/


static bool IsFindClient(string AccountNumber){
clsBankClient Client = clsBankClient::FindClient(AccountNumber);
return Client.IsMode();
}

/*static bool IsFindClient(string AccountNumber, string PinCode){
clsBankClient Client = clsBankClient::FindClient(AccountNumber, PinCode);
return IsMode();
}*/

static clsBankClient AddClient(string AccountNumber){
string FristName = clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Frist Name: "))));
string LastName = clsString::UpperFristLetterOfEachWord(clsString::LowerAllString(clsString::EditSpace(clsTools::ReadString("Last Name: "))));
string Email = clsTools::ReadString("Email: ");
string Phone = clsTools::ReadString("Phone: ");
string PinCode = clsTools::ReadString("Pin Code: ");
double AccountBalance = clsTools::ReadDouble("Account Balance: ");

return clsBankClient(enMode::Exist, FristName, LastName, Email, Phone, AccountNumber, PinCode, AccountBalance);
}

void AddClient(void){
fstream MyFile;
MyFile.open("Clients.txt", ios::out | ios::app);

if(MyFile.is_open()){
string Line = _ClassToOneLine(*this);
MyFile << Line << endl;
MyFile.close();
}

}

void DeleteClient(void){
vector <clsBankClient> vClient;
fstream MyFile;
MyFile.open("Clients.txt", ios::in);
if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
clsBankClient Client = _OneLineToClass(Line);
if(_AccountNumber == Client._AccountNumber){
continue;
}

vClient.push_back(Client);
}

MyFile.close();
}

_VectorToFile(vClient);
}

void Update(void){
vector <clsBankClient> vClient;
fstream MyFile;
MyFile.open("Clients.txt", ios::in);

if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){

clsBankClient Client = _OneLineToClass(Line);

if(_AccountNumber == Client._AccountNumber){
_EditData(Client);
}

vClient.push_back(Client);
}

MyFile.close();
}

_VectorToFile(vClient);
}

void Deposit(double ValueDeposit){
vector <clsBankClient> vClient;
fstream MyFile;
MyFile.open("Clients.txt", ios::in);
if(MyFile.is_open()){

string Line;
while(getline(MyFile, Line)){
clsBankClient Client = _OneLineToClass(Line);
if(_AccountNumber == Client._AccountNumber){
Client._AccountBalance += ValueDeposit;
}

vClient.push_back(Client);
}

MyFile.close();
}

_VectorToFile(vClient);
}

void Withdraw(double ValueWithdraw){
vector <clsBankClient> vClient;
fstream MyFile;
MyFile.open("Clients.txt", ios::in);
if(MyFile.is_open()){

string Line;
while(getline(MyFile, Line)){
clsBankClient Client = _OneLineToClass(Line);
if(_AccountNumber == Client._AccountNumber){
Client._AccountBalance -= ValueWithdraw;
}

vClient.push_back(Client);
}

MyFile.close();
}

_VectorToFile(vClient);
}

static double getTotalBalances(void){
vector <clsBankClient> vClient = FileToVector();
double Totalbalaces = 0;
for(clsBankClient &vC : vClient){
Totalbalaces += vC._AccountBalance;
}

return Totalbalaces;
}


void Transfer(clsBankClient Client2, double Transfer){
Withdraw(Transfer);
Client2.Deposit(Transfer);

_SaveTransferRegister(Client2, Transfer);
}


};