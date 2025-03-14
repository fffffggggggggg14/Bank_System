#pragma once

#include <iostream>
#include <string>
using namespace std;

class clsPerson {
private:
string _FristName;
string _LastName;
string _Email;
string _Phone;

public:
clsPerson(string FristName, string LastName, string Email, string Phone){
_FristName = FristName;
_LastName = LastName;
_Email = Email;
_Phone = Phone;
}

void setFristName(string FirstName){
_FristName = FirstName;
}

string getFristName(void){
return _FristName;
}

void setLastName(string LastName){
_LastName = LastName;
}

string getLastName(void){
return _LastName;
}


void setEmail(string Email){
_Email = Email;
}

string getEmail(void){
return _Email;
}

void setPhone(string Phone){
_Phone = Phone;
}

string getPhone(void){
return _Phone;
}

string getFullName(void){
return _FristName + " " + _LastName;
}

};