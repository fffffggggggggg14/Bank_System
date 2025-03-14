#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "vector"
#include "fffggggg_clsString.h"

using namespace std;

class clsCurrency {
private:
string _Country;
string _Code;
string _Name;
float _Rate;
enum enMode {Void = 1, Exist = 2};
enMode _Mode;

static clsCurrency _OneLineToClass(string Line, string Format = "#//#"){
vector <string> vCurrency = clsString::SplitString(Line, Format);

return clsCurrency(enMode::Exist, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));
}

static clsCurrency _Void(void){
return clsCurrency(enMode::Void, "", "", "", 0);
}

string _ClassToOneLine(clsCurrency C, string F = "#//#"){
return C._Country + F + C._Code + F + C._Name + F + to_string(C._Rate);
}

void _VectorToFile(vector <clsCurrency> vCurrency){
fstream MyFile;
MyFile.open("Currencies.txt", ios::out);

if(MyFile.is_open()){
for(clsCurrency Currency : vCurrency){
string Line = _ClassToOneLine(Currency);
MyFile << Line << endl;
}

MyFile.close();
}

}

void _Update(void){
vector <clsCurrency> vCurrency;
fstream MyFile;
MyFile.open("Currencies.txt", ios::in);
if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
clsCurrency Currency = _OneLineToClass(Line);
if(_Code == Currency._Code){
Currency._Rate = _Rate;
}

vCurrency.push_back(Currency);
}

MyFile.close();
}

_VectorToFile(vCurrency);
}

public:
clsCurrency(enMode Mode, string Country, string Code, string Name, float Rate){
_Country = Country;
_Code = Code;
_Name = Name;
_Rate = Rate;
_Mode = Mode;
}

bool IsMode(void){
return enMode::Exist == _Mode;
}

string getCountry(void){
return _Country;
}

string getCode(void){
return _Code;
}

string getName(void){
return _Name;
}

void setRate(float Rate){
_Rate = Rate;
_Update();
}

float getRate(void){
return _Rate;
}

static clsCurrency FindCurrency(string Input){
Input = clsString::UpperAllString(Input);

fstream MyFile;
MyFile.open("Currencies.txt", ios::in);
if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
clsCurrency Currency = _OneLineToClass(Line);
if(clsString::UpperAllString(Currency._Country) == Input || Currency._Code == Input){
return Currency;
}

}

MyFile.close();
}

return _Void();
}

static bool IsFindCurrency(string Input){
clsCurrency Currency = clsCurrency::FindCurrency(Input);
return Currency.IsMode();
}


static vector <clsCurrency> FileToVector(void){
vector <clsCurrency> vCurrency;
fstream MyFile;
MyFile.open("Currencies.txt", ios::in);

if(MyFile.is_open()){
string Line;
while(getline(MyFile, Line)){
clsCurrency Currency = _OneLineToClass(Line);
vCurrency.push_back(Currency);
}

MyFile.close();
}

return vCurrency;
}


double CurrencyCalculatorToUSD(double Amount){
cout << Amount << " " << getCode() << " = " << Amount / getRate() << " USD" << endl;
}

double CurrencyCalculator(clsCurrency Currency2, double Amount){
cout << Amount << " " << getCode() << " = " << (Amount / getRate()) * Currency2.getRate() << " " << Currency2.getCode() << endl;
}

};