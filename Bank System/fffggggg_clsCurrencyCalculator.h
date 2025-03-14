#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsCurrency.h"
#include "fffggggg_clsTools.h"

using namespace std;

class clsCurrencyCalculator : protected clsScreenHeader {
private:
static void _PrintCurrency(clsCurrency Currency, string S){
cout << S << endl;
cout << "____________________________" << endl;
cout << "Country: " << Currency.getCountry() << endl;
cout << "Code: " << Currency.getCode() << endl;
cout << "Name: " << Currency.getName() << endl;
cout << "Rate(1$) = : " << Currency.getRate() << endl;
cout << "____________________________" << endl;

}

public:
static void CurrencyCalculator(void){
do{
system("cls");
_ScreenHeader("\t  Currency Calculator Screen");

string Input1 = clsTools::ReadString("Enter Currency 1 Code: ");
while(!clsCurrency::IsFindCurrency(Input1)){
Input1 = clsTools::ReadString("Enter Currency 1 Code: ");
}

cout << endl;

string Input2 = clsTools::ReadString("Enter Currency 2 Code: ");
while(!clsCurrency::IsFindCurrency(Input2)){
Input2 = clsTools::ReadString("Enter Currency 2 Code: ");
}

cout << endl;

double Amount = clsTools::ReadDouble("Enter Amount To Excheange: ");

cout << endl;

clsCurrency Currency1 = clsCurrency::FindCurrency(Input1);
_PrintCurrency(Currency1, "Convert From");

cout << endl;


if(clsString::UpperAllString(Input2) == "USD"){
//cout << Amount << " " << Input1 << " = " << Amount / Currency1.getRate() << " " << Input2 << endl;
Currency1.CurrencyCalculatorToUSD(Amount);
}


if(clsString::UpperAllString(Input2) != "USD"){
//cout << Amount << " " << Input1 << " = " << Amount / Currency1.getRate() << " " << Input2 << endl;
Currency1.CurrencyCalculatorToUSD(Amount);

cout << "\nConverting from USD to\n\n";

clsCurrency Currency2 = clsCurrency::FindCurrency(Input2);
_PrintCurrency(Currency2, "To");


Currency1.CurrencyCalculator(Currency2, Amount);
//cout << Amount << " " << Input1 << " = " << (Amount / Currency1.getRate()) * Currency2.getRate() << " " << Input2 << endl;
}

cout << endl;

}while(clsTools::YorN("Do you want Perfome another calculation (Y / N): ") == 'Y');

}

};