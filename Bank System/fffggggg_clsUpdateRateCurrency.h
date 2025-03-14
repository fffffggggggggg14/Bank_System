#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsCurrency.h"
#include "fffggggg_clsScreenHeader.h"

using namespace std;

class clsCurrencyRate : protected clsScreenHeader {
private:
static void _PrintCurrency(clsCurrency Currency){
cout << "Currency Card" << endl;
cout << "____________________________" << endl;
cout << "Country: " << Currency.getCountry() << endl;
cout << "Code: " << Currency.getCode() << endl;
cout << "Name: " << Currency.getName() << endl;
cout << "Rate(1$) = : " << Currency.getRate() << endl;
cout << "____________________________" << endl;

}


public:
static void CurrencyRate(void){
_ScreenHeader("\t    Update Currency Screen");

string Input = clsTools::ReadString("Enter Country Or Code: ");
while(!clsCurrency::IsFindCurrency(Input)){
Input = clsTools::ReadString("Enter Country Or Code: ");
}

clsCurrency Currency = clsCurrency::FindCurrency(Input);

cout << endl;

_PrintCurrency(Currency);

cout << endl;


if(clsTools::YorN("Are You Sure: (Y / N): ") == 'Y'){}
cout << "Update Currency Rate:" << endl;
cout << "____________________" << endl;
Currency.setRate(clsTools::ReadFloat("Enter New Rate: "));

cout << "\nCurrency Rate Update Successfully (-:\n\n";

_PrintCurrency(Currency);

cout << endl;

}

};