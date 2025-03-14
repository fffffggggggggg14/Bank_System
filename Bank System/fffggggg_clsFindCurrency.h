#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsCurrency.h"
#include "fffggggg_clsTools.h"

using namespace std;

class clsFindCurrency : protected clsScreenHeader {
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
static void FindCurrency(void){
_ScreenHeader("\t      Find Curreny Screen");

string Input = clsTools::ReadString("Enter Country Or Code: ");
while(!clsCurrency::IsFindCurrency(Input)){
Input = clsTools::ReadString("Enter Country Or Code: ");
}

cout << "\nCurrency Found (-:\n\n";

clsCurrency Currency = clsCurrency::FindCurrency(Input);

cout << endl;


_PrintCurrency(Currency);

cout << endl;

}

};