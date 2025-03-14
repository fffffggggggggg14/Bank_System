#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "iomanip"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsCurrency.h"

using namespace std;

class clsCurrencyList : protected clsScreenHeader {
private:
static void PrintCurrencyData(clsCurrency Currency){
cout << "| " << left << setw(30) << Currency.getCountry();
cout << "| " << left << setw(10) << Currency.getCode();
cout << "| " << left << setw(42) << Currency.getName();
cout << "| " << left << setw(15) << Currency.getRate() << endl;

}

public:
static void CurrencyList(void){
vector <clsCurrency> vCurrency = clsCurrency::FileToVector();

_ScreenHeader("\t     Currencies List Scrren\n\t\t\t\t\t\t\t(" + to_string(vCurrency.size()) + ") Currency");

cout << "______________________________________________________________________________________________________" << endl;
cout << "| " << left << setw(30) << "Country";
cout << "| " << left << setw(10) << "Code";
cout << "| " << left << setw(42) << "Name";
cout << "| " << left << setw(15) << "Rate/(1$)" << endl;
cout << "______________________________________________________________________________________________________" << endl;

for(clsCurrency &Currency : vCurrency){
PrintCurrencyData(Currency);
}

cout << "______________________________________________________________________________________________________" << endl;

}


};