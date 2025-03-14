#pragma once

#include <iostream>
#include <string>
#include "fffggggg_clsTools.h"
#include "fffggggg_clsScreenHeader.h"
#include "fffggggg_clsMainMenue.h"
#include "fffggggg_clsCurrencyList.h"
#include "fffggggg_clsFindCurrency.h"
#include "fffggggg_clsUpdateRateCurrency.h"
#include "fffggggg_clsCurrencyCalculator.h"

using namespace std;

class clsCurrencyExchange : protected clsScreenHeader {
private:
enum enMenue {LsitCurrencies = 1, FindCurrencies = 2, UpdataRate = 3, CurrencyCalculator = 4, MainMenue = 5};

static void _GoBackMainMenue(void){
system("pause");
CurrencyExhangeMenue();
}

static void _PrintMainMenue(void){
system("cls");
_ScreenHeader("\tCurrancy Exhange Main Screen");
cout << "=======================================================" << endl;
cout << "Currency Exhange Menue" << endl;
cout << "=======================================================" << endl;
cout << "[1] List Currencies." << endl;
cout << "[2] Fine Currency." << endl;
cout << "[3] Update Rate." << endl;
cout << "[4] Currency Calculator." << endl;
cout << "[5] Main Menue." << endl;
cout << "=======================================================" << endl;
}

static void _LsitCurrencies(void){
//cout << "Lsit Currencies" << endl;
clsCurrencyList::CurrencyList();
}

static void _FindCurrencies(void){
//cout << "Find Currencies" << endl;
clsFindCurrency::FindCurrency();
}

static void _UpdataRate(void){
//cout << "Update Rate" << endl;
clsCurrencyRate::CurrencyRate();
}

static void _CurrencyCalculator(void){
//cout << "Currency Calculator" << endl;
clsCurrencyCalculator::CurrencyCalculator();
}

public:
static void CurrencyExhangeMenue(void){
_PrintMainMenue();

short ChooseNumber = clsTools::ReadShort("Choose what do you want to do? [1 : 5]: ", 1, 5);

if(ChooseNumber == enMenue::LsitCurrencies){
system("cls");
_LsitCurrencies();
_GoBackMainMenue();
}

if(ChooseNumber == enMenue::FindCurrencies){
system("cls");
_FindCurrencies();
_GoBackMainMenue();
}

if(ChooseNumber == enMenue::UpdataRate){
system("cls");
_UpdataRate();
_GoBackMainMenue();
}

if(ChooseNumber == enMenue::CurrencyCalculator){
system("cls");
_CurrencyCalculator();
_GoBackMainMenue();
}


}


};