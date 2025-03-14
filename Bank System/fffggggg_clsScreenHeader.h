#pragma once

#include <iostream>
#include <string>
#include "fffggggg_Global.h"
#include "fffggggg_clsDate.h"
using namespace std;

static bool _Allow(short Value){
return (GlobalUser.getPermissions() & Value) != 0;
}

static string Powers(bool Flag){
string S;

if(!Flag){return "";}

if(GlobalUser.getPermissions() == -1){return "(All system Screens)";}

if(_Allow(1)){S += "(1) ";}
if(_Allow(2)){S += "(2) ";}
if(_Allow(4)){S += "(3) ";}
if(_Allow(8)){S += "(4) ";}
if(_Allow(16)){S += "(5) ";}
if(_Allow(32)){S += "(6) ";}
if(_Allow(64)){S += "(7) ";}
if(_Allow(128)){S += "(8) ";}
if(_Allow(256)){S += "(9) ";}

return S;
}

class clsScreenHeader {

protected:
static void _ScreenHeader(string S, bool Flag = 0){
cout << "\t\t\t\t\t____________________________________________\n";
cout << "\t\t\t\t\t" << S << endl;
cout << "\t\t\t\t\t____________________________________________\n\n";
cout << "\t\t\t\t\t" << "User: " << GlobalUser.getUserName() << " " << Powers(Flag) << endl;
clsDate Date;
cout << "\t\t\t\t\tDate: ";
Date.PrintDate();
cout << "\n\n";
}


};