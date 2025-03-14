#pragma once

#include <iostream>
#include "fffggggg_clsDate.h"
using namespace std;


class clsPeriod {
private:
clsDate _StartPeriod;
clsDate _EndPeriod;

public:

clsPeriod(clsDate StartPeriod, clsDate EndPeriod){
_StartPeriod = StartPeriod;
_EndPeriod = EndPeriod;
}


static bool IsOverLapIsPeriod(clsPeriod P1, clsPeriod P2){
return !((P2._EndPeriod.IsDateBeforeDate2(P1._StartPeriod)) || (P1._EndPeriod.IsDateBeforeDate2(P2._StartPeriod)));

}

bool IsOverLapIsPeriod(clsPeriod P2){
return IsOverLapIsPeriod(*this, P2);
}


//--------------------------------------------------------------------------------------------------------


static int PeriodLengthInDay(clsPeriod P1, bool Flag = 0){
return P1._StartPeriod.GetDifferenceInDays(P1._EndPeriod, Flag);
}


int PeriodLengthInDay(bool Flag = 0){
return PeriodLengthInDay(*this, Flag); 
}

//---------------------------------------------------------------------------------------------------------


static bool IsDateInPeriod(clsPeriod P, clsDate D){
return (P._StartPeriod.IsDateBeforeDate2(D) && P._EndPeriod.Date1AfterDate2(D)) || 
(P._StartPeriod.IsDate1EqualDate2(D) || P._EndPeriod.IsDate1EqualDate2(D));

}

bool IsDateInPeriod(clsDate D){
return IsDateInPeriod(*this, D);
}


//-----------------------------------------------------------------------------------------------------------


static int CountOverLapDays(clsPeriod P1, clsPeriod P2){
if(!P1.IsOverLapIsPeriod(P2)){return 0;}
int LengthPeriod1 = P1.PeriodLengthInDay();
int LengthPeriod2 = P2.PeriodLengthInDay();
int CountDays = 0;

if(LengthPeriod1 < LengthPeriod2){
while(!P1._StartPeriod.IsDate1EqualDate2(P1._EndPeriod)){

if(P2.IsDateInPeriod(P1._StartPeriod)){CountDays++;}

P1._StartPeriod.AddOneDay();

}

}


else {

while(!P2._StartPeriod.IsDate1EqualDate2(P2._EndPeriod)){

if(P1.IsDateInPeriod(P2._StartPeriod)){CountDays++;}

P2._StartPeriod.AddOneDay();

}


}


return CountDays;
}


int CountOverLapDays(clsPeriod P2){
return CountOverLapDays(*this, P2);
}

};

// Mohamed Essam
// fffggggg