#pragma once

#include <iostream>
#include "fffggggg_clsString.h"
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

class clsTools {
public:

enum enTypeChars {CapitalLetter = 1, SmallLetter = 2, NumberChar = 3, PunctuationsChar = 4, MaxChar = 5};

//--------------------------------------------------------------------------------------------------------------

static void Srand(void){
srand((unsigned)time(NULL));
}

static int RandomNumber(int From, int To){
return rand() % (To - From + 1) + From;
}

//---------------------------------------------------------------------------------------------------------------

static char RandomChar(enTypeChars TypeChars){

if(TypeChars == MaxChar){
TypeChars = enTypeChars(RandomNumber(1, 4));
}

if(TypeChars == CapitalLetter){return char(RandomNumber(65, 90));}
if(TypeChars == SmallLetter){return char(RandomNumber(97, 122));}
if(TypeChars == NumberChar){return char(RandomNumber(48, 57));}

if(TypeChars == PunctuationsChar){
int Number = RandomNumber(1, 4);

if(Number == 1){return char(RandomNumber(33, 47));}
if(Number == 2){return char(RandomNumber(58, 46));}
if(Number == 3){return char(RandomNumber(91, 96));}
if(Number == 4){return char(RandomNumber(123, 126));}
}

}

//------------------------------------------------------------------------------------------------------------

static string WordRandomLetter(enTypeChars TypeChars, int Length){
string S;
for(int i = 0; i < Length; i++){
S += RandomChar(TypeChars);
}

return S;
}

//---------------------------------------------------------------------------------------------------------

static string KeyRandomLetter(enTypeChars TypeChar){
return WordRandomLetter(TypeChar, 4) + " - " + WordRandomLetter(TypeChar, 4) + " - " + WordRandomLetter(TypeChar, 4) + " - " + WordRandomLetter(TypeChar, 4);
}


//---------------------------------------------------------------------------------------------------------


static void KeysRandomLetter(enTypeChars TypeChars, int Index){
for(int i = 1; i <= Index; i++){
cout << "[" << i << "] : " << KeyRandomLetter(TypeChars) << endl; 
}

}

//-------------------------------------------------------------------------------------------------------

static void Swap(int &n1, int &n2){
int Temp = n1;
n1 = n2;
n2 = Temp;
}

static void Swap(short &n1, short &n2){
int Temp = n1;
n1 = n2;
n2 = Temp;
}

static void Swap(float &n1, float &n2){
float Temp = n1;
n1 = n2;
n2 = Temp;
}

static void Swap(double &n1, double &n2){
double Temp = n1;
n1 = n2;
n2 = Temp;
}

static void Swap(char &S1, char &S2){
char Temp = S1;
S1 = S2;
S2 = Temp;
}

static void Swap(string &C1, string &C2){
string Temp = C1;
C1 = C2;
C2 = Temp;
}

static void Swap(bool &B1, bool &B2){
bool Temp = B1;
B1 = B2;
B2 = Temp;
}

//---------------------------------------------------------------------------------------------------------


static void ShuffleArray(int Arr[], int Length){
for(int i = 0; i < Length; i++){
Swap(Arr[RandomNumber(0, Length - 1)], Arr[RandomNumber(0, Length - 1)]);
}

}

static void ShuffleArray(short Arr[], int Length){
for(int i = 0; i < Length; i++){
Swap(Arr[RandomNumber(0, Length - 1)], Arr[RandomNumber(0, Length - 1)]);
}

}

static void ShuffleArray(string Arr[], int Length){
for(int i = 0; i < Length; i++){
Swap(Arr[RandomNumber(0, Length - 1)], Arr[RandomNumber(0, Length - 1)]);
}

}

static void ShuffleArray(double Arr[], int Length){
for(int i = 0; i < Length; i++){
Swap(Arr[RandomNumber(0, Length - 1)], Arr[RandomNumber(0, Length - 1)]);
}

}

static void ShuffleArray(float Arr[], int Length){
for(int i = 0; i < Length; i++){
Swap(Arr[RandomNumber(0, Length - 1)], Arr[RandomNumber(0, Length - 1)]);
}

}

static void ShuffleArray(char Arr[], int Length){
for(int i = 0; i < Length; i++){
Swap(Arr[RandomNumber(0, Length - 1)], Arr[RandomNumber(0, Length - 1)]);
}

}

static void ShuffleArray(bool Arr[], int Length){
for(int i = 0; i < Length; i++){
Swap(Arr[RandomNumber(0, Length - 1)], Arr[RandomNumber(0, Length - 1)]);
}

}

//------------------------------------------------------------------------------------------------------


static void FillArrayWithRandomNumbers(int Arr[], int Length, int From, int To){
for(int i = 0; i < Length; i++){
Arr[i] = RandomNumber(From, To);
}

}

static void FillArrayWithRandomNumbers(short Arr[], int Length, short From, short To){
for(int i = 0; i < Length; i++){
Arr[i] = RandomNumber(From, To);
}

}

static void FillArrayWithRandomNumbers(float Arr[], int Length, float From, float To){
for(int i = 0; i < Length; i++){
Arr[i] = RandomNumber(From, To);
}

}

static void FillArrayWithRandomNumbers(double Arr[], int Length, double From, double To){
for(int i = 0; i < Length; i++){
Arr[i] = RandomNumber(From, To);
}

}

static void FillArrayWithRandomString(string Arr[], int Length, enTypeChars TypeChars, int WordLength){
for(int i = 0; i < Length; i++){
Arr[i] = WordRandomLetter(TypeChars, WordLength);
}

}

static void FillArrayWithRandomChar(char Arr[], int Length, enTypeChars TypeChars){
for(int i = 0; i < Length; i++){
Arr[i] = RandomChar(TypeChars);
}

}

static void FillArrayWithRandomBool(bool Arr[], int Length){
for(int i = 0; i < Length; i++){
Arr[i] = RandomNumber(0, 1);
}

}

static void FillArrayWithRandomKeys(string Arr[], int Length, enTypeChars TypeChars){
for(int i = 0; i < Length; i++){
Arr[i] = KeyRandomLetter(TypeChars);
}

}

//-------------------------------------------------------------------------------------------------


static string Tabs(int Length){
string S;
for(int i = 0; i < Length; i++){
S += "\t";
}

return S;
}

//--------------------------------------------------------------------------------------------------

static string EncryptText(string S, int Key){
string EditString;
for(int i = 0; S[i] > '\0'; i++){
EditString += S[i] + Key;
}

return EditString;
}

static string DecryptText(string S, int Key){
string EditString;
for(int i = 0; S[i] > '\0'; i++){
EditString += S[i] - Key;
}

return EditString;
}


//----------------------------------------------------------------------------------------------


static short ReadShort(string S){
short Number;
cout << S;
cin >> Number;

while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Please Number: ";
cin >> Number;
}

return Number;
}

static short ReadShort(string S, short From, short To){
short Number = ReadShort(S);
while(Number < From || Number > To){
cout << "Please Number From " << From << " To " << To << endl;
Number = ReadShort(S);
}

return Number;
}


static int ReadNumber(string S){
int Number;
cout << S;
cin >> Number;

while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Please Number: ";
cin >> Number;
}

return Number;
}

static int ReadNumber(string S, int From, int To){
int Number = ReadNumber(S);
while(Number < From || Number > To){
cout << "Please Number From " << From << " To " << To << endl;
Number = ReadNumber(S);
}

return Number;
}


static float ReadFloat(string S){
float Number;
cout << S;
cin >> Number;

while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Please Number: ";
cin >> Number;
}

return Number;
}

static float ReadFloat(string S, float From, float To){
int Number = ReadFloat(S);
while(Number < From || Number > To){
cout << "Please Number From " << From << " To " << To << endl;
Number = ReadFloat(S);
}

return Number;
}





static double ReadDouble(string S){
double Number;
cout << S;
cin >> Number;

while(cin.fail()){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "Please Number: ";
cin >> Number;
}

return Number;
}

static double ReadDouble(string S, double From, double To){
double Number = ReadDouble(S);
while(Number < From || Number > To){
cout << "Please Number From " << From << " To " << To << endl;
Number = ReadDouble(S);
}

return Number;
}



static string ReadString(string S){
string String;
cout << S;
getline(cin >> ws, String);

return String;
}


static char ReadChar(string S){
char C;

cout << S;
cin >> C;

return C;
}


static bool ReadBool(string S){
bool B;

cout << S;
cin >> B;

return B;
}


//------------------------------------------------------------------------------------------------


static char YorN(string S){
char C, UpperC;
do{
cout << S;
cin >> C;

UpperC = clsString::UpperChar(C);
}while(UpperC != 'Y' && UpperC != 'N');

return UpperC;
}

static bool TorF(string S){
short Number;

do{
cout << S;
cin >> Number;
}while(Number != 0 && Number != 1);

return Number;
}



//-------------------------------------------------------------------------------------------------


static bool IsNumberBetween(int Number, int From, int To){
return Number >= From && Number <= To;
}

static bool IsNumberBetween(short Number, short From, short To){
return Number >= From && Number <= To;
}

static bool IsNumberBetween(float Number, float From, float To){
return Number >= From && Number <= To;
}

static bool IsNumberBetween(double Number, double From, double To){
return Number >= From && Number <= To;
}


};
