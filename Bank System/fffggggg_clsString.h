#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class clsString {
private:
string _S;

public:
static char UpperChar(char C){
return (C >= 97 && C <= 122) ? C -= 32 : C;
}

static char LowerChar(char C){
return (C >= 65 && C <= 90) ? C += 32 : C; 
}

static bool IsLowerChar(char C){
return (C >= 97 && C <= 122);
}

static bool IsUpperChar(char C){
return (C >= 65 && C <= 90);
}

static char InvertChar(char C){
if(C >= 65 && C <= 90){return C += 32;}
if(C >= 97 && C <= 122){return C -= 32;}
}

static bool IsCharVowel(char C){
return LowerChar(C) == 'a' || LowerChar(C) == 'e' || LowerChar(C) == 'i' || LowerChar(C) == 'o' || LowerChar(C) == 'u'; 
}

static bool isCharPunctuations(char C){
return ((C >= 33 && C <= 47) || (C >= 58 && C <= 64) || (C >= 91 && C <= 96) || (C >= 123 && C <= 126));
}


static bool Test(string S, string XX, int &length){

if(S[length] == XX[0]){
for(int j = 0; XX[j] > '\0'; j++){
if(S[length + j] != XX[j]){return 0;}
}
length = length + Length(XX) - 1;
return 1;
}

return 0;
}


//-----------------------------------------------------------------------------------------------------


clsString(void){}

clsString(string String){
_S = String;
}

void setString(string String){
_S = String;
}

string getString(void){
return _S;
}



//----------------------------------------------------------------------------------


static void PrintFristLetterOfEachWord(string S){
vector <char> vFristChar;

if(S[0] != ' '){vFristChar.push_back(S[0]);}

for(int i = 0; S[i] > '\0'; i++){
if(S[i] != ' ' && S[i - 1] == ' '){
vFristChar.push_back(S[i]);
}
}

for(char &Char : vFristChar){
cout << Char << endl;
}

}

void PrintFristLetterOfEachWord(void){
PrintFristLetterOfEachWord(_S);
}



//-----------------------------------------------------------------------------------



static string UpperFristLetterOfEachWord(string S){
string EditString;
short Length = 0;

if(S[0] != ' ' && IsLowerChar(S[0])){
EditString += UpperChar(S[0]);
Length++;
}

for(Length; S[Length] > '\0'; Length++){
if((S[Length] != ' ' && S[Length - 1] == ' ') && IsLowerChar(S[Length])){
EditString += UpperChar(S[Length]);
continue;
}
EditString += S[Length];
}

return EditString;
}


void UpperFristLetterOfEachWord(void){
_S = UpperFristLetterOfEachWord(_S);
}



//-----------------------------------------------------------------------



static string LowerFristLetterOfEachWord(string S){
string EditString;
short Length = 0;

if(S[0] != ' ' && IsUpperChar(S[0])){
EditString += LowerChar(S[0]);
Length++;
}

for(Length; S[Length] > '\0'; Length++){
if((S[Length] != ' ' && S[Length - 1] == ' ') && IsUpperChar(S[Length])){
EditString += LowerChar(S[Length]);
continue;
}
EditString += S[Length];
}

return EditString;
}

void LowerFristLetterOfEachWord(void){
_S = LowerFristLetterOfEachWord(_S);
}



//------------------------------------------------------------------------



static string UpperAllString(string S){
string EditString;
for(int i = 0; S[i] > '\0'; i++){
if(IsLowerChar(S[i])){
EditString += UpperChar(S[i]);
continue;}
EditString += S[i];
}

return EditString;
}


void UpperAllString(void){
_S = UpperAllString(_S);
}


//-----------------------------------------------------------------------------


static string LowerAllString(string S){
string EditString;
for(int i = 0; S[i] > '\0'; i++){
if(IsUpperChar(S[i])){
EditString += LowerChar(S[i]);
continue;
}
EditString += S[i];
}

return EditString;
}


void LowerAllString(void){
_S = LowerAllString(_S);
}

//------------------------------------------------------------------------------


static string InvertAllCharString(string S){
string EditString;
for(int i = 0; S[i] > '\0'; i++){
EditString += InvertChar(S[i]);
}

return EditString;
}

void InvertAllCharString(void){
_S = InvertAllCharString(_S);
}

//-----------------------------------------------------------------------



static int Length(string S){
int CountChar = 0;
for(int i = 0; S[i] > '\0'; i++){
CountChar++;
}

return CountChar;
}

int Length(void){
return Length(_S);
}



//------------------------------------------------------------------------


static int CountCapitalLetters(string S){
int CountChar = 0;
for(int i = 0; S[i] > '\0'; i++){
if(IsUpperChar(S[i])){CountChar++;}
}

return CountChar;
}

int CountCapitalLetters(void){
return CountCapitalLetters(_S);
}


//--------------------------------------------------------------------


static int CountSmallLetters(string S){
int CountChar = 0;
for(int i = 0; S[i] > '\0'; i++){
if(IsLowerChar(S[i])){CountChar++;}
}

return CountChar;
}

int CountSmallLetters(void){
return CountSmallLetters(_S);
}


//----------------------------------------------------------------------

static int CountTheCharInString(string S, char C, bool Flag = 0){
int CountChar = 0;

if(Flag){
for(int i = 0; S[i] > '\0'; i++){
if(LowerChar(S[i]) == LowerChar(C)){CountChar++;}
}

return CountChar;
}


for(int i = 0; S[i] > '\0'; i++){
if(S[i] == C){CountChar++;}
}

return CountChar;
}

int CountTheCharInString(char C, bool Flag = 0){
return CountTheCharInString(_S, C, Flag);
}


//-------------------------------------------------------------------


static int CountCharVower(string S){
int CountChar = 0;
for(int i = 0; S[i] > '\0'; i++){
if(IsCharVowel(S[i])){CountChar++;}
}

return CountChar;
}

int CountCharVower(void){
return CountCharVower(_S);
}


//-------------------------------------------------------------------------


static void PrintCharVowels(string S){
vector <char> vCharVowels;

for(int i = 0; S[i] > '\0'; i++){
if(IsCharVowel(S[i])){
vCharVowels.push_back(S[i]);
}
}

for(char &C : vCharVowels){
cout << C << " ";
}
}


void PrintCharVowels(void){
PrintCharVowels(_S);
}


//-------------------------------------------------------------------------------


static void PrintEachWordInString(string S){
vector <string> vEachWord;
string Word;

for(int i = 0; S[i] > '\0'; i++){
if(S[i] != ' '){
Word += S[i];
}
else{
vEachWord.push_back(Word);
Word = "";
}
}
vEachWord.push_back(Word);

for(string &SS : vEachWord){
if(SS != ""){cout << SS << endl;}
}

}

void PrintEachWordInString(void){
PrintEachWordInString(_S);
}


//-----------------------------------------------------------------------------------


static int CountEachWordInString(string S){
vector <string> vEachWord;
string Word;
int CountWord = 0;

for(int i = 0; S[i] > '\0'; i++){
if(S[i] != ' '){
Word += S[i];
}
else{vEachWord.push_back(Word);
Word = "";}
}
vEachWord.push_back(Word);

for(string &SS : vEachWord){
if(SS != ""){CountWord++;}
}

return CountWord;
}

int CountEachWordInString(void){
return CountEachWordInString(_S);
}


//------------------------------------------------------------------------------------


static vector <string> SplitString(string S, string XX){
vector <string> vEachWord;
string Word;

for(int i = 0; S[i] > '\0'; i++){
if(!Test(S, XX, i)){
Word += S[i];
}
else {
if(Word != ""){vEachWord.push_back(Word);
Word = "";}
}
}
vEachWord.push_back(Word);

return vEachWord;
}

static vector <string> SplitString(clsString clsS, string XX){
vector <string> vEachWord;
string S = clsS.getString();
string Word;

for(int i = 0; S[i] > '\0'; i++){
if(!Test(S, XX, i)){
Word += S[i];
}
else {
if(Word != ""){vEachWord.push_back(Word);
Word = "";}
}
}
vEachWord.push_back(Word);

return vEachWord;
}


vector <string> SplitString(string XX = " "){
return SplitString(_S, XX);
}


//------------------------------------------------------------------------


static string TrimRight(string S){
string EditString;
int CountSpace = 0;
for(int i = 0; S[i] > '\0'; i++){
if(S[i] != ' '){break;}
CountSpace++;
}

for(int i = CountSpace; S[i] > '\0'; i++){
EditString += S[i];
}

return EditString;
}

void TrimRight(void){
_S = TrimRight(_S);
}


//----------------------------------------------------------------------------


static string TrimLeft(string S){
int CountChar = Length(S);
string EditString;
int CountSpace = 0;

for(int i = CountChar - 1; i >= 0; i--){
if(S[i] != ' '){break;}
CountSpace++;
}

for(int i = 0; i < CountChar - CountSpace; i++){
EditString += S[i];
}

return EditString;
}


void TrimLeft(void){
_S = TrimLeft(_S);
}


//-----------------------------------------------------------------------------


static string Trim(string S){
S = TrimRight(S);
S = TrimLeft(S);

return S;
}

void Trim(void){
_S = Trim(_S);
}


//--------------------------------------------------------------------------------


static string JoinString(vector <string> vString, string XX){
string EditString;

for(int i = 0; i < vString.size(); i++){
EditString += vString[i];

if(i != vString.size() - 1){
EditString += XX;
}

}

return EditString;
}


//---------------------------------------------------------------------------------


static string JoinString(string Array[], int Length, string XX){
string EditString;

for(int i = 0; i < Length; i++){
EditString += Array[i];

if(i != Length - 1){
EditString += XX;
}

}

return EditString;
}


//-----------------------------------------------------------------------------------

static string ReplaceWords(string S, string FromString, string ToString, bool Flag = 0){
vector <string> vString;
vString = SplitString(S, " ");

string EditString;

for(int i = 0; i < vString.size(); i++){

if(Flag){
if(LowerAllString(vString[i]) == LowerAllString(FromString)){vString[i] = ToString;}
}

else if(vString[i] == FromString){vString[i] = ToString;}

EditString += vString[i];

if(i != vString.size() - 1){
EditString += " ";
}

}

return EditString;
}


void ReplaceWords(string FromString, string ToString, bool Flag = 0){
_S = ReplaceWords(_S, FromString, ToString, Flag);
}


//------------------------------------------------------------------------------------


static string ReverseWordInString(string S){
vector <string> vString;
vString = SplitString(S, " ");

string EditString;

for(int i = vString.size() - 1; i >= 0; i--){
EditString += vString[i];

if(i != 0){
EditString += " ";
}

}

return EditString;
}

void ReverseWordInString(void){
_S = ReverseWordInString(_S);
}


//----------------------------------------------------------------------------------------


static string RemovePunctuations(string S){
string EditString;

for(int i = 0; S[i] > '\0'; i++){
if(isCharPunctuations(S[i])){continue;}
EditString += S[i];
}

return EditString;
}

void RemovePunctuations(void){
_S = RemovePunctuations(_S);
}


//------------------------------------------------------------------------------------------


static string EditSpace(string S){
string EditString;

S = Trim(S);

for(int i = 0; S[i] > '\0'; i++){

if(S[i] == ' ' && S[i + 1] == ' '){continue;}

EditString += S[i];

}

return EditString;
}

void EditSpace(void){
_S = EditSpace(_S);
}

//--------------------------------------------------------------------------------------------------------------

static string SwitchCharString(string S, string FromChars, string ToChars){
string EditString;
for(int i = 0; S[i] > '\0'; i++){
if(Test(S, FromChars, i)){
EditString += ToChars;
continue;
}
EditString += S[i];
}

return EditString;
}

void SwitchCharString(string FromChars, string ToChars){
_S = SwitchCharString(_S, FromChars, ToChars);
}


};

// Mohamed Essam
// fffggggg