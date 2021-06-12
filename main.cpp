#include <iostream>
#include <fstream>

using namespace std;

bool isANumber(string &n);
bool isCharAPossible(char &c);
bool isAPossibleRegion(int &n);

int main() {
    ifstream file;
    string res = "";
    file.open(R"(C:\Users\maksi\Desktop\pythonProject1\num.txt)");
    if(file.is_open()) {
        string s;
        file >> s;
        cout << s << endl;
        cout << s.size() << endl;
        for(int i = 0; i < s.size(); i++)
        {
            cout << i <<": " <<s[i] -'0' + '0'<< endl;
            if( (s[i] - '0' + '0') == -48 || (s[i] - '0' + '0') == -47)
            {
                continue;
            }
            switch (s[i] - '0' + '0') {
                case -112: res += 'A'; break;
                case -110: res += 'B';break;
                case -107: res += 'E';break;
                case -102: res += 'K';break;
                case -100: res += 'M';break;
                case -99: res += 'H';break;
                case -98: res += 'O';break;
                case -96: res += 'P';break;
                case -95: res += 'C';break;
                case -94: res += 'T';break;
                case -93: res += 'Y';break;
                case -91: res += 'X';break;
                case -80: res += 'A';break;
                case -78: res += 'B';break;
                case -75: res += 'E';break;
                case -70: res += 'K';break;
                case -68: res += 'M';break;
                case -67: res += 'H';break;
                case -66: res += 'O';break;
                case -128: res += 'P';break;
                case -127: res += 'C';break;
                case -126: res += 'T';break;
                case -125: res += 'Y';break;
                case -123: res += 'X';break;
                default: res += s[i] - '0' + '0';
            }
        }
        cout << res;
    }
    else
        cout << "File not open";
    file.close();
    if(isANumber(res)) {
        ofstream fileout;
        fileout.open(R"(C:\Users\maksi\Desktop\pythonProject1\num.txt)");
        if(fileout.is_open()) {
            fileout << res;
        } else
            cout << "File not open";
        fileout.close();
    } else {
        ofstream fileout;
        fileout.open(R"(C:\Users\maksi\Desktop\pythonProject1\num.txt)");
        if(fileout.is_open()) {
            fileout << "Invalid number";
        } else
            cout << "File not open";
        fileout.close();
    }


    return 0;
}

bool isANumber(string &n)
{
    bool isFirstAPossibleChar = isCharAPossible(n[0]);
    bool isSecondAPossibleChar = isCharAPossible(n[4]);
    bool isThirdAPossibleChar = isCharAPossible(n[5]);
    bool isAInt = (n[1] - '0' >=0 && n[1] - '0' <=10) && (n[2] - '0' >=0 && n[2] - '0' <=10) && (n[3] - '0' >=0 && n[3] - '0' <=10);
    int reg = 0;
    for(int i = 6; i < n.size(); i++)
    {
        reg = reg * 10 + (n[i] - '0');
    }
    bool isRightRegion = isAPossibleRegion(reg);
    return isFirstAPossibleChar && isSecondAPossibleChar && isThirdAPossibleChar && isAInt && isRightRegion;
}

bool isCharAPossible(char &c)
{
    char possibleSymbols[12] = {'A','B','E','K','M','H','O','P','C','T','Y','X'};
    for(int i = 0; i < 12; i++)
    {
        if(c == possibleSymbols[i]){
            return true;
        }
    }
    return false;
}

bool isAPossibleRegion(int &n)
{
 int possibleRegions[42] = {102,113,116,121,122,123,124,125,126,134,136,138,142,147,150,152,154156,159,161,163,164,173,174,177,
                          178,186,190,193,196,197,198,199,702,750,716,761,763,774,777,790,797,799};
 if(n >0 && n < 100){
     return true;
 } else{
     for(int possibleRegion : possibleRegions)
     {
         if(n == possibleRegion){
             return true;
         }
     }
 }
    return false;
}
