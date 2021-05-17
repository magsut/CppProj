#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    file.open("number.txt");
    if(file.is_open()) {
        string s;
        getline(file,s);
        cout << s << endl;
        string res;
        for(int i = 0; i < s.size(); i++)
        {
            cout << s[i] - '0' + '0' << " " << i << endl;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if( (s[i] - '0' + '0') == -48)
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
                default: res += s[i] - '0' + '0';
            }
        }
        cout << res;
    }
    else
        cout << "File not open";
    file.close();
    return 0;
}
