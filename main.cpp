#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    string res = "";
    file.open( "/home/maksim/PycharmProjects/pythonProject1/num.txt");
    if(file.is_open()) {
        string s;
        //getline(file,s);
        //file.getline(s);
        file >> s;
        cout << s << endl;
        cout << s.size() << endl;
        for(int i = 0; i < s.size(); i++)
        {
            cout << i <<": " <<s[i] -'0' + '0'<< endl;
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
    ofstream fileout;
    fileout.open("/home/maksim/PycharmProjects/pythonProject1/num.txt");
    if(fileout.is_open())
    {
        fileout << res;
    }
    else
        cout << "File nit open";
    fileout.close();
    return 0;
}

//АВЕКМНОРСТУХ