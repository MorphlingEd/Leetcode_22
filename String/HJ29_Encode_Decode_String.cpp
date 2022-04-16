#include<iostream>
#include<string>
using namespace std;

int main(){
    string enc, dec;
    cin >> enc; cin >> dec;

    for (int i = 0; i < enc.size(); i++){
        char c = enc[i];
        if (c >= 'a' && c <= 'z')
            c = (c == 'z' ? 'A' : (c+1 - 'a' + 'A'));
        else if (c >= 'A' && c <= 'Z')
            c = (c == 'Z' ? 'a' : (c+1 - 'A' + 'a'));
        else if (c >= '0' && c <= '9')
            c = (c == '9' ? '0' : c+1);

        cout << c;
    }
    cout << endl;

    for (int i = 0; i < dec.size(); i++){
        char c = dec[i];
        if (c >= 'a' && c <= 'z')
            c = (c == 'a' ? 'Z' : (c - 1 - 'a' + 'A'));
        else if (c >= 'A' && c <= 'Z')
            c = (c == 'A' ? 'z' : (c - 1 - 'A' + 'a'));
        else if (c >= '0' && c <= '9')
            c = (c == '0' ? '9' : c - 1);

        cout << c;
    }
    cout << endl;

    return 0;
}