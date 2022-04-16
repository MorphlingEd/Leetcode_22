#include<iostream>
#include<string>
using namespace std;

int main(){
//    string s = to_string(-123);
//    cout << s << endl;
//
//    int num = stoi(s);
//    cout << num << endl;
//
//    s = "1,2,-10,#,5";
//    size_t pos = 0;
//    string token;
//    string delimiter = ",";
//    while ((pos = s.find(delimiter)) != string::npos){
//        token = s.substr(0, pos);
//        cout << token << endl;
//        s.erase(0, pos + delimiter.length());
//    }
//    cout << s << endl;

    int n = 0;
    double sum = 0;

    string word;
    while (cin >> word){
        sum += word.size();
        n++;
    }

    cout << sum / n << endl;


    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);
    // please finish the FUNCTION body here.
    // please define the C output here. FOR EXAMPLE: printf("%d",a);
    return 0;
}