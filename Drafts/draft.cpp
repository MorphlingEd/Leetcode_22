#include<iostream>
#include<unordered_set>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{
//    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);
//    // please finish the FUNCTION body here.
//    // please define the C output here. FOR EXAMPLE: printf("%d",a);
//    unordered_set<char> vowels = {'a','e','i','o','u',
//                                 'A','E','I','O','U'};
//
//    string word;
//    while(cin >> word) {
//        for (char & i : word){
//            char c = i;
//            if (vowels.find(c) != vowels.end() && c > 'a')
//                i = c - 'a' + 'A';
//            else if (vowels.find(c) == vowels.end() && c < 'a')
//                i = c - 'A' + 'a';
//        }
//        cout << word << " ";
//    }
//    cout << endl;
//
//    return 0;
//    string S;
//    cin >> S;
//
//    unordered_map<char, int> records;
//    for (const char& c : S)
//        records[c]++;
//
//    int res = 1, n = S.size();
//    for (int i = 1; i <= n; i++)
//        res *= i;
//
//    for (auto& tup : records)
//        if (tup.second > 1)
//            for (int i = 1; i <= tup.second; i++)
//                res /= i;
//    cout << res << endl;
    for (float f = 0; f < 1.1; f += 0.1)
        cout << f+0.5 <<  ": " << round(f + 0.5) << endl;

    return 0;
}