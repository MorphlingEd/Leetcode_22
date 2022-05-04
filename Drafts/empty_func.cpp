#include<iostream>
using namespace std;

int foo(char* buffer);


int main(){
    char buffer[4] = "abc";
    cout << foo(buffer) << endl;
    return 0;
}