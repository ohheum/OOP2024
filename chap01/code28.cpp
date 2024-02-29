#include <iostream>
#include <string>
using namespace std;

int main() {
    string str; 		// 빈(empty) 스트링
    string str1 = "John Doe";
    string str2("Nam-gu, Busan, Korea");
    string name = str1;
    string address(str2);
    cout << str << " " << str1 << " " << str2 << " "
         << name << " " << address << endl;
    string str3 = {"Hello World"};
    string str4{"Hello World"};
    string str5{str3};
    cout << str3 << " " << str4 << " " << str5 << endl;
    return 0;
}