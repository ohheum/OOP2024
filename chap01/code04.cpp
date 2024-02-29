#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    string gender;
    cout << "Please enter your name, age, and gender: ";

    cin >> name >> age >> gender;
    cout << name << " " << age << " " << gender << endl;
    if (gender == "male")
        cout << name << ", you’re " << age << " years old man."<< endl;
    else if (gender == "female")
        cout << name << ", you’re " << age << " years old woman." << endl;
    else
        cout << name << ", you’re " << age << " years old." << endl;

    return 0;
}