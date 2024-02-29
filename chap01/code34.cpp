#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 1000;

int main() {
    ifstream infile("input34.txt");
    string lines[MAX];
    string line;
    int n=0;
    while(getline(infile, line))
        lines[n++] = line;
    infile.close();

    for (int i=n-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (lines[j].length() > lines[j+1].length()) {
                string tmp = lines[j];
                lines[j] = lines[j+1];
                lines[j+1] = tmp;
            }
        }
    }

    for (int i=0; i<n; i++)
        cout << lines[i] << endl;
    return 0;
}