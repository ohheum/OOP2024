#include <iostream>
#include <cmath>

const int MIN = 0;  // #define MIN 0, constant
const int MAX = 360;
const int STEP = 10;

using namespace std;

int main() {
    double radian, pi, value;
    pi = 4.0 * atan(1.0);

    cout << "Angle : Sine" << endl;
    for (int degree=MIN; degree<=MAX; degree+=STEP) {
        radian = pi*degree/180;
        value = sin(radian);
        cout << degree << " : " << value << endl;
    }
    return 0;
}