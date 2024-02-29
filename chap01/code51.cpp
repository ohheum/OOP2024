#include <iostream>
using namespace std;

void bubble_sort(int n, int data[]);
void swap(int &a, int &b);

int main() {
    int data[] = {3, 1, 5, 2, 9, 7, 8, 2};
    bubble_sort(8,  data);
    for (int i=0; i<8; i++)
        cout << data[i] << " ";
    return 0;
}

void bubble_sort(int n, int data[]) {
    for ( int i=n-1; i>0; i--) {
        for ( int j=0; j<i; j++ ) {
            if (data[j] > data[j+1])
                swap(data[j], data[j+1]);
        }
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a= b;
    b = tmp;
}