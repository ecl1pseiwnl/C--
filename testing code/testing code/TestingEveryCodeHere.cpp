#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int dem = 0;
    while (n != 0) {
        if (n >= 50) {
            dem++;
            n -= 50;
        }
        else if (n >= 20) {
            dem++;
            n -= 20;
        }
        else if (n >= 10) {
            dem++;
            n -= 10;
        }
    }
    cout << dem;
}