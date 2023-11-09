#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long tong = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }
    if (tong > n) {
        cout << "1";
    }
    else cout << "0";
}