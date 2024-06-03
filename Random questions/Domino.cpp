#include <iostream>

using namespace std;

int main() {
    long long m, n;
    cin >> m >> n;
    long long TongNgang = 0, TongDoc = 0;
    long long Tong = 0;
    TongNgang = m / 2;
    TongDoc = n;
    Tong = TongNgang * TongDoc;
    if (m % 2 != 0) {
        Tong += 1 * n / 2;
    }
    cout << Tong;
}