#include <iostream>
using namespace std;

int tinhTongUoc(int n) {
    int tong = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            tong += i;
        }
    }
    return tong;
}

bool laSoPhongPhu(int n) {
    return n < tinhTongUoc(n);
}

int main() {
    int n;
    cin >> n;
    if (laSoPhongPhu(n)) {
        cout << "1";
    }
    else {
        cout << "0";
    }
    return 0;
}