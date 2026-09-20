#include <iostream>

using namespace std;

//ham tim so cuoi cung cua giai thua khac 0
int lastDigit(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
        while (res % 10 == 0) {
            res /= 10;
        }
        res = res % 100;
    }
    while (res % 10 == 0) {
        res /= 10;
    }
    return res % 10;
}

// toan tu tim so cuoi cung cua giai thua khac 0
int main()
{
    int n;
    cin >> n;
    long long res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
        while (res % 10 == 0) res /= 10;
        res = res % 100;
    }
    while (res % 10 == 0) res /= 10;
    cout << res % 10;
}