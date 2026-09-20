#include <iostream>
using namespace std;

int main() {
    int n, m;
    int res = 0, ros = 0;
    int a, b;
    cin >> n >> m;
    while (n > 0) {
        a = n % 10;
        res = res * 10 + a;
        n = n / 10;
    }
    while (m > 0) {
        b = m % 10;
        ros = ros * 10 + b;
        m = m / 10;
    }
    if (res > ros) {
        cout << res;
    }
    else {
        cout << ros;
    }
    return 0;
}