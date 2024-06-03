#include <iostream>
using namespace std;

int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    long long x = 0;
    for (long long i = 1; i <= k; i++) {
        if (i % 2 == 1) {
            x += a;
        }
        else {
            x -= b;
        }
    }
    cout << x;
}