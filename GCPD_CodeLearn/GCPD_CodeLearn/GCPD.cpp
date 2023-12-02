#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool ar[1000001];

void sangsnt(int n) {
    for (int i = 2; i <= n; i++) {
        ar[i] = 1;
    }
    ar[0] = ar[1] = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (ar[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                ar[j] = 0;
            }
        }
    }
}


int greatestCommonPrimeDivisor(int a, int b)
{
    sangsnt(min(a, b));
    int d = 0;
    for (int i = min(a, b); i >= 2; i--) {
        if (ar[i] && a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << greatestCommonPrimeDivisor(a, b);
    return 0;
}