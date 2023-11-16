#include <iostream>

using namespace std;

int main() {
    int n, k;
    int m;
    cin >> n >> k;
    long long tongsp = 0;
    int dem = 0;
    while (tongsp < n) {
        tongsp += k;
        k = k * 2;
        dem++;
    }
    cout << dem;
}