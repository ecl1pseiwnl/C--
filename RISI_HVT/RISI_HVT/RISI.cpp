#include <iostream>

using namespace std;

int main() {
    int n, k;
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

//cach 2:
int main2() {
    int n, k, dem = 0;
    cin >> n >> k;
    long long tongsp = k;
    while (tongsp < n) {
        k = k * 2;
        tongsp += k;
        dem++;
    }
    cout << dem;
}