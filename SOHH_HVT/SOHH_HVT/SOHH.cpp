#include <iostream>
#include <cmath>
using namespace std;

bool shh(int n) {
    int sum = 1;
    if (n < 0) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (n / i != i) {
                sum += n / i;
            }
        }
    }
    if (sum == n) {
        return true;
    }
    else return false;
}

int main() {
    int n, dem = 0;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (shh(i)) {
            dem++;
            cout << i << " ";
        }
    }
    if (dem == 0) cout << "-1";
}