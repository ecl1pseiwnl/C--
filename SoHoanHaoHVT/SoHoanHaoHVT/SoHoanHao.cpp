#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    int sum = 0;
    for (long long i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (n / i == i) {
                sum -= i;
            }
        }
    }
    if (sum == n) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
