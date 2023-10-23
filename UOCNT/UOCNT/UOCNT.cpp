#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int cnt;
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        cnt = 0;
        while (n % i == 0) {
            cnt++;
            if (cnt == 1) {
                sum += i;
            }
            n /= i;
        }
    }
    cout << sum << endl;
