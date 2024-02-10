#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            m += i;
            if (n / i != i) {
                m += (n / i);
            }
        }
    }
    if (m == n) {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}
