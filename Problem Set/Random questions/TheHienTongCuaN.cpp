#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << "IMPOSSIBLE";
    }
    else {
        for (int i = 1; i <= n / 2 + 1; ++i) {
            int sum = 0;
            for (int j = i; sum < n; ++j) {
                sum += j;
                if (sum == n) {
                    for (int k = i; k <= j; ++k) {
                        cout << k;
                        if (i < j) {
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}