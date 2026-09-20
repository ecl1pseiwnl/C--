#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int a, b;
    int s1 = 0, s2 = 0;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            s1 += i;
        }
    }
    for (int i = 1; i < m; i++) {
        if (m % i == 0) {
            s2 += i;
        }
    }
    if (s1 == m && s2 == n) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
