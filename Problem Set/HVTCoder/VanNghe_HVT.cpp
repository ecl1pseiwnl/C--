#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ucln = __gcd(n, m);
    int x = n / ucln;
    int y = m / ucln;
    cout << ucln << endl << x << " " << y;
}