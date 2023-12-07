#include <iostream>
using namespace std;
typedef long long ll;

const ll N = 100002;
double a[N];

int main() {
    ll n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        long long l, r, a1 = 0, a2 = 0, a3 = 0;
        cin >> l >> r;
        for (long long i = l; i <= r; i++) {
            if (a[i] == 1) {
                a1++;

            }
            else if (a[i] == 2) {
                a2++;

            }
            else {
                a3++;
            }
        } cout << a1 << " " << a2 << " " << a3 << endl;
    }
    return 0;
}