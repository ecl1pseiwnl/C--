#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7 + 1;
ll a[N], F[N];

void seive(ll l, ll r) {
    // 1 = false, 0 = true
    a[0] = a[1] = 1;
    for (int i = 2; i <= sqrt(N); i++) {
        if (a[i] == 0) {
            for (int j = i * i; j < r; j += i) {
                a[j] = 1;
            }
        }
    }
    for (ll i = l; i <= r; i++) {
        if (a[i] == 0 && a[i + 2] == 0 && i + 2 <= r) {
            F[i] = F[i - 1] + 1;
        }
        else {
            F[i] = F[i - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll l, r;
    cin >> l >> r;
    seive(l, r);
    cout << F[r] - F[l - 1];
}