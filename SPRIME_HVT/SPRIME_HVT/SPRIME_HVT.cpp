#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
ll l, r;

void sang(ll l, ll r) {
    bool tf = true;
    vector<bool> a(r - 1, true);
    for (ll i = 2; i <= sqrt(r); i++) {
        for (ll j = max(i * i, (l*i -1)/i*i); j <= r; j += i) {
            a[j - l] = false;
        }
    }
    for (int i = l; i <= r; i++) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> l >> r;
    sang(l, r);
}
