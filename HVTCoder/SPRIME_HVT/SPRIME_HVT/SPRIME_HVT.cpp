#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl "\n"
#define mp make_pair
#define pb push_back
ll l, r;
vector<bool> a(r - 1, true);

void sang(ll l, ll r) {
    a[1] = a[0] = false;
    for (ll i = 2; i <= sqrt(r); i++) {
        for (ll j = max(i * i, (l * i - 1) / i * i); j <= r; j += i) {
            a[j - l] = false;
        }
    }
}

bool check(int n) {
    while (n > 0) {
        if (a[n] == false) {
            return false;
        }
        n % 10;
        n /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> l >> r;
    sang(l, r);
    for (ll i = l; i <= r; i++) {
        if (check(a[i]) == true) {
            cout << i << endl;
        }
    }
}
