#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef map<int,int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

bool check(ll x) {
    vector<ll> v;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (x / i != i) {
                v.pb(i);
            } else {
                v.pb(i);
                v.pb(x/i);
            }
        }
    }
    if (v.size() == 3) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    while(n--) {
        ll x;
        cin >> x;
        if (check(x)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
