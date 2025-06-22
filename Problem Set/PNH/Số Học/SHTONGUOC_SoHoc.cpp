#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    ll s = 0;
    vi v, u;
    for (int i = 1; i <= sqrt(a); i++) {
        if (a % i == 0) {
            v.pb(i);
        }
    }
    for (int i = sqrt(a); i >= 1; i--) {
        if (a % i == 0 && a / i != i) {
            v.pb(a / i);
        }
    }
    for (int i = 1; i <= sqrt(b); i++) {
        if (b % i == 0) {
            u.pb(i);
        }
    }
    for (int i = sqrt(b); i >= 1; i--) {
        if (b % i == 0 && b / i != i) {
            u.pb(b / i);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (find(u.begin(), u.end(), v[i]) == u.end()) {
            s += v[i];
        }
        else continue;
    }
    cout << s;
    return 0;
}
