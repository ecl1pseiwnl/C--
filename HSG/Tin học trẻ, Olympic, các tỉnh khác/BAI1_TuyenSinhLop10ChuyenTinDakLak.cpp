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
    ll n;
    long double ans = 0;
    vector<ll> v;
    cin >> n;
    for (int i = 1; i <= 2 * n + 3; i++) {
        if (i % 2 != 0) v.pb(i);
    }
    for (int i = 0; i < v.size() - 1; i++) {
        double temp = v[i] * v[i + 1];
        ans += 1 / temp;
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}