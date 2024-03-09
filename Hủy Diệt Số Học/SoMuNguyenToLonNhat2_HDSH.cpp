#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n, i = 2, maxv = INT_MIN;
    map<ll, ll> m;
    cin >> n;
    while (i <= sqrt(n)) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
        i++;
    }
    if (n != 1) {
        m[n]++;
    }
    for (auto& it : m) {
        if (maxv < it.second) {
            maxv = it.second;
        }
    }
    cout << maxv;
    return 0;
}