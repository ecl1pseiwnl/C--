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
    cin.tie(nullptr);
    ll n,cnt = 0;
    cin >> n;
    for (ll i = 2; i <= n; i*=2) {
        cnt += n/i;
    }
    cout << cnt;
    return 0;
}
