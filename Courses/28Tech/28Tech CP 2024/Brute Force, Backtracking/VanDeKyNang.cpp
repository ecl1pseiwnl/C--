#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
ll lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int32_t INF32 = 0x3f3f3f3f;
const int64_t INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 17;
int a[N], v[N], w[N][N];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < t; i++) {
        for (int j = i+1; j < t; j++) {
            cin >> w[i][j];
        }
    }
    int s = 2e9;
    for (int mask = 0; mask < (1 << t); mask++) {
        for (int i = 0; i < t; i++) {
            if((mask >> i) & 1) {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
        }
        int cur = 0;
        for (int i = 0; i < t; i++) {
            cur += a[i] * v[i];
            for (int j = i + 1; j < t; j++) {
                cur += w[i][j] * a[i] * a[j];
            }
        }
        s = min(cur,s);
    }
    cout << s;
    return 0;
}
