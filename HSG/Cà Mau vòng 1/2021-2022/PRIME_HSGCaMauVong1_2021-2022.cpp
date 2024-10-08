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
#define pb push_back
#define endl "\n"
const int MOD = 1e9+7;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;

const int N = 1e7+7;
int a[N];

void snt() {
    ms(a,1);
    a[1] = a[0] = 0;
    for (int i = 2; i*i <= N; i++) {
        if (a[i]) {
            for (int j = i*i; j<=N; j+=i) {
                a[j] = 0;
            }
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    snt();
    ll n, ans = 0;
    cin >> n;
    vi v(n);
    unordered_map<int,int> cnt;
    for (auto& it : v) {
        cin >> it;
        cnt[it]++;
    }
    for (auto [x,y] : cnt) {
        if (a[x] && y > 1) ans += y*(y-1)/2;
    }
    cout << ans;
    return 0;
}
