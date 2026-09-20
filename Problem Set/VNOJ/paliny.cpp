#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<mii> viii;
const double PI = 3.141592653589793238463;
#define bmask(x,i) (((x) >> (i)) & 1)
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
const int EPS = -1e9;
constexpr int MOD = 1e9+7;
constexpr int32_t IINF = 0x3f3f3f3f;
constexpr int64_t LLINF = 0x3f3f3f3f3f3f3f3f;

const int N = 5e4+7;
int n;
string s;

void manacher() {
    string res = "^";
    for (auto it : s) {
        res += "#";
        res += it;
    }
    res += "#$";
    int k = res.size();
    vi p(k+7,0);
    int l = 0, r = 0;
    for (int i = 1; i < k; i++) {
        if (r > i) p[i] = min(r-i,p[2*l-i]);
        else p[i] = 0;
        while(res[i+1+p[i]] == res[i-1-p[i]]) p[i]++;
        if (i+p[i] > r) {
            l = i;
            r = i+p[i];
        }
    }
    int ans = 0;
    for (int i = 1; i < k; i++) ans = max(ans,p[i]);
    cout << ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    cin >> s;
    manacher();
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}


/// chat nhi phan nma luoi chia TH chan le =))))
/*
const int base = 256, N = 5e4+7;
ll hashS[N], hashT[N], pw[N];
int n, ans;
string s, t;

ll cal(ll hs[], int l, int r) {
    return (1ll*hs[r] - hs[l-1] * pw[r-l+1] % MOD + MOD)%MOD;
}

bool check(int k) {
    for (int i = 1; i <= n-k+1; i++) {
        ll nor = cal(hashS,i,i+k-1), rev = cal(hashT,n-(i+k-1)+1,n-i+1);
        if (nor == rev) {
            return 1;
        }
    }
    return 0;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    cin >> s;
    t = s;
    s = "#" + s;
    reverse(all(t));
    t = "#" + t;
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = (pw[i-1] * base)%MOD;
    for (int i = 1; i <= n; i++) {
        hashS[i] = (hashS[i-1] * base + s[i] - 'a' + 1) % MOD;
        hashT[i] = (hashT[i-1] * base + t[i] - 'a' + 1) % MOD;
    }
    int l = 1, r = n;
    while(l <= r) {
        int m = (l+r)/2;
        if (check(m)) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }
    cout << ans;
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}*/
