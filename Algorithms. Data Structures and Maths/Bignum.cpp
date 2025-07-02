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
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define Mask(x,i) (((x) >> (i)) & 1)
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define ins insert
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define mp make_pair
#define ep emplace_back
#define pb push_back
#define endl "\n"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define name "TASK"
ll __lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
constexpr int MOD = 1e9+7;
constexpr int IINF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;

/// add
string add(string a, string b) {
    ll c = 0, s;
    string ans = "";
    a.insert(0,max(0,int(b.size()-a.size())),'0');
    b.insert(0,max(0,int(b.size()-a.size())),'0');
    FORD(i,a.size()-1,0) {
        s = (a[i] - '0') + (b[i] - '0') + c;
        c = s / 10;
        ans = char(s%10+'0') + ans;
    }
    if (c > 0) ans = '1' + ans;
    return ans;
}

/// sub
string sub(string a, string b) {
    ll c = 0, s, neg = (a.size() < b.size() || (a.size() == b.size() && a < b));
    if (neg) swap(a,b);
    string ans;
    reverse(all(a));
    reverse(all(b));
    REP(i,a.size()) {
        s = (a[i] - '0') - c - (i < b.size() ? b[i] - '0' : 0);
        c = (s < 0 ? 1 : 0);
        ans.pb((s+10*c)+'0');
    }
    while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    if (neg) ans += "-";
    reverse(all(ans));
    return ans.size() ? ans : 0;
}

/// mul
string smul(string a, int k) {
    ll c = 0,s;
    string ans = a;
    FORD(i,a.size()-1,0){
        s = (a[i] - '0') * k + c;
        c = s / 10;
    	ans[i] = (s % 10 + '0');
    }
    if(c != 0) {
		ans = char(c + '0') + ans;
	}
    while(ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
    return ans;
}

string bmul(string a, string b) {
    string ans, ax = "0", bx;
    int t = 0;
    FORD(i,b.size()-1,0) {
        bx = smul(a, b[i] - '0');
        bx.insert(bx.size(), t, '0');
        ++t;
        ans = add(ax, bx);
        ax = ans;
    }
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << add("1","2") << " " << sub("2","1") << " " << bmul("10","2");

    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
