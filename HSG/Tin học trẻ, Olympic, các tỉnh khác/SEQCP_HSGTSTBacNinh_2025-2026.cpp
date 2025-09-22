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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 70007, sz = 275;
struct Q{
    int id,l,r;
} qu[N];
int n,q;
ll v[N],f[N],ans[N],ph[N],XOR;
vi p;

void calc() {
    vector<bool> u(N,1);
    u[0] = u[1] = 0;
    for (int i = 2; i*i < N; i++) {
        if (u[i]) {
            p.pb(i);
            for (int j = i*i; j < N; j += i) {
                u[j] = 0;
            }
        }
    }
    for (auto it : p) {
        ph[it] = rng();
    }
    FOR(i,1,n) {
        int cur = v[i];
        f[i] = 0;
        for (auto it : p) {
            if (it*it > cur) break;
            int cnt = 0;
            while (cur % it == 0) {
                cnt++;
                cur /= it;
            }
            if (cnt % 2 == 1) f[i] ^= ph[it];
        }
        if (cur > 1) f[i] ^= ph[cur];
    }
}

bool cmp(const Q&a, const Q&b) {
    if (a.l/sz == b.l/sz) {
        if ((a.l/sz)&1) return a.r < b.r;
        else return a.r > b.r;
    }
    return a.l < b.l;
}

void del(int x) {
    XOR ^= f[x];
}

void add(ll x) {
    XOR ^= f[x];
}

// Tich cua ca doan thi co the len 7000^7000 nen se ap dung XOR Hashing + phan tich thua so nguyen to
// Mot so la so chinh phuong khi thua so nguyen to cua no toan mu chan
// -> Khi sqrt thi no van se luon la 1 so nguyen duong
// Do do ap dung vao, ta se xet neu XOR cua doan la 1 thi tong so mu bi le nen khong bi triet tieu nen bang 1

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("SEQCP.INP","r",stdin);
    freopen("SEQCP.OUT","w",stdout);
    cin >> n >> q;
    FOR(i,1,n) {
        cin >> v[i];
    }
    calc();
    FOR(i,1,q) {
        cin >> qu[i].l >> qu[i].r;
        qu[i].id = i;
    }
    sort(qu+1,qu+q+1,cmp);
    int l = 1,r = 0;
    FOR(i,1,q) {
        while(l > qu[i].l) add(--l);
        while(l < qu[i].l) del(l++);
        while(r < qu[i].r) add(++r);
        while(r > qu[i].r) del(r--);
        ans[qu[i].id] = XOR;
    }
    FOR(i,1,q) {
        cout << (ans[i] == 0 ? "YES\n" : "NO\n");
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}

