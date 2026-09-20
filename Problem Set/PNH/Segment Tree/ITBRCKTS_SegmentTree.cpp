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

const int N = 1e5+7;
int n,q;
string s;

struct Node{
    int s,minv;
    Node() {s = 0, minv = 0;}
    Node(int x) : s(x), minv(min(0,x)) {}
    friend Node operator + (const Node& a, const Node& b) {
        Node ans;
        //Tinh tong nhu GSS
        ans.s = a.s + b.s;
        ans.minv = min(a.minv,a.s+b.minv);
        return ans;
    }
};

Node t[N<<2];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || pos > r) return;
    if (l == r) return t[id] = Node(val), void();
    int m = l+r>>1;
    update(id<<1,l,m,pos,val);
    update(id<<1|1,m+1,r,pos,val);
    t[id] = t[id<<1] + t[id<<1|1];
}

Node get(int id, int l, int r, int x, int y) {
    if (y < l || x > r) return Node();
    if (l >= x && r <= y) return t[id];
    int m = l+r>>1;
    return get(id<<1,l,m,x,y) + get(id<<1|1,m+1,r,x,y);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q >> s;
    s = ' ' + s;
    FOR(i,1,n) {
        if (s[i] == '(') {
            update(1,1,n,i,1);
        } else update(1,1,n,i,-1);
    }
    while(q--) {
        int ty,l,r;
        char c;
        cin >> ty;
        if (ty == 0) {
            cin >> l;
            if (s[l] == '(') {
                update(1,1,n,l,-1);
                s[l] = ')';
            } else {
                update(1,1,n,l,1);
                s[l] = '(';
            }
        } else {
            cin >> l >> r;
            Node ans = get(1,1,n,l,r);
            cout << (ans.s == 0 && ans.minv >= 0);
        }
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
