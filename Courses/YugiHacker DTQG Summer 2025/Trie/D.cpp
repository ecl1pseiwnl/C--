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

const int sz = 2, N = 1e5+7, lg = 30;

struct Trie{
    struct Node{
        int exist, cnt, child[sz];
        Node() : exist(0), cnt(0) {
            ms(child,0);
        }
    };
    vector<Node> node;
    Trie() {
        node.ep();
    };
    void add(int x) {
        int pos = 0;
        for (int i = lg; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (node[pos].child[j] == 0) {
                node[pos].child[j] = node.size();
                node.ep();
            }
            pos = node[pos].child[j];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }

    int sol(int x) {
        int ans = 0, pos = 0;
        for (int i = lg; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (node[pos].child[1^j]) {
                pos = node[pos].child[1^j];
                ans ^= (1 ^ j) << i;
            } else {
                pos = node[pos].child[j];
                ans ^= (j << i);
            }
        }
        return ans;
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n,k,ans = 0,res;
        cin >> n >> k;
        vi v(n+1), pre(n+1,0);
        FOR(i,1,n) {
            cin >> v[i];
            pre[i] = pre[i-1] ^ v[i];
        }
        Trie trie;
        trie.add(pre[0]);
        FOR(i,1,n) {
            int prej = trie.sol(pre[i]^k);
            if (prej ^ pre[i] ^ k > ans) {
                ans = max(ans,prej ^ pre[i] ^ k);
                res = prej;
            }
            trie.add(pre[i]);
        }
        cout << res;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
