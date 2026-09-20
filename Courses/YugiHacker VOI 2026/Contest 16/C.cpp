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
#define BIT(x,i) (((x) >> (i)) & 1)
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

const int lg = 30;
int q;

struct Trie {
    struct Node {
        Node *child[2];
        int pre,End;
        ll s;
        Node() {
            pre = End = s = 0;
            ms(child,0);
        }
    };
    int cnt;
    Node *root;
    Trie() : cnt(0) {
        root = new Node();
    }
    void add(int x) {
        Node *p = root;
        FORD(j,lg,0) {
            int k = BIT(x,j);
            if (!p->child[k]) p->child[k] = new Node();
            p = p->child[k];
            p->pre++;
            p->s += x;
        }
        p->End++;
        cnt++;
    }
    void del(int x) {
        Node *p = root;
        FORD(j,lg,0) {
            int k = BIT(x,j);
            if (!p->child[k]) p->child[k] = new Node();
            p = p->child[k];
            p->pre--;
            p->s -= x;
        }
        p->End--;
        cnt--;
    }
    bool Find(int x) {
        Node *p = root;
        FORD(j,lg,0) {
            int k = BIT(x,j);
            if (!p->child[k] || p->child[k]->pre == 0) return 0;
            p = p->child[k];
        }
        return 1;
    }
    ll calc(int x) {
        if (x <= 0) return 0;
        Node *p = root;
        ll ans = 0;
        FORD(j,lg,0) {
            int k = BIT(x,j);
            if (k == 1) ans += (p->child[0] ? p->child[0]->s : 0);
            if (!p->child[k]) return ans;
            p = p->child[k];
        }
        ans += p->s;
        return ans;
    }
    int findpos(int x) {
        int ans = 0;
        Node *p = root;
        FORD(j,lg,0) {
            int check = (p->child[0] ? p->child[0]->pre : 0);
            if (x <= check) {
                p = p->child[0];
            } else {
                x -= check;
                p = p->child[1];
                ans |= (1<<j);
            }
        }
        return ans;
    }
    int maxv(int x) {
        int ans = 0;
        if (!cnt) return x;
        Node *p = root;
        FORD(j,lg,0) {
            int k = BIT(x,j);
            if (p->child[1^k] && p->child[1^k]->pre) {
                ans |= (1<<j);
                p = p->child[1^k];
            }
            else p = p->child[k];
        }
        return ans;
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> q;
    Trie trie;
    while(q--) {
        int ty,x,y;
        cin >> ty >> x;
        if (ty == 1) {
            trie.add(x);
        } else if (ty == 2) {
            if (trie.Find(x)) trie.del(x);
        } else if (ty == 3) {
            cin >> y;
            cout << trie.calc(y) - trie.calc(x-1) << endl;
        } else if (ty == 4) {
            cout << trie.findpos(x) << endl;
        } else cout << trie.maxv(x) << endl;
    }
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}

