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

const int sz = 26;
#define N 1000100

struct Trie{
    struct Node{
        Node* child[26];
        int exist, cnt;
        Node() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
            exist = cnt = 0;
        }
    };
    int cur;
    Node* root;
    Trie() : cur(0) {
        root = new Node();
    };
    void add(string s) {
        Node* p = root;
        for (char c : s) {
            if (p->child[c - 'a'] == nullptr) p->child[c - 'a'] = new Node();
            p = p->child[c - 'a'];
            p->cnt++;
        }
        p->exist++;
    }

    bool qdel(Node* p, string& s, int i) {
        if (i != (int)s.size()) {
            bool tf = qdel(p->child[s[i] - 'a'],s,i+1);
            if (tf) p->child[s[i] - 'a'] = nullptr;
        }
        else p->exist--;
        if (p != root) {
            p->cnt--;
            if (p->cnt == 0) {
                delete(p);
                return 1;
            }
        }
        return 0;
    }

    void del(string s) {
        if (finds(s) == false) return;
        qdel(root, s, 0);
    }

    bool finds(string s) {
        Node* p = root;
        for (char c : s) {
            if (p->child[c - 'a'] == nullptr) return 0;
            p = p->child[c - 'a'];
        }
        return (p->exist != 0);
    }
    bool prefix(Node* root, string s) {
        Node* cur = root;
        for (char c : s) {
            if (cur->child[c-'a'] == nullptr) return 0;
            cur = cur->child[c-'a'];
        }
        return 1;
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n;
    bool tf = 0;
    Trie trie;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (trie.prefix(trie.root,s)) tf = 1;
        trie.add(s);
    }
    cout << (tf == 1 ? "YES" : "NO");
    cerr << "\nTime elapsed: " << TIME << "s. \n";
    return 0;
}
