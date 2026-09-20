#include <bits/stdc++.h>
#include <windows.h>
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
ll lcm(ll x, ll y) { return 1ll*(x / __gcd(x,y))*y;}
#define ms(a,n) memset(a, n,sizeof(a))
#define all(x) (x).begin(),(x).end
#define ins insert
#define sz(x) (int)(x.size())
#define name "TASK"
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define rand(l, r) uniform_int_distribution< int64_t > (l, r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;


void makefile(ofstream& inp) {
    int n = rand(1, 100);
    int m = rand(0, min(100000LL, (ll)n*(n-1)/2));
    int Q = rand(1, 100000);
    inp << n << " " << m << " " << Q << endl;
    set<pi> edges;
    for (int i = 0; i < m; i++) {
        int u = rand(1, n);
        int v = rand(1, n);
        while (u == v || edges.count({min(u,v), max(u,v)})) {
            u = rand(1, n);
            v = rand(1, n);
        }
        edges.insert({min(u,v), max(u,v)});
        inp << u << " " << v << "\n";
    }

    for (int i = 0; i < Q; i++) {
        int x = rand(1, n);
        inp << x << (i < Q-1 ? " " : "");
    }
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int test = 50;
    string input,output, testName = "TRAVEL";
    for (int i = 41; i <= test; i++) {
        string curTest = "test";
        curTest += (i < 10 ? "0" : "") + to_string(i);
        system(("mkdir " + curTest).c_str());
        input  = curTest + "\\" + testName + ".INP";
        output = curTest + "\\" + testName + ".OUT";
        ofstream Input(input.c_str());
        makefile(Input);
        Input.close();
        system(("chinh.exe < " + input + " > " + output).c_str());
    }
    return 0;
}

/*
vector<int> adj[100005];
bool vis[100005];

void dfs(int u, int n, vector<int> adj[]) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, n, adj);
        }
    }
}

bool hasPathFrom1ToN(int n, vector<int> adj[]) {
    memset(vis, false, sizeof(vis));
    dfs(1, n, adj);
    return vis[n];
}

void makefile(ofstream &inp, int testId) {
    int n, m;

    if (testId <= 10) {
        n = rand(2, 100);
        m = rand(1, min(500, n*(n-1)/2));
    } else if (testId <= 30) {
        n = rand(100, 1000);
        m = rand(1000, min(10000, n*(n-1)/2));
    } else {
        n = rand(1000, 1e5);
        m = rand(10000, 2e5);
    }

    m = min(m, n*(n-1)/2);

    inp << n << " " << m << endl;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    set<pair<int,int>> edges;
    vector<tuple<int,int,int>> edgeList;

    vector<int> path;
    path.pb(1);
    int cur = 1;
    while (cur != n) {
        int next = rand(cur+1, n);
        if (next > cur) {
            path.pb(next);
            cur = next;
        }
    }
    for (int i = 0; i < sz(path)-1; i++) {
        int x = path[i];
        int y = path[i+1];
        int z = rand(1, 1000);
        edges.insert({x, y});
        edgeList.pb({x, y, z});
        adj[x].pb(y);
    }

    int remaining = m - sz(edgeList);
    for (int i = 0; i < remaining; i++) {
        int x = rand(1, n);
        int y = rand(1, n);
        while (x == y || edges.count({x, y}) > 0) {
            x = rand(1, n);
            y = rand(1, n);
        }

        int z = rand(1, 1000000000);
        edges.insert({x, y});
        edgeList.pb({x, y, z});
        adj[x].pb(y);
    }

    if (!hasPathFrom1ToN(n, adj)) {
        if (edges.count({1, n}) == 0) {
            edgeList.pb({1, n, rand(1, 1000)});
        }
    }

    shuffle(edgeList.begin(),edgeList.end(), rng);

    for (auto [x, y, z] : edgeList) {
        inp << x << " " << y << " " << z << endl;
    }
}
*/
