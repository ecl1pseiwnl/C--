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
#define all(x) (x).begin(),(x).end
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

struct edge{
    int x,y;
};

const int N = 1e5+7;
int n,m,q, par[N], sz[N];
vector<edge> v;
set<int, greater<int>> ans;

void makeset() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int u) {
    if (u == par[u]) return u;
    int p = find_set(par[u]);
    return p;
}

void Union(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        edge e;
        e.x = x;
        e.y = y;
        v.pb(e);
    }
    makeset();
    for (int i = 0; i < m; i++) {
        edge e = v[i];
        Union(e.x,e.y);
    }
    for (int i = 1; i <= n; i++) {
        ans.insert(sz[find_set(par[i])]);
    }
    while(q--) {
        int x, i = 0;
        cin >> x;
        ll sum = 0;
        for (auto it : ans) {
            sum += it;
            if (sum >= x) {
                cout << i << " ";
                break;
            }
            i++;
        }
    }
    return 0;
}
