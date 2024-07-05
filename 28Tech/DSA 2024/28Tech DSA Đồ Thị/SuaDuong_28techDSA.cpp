#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

struct edge {
    int u, v, w;
};
const int N = 1e5 + 7;
int n, m, par[N], sz[N];
vector<edge> canh;

void makeset() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == par[v]) {
        return v;
    }
    return par[v] = find(par[v]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge e;
        e.u = x;
        e.v = y;
        e.w = z;
        canh.pb(e);
    }
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void kruskal() {
    vector<edge> MST;
    ll d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for (int i = 0; i < m; i++) {
        if (MST.size() == n - 1) break;
        edge e = canh[i];
        if (Union(e.u, e.v)) {
            MST.pb(e);
            d += e.w;
        }
    }
    if (MST.size() != n - 1) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    makeset();
    kruskal();
    return 0;
}
