#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

const int N = 105, INF = INT_MAX;
int n, m, s, t, par[N];
vector<pi> v[N];

void inp() {
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb({ y,z });
        v[y].pb({ x,z });
    }
}

void dijkstra(int u, int s, int t) {
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({ 0,s });
    while (!q.empty()) {
        pi top = q.top();
        q.pop();
        int vert = top.second, length = top.first;
        if (d[vert] < length) continue;
        for (auto it : v[vert]) {
            int x = it.first, y = it.second;
            if (d[x] > d[vert] + y) {
                d[x] = d[vert] + y;
                q.push({ d[x],x });
                par[x] = vert;
            }
        }
    }
    if (u == 0) {
        cout << d[t] << endl;
    }
    else if (u == 1) {
        vi path;
        while (t != s) {
            path.pb(t);
            t = par[t];
        }
        path.pb(t);
        reverse(path.begin(), path.end());
        cout << path.size() << " ";
        for (auto it : path) cout << it << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inp();
    while (t--) {
        int u, x, y;
        cin >> u >> x >> y;
        dijkstra(u, x, y);
    }
    return 0;
}
