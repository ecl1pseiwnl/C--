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

const int N = 1005, INF = INT_MAX;
int n, m, u;
vector<pair<int, int>> v[N];
bool visit[N];

void inp() {
    cin >> n >> m >> u;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb({ y,z });
        v[y].pb({ x,z });
    }
}

void dijkstra(int u) {
    vector<ll> d(n + 1, INF);
    d[u] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> Q;
    Q.push({ 0,u });
    while (!Q.empty()) {
        pi top = Q.top();
        Q.pop();
        int length = top.first, vert = top.second;
        if (length > d[vert]) continue;
        for (auto it : v[vert]) {
            int x = it.first, y = it.second;
            if (d[x] > d[vert] + y) {
                d[x] = d[vert] + y;
                Q.push({ d[x],x });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    dijkstra(u);
    return 0;
}
