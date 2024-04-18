#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 10000000007
#define endl "\n";
#define mp make_pair
#define pb push_back

const int N = 505, INF = INT_MAX;
int n, m, q;
vector<pair<int, int>> v[N];

void inp() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb({ y,z });
        v[y].pb({ x,z });
    }
}

void dijkstra(int s, int t) {
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({ 0,s });
    while (!q.empty()) {
        pi top = q.top();
        q.pop();
        int vert = top.second, len = top.first;
        if (d[vert] < len) continue;
        for (auto it : v[vert]) {
            int x = it.first, y = it.second;
            if (d[x] > d[vert] + y) {
                d[x] = d[vert] + y;
                q.push({ d[x],x });
            }
        }
    }
    if (d[t] != INF) {
        cout << d[t] << endl;
    }
    else cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    while (q--) {
        int x, y;
        cin >> x >> y;
        dijkstra(x, y);
    }
    return 0;
}
