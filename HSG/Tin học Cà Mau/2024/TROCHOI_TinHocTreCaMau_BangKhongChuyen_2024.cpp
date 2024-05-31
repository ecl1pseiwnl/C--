#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef map<int,int> mii;
#define mp make_pair
#define pb push_back
#define endl "\n"
#define MOD 10000007

const int N = 1e5+7, INF = INT_MAX;
int n,m,s,t1,t2;
vector<pi> v[N];

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    cin >> s >> t1 >> t2;
}

int dijkstra(int s, int t) {
    vector<ll> d(n+1, INF);
    d[s] = 0;
    priority_queue<pi,vector<pi>,greater<pi>> q;
    q.push({0,s});
    while(!q.empty()) {
        auto top = q.top();
        q.pop();
        int vert = top.second, len = top.first;
        if (d[vert] < len) continue;
        for (auto it : v[vert]) {
            int x = it.first, w = it.second;
            if (d[x] > d[vert] + w) {
                d[x] = d[vert] + w;
                q.push({d[x], x});
            }
        }
    }
    return d[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    inp();
    cout << dijkstra(s,t1) + dijkstra(t1,t2);
    return 0;
}
