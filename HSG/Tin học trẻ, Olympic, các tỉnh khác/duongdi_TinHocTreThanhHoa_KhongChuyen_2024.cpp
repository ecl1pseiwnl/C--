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

const int N = 1e5+7, INF = INT_MAX;
int n;
vector<pair<int,int>> v[N];

void dijkstra(int s) {
    vector<int> d(n+1,INF);
    d[s] = 0;
    priority_queue<pi,vector<pi>,greater<pi>> q;
    q.push({0,s});
    while(!q.empty()) {
        pi top = q.top();
        q.pop();
        int vert = top.second, len = top.first;
        if (d[vert] < len) continue;
        for (auto it : v[vert]) {
            int x = it.first, w = it.second;
            if (d[x] > d[vert] + w) {
                d[x] = d[vert] + w;
                q.push({d[x],x});
            }
        }
    }
    cout << d[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    dijkstra(1);
    return 0;
}
