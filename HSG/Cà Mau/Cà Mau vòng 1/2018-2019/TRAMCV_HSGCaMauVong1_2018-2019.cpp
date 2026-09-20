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

const int N = 1005, INF = INT_MAX;
int n, a, b, s;
vector<pair<int, int>> v[N], u;

void dijkstra(int s) {
    vector<int> d(n + 1, INF);
    d[s] = d[0] = 0;
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
    u.pb({ s,*max_element(d.begin(),d.end()) });
}

bool cmp(pi a, pi b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (cin >> a >> b >> s) {
        v[a].pb({ b,s });
        v[b].pb({ a,s });
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }
    sort(u.begin(), u.end(), cmp);
    for (auto it : u) {
        cout << it.first << endl << it.second;
        return 0;
    }
    return 0;
}
