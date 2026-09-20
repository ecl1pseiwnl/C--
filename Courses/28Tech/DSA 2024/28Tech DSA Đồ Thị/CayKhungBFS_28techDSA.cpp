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

struct canh {
    int x, y;
};
const int N = 1005;
int n, m, u;
vi v[N];
bool used[N];

void inp() {
    cin >> n >> m >> u;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    memset(used, false, sizeof(used));
}

void bfs(int u) {
    vector<canh> ck;
    queue<int> q;
    q.push(u);
    used[u] = true;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (auto it : v[c]) {
            if (!used[it]) {
                used[it] = true;
                q.push(it);
                ck.push_back({ c,it });
            }
        }
    }
    for (auto it : ck) {
        cout << it.x << "->" << it.y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    bfs(u);
    return 0;
}
