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

const int N = 1005;
int n, m, t;
vector<int> v[N];
bool visit[N];


void inp() {
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    memset(visit, false, sizeof(visit));
}

void bfs(int u) {
    visit[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        cout << c << " ";
        for (auto it : v[c]) {
            if (!visit[it]) {
                visit[it] = true;
                q.push(it);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    bfs(t);
    return 0;
}
