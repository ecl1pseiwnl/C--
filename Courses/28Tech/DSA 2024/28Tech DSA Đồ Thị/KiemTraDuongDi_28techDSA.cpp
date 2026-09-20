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
int n, m, t, temp[N], ans = 1;
vector<int> v[N];
bool visited[N];

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cin >> t;
    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for (auto it : v[u]) {
        if (!visited[it]) {
            temp[it] = ans;
            dfs(it);
        }
    }
}

void tplt() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            temp[i] = ans;
            dfs(i);
            ans++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    tplt();
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (temp[x] == temp[y]) {
            cout << "1\n";
        }
        else cout << "-1\n";
    }
    cout << endl;
    return 0;
}
