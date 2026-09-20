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

const int N = 1005;
int n, m;
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
    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for (auto it : v[u]) {
        if (!visited[it]) {
            dfs(it);
        }
    }
}

void dinhtru() {
    int ans = 0, tplt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ++tplt;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int dem = 0;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                ++dem;
                dfs(j);
            }
        }
        if (dem > tplt) {
            ++ans;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    dinhtru();
    return 0;
}
