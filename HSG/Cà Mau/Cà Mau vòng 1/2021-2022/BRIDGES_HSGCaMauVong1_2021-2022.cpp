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

const int N = 1e5 + 5;
int n, m, cmp;
vi v[N], a[N], tmp;
bool visit[N];

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    memset(visit, false, sizeof(visit));
}

void dfs(int u) {
    visit[u] = true;
    for (auto it : v[u]) {
        if (!visit[it]) {
            a[cmp].pb(it);
            dfs(it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            cmp = i;
            a[cmp].pb(cmp);
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int minv = INT_MAX;
        for (auto it : a[i]) {
            minv = min(it, minv);
        }
        if (minv != INT_MAX) {
            tmp.pb(minv);
        }
    }
    cout << tmp.size() - 1 << endl;
    int i = 1;
    while (i < tmp.size()) {
        cout << tmp[i - 1] << " " << tmp[i] << endl;
        i++;
    }
    return 0;
}
