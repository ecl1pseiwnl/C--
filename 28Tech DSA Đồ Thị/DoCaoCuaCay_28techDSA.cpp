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
int n, d[N];
vi v[N];
bool visit[N];

void inp() {
    cin >> n;
    for (int i = 0; i < n; i++) {
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
            d[it] = d[u] + 1;
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
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
