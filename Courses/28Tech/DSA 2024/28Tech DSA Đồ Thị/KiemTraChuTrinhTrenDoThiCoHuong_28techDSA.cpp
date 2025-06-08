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

const int N = 1005;
int n, m, color[N], par[N];
vi v[N];

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    memset(color, 0, sizeof(color));
    memset(par, 0, sizeof(par));
}

bool dfs(int u) {
    color[u] = 1;
    for (auto it : v[u]) {
        if (color[it] == 0) {
            par[it] = u;
            if (dfs(it)) return true;
        }
        else if (color[it] == 1) {
            return true;
        }
    }
    color[u] = 2;
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    inp();
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (dfs(i)) {
                cout << "1";
                return 0;
            }
        }
    }
    cout << "0";
    return 0;
}