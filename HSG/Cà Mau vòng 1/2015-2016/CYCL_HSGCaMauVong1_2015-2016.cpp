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

int n, m, maxv = INT_MIN, color[4005], parent[4005];
vi v[4005], pathh, a;

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    memset(color, 0, sizeof(color));
}

bool dfs(int u) {
	color[u] = 1;
	for (int it : v[u]) {
	    a.pb(it);
		if (color[it] == 0) {
			if (dfs(it)) {
			    parent[it] = u;
                return true;
			}
		}
		else if (color[it] == 1) {
			return true;
		}
	}
	color[u] = 2;
	return false;
}

void path(int u) {
    int cnt = 1, en;
    reverse(a.begin(),a.end());
    for (int i = a.size(); i >= 0; i--) {
        if (a[i] != u) {
            en = i;
            break;
        }
    }
    while (en != u) {
        en = parent[en];
        cnt++;
    }
    pathh.pb(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inp();
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (dfs(i)) {
                path(i);
            }
        }
    }
    for (auto it : pathh) {
        maxv = max(it,maxv);
    }
    cout << maxv;
    return 0;
}
