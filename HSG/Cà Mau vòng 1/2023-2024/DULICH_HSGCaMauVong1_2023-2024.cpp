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

const int N = 1e5 + 7;
int n, m, q, maxv = INT_MIN;
vi v[N],a, tmp;
bool visited[N];

void inp() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	memset(visited,false,sizeof(visited));
}

void dfs(int u) {
	visited[u] = true;
	for (auto it : v[u]) {
		if (!visited[it]) {
			tmp.pb(it);
			dfs(it);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
            temp.pb(i);
			dfs(i);
			a.pb(tmp.size());
            tmp.clear();
		}
	}
    sort(a.begin(),a.end(), greater<int> ());
    while(q--) {
        int x, s = 0, cnt = -1;
        cin >> x;
        for (int i = 0; i < a.size(); i++) {
            s += a[i];
            cnt++;
            if (s >= x) {
                break;
            }
        }
        cout << cnt << ' ';
    }
	return 0;
}
