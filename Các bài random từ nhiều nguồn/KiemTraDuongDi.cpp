#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

int n, m, t;
vi v[1001];
bool visited[1001];

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	cin >> t;
	while (t--) {
		int x, y, check = 0;
		cin >> x >> y;
		for (auto it : v[x]) {
			if (it == y) {
				check = 1;
			}
		}
		if (check == 1) {
			cout << "1" << endl;
		}
		else cout << "-1" << endl;
	}
	return 0;
}