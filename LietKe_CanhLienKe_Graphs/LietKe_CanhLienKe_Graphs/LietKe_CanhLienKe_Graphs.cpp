#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl cout << "\n";
#define mp make_pair
#define pb push_back

int n, m;
vi v[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x); //Neu do thi la do thi vo huong
	}
	for (int i = 1; i <= n; i++) {
		cout << i << " : ";
		for (int x : v[i]) {
			cout << x << " ";
		}
		endl
	}
	return 0;
}