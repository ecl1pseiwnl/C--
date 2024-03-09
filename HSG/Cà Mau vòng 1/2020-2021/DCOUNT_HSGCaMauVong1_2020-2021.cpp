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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt = 0;
	cin >> n;
	int a[n];
	map<int, int> m;
	for (int& it : a) cin >> it;
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
	}
	for (auto it : m) {
		if (it.second % 2 == 1) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}