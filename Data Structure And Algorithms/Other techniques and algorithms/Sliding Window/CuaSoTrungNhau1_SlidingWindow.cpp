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

bool solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	bool check = 0;
	si se;
	for (int i = 0; i < k; i++) {
		if (se.count(a[i])) {
			return true;
		}
		se.insert(a[i]);
	}
	for (int i = k; i < n; i++) {
		se.erase(a[i - k]);
		if (se.count(a[i])) return true;
		se.insert(a[i]);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (solve()) {
		cout << "1";
	}
	else cout << "0";
	return 0;
}