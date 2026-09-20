#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl "\n"
#define mp make_pair
#define pb push_back

bool check(string s) {
	ll l = 0, r = s.size() - 1;
	while (l <= r) {
		if (s[l] != s[r]) {
			return 0;
		}
		else {
			l++; r--;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (check(s) == 1) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}