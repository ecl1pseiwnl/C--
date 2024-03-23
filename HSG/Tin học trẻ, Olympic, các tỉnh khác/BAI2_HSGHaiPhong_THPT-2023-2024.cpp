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

int dem(int l, int r, string s) {
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		if (s[i] != '1') cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != '1' && s[r] != '1') {
			l++;
			r--;
		}
		else if (s[r] == '1' && s[l] == '0') {
			l++;
		}
		else if (s[l] == '1' && s[r] == '0') {
			r--;
		}
		if (s[l] == '1' && s[r] == '1') {
			cout << dem(l, r, s);
			return 0;
		}
	}
	cout << "0";
	return 0;
}