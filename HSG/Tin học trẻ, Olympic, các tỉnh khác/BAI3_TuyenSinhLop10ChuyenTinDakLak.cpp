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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin, s);
	vector<char> v;
	vi u;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int temp = s[i] - '0';
			u.pb(temp);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			v.pb(s[i]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= 'A' && v[i] <= 'Q') {
			cout << char(v[i] + u[i]);
		}
		else if (v[i] >= 'R' && v[i] <= 'Z') {
			if (v[i] + u[i] <= 90) {
				cout << char(v[i] + u[i]);
			}
			else if (v[i] + u[i] > 90) {
				cout << char(65 + (v[i] - u[i] - 91));
			}
		}
	}
	return 0;
}