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
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				cout << '5';
			}
			else {
				cout << s[i];
			}
		}
	}
	return 0;
}