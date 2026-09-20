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
	string s;
	cin >> s;
	int cnt = 0, temp = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			temp++;
		}
		else if (s[i] == '1') {
			if (cnt < temp) {
				cnt = temp;
			}
			temp = 0;
		}
	}
	cout << cnt;
	return 0;
}