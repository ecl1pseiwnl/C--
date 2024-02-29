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
	string s, temp, ans;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		temp += s[i];
		if (temp.size() == 5) {
			int sum = 0, c = stoi(temp);
			while (c != 0) {
				sum += c % 10;
				c /= 10;
			}
			ans += to_string(sum);
			temp.erase(temp.begin(), temp.end());
		}
	}
	cout << ans;
	return 0;
}