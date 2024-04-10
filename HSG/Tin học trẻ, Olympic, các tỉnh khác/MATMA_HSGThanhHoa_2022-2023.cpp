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
	cin >> s;
	int maxv = INT_MIN;
	if (s.size() > 7) {
		cout << "-1";
		return 0;
	}
	do {
		int num = stoi(s);
		if (num % 30 == 0) {
			maxv = max(num, maxv);
		}
	} while (next_permutation(s.begin(), s.end()));
	cout << maxv;
	return 0;
}