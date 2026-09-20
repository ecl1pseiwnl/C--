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
	int n, s, m;
	cin >> n >> s >> m;
	if (s * m > (s - s / 7) * n) cout << "-1";
	else {
		for (int i = 1; i <= s - s / 7; i++) {
			if (n * i >= s * m) {
				cout << i;
				break;
			}
		}
	}
	return 0;
}
