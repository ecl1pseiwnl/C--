#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl "\n";
#define mp make_pair
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, res;
	cin >> n;
	res = n;
	cout << n << " ";
	while (res != 1 && res >= 0) {
		if (res % 2 == 1) {
			res = res * 3 + 1;
		}
		else {
			res = res / 2;
		}
		cout << res << " ";
	}
	return 0;
}