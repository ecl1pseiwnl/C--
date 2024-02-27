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

bool check(int n) {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			cnt++;
		}
	}
	if (cnt == 3) {
		return true;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt = 0;
	cin >> n;
	for (int i = 2; i < n; i++) {
		if (check(i)) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}