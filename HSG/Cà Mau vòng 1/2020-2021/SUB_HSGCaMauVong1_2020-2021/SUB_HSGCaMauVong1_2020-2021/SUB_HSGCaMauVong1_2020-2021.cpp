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
	int n, minv = INT_MAX, sum;
	cin >> n;
	int a[n];
	for (int& it : a) cin >> it;
	int l, r;
	for (l = 0; l < n; l++) {
		sum = 0;
		for (r = 0; r < n; r++) {
			sum += a[r];
			if (sum % 2021 == 0 && sum < minv) {
				minv = sum;
			}
			else {
				sum -= a[r];
			}
		}
	}
	cout << minv;
	return 0;
}