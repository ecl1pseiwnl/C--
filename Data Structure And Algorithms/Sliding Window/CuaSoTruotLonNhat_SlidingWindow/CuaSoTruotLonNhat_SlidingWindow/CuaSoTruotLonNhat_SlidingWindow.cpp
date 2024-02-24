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
	int n, k;
	ll sum = 0, ind = 0;
	cin >> n >> k;
	int a[1001];
	for (int& it : a) cin >> it;
	for (int i = 0; i < k; i++) {
		sum += a[i];
	}
	ll res = sum;
	for (int i = k; i < n; i++) {
		sum = sum - a[i - k] + a[i];
		if (sum > res) {
			res = sum;
			ind = i - k + 1;
		}
	}
	cout << res << endl;
	for (int i = 0; i < k; i++) {
		cout << a[ind + i] << " ";
	}
	return 0;
}