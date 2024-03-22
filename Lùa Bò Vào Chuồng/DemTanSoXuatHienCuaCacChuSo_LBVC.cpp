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

const int N = 1e6 + 7;
int a[N], cnt[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		int tmp = a[i];
		while (tmp != 0) {
			int c = tmp % 10;
			cnt[c]++;
			tmp /= 10;
		}
	}
	for (int i = 0; i <= 9; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}