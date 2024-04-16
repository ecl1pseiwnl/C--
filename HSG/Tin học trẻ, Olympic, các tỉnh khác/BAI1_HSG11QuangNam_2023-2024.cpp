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
	int n, cnt = 0;
	long double sum = 0;
	cin >> n;
	int a[n];
	for (auto& it : a) cin >> it;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			sum += double(a[i]);
			cnt++;
		}
	}
	cout << fixed << setprecision(2) << sum / cnt;
	return 0;
}