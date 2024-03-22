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
	int n, maxv = INT_MIN;
	cin >> n;
	vector<int> v(n);
	for (auto it : v) {
		cin >> it;
		maxv = max(it, maxv);
	}
	int a[maxv];
	for (int i = 0; i < v.size(); i++) {
		a[v[i]]++;
	}
	for (int i = 1; i <= maxv; i++) {
		if (a[i] != 0) {
			cout << i << " " << a[i] << endl;
		}
	}
	return 0;
}