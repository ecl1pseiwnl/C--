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
	int n;
	cin >> n;
	vector<int> v(n - 1), a(n);
	for (auto it : v) cin >> it;
	for (int i = 0; i < v.size(); i++) {
		a[i]++;
	}
	for (int i = 1; i < a.size(); i++) {
		if (a[i] == 0) {
			cout << i << " ";
		}
	}
	return 0;
}