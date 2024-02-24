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
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int& it : a) cin >> it;
	for (int& it : b) cin >> it;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j]) {
			cout << a[i] << " ";
			i++;
		}
		else {
			cout << b[j] << " ";
			j++;
		}
	}
	while (i < n) {
		cout << a[i] << " ";
		i++;
	}
	while (j < m) {
		cout << b[j] << " ";
		j++;
	}
	return 0;
}
