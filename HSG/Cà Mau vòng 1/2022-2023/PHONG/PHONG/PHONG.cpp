#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mp;
#define endl "\n"
#define mp make_pair
#define pb push_back

struct ph {
	int bd, kt, stt;
};

bool cmp(ph a, ph b) {
	if (a.bd < b.bd) {
		return a.bd < b.bd;
	}
	return a.kt < b.kt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ph a[n];
	int i = 0;
	while (n--) {
		cin >> n;
		a[i].stt = i + 1;
		i++;
	}
	sort(a, a + n, cmp);
	int kt = 1, nht = a[0].kt;
	vi v;
	v.pb(a[0].stt);
	for (int i = 0; i < n; i++) {
		if (nht <= a[i].bd) {
			kt++;
			v.pb(a[i].stt);
			nht = a[i].kt;
		}
	}
	cout << kt << endl;
	for (auto it : a) {
		cout << it << endl;
	}
	return 0;
}