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
	ll l, r, cnt = 0;
	cin >> l >> r;
	ll a = sqrt(l), b = sqrt(r);
	if (a * a != l) {
		++a;
	}
	for (int i = a; i <= b; i++) {
		cnt++;
	}
	cout << cnt;
	return 0;
}