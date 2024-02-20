#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> se;
typedef map<int, int> mii;
#define endl "\n";
#define mp make_pair
#define pb push_back
#define a first
#define b second

const int N = 1e7;
ll n;
pair<ll, ll> p[N];

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
	if (x.a < x.b && y.a < y.b) {
		if (x.a == y.a) return x.b > y.b;
		return x.a < y.a;
	}
	if (x.b < x.a && y.b < y.a) {
		if (x.b == y.b) return x.a < y.a;
		return x.b > y.b;
	}
	return x.b - x.a > y.b - y.a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].a;
	}
	for (int i = 1; i <= n; i++) {
		cin >> p[i].b;
	}
	sort(p + 1, p + n + 1, cmp);
	ll res = 0, temp = 0;
	for (int i = 1; i <= n; i++) {
		temp = temp - p[i].a;
		res = min(res, temp);
		temp += p[i].b;
	}
	cout << -res;
	return 0;
}