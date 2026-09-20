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

map<ll, ll> F;

ll fib(ll n) {
	if (F.count(n)) {
		return F[n];
	}
	ll k = n / 2;
	if (n % 2 == 0) {
		return F[n] = (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) % MOD;
	}
	return F[n] = (fib(k) * fib(k - 1) + fib(k) * fib(k + 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	F[0] = F[1] = 1;
	cout << (n == 0 ? 0 : fib(n - 1));
	return 0;
}