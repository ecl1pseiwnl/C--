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
	ll n, i = 2;
	cin >> n;
	set<ll> se;
	while (i <= sqrt(n)) {
		while (n % i == 0) {
			se.insert(i);
			n /= i;
		}
		i++;
	}
	if (n != 1) {
		se.insert(n);
	}
	cout << se.size();
	return 0;
}