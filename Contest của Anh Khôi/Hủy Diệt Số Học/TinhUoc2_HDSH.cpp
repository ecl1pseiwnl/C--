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
	ll n;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			cout << i << " ";
		}
	}
	for (int i = sqrt(n); i >= 1; i--) {
		if (n % i == 0 && n / i != i) {
			cout << n/i << " ";
		}
	}
	return 0;
}