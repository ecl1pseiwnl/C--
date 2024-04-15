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

const int N = 1e6 + 7;
vi a(N, 1), b(N, 0);
int p, q, ans;

void ptich() {
	for (int i = 2; i * i <= N; i++) {
		if (a[i]) {
			for (int j = 1; i <= N; j += i) {
				a[j] *= i;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p >> q;
	ptich();
	for (int i = p; i <= q; i++) {
		ans += b[a[i]];
		b[a[i]]++;
	}
	cout << ans;
	return 0;
}