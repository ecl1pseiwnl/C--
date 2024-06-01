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
	int a, b, x, y, cnt = 0;
	cin >> a >> b >> x >> y;
	int F[b];
	memset(F, 0, sizeof(F));
	for (int i = a; i <= b; i++) {
		if (i % x == 0 || i % y == 0) {
			F[i] = F[i - 1] + 1;
		}
		else F[i] = F[i - 1];
	}
	cout << F[b] - F[a - 1];
	return 0;
}